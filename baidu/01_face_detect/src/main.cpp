#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include "base64.hpp"
#include <string.h>
#include <streambuf>
#include "face.h"
#include <sstream>
#include "common.h"


using std::string;
using std::map;
using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::istreambuf_iterator;
using std::stringstream;


int main(int argc, char *argv[])
{
  //build connection
  string app_id ="11210565";
  string api_key = "HA0moQndrtIGirVUMTjr4bkl";
  string secret_key = "qMyI2UxqSo4XxsszXI2dGDUAgCARPWxI";

  if (argc < 3) {
    cout << "Please specify input pic and face_num" << endl;
    exit(1);
  }

  int face_num = atoi(argv[2]);
  stringstream face_n;
  string num;

  //convert int to string
  face_n << face_num;
  face_n >> num;

  aip::Face client(app_id, api_key, secret_key);

  cv::Mat img = cv::imread(argv[1]);
  Json::Value result;
  ifstream in;
  in.open(argv[1], ios::in|ios::binary);

  string image_org((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());

  string encode_base64 = base64_encode(image_org);
  string image_type("BASE64");

  result = client.detect(encode_base64, image_type, aip::null);

  map<string, string> options;
  options["face_field"] = "age,beauty,glasses,faceshape,gender,race";
  options["max_face_num"] = num.c_str();
  options["face_type"] = "LIVE";


  //result = client.detect(encode_base64, image_type, options);
  print_json(result);

  for (int idx=0; idx < face_num; idx++) {
    double x = result["result"]["face_list"][idx]["location"]["left"].asDouble();
    double y = result["result"]["face_list"][idx]["location"]["top"].asDouble();
    double w = result["result"]["face_list"][idx]["location"]["width"].asDouble();
    double h = result["result"]["face_list"][idx]["location"]["height"].asDouble();
    //BGR
    //cv::rectangle(img, cv::Rect(x,y,w,h), cv::Scalar(255,0,0), 2);
    cv::rectangle(img, cv::Rect(x,y,w,h), cv::Scalar(0,255,0), 1);
    //cv::rectangle(img, cv::Rect(x,y,w,h), cv::Scalar(0,0,255), 2);
  }

  cv::imshow("detect",img);
  cv::waitKey();


  //delete buffer;
  return 0;
}
