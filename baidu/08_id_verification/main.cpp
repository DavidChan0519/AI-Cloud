#include <iostream>
#include <fstream>
#include <opencv2/highgui/highgui.hpp>
#include "base64.hpp"
#include <string.h>
#include <streambuf>
#include "face.h"
#include <sstream>
#include <json/json.h>
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
  if (argc < 2) {
    cout << "Please specify group_id" << endl;
    exit(-1);
  }

  Json::Value result;

  string app_id ="11210565";
  string api_key = "HA0moQndrtIGirVUMTjr4bkl";
  string secret_key = "qMyI2UxqSo4XxsszXI2dGDUAgCARPWxI";

  aip::Face client(app_id, api_key, secret_key);

  ifstream in;
  in.open(argv[1], ios::in|ios::binary);

  string image_org((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());

  string image = base64_encode(image_org);
  string image_type ="BASE64";
  string id_card_number ="342528198605174798" ;
  string name = "David";

  // method 1
  result = client.person_verify(image, image_type, id_card_number, name, aip::null);
  print_json(result);

  result.clear();

  // method 2
  map<string, string> options;
  options["quality_control"] = "NORMAL";
  options["liveness_control"] = "LOW";

  result = client.person_verify(image, image_type, id_card_number, name, options);
  print_json(result);
  return 0;
}



