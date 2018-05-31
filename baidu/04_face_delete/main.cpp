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
  if (argc < 3) {
    cout << "Please specify group_id user_id" << endl;
    exit(-1);
  }

  Json::Value result;

  string app_id ="11210565";
  string api_key = "HA0moQndrtIGirVUMTjr4bkl";
  string secret_key = "qMyI2UxqSo4XxsszXI2dGDUAgCARPWxI";

  aip::Face client(app_id, api_key, secret_key);

  string group_id = argv[1];
  string user_id = argv[2];
  string face_token = "daf931cf7355c12d16337fc7dade4a2f";


  result = client.face_delete(user_id, group_id, face_token, aip::null);

  print_json(result);
  return 0;
}



