#include <iostream>
#include <fstream>
#include <opencv2/highgui/highgui.hpp>
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
  if (argc < 2) {
    cout << "Please specify pic" << endl;
    exit(-1);
  }

  Json::Value result;

  string app_id ="11210565";
  string api_key = "HA0moQndrtIGirVUMTjr4bkl";
  string secret_key = "qMyI2UxqSo4XxsszXI2dGDUAgCARPWxI";

  aip::Face client(app_id, api_key, secret_key);

  ifstream in(argv[1],ios::in|ios::binary);

  string image((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());

  string encode_base64 = base64_encode(image);
  string image_type="BASE64";
  string group_id = "group1";
  string user_id = "user1";

  map<string, string> options;
  options["user_info"] = "David Chan";
  options["quality_control"] = "NORMAL";
  options["liveness_control"] = "LOW";

  result = client.user_update(encode_base64, image_type, group_id, user_id, options);

  print_json(result);

  return 0;
}



