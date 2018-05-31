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

  string group_id = argv[1];

  result = client.group_add(group_id, aip::null);
  print_json(result);

  cout << "=====================get group list(no param)====================="<<endl;
  result.clear();

  result = client.group_getlist(aip::null);
  print_json(result);

  cout << "=====================get group list(with param)========================"<<endl;
  result.clear();

  map<string, string> options;
  options["start"] = "0";
  options["length"] = "50";

  result = client.group_getlist(options);
  print_json(result);

  return 0;
}



