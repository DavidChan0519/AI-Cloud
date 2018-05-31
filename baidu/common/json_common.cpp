#include <json/json.h>
#include <iostream>

using std::string;
using std::map;
using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::istreambuf_iterator;
using std::stringstream;



void print_json(Json::Value &value)
{
  switch ( value.type() )
     {
     case Json::nullValue:
        break;
     case Json::intValue:
        cout << Json::valueToString( value.asLargestInt() ).c_str();
        break;
     case Json::uintValue:
        cout << Json::valueToString( value.asLargestUInt() ).c_str();
        break;
     case Json::realValue:
        cout << value.asDouble();
        break;
     case Json::stringValue:
        cout << value.asString().c_str();
        break;
     case Json::booleanValue:
        cout << (value.asBool() ? "true" : "false");
        break;
     case Json::arrayValue:
        {
           cout << endl;

           int size = value.size();
           for ( int index =0; index < size; ++index )
           {
              print_json(value[index]);
              cout << endl;
           }
        }
        break;
     case Json::objectValue:
        {
           Json::Value::Members members(value.getMemberNames());

           for ( Json::Value::Members::iterator it = members.begin(); it != members.end(); ++it )
           {
              const string &name = *it;
              cout << "[" << name << "]" <<  "\t: ";
              print_json(value[name]);
              cout << endl;
           }
        }
        break;
     default:
        break;
     }

}




