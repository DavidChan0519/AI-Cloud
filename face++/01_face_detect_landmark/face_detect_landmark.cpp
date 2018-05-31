#include <iostream>
#include <opencv2/opencv.hpp>
#include <curl/curl.h>
#include <string>
#include <streambuf>
#include <fstream>
#include <json/json.h>
#include "common.h"

/*
curl -X POST "https://api-cn.faceplusplus.com/facepp/v3/detect" -F "api_key=<api_key>" \
-F "api_secret=<api_secret>" \
-F "image_file=@image_file.jpg" \
-F "return_landmark=1" \
-F "return_attributes=gender,age"
*/


using namespace std;

static size_t save_response_callback(char *ptr, size_t size, size_t nmemb, string &stream)
{
  size_t sizes = size*nmemb;

  string temp(ptr,sizes);
  stream += temp;

  return sizes;
}



int main(int argc, char *argv[])
{
  if (argc < 2) {
    cout << "Please specify pic path" << endl;
    exit(-1);
  }

  cv::Mat img = cv::imread(argv[1]);
  cv::namedWindow("landmark1st", CV_WINDOW_NORMAL);
  cv::imshow("landmark1st",img);

  CURL *curl;
  CURLcode res;
  curl_httppost *formpost=NULL;
  curl_httppost *formlast=NULL;
  string postret;
  long code;

  /* In windows, this will init the winsock stuff */
  curl_global_init(CURL_GLOBAL_ALL);

  /* get a curl handle */
  curl = curl_easy_init();
  if(curl) {
    /* First set the URL that is about to receive our POST. This URL can
       just as well be a https:// URL if that is what should receive the
       data. */
    curl_easy_setopt(curl, CURLOPT_URL, "https://api-cn.faceplusplus.com/facepp/v3/detect");

    /* Now specify the POST data */
    curl_formadd(&formpost, &formlast, CURLFORM_COPYNAME,"api_key", CURLFORM_COPYCONTENTS, "k-rDxYjKMnXMRtRbFgIhcvrmPSFXK2wD", CURLFORM_END);
    curl_formadd(&formpost, &formlast, CURLFORM_COPYNAME,"api_secret", CURLFORM_COPYCONTENTS, "I1Mo4QJrwlCshBrjqI4NhlpGgljemW4y", CURLFORM_END);
    curl_formadd(&formpost, &formlast, CURLFORM_COPYNAME,"image_file", CURLFORM_FILE, argv[1], CURLFORM_END);

    //option
    curl_formadd(&formpost, &formlast, CURLFORM_COPYNAME,"return_landmark", CURLFORM_COPYCONTENTS, "2", CURLFORM_END);
    curl_formadd(&formpost, &formlast, CURLFORM_COPYNAME,"return_attributes", CURLFORM_COPYCONTENTS, "gender,age,smiling", CURLFORM_END);

    //do not swap those 2 options below
    curl_easy_setopt(curl, CURLOPT_POST,  true);
    curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);


    curl_easy_setopt(curl,CURLOPT_WRITEDATA,  &postret);
    curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION, save_response_callback);

#ifdef SKIP_PEER_VERIFICATION
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
#endif

#ifdef SKIP_HOSTNAME_VERIFICATION
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
#endif

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    }

    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &code);
    Json::Value res_data;
    Json::Reader *reader = new Json::Reader(Json::Features::strictMode());
    if(!reader->parse(postret, res_data)){
      cout<<"parse error";
      return -1;
    }
    cout<<"HTTP Status Code:"<<code<<endl;
    cout<<res_data<<endl;

    int faceNum = res_data["faces"].size();

    for (int loop = 0; loop < faceNum; loop++) {
      Json::Value Coords = res_data["faces"][loop]["landmark"];
      Json::Value::Members members(Coords.getMemberNames());
      for ( Json::Value::Members::iterator it = members.begin(); it != members.end(); ++it ) {
         const string &name = *it;

         int y = Coords[name]["y"].asInt();
         int x = Coords[name]["x"].asInt();

         //img.at<cv::Vec3b>(y,x)[0]=0;//blue
         //img.at<cv::Vec3b>(y,x)[1]=255;//green
         //img.at<cv::Vec3b>(y,x)[2]=0;//red

         cv::Point  p2;
         p2.y = y;
         p2.x = x;
         cv::circle(img, p2, 2, cv::Scalar(0,255,0), -1);
      }
    }

    cv::namedWindow("landmark2nd", CV_WINDOW_NORMAL);
    cv::imshow("landmark2nd",img);
    cv::waitKey();

    /* always cleanup */
    curl_easy_cleanup(curl);
  }

  curl_global_cleanup();
  return 0;
}

