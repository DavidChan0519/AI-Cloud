#include <iostream>
#include <opencv2/opencv.hpp>
#include <curl/curl.h>
#include <string.h>
#include <streambuf>
#include <fstream>
#include <json/json.h>
#include "common.h"

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
  if (argc < 3) {
    cout << "Please specify 1st & 2nd pic path" << endl;
    exit(-1);
  }

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
    curl_easy_setopt(curl, CURLOPT_URL, "https://api-cn.faceplusplus.com/facepp/v3/compare");

    /* Now specify the POST data */
    curl_formadd(&formpost, &formlast, CURLFORM_COPYNAME,"api_key", CURLFORM_COPYCONTENTS, "k-rDxYjKMnXMRtRbFgIhcvrmPSFXK2wD", CURLFORM_END);
    curl_formadd(&formpost, &formlast, CURLFORM_COPYNAME,"api_secret", CURLFORM_COPYCONTENTS, "I1Mo4QJrwlCshBrjqI4NhlpGgljemW4y", CURLFORM_END);
    curl_formadd(&formpost, &formlast, CURLFORM_COPYNAME,"image_file1", CURLFORM_FILE, argv[1], CURLFORM_END);
    curl_formadd(&formpost, &formlast, CURLFORM_COPYNAME,"image_file2", CURLFORM_FILE, argv[2], CURLFORM_END);

    //option
    curl_formadd(&formpost, &formlast, CURLFORM_COPYNAME,"return_landmark", CURLFORM_COPYCONTENTS, "2", CURLFORM_END);
    curl_formadd(&formpost, &formlast, CURLFORM_COPYNAME,"return_attributes", CURLFORM_COPYCONTENTS, "gender,age,smiling,emotion,ethnicity,beauty", CURLFORM_END);

    curl_easy_setopt(curl,CURLOPT_WRITEDATA,  &postret);
    curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION, save_response_callback);
    curl_easy_setopt(curl, CURLOPT_POST,  true);
    curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);

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

    cout << "==================== Result :====================" << endl;
    cout << "confidence :" << res_data["confidence"].asDouble() << endl;

    cv::Mat img1st = cv::imread(argv[1]);
    cv::namedWindow("1st", CV_WINDOW_NORMAL);
    cv::imshow("1st",img1st);

    cv::Mat img2nd = cv::imread(argv[2]);
    cv::namedWindow("2nd", CV_WINDOW_NORMAL);
    cv::imshow("2nd",img2nd);

    cv::waitKey(0);

    /* always cleanup */
    curl_easy_cleanup(curl);
  }

  curl_global_cleanup();
  return 0;
}

