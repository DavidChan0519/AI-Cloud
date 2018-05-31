/**
 * Copyright (c) 2017 Baidu.com, Inc. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on
 * an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations under the License.
 *
 * @author baidu aip
 */

#ifndef __AIP_FACE_H__
#define __AIP_FACE_H__

#include "base/base.h"

namespace aip {

    class Face: public AipBase
    {
    public:
        
        std::string _detect =
            "https://aip.baidubce.com/rest/2.0/face/v3/detect";
        
        std::string _search =
            "https://aip.baidubce.com/rest/2.0/face/v3/search";
        
        std::string _user_add =
            "https://aip.baidubce.com/rest/2.0/face/v3/faceset/user/add";
        
        std::string _user_update =
            "https://aip.baidubce.com/rest/2.0/face/v3/faceset/user/update";
        
        std::string _face_delete =
            "https://aip.baidubce.com/rest/2.0/face/v3/faceset/face/delete";
        
        std::string _user_get =
            "https://aip.baidubce.com/rest/2.0/face/v3/faceset/user/get";
        
        std::string _face_getlist =
            "https://aip.baidubce.com/rest/2.0/face/v3/faceset/face/getlist";
        
        std::string _group_getusers =
            "https://aip.baidubce.com/rest/2.0/face/v3/faceset/group/getusers";
        
        std::string _user_copy =
            "https://aip.baidubce.com/rest/2.0/face/v3/faceset/user/copy";
        
        std::string _user_delete =
            "https://aip.baidubce.com/rest/2.0/face/v3/faceset/user/delete";
        
        std::string _group_add =
            "https://aip.baidubce.com/rest/2.0/face/v3/faceset/group/add";
        
        std::string _group_delete =
            "https://aip.baidubce.com/rest/2.0/face/v3/faceset/group/delete";
        
        std::string _group_getlist =
            "https://aip.baidubce.com/rest/2.0/face/v3/faceset/group/getlist";
        
        std::string _person_verify =
            "https://aip.baidubce.com/rest/2.0/face/v3/person/verify";
        
        std::string _faceverify =
            "https://aip.baidubce.com/rest/2.0/face/v3/faceverify";
        
        std::string _video_sessioncode =
            "https://aip.baidubce.com/rest/2.0/face/v1/faceliveness/sessioncode";
        
        std::string _video_faceliveness =
            "https://aip.baidubce.com/rest/2.0/face/v1/faceliveness/verify";
        

        Face(const std::string & app_id, const std::string & ak, const std::string & sk): AipBase(app_id, ak, sk)
        {
        }

        std::string vector_join_base64(const std::vector<std::string> & v_images) {
            std::string images;
            size_t count = v_images.size();
            for (size_t i = 0; i < count;i++)
            {
                std::string image = v_images[i];
                images += base64_encode(image.c_str(), (int) image.size());
                if (i != (count - 1)) {
                    images += ",";
                }

            }
            return images;
        }
        
        /**
         * detect
         * @param image 图片信息(**总数据大小应小于10M**)，图片上传方式根据image_type来判断
         * @param image_type 图片类型 **BASE64**:图片的base64值，base64编码后的图片数据，需urlencode，编码后的图片大小不超过2M；**URL**:图片的 URL地址( 可能由于网络等原因导致下载图片时间过长)**；FACE_TOKEN**: 人脸图片的唯一标识，调用人脸检测接口时，会为每个人脸图片赋予一个唯一的FACE_TOKEN，同一张图片多次检测得到的FACE_TOKEN是同一个
         * options 可选参数:
         * face_field 包括age,beauty,expression,faceshape,gender,glasses,landmark,race,qualities信息，逗号分隔，默认只返回人脸框、概率和旋转角度
         * max_face_num 最多处理人脸的数目，默认值为1，仅检测图片中面积最大的那个人脸；**最大值10**，检测图片中面积最大的几张人脸。
         * face_type 人脸的类型 **LIVE**表示生活照：通常为手机、相机拍摄的人像图片、或从网络获取的人像图片等**IDCARD**表示身份证芯片照：二代身份证内置芯片中的人像照片 **WATERMARK**表示带水印证件照：一般为带水印的小图，如公安网小图 **CERT**表示证件照片：如拍摄的身份证、工卡、护照、学生证等证件图片 默认**LIVE**
         */
        Json::Value detect(
            std::string const & image,
            std::string const & image_type,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["image"] = image;
            data["image_type"] = image_type;

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_detect, null, data, null);

            return result;
        }
        
        /**
         * search
         * @param image 图片信息(**总数据大小应小于10M**)，图片上传方式根据image_type来判断
         * @param image_type 图片类型 **BASE64**:图片的base64值，base64编码后的图片数据，需urlencode，编码后的图片大小不超过2M；**URL**:图片的 URL地址( 可能由于网络等原因导致下载图片时间过长)**；FACE_TOKEN**: 人脸图片的唯一标识，调用人脸检测接口时，会为每个人脸图片赋予一个唯一的FACE_TOKEN，同一张图片多次检测得到的FACE_TOKEN是同一个
         * options 可选参数:
         * group_id_list 从指定的group中进行查找 用逗号分隔，**上限20个**
         * quality_control 图片质量控制  **NONE**: 不进行控制 **LOW**:较低的质量要求 **NORMAL**: 一般的质量要求 **HIGH**: 较高的质量要求 **默认 NONE**
         * liveness_control 活体检测控制  **NONE**: 不进行控制 **LOW**:较低的活体要求(高通过率 低攻击拒绝率) **NORMAL**: 一般的活体要求(平衡的攻击拒绝率, 通过率) **HIGH**: 较高的活体要求(高攻击拒绝率 低通过率) **默认NONE**
         * user_id 当需要对特定用户进行比对时，指定user_id进行比对。即人脸认证功能。
         * max_user_num 查找后返回的用户数量。返回相似度最高的几个用户，默认为1，最多返回5个。
         */
        Json::Value search(
            std::string const & image,
            std::string const & image_type,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["image"] = image;
            data["image_type"] = image_type;

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_search, null, data, null);

            return result;
        }
        
        /**
         * user_add
         * @param image 图片信息(**总数据大小应小于10M**)，图片上传方式根据image_type来判断
         * @param image_type 图片类型 **BASE64**:图片的base64值，base64编码后的图片数据，需urlencode，编码后的图片大小不超过2M；**URL**:图片的 URL地址( 可能由于网络等原因导致下载图片时间过长)**；FACE_TOKEN**: 人脸图片的唯一标识，调用人脸检测接口时，会为每个人脸图片赋予一个唯一的FACE_TOKEN，同一张图片多次检测得到的FACE_TOKEN是同一个
         * @param group_id 用户组id（由数字、字母、下划线组成），长度限制128B
         * @param user_id 用户id（由数字、字母、下划线组成），长度限制128B
         * options 可选参数:
         * user_info 用户资料，长度限制256B
         * quality_control 图片质量控制  **NONE**: 不进行控制 **LOW**:较低的质量要求 **NORMAL**: 一般的质量要求 **HIGH**: 较高的质量要求 **默认 NONE**
         * liveness_control 活体检测控制  **NONE**: 不进行控制 **LOW**:较低的活体要求(高通过率 低攻击拒绝率) **NORMAL**: 一般的活体要求(平衡的攻击拒绝率, 通过率) **HIGH**: 较高的活体要求(高攻击拒绝率 低通过率) **默认NONE**
         */
        Json::Value user_add(
            std::string const & image,
            std::string const & image_type,
            std::string const & group_id,
            std::string const & user_id,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["image"] = image;
            data["image_type"] = image_type;
            data["group_id"] = group_id;
            data["user_id"] = user_id;

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_user_add, null, data, null);

            return result;
        }
        
        /**
         * user_update
         * @param image 图片信息(**总数据大小应小于10M**)，图片上传方式根据image_type来判断
         * @param image_type 图片类型 **BASE64**:图片的base64值，base64编码后的图片数据，需urlencode，编码后的图片大小不超过2M；**URL**:图片的 URL地址( 可能由于网络等原因导致下载图片时间过长)**；FACE_TOKEN**: 人脸图片的唯一标识，调用人脸检测接口时，会为每个人脸图片赋予一个唯一的FACE_TOKEN，同一张图片多次检测得到的FACE_TOKEN是同一个
         * @param group_id 更新指定groupid下uid对应的信息
         * @param user_id 用户id（由数字、字母、下划线组成），长度限制128B
         * options 可选参数:
         * user_info 用户资料，长度限制256B
         * quality_control 图片质量控制  **NONE**: 不进行控制 **LOW**:较低的质量要求 **NORMAL**: 一般的质量要求 **HIGH**: 较高的质量要求 **默认 NONE**
         * liveness_control 活体检测控制  **NONE**: 不进行控制 **LOW**:较低的活体要求(高通过率 低攻击拒绝率) **NORMAL**: 一般的活体要求(平衡的攻击拒绝率, 通过率) **HIGH**: 较高的活体要求(高攻击拒绝率 低通过率) **默认NONE**
         */
        Json::Value user_update(
            std::string const & image,
            std::string const & image_type,
            std::string const & group_id,
            std::string const & user_id,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["image"] = image;
            data["image_type"] = image_type;
            data["group_id"] = group_id;
            data["user_id"] = user_id;

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_user_update, null, data, null);

            return result;
        }
        
        /**
         * face_delete
         * @param user_id 用户id（由数字、字母、下划线组成），长度限制128B
         * @param group_id 用户组id（由数字、字母、下划线组成），长度限制128B
         * @param face_token 需要删除的人脸图片token，（由数字、字母、下划线组成）长度限制64B
         * options 可选参数:
         */
        Json::Value face_delete(
            std::string const & user_id,
            std::string const & group_id,
            std::string const & face_token,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["user_id"] = user_id;
            data["group_id"] = group_id;
            data["face_token"] = face_token;

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_face_delete, null, data, null);

            return result;
        }
        
        /**
         * user_get
         * @param user_id 用户id（由数字、字母、下划线组成），长度限制128B
         * @param group_id 用户组id（由数字、字母、下划线组成），长度限制128B
         * options 可选参数:
         */
        Json::Value user_get(
            std::string const & user_id,
            std::string const & group_id,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["user_id"] = user_id;
            data["group_id"] = group_id;

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_user_get, null, data, null);

            return result;
        }
        
        /**
         * face_getlist
         * @param user_id 用户id（由数字、字母、下划线组成），长度限制128B
         * @param group_id 用户组id（由数字、字母、下划线组成），长度限制128B
         * options 可选参数:
         */
        Json::Value face_getlist(
            std::string const & user_id,
            std::string const & group_id,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["user_id"] = user_id;
            data["group_id"] = group_id;

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_face_getlist, null, data, null);

            return result;
        }
        
        /**
         * group_getusers
         * @param group_id 用户组id（由数字、字母、下划线组成），长度限制128B
         * options 可选参数:
         * start 默认值0，起始序号
         * length 返回数量，默认值100，最大值1000
         */
        Json::Value group_getusers(
            std::string const & group_id,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["group_id"] = group_id;

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_group_getusers, null, data, null);

            return result;
        }
        
        /**
         * user_copy
         * @param user_id 用户id（由数字、字母、下划线组成），长度限制128B
         * options 可选参数:
         * src_group_id 从指定组里复制信息
         * dst_group_id 需要添加用户的组id
         */
        Json::Value user_copy(
            std::string const & user_id,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["user_id"] = user_id;

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_user_copy, null, data, null);

            return result;
        }
        
        /**
         * user_delete
         * @param group_id 用户组id（由数字、字母、下划线组成），长度限制128B
         * @param user_id 用户id（由数字、字母、下划线组成），长度限制128B
         * options 可选参数:
         */
        Json::Value user_delete(
            std::string const & group_id,
            std::string const & user_id,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["group_id"] = group_id;
            data["user_id"] = user_id;

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_user_delete, null, data, null);

            return result;
        }
        
        /**
         * group_add
         * @param group_id 用户组id（由数字、字母、下划线组成），长度限制128B
         * options 可选参数:
         */
        Json::Value group_add(
            std::string const & group_id,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["group_id"] = group_id;

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_group_add, null, data, null);

            return result;
        }
        
        /**
         * group_delete
         * @param group_id 用户组id（由数字、字母、下划线组成），长度限制128B
         * options 可选参数:
         */
        Json::Value group_delete(
            std::string const & group_id,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["group_id"] = group_id;

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_group_delete, null, data, null);

            return result;
        }
        
        /**
         * group_getlist
         * options 可选参数:
         * start 默认值0，起始序号
         * length 返回数量，默认值100，最大值1000
         */
        Json::Value group_getlist(
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_group_getlist, null, data, null);

            return result;
        }
        
        /**
         * person_verify
         * @param image 图片信息(**总数据大小应小于10M**)，图片上传方式根据image_type来判断
         * @param image_type 图片类型 **BASE64**:图片的base64值，base64编码后的图片数据，需urlencode，编码后的图片大小不超过2M；**URL**:图片的 URL地址( 可能由于网络等原因导致下载图片时间过长)**；FACE_TOKEN**: 人脸图片的唯一标识，调用人脸检测接口时，会为每个人脸图片赋予一个唯一的FACE_TOKEN，同一张图片多次检测得到的FACE_TOKEN是同一个
         * @param id_card_number 身份证号（真实身份证号号码）
         * @param name utf8，姓名（真实姓名，和身份证号匹配）
         * options 可选参数:
         * quality_control 图片质量控制  **NONE**: 不进行控制 **LOW**:较低的质量要求 **NORMAL**: 一般的质量要求 **HIGH**: 较高的质量要求 **默认 NONE**
         * liveness_control 活体检测控制  **NONE**: 不进行控制 **LOW**:较低的活体要求(高通过率 低攻击拒绝率) **NORMAL**: 一般的活体要求(平衡的攻击拒绝率, 通过率) **HIGH**: 较高的活体要求(高攻击拒绝率 低通过率) **默认NONE**
         */
        Json::Value person_verify(
            std::string const & image,
            std::string const & image_type,
            std::string const & id_card_number,
            std::string const & name,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["image"] = image;
            data["image_type"] = image_type;
            data["id_card_number"] = id_card_number;
            data["name"] = name;

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_person_verify, null, data, null);

            return result;
        }
        
        /**
         * faceverify
         * @param image 图片信息(**总数据大小应小于10M**)，图片上传方式根据image_type来判断
         * @param image_type 图片类型 **BASE64**:图片的base64值，base64编码后的图片数据，需urlencode，编码后的图片大小不超过2M；**URL**:图片的 URL地址( 可能由于网络等原因导致下载图片时间过长)**；FACE_TOKEN**: 人脸图片的唯一标识，调用人脸检测接口时，会为每个人脸图片赋予一个唯一的FACE_TOKEN，同一张图片多次检测得到的FACE_TOKEN是同一个
         * options 可选参数:
         * face_fields 如不选择此项，返回结果默认只有人脸框、概率和旋转角度。可选参数为qualities、faceliveness。qualities：图片质量相关判断；faceliveness：活体判断。如果两个参数都需要选择，请使用半角逗号分隔。
         */
        Json::Value faceverify(
            std::string const & image,
            std::string const & image_type,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["image"] = image;
            data["image_type"] = image_type;

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_faceverify, null, data, null);

            return result;
        }
        
        /**
         * video_sessioncode
         * options 可选参数:
         * appid 百度云创建应用时的唯一标识ID
         */
        Json::Value video_sessioncode(
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_video_sessioncode, null, data, null);

            return result;
        }
        
        /**
         * video_faceliveness
         * @param session_id 语音校验码会话id，使用此接口的前提是已经调用了语音校验码接口
         * @param video_base64 base64编码后的视频数据（视频限制：最佳为上传5-15s的mp4文件。视频编码方式：h264编码；音频编码格式：aac，pcm均可。）
         * options 可选参数:
         */
        Json::Value video_faceliveness(
            std::string const & session_id,
            std::string const & video_base64,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["session_id"] = session_id;
            data["video_base64"] = video_base64;

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_video_faceliveness, null, data, null);

            return result;
        }
        /**
         * match
         * @param data 参数对象数组
         *
         */
        Json::Value match(
            Json::Value const & data)
        {
            std::string _match =
                "https://aip.baidubce.com/rest/2.0/face/v3/match";
            Json::Value result =
                this->request(_match, null, data.toStyledString(), null);

            return result;
        }

    };
}
#endif