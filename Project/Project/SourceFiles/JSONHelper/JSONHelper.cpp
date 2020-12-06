#include "../StdAfx.h"
#include "JsonHelper.h"

//#include "External/rapidjson/include/document.h"
//
//#include "External/rapidjson/include/writer.h"
//#include "External/rapidjson/include/filewritestream.h"
//
//#include "External/rapidjson/include/reader.h"
//#include "External/rapidjson/include/filereadstream.h"
//
//
//#include "External/rapidjson/include/error/en.h"
//
////rapidjson��json�������ō\����͂��邽�߂̃c�[��
//using namespace rapidjson;
//
//bool FileOpen(std::string& fileName, rapidjson::Document& srcDoc);
//bool ReadJson(rapidjson::Document& srcDoc);
//bool WriteJson(rapidjson::Document& srcDoc);
//void GenerateFile(std::string& fileName, rapidjson::Document& srcDoc);
//void StringView(rapidjson::Document& srcDoc);
//
//
//static const char* s_json = R"(
//{
//    "string" : "foo",
//    "number" : 123,
//    "array" : [
//        0, 0, 0, 0
//    ],
//    "object" : {
//        "v0" : "bar",
//        "v1" : 456,
//        "v2" : 0.123
//    }
//}
//)";
//
//
//void StringView(rapidjson::Document& srcDoc)
//{
//    // write
//    StringBuffer ws;
//    Writer<StringBuffer> writer(ws);
//
//    srcDoc.Accept(writer);
//
//    const char* result = ws.GetString();
//    printf("%s\n", result);
//}
//
//bool FileOpen(std::string& fileName, rapidjson::Document& srcDoc)
//{
//    //�ǂݍ��ݐ�p�Ńt�@�C�����J��
//    std::ifstream ifs(fileName.c_str()
//        , std::ios::in      //�ǂݎ���p���[�h�ŋN��
//        | std::ios::binary  //�o�C�i�����[�h��
//        | std::ios::ate);   //�t�@�C��(���e��)�T�C�Y��m�邽�߂ɃV�[�N���t�@�C�����̃f�[�^������
//
//    //�t�@�C�����J������(���݂��Ă��邩�H)
//    if (!ifs.is_open())
//    {
//        //�t�@�C�����J���Ȃ�����
//        printf("�t�@�C�����Ȃ�����\n");
//        return false;
//    }
//
//    //�V�[�N�̌��݈ʒu�i�����̍��W�j����t�@�C���ɓ������ꂽ�f�[�^�T�C�Y���擾�B
//    std::ifstream::pos_type fileSize = ifs.tellg();
//
//
//    //�V�[�N�̓ǂݎ����W�̕ύX
//    //�t�@�C���i���e�j�̐擪����ɓǂݍ��݂��J�n����悤�Ɏw�肷��B
//    ifs.seekg(0, std::ios::beg);
//
//    //�z��̐錾�B�t�@�C���̃f�[�^�T�C�Y+������NULL�������̗]�T��^����
//    std::vector<char> bytes(static_cast<size_t>(fileSize) + 1);
//
//    //�t�@�C���̏���z��ɃR�s�[
//    ifs.read(bytes.data(), static_cast<size_t>(fileSize));
//
//    //rapidjson�̃��[�g�̃������ɍ\�����R�s�[�A�W�J����B
//    srcDoc.Parse(bytes.data());
//
//    bool error = srcDoc.HasParseError();
//
//    if (!srcDoc.IsObject() || error)
//    {
//        {   //�G���[�R�[�h�̕\��
//            size_t offset = srcDoc.GetErrorOffset();
//            ParseErrorCode code = srcDoc.GetParseError();
//            const char* msg = GetParseError_En(code);
//            printf("%d:%d(%s)\n", offset, code, msg);
//        }
//
//        printf("�L����Json�h�L�������g�ł͂Ȃ�����\n");
//
//        return false;
//    }
//
//    return true;
//}
//
//bool ReadJson(rapidjson::Document& srcDoc)
//{
//    // string
//    {
//        const char* v = srcDoc["string"].GetString();
//        printf("string = %s\n", v);
//    }
//
//    // number
//    {
//        int v = srcDoc["number"].GetInt();
//        printf("number = %d\n", v);
//    }
//
//    // array
//    {
//        const Value& a = srcDoc["array"];
//        SizeType num = a.Size();
//
//        for (SizeType i = 0; i < num; i++) {
//            int v = a[i].GetInt();
//            printf("array[%d] = %d\n", i, v);
//        }
//    }
//
//    // object
//    {
//        const Value& o = srcDoc["object"];
//
//        // enumerate members in object
//        for (Value::ConstMemberIterator itr = o.MemberBegin();
//            itr != o.MemberEnd(); itr++)
//        {
//            const char* name = itr->name.GetString();
//            const Value& value = itr->value;
//            Type type = value.GetType();
//
//            printf("%s = ", name);
//            switch (type) {
//            case kStringType:
//                printf("%s", value.GetString());
//                break;
//
//            case kNumberType:
//                if (value.IsDouble())
//                    printf("%f", value.GetDouble());
//                else
//                    printf("%d", value.GetInt());
//                break;
//
//            default:
//                printf("(unknown type)");
//                break;
//            }
//            printf("\n");
//        }
//
//    }
//
//
//    return true;
//}
//
//bool WriteJson(rapidjson::Document& srcDoc)
//{
//
//
//    // string
//    {
//        srcDoc["string"].SetString("ohno");
//        const char* v = srcDoc["string"].GetString();
//        printf("string = %s\n", v);
//    }
//
//    // number
//    {
//        srcDoc["number"].SetInt(123581);
//        int v = srcDoc["number"].GetInt();
//        printf("number = %d\n", v);
//    }
//
//    // array
//    {
//        const Value& a = srcDoc["array"];
//        SizeType num = a.Size();
//        for (SizeType i = 0; i < num; i++) {
//            int v = a[i].GetInt();
//            printf("array[%d] = %d\n", i, v);
//        }
//
//
//
//        //    Value val(kArrayType);
//        //val.
//
//
//
//    }
//
//    // object
//    {
//        const Value& o = srcDoc["object"];
//
//        // enumerate members in object
//        for (Value::ConstMemberIterator itr = o.MemberBegin();
//            itr != o.MemberEnd(); itr++)
//        {
//            const char* name = itr->name.GetString();
//            const Value& value = itr->value;
//            Type type = value.GetType();
//
//            printf("%s = ", name);
//            switch (type) {
//            case kStringType:
//                printf("%s", value.GetString());
//                break;
//
//            case kNumberType:
//                if (value.IsDouble())
//                    printf("%f", value.GetDouble());
//                else
//                    printf("%d", value.GetInt());
//                break;
//
//            default:
//                printf("(unknown type)");
//                break;
//            }
//            printf("\n");
//        }
//
//    }
//
//    return true;
//}
//
//void GenerateFile(std::string& fileName, rapidjson::Document& srcDoc)
//{
//    //StringStream rs();
//
//    //srcDoc.ParseStream(rs);
//
//    StringBuffer ws;
//    Writer<StringBuffer> writer(ws);
//
//    srcDoc.Accept(writer);
//
//
//    ////�V�[�N�̌��݈ʒu�i�����̍��W�j����t�@�C���ɓ������ꂽ�f�[�^�T�C�Y���擾�B
//    //std::ifstream::pos_type fileSize = ifs.tellg();
//
//
//    ////�V�[�N�̓ǂݎ����W�̕ύX
//    ////�t�@�C���i���e�j�̐擪����ɓǂݍ��݂��J�n����悤�Ɏw�肷��B
//    //ifs.seekg(0, std::ios::beg);
//
//    ////�z��̐錾�B�t�@�C���̃f�[�^�T�C�Y+������NULL�������̗]�T��^����
//    //std::vector<char> bytes(static_cast<size_t>(fileSize) + 1);
//
//    ////�t�@�C���̏���z��ɃR�s�[
//    //ifs.read(bytes.data(), static_cast<size_t>(fileSize));
//
//    ////rapidjson�̃��[�g�̃������ɍ\�����R�s�[�A�W�J����B
//    //srcDoc.Parse(bytes.data());
//
//
//    const char* data_string = ws.GetString();
//
//
//    //ofstream�ł�std::ios::ate���g�p�\
//    //�ǂ���̏������݂̏ꍇ�ł��t�@�C���̖�����NULL��������͂��邱�Ƃ�
//    //�������������݂���Ă��邱�Ƃ�ۏ؂���
//
//    //�������݃��[�h
//    std::ofstream ofs(fileName.c_str()
//        , std::ios::out);
//
//    ////�㏑�����[�h
//    ////std::ofstream ofs(fileName.c_str()
//    ////                , std::ios::trunc);
//
//    ofs << data_string;
//    ofs.close();
//
//}
//
//
//int main()
//{
//    std::string file_name = "test.json";
//
//    rapidjson::Document Doc;//�ł��d�v�ȕ����ADOM�̃��[�g����
//
//    //�t�@�C�����J��
//    if (!FileOpen(file_name, Doc))
//    {
//        //json�����[�h�ł��Ȃ������B
//        printf("json�t�@�C�����J���Ȃ�����\n");
//    }
//
//    //�ǂݍ���
//    std::cout << "//***�������ݑO****************************//\n";
//    ReadJson(Doc);
//    StringView(Doc);
//
//    //��������
//    std::cout << "//***�������݌�****************************//\n";
//    WriteJson(Doc);
//    StringView(Doc);
//    std::cout << "//*****************************************//\n";
//
//
//    GenerateFile(file_name, Doc);
//
//    ReadJson(Doc);
//
//
//
//
//    // read
//    //StringStream rs(json);
//
//    //doc.ParseStream(rs);
//
//
//
//   // Doc.Accept();
//
//   //// const char* result = ws.GetString();
//   // printf("%s\n", result);
//
//
//
//
//
//
//    return 0;
//}
//



