#include "httpClient.h"

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

string HttpClient::JsonToString(jsonData data){
		FastWriter fw ;
		jsonData j_reqdata;
		return fw.write(data);
}
jsonData HttpClient::StringToJson(string data){
		Reader reader;
		jsonData j_reqdata;
		reader.parse(data.c_str(),j_reqdata);
		return j_reqdata;
}
void HttpClient::HttpInit(){
	curl_global_init(CURL_GLOBAL_DEFAULT);				
	curl = curl_easy_init();
}
void HttpClient::AddToHeader(string header){
	if(curl) {
		chunk = curl_slist_append(chunk, header.c_str());
	}
}
string HttpClient::GetToURL(string url){
	if(curl) {
		
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER,chunk);
		curl_easy_setopt(curl, CURLOPT_URL,url.c_str());
		
		string resData;
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &resData);
		
		res = curl_easy_perform(curl);
		
		if(res != CURLE_OK){
			fprintf(stderr, "curl_easy_perform() connection error\n");
			fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
			curl_easy_cleanup(curl);
			curl_global_cleanup();
			return 0;
		}
		
		curl_easy_cleanup(curl);
		curl_global_cleanup();
		return resData;
	}
	return 0;
}
string HttpClient::GetDeleteToURL(string url){
	if(curl) {
		
		curl_easy_setopt(curl,CURLOPT_CUSTOMREQUEST,"DELETE");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER,chunk);
		curl_easy_setopt(curl, CURLOPT_URL,url.c_str());
		
		string resData;
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &resData);
		
		res = curl_easy_perform(curl);
		
		if(res != CURLE_OK){
			fprintf(stderr, "curl_easy_perform() connection error\n");
			fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
			curl_easy_cleanup(curl);
			curl_global_cleanup();
			return 0;
		}
		
		curl_easy_cleanup(curl);
		curl_global_cleanup();
		return resData;
	}
	return 0;
}
jsonData HttpClient::GetDeleteJsonToURL(string url){
	if(curl) {
		
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER,chunk);
		curl_easy_setopt(curl, CURLOPT_URL,url.c_str());
		
		string resData;
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &resData);
		
		res = curl_easy_perform(curl);
		
		if(res != CURLE_OK){
			fprintf(stderr, "curl_easy_perform() connection error\n");
			fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
			curl_easy_cleanup(curl);
			curl_global_cleanup();
			return 0;
		}
		
		curl_easy_cleanup(curl);
		curl_global_cleanup();
		return StringToJson(resData);
	}
	return 0;
}
jsonData HttpClient::GetJsonToURL(string url){
	if(curl) {
		
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER,chunk);
		curl_easy_setopt(curl, CURLOPT_URL,url.c_str());
		
		string resData ="";
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &resData);
		cout << resData << endl;
		res = curl_easy_perform(curl);
		
		if(res != CURLE_OK){
			fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
			curl_easy_cleanup(curl);
			curl_global_cleanup();
			return 0;
		}else{
			curl_easy_cleanup(curl);
			curl_global_cleanup();	
			return StringToJson(resData);
		}
		
		
	}
}
string HttpClient::PostToURL(string url,string data){
	if(curl) {
		
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER,chunk);
		//curl_easy_setopt(curl, CURLOPT_HEADER, 0L);
		curl_easy_setopt(curl, CURLOPT_URL,url.c_str());
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE,(long)data.length());
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
		//curl_easy_setopt(curl, CURLOPT_POST, 1);
		//curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
		
		string resData ;
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &resData);
		
		//string resData = JsonToString(resData);
		cout << resData << endl; 
		
		res = curl_easy_perform(curl);
		jsonData jdata = StringToJson(resData);
		
		
		
		//string resData = JsonToString(jresData);
		
		if(res != CURLE_OK){
			fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
			curl_easy_cleanup(curl);
			curl_global_cleanup();
			return 0;
		}
		
		curl_easy_cleanup(curl);
		curl_global_cleanup();
		return resData;
		
	}
}

jsonData HttpClient::PostJsonToURL(string url,jsonData data){
	if(curl) {
		string s_data = JsonToString(data);
		
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER,chunk);
		curl_easy_setopt(curl, CURLOPT_URL,url.c_str());
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE,(long)s_data.length());
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, s_data.c_str());
		
		string resData ="";
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &resData);
		
		res = curl_easy_perform(curl);
		
		return StringToJson(resData);
		if(res != CURLE_OK){
			fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
			curl_easy_cleanup(curl);
			curl_global_cleanup();
			return 0;
		}
		curl_easy_cleanup(curl);
		curl_global_cleanup();
		
		
	}
}