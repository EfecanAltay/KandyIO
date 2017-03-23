#ifndef _HttpClient_H_INCLUDED_
#define _HttpClient_H_INCLUDED_

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>

using namespace std;
using namespace Json;

typedef Value jsonData ;	//Value değişkeni aynı zamanda jsonDatadır.Anlaşılması kolay olması için kulandım.

class HttpClient{
	public:
		void HttpInit(void);
		void AddToHeader(string);
		string GetToURL(string);
		jsonData GetJsonToURL(string);
		jsonData PostJsonToURL(string,jsonData);
		string PostToURL(string,string);
		jsonData StringToJson(string);
		string JsonToString(jsonData);
		string GetDeleteToURL(string);
		jsonData GetDeleteJsonToURL(string);
		
	private:
		CURL *curl;		//Httpnin temelidir.
		CURLcode res;	//gelen verilerin durum bilgisini bu değişkene alıp kontrol ediyoruz.
		struct curl_slist *chunk = NULL; 	//Gönderilecek verinin header Listesini oluşturmak için.
		size_t write_to_string(void *,size_t,size_t,void *); //gelen verinin boyutunu hesaplamak için geçerli fonk.
};

#endif