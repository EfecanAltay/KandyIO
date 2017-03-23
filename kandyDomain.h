#ifndef _KandyDomain_H_INCLUDED_
#define _KandyDomain_H_INCLUDED_

#include<string>
#include "httpClient.h"
using namespace std;

class KandyDomain{
	public:
		string domain_name,project_name;
		KandyDomain(void);
		KandyDomain(string,string);
		void setDomainApi(string,string);
		void Connect();
		void Disconnect();
		
	private:
		HttpClient httpClient;
		string domain_api_key,domain_api_secret;
		string apiUrl;
		string domain_access_token;
};

#endif