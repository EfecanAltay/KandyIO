#ifndef _KandyClient_H_INCLUDED_
#define _KandyClient_H_INCLUDED_

#include<list>
#include "httpClient.h"


class KandyClient{
	public:
		HttpClient httpClient;
		KandyClient(string,string);
		//account
		void Connect(void);
		void Disconnect(void);
		void CreateDomain(string,string);
		void DeleteDomain(string);
		string GetListDomains(void);
	private:
		string apiUrl;
		string apiKey,apiSecretKey ;
		string accessToken;
		list<string> domainLists ;
};

#endif