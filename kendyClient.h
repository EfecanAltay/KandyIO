#ifndef _KendyClient_H_INCLUDED_
#define _KendyClient_H_INCLUDED_

#include<list>
#include "httpClient.h"


class KendyClient{
	public:
		HttpClient httpClient;
		KendyClient(string,string);
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