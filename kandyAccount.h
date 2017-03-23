#ifndef _KandyAccount_H_INCLUDED_
#define _KandyAccount_H_INCLUDED_

#include<list>
#include "httpClient.h"
#include "kandyDomain.h"

class KandyAccount{
	public:
		HttpClient httpClient;
		KandyAccount(string,string);
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
		KandyDomain domain;
};

#endif