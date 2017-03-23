#include "kandyDomain.h"

KandyDomain::KandyDomain(){
	apiUrl = "https://api.kandy.io/v1.2/";
	domain_name = "" ;
	project_name = "";
	httpClient.HttpInit();
}
KandyDomain::KandyDomain(string domainName,string projectName){
	domain_name = domainName ;
	project_name = projectName;
	apiUrl = "https://api.kandy.io/v1.2/";
	httpClient.HttpInit();
}
void KandyDomain::setDomainApi(string domainApiKey,string domainApiSecret){
	domain_api_key = domainApiKey;
	domain_api_secret = domainApiSecret;	
}
void KandyDomain::Connect(){
	cout << "Domain is Connecting..." << endl;
	if(domain_api_key != ""){
		
		jsonData jdata = httpClient.GetJsonToURL(apiUrl + "domains/accesstokens?key=" + domain_api_key + "&domain_api_secret=" + domain_api_secret);
		cout << httpClient.JsonToString(jdata["result"]) << endl;
		
		if(jdata["status"].asUInt() == 0){
			domain_access_token = jdata["result"]["domain_access_token"].asString();
			cout << domain_access_token << endl;
			cout << "Domain is Connect"<< endl;
		}
		else {
			cout << "error"<<endl;
		}
	}
	else{
		cout << "DomainApi is null.please first try create domain with use KendyAccount" << endl;
	}
}
void KandyDomain::Disconnect(){
	cout << "Domain is Disconnecting..."<< endl;
	if(domain_api_key != ""){
		jsonData jdata= httpClient.GetJsonToURL(apiUrl + "domains/accesstokens?key=" + domain_api_key + "&domain_api_secret=" + domain_api_secret + "&domain_access_token=" + domain_access_token);
		cout << "help";
		cout << jdata["status"].asUInt() << endl;
		
		if(jdata["status"] == 0){
			cout << "domain is Disconnect"<< endl;
		}
	}
	else{
		cout << "DomainApi is null.please first try create domain with use KendyAccount" << endl;
	}
}