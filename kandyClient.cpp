#include "kandyClient.h"


KandyClient::KandyClient(string _apiKey,string _apiSecretKey){
	apiUrl = "https://api.kandy.io/v1.2/";
	apiKey = _apiKey;
	apiSecretKey = _apiSecretKey; 
	httpClient.HttpInit();
}
void KandyClient::Connect(){
	printf("\nConnect the Kandy with token \n");
	jsonData jdata = httpClient.GetJsonToURL("https://api.kandy.io/v1.2/accounts/accesstokens?key="+apiKey+"&account_api_secret=" + apiSecretKey);
	if(jdata["status"].asUInt() == 0)
	{
		accessToken = jdata["result"]["account_access_token"].asString();
		
		cout << "connection success:You've a token :) : accessToken ="+accessToken << endl;
	}
	else{
		cerr << "connection err" << endl;
	}
}
void KandyClient::Disconnect(){
	if(accessToken != ""){
		printf("\nDisconnect the Kandy with token \n");
		string url = apiUrl+"accounts/accesstokens?key="+apiKey+"&account_api_secret=" + apiSecretKey + "&account_access_token="+accessToken;
		jsonData jdata = httpClient.GetJsonToURL(url);
		if(jdata["status"].asUInt() == 0)
		{
			cout << "\ndisconnecting success:Token deleted" << endl;
			accessToken = "";
		}
		else{
			cerr << "\nconnection err" << endl;
		}
	}
}
void KandyClient::CreateDomain(string DomainName,string ProjectName){
	if(accessToken != ""){
		//httpClient.AddToHeader("Accept: application/json");
		httpClient.AddToHeader("Content-Type: application/json");
		printf("\nCreating Domain... \n");
		string url = apiUrl+"accounts/domains?key="+accessToken;
		string data = "{'domain_name':'" + DomainName + "','project_name':'" +ProjectName+ "'}";
		cout << data << endl;
		string resData = httpClient.PostToURL(url,data);
		cout <<"help"<< endl;
		cout << resData << endl;
		//domainLists.push_back(resData);
	}
}
void KandyClient:: DeleteDomain(string DomainKey){
	if(accessToken != ""){
		printf("\nDeleting Domain... \n");
		domainLists.remove(DomainKey);
		string url = apiUrl+"accounts/domains?key="+accessToken +"&domain_api_key="+DomainKey;
		jsonData resData = httpClient.GetJsonToURL(url);
	}
}
string KandyClient::GetListDomains(){
	if(accessToken != ""){
		printf("\nlists Domain : \n");
		string url = apiUrl+"accounts/domains?key="+accessToken;
		jsonData jdata = httpClient.GetJsonToURL(url);
		if(jdata["status"] == 0){
			return httpClient.JsonToString(jdata);
		}else{
			cerr<< "message: " << jdata["message"] << endl; 
			return "" ;
		}
	}
}
