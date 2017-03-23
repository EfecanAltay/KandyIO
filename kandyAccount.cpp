#include "kandyAccount.h"


KandyAccount::KandyAccount(string _apiKey,string _apiSecretKey){
	apiUrl = "https://api.kandy.io/v1.2/";
	apiKey = _apiKey;
	apiSecretKey = _apiSecretKey; 
	httpClient.HttpInit();
}
void KandyAccount::Connect(){
	printf("\nConnect the Kandy with token \n");
	jsonData jdata = httpClient.GetJsonToURL("https://api.kandy.io/v1.2/accounts/accesstokens?key="+apiKey+"&account_api_secret=" + apiSecretKey);
	cout << httpClient.JsonToString(jdata) << endl;
	if(jdata != 0 )
	if(jdata["status"].asUInt() == 0)
	{
		accessToken = jdata["result"]["account_access_token"].asString();
		
		cout << "connection success:You've a token :) : accessToken = "+accessToken << endl;
	}
	else{
		cerr << "connection err" << endl;
	}
}
void KandyAccount::Disconnect(){
	if(accessToken != ""){
		printf("\nDisconnect the Kandy with token \n");
		string url = apiUrl+"accounts/accesstokens?key="+apiKey+"&account_api_secret=" + apiSecretKey + "&account_access_token="+accessToken;
		jsonData jdata = httpClient.GetDeleteJsonToURL(url);
		
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
void KandyAccount::CreateDomain(string DomainName,string ProjectName){
	if(accessToken != ""){
		httpClient.AddToHeader("Content-Type: application/json;");
		printf("\nCreating Domain... \n");
		cout <<">accToken : "<< accessToken << endl;
		string url = apiUrl+"accounts/domains?key="+accessToken;
		cout <<">url : " << url << endl;
		string data = "{\"domain_name\":\"" + DomainName + "\",\"project_name\":\"" +ProjectName+ "\"}";
		string resData = httpClient.PostToURL(url,data);
		cout << resData << endl;
		
		jsonData jresData = httpClient.StringToJson(resData);
		cout << "resMessage : "<<jresData["message"].asString() << endl;
		int status = jresData["status"].asInt();
		
		if(status == 2001){
			cout<<"!! please sending different DomainName" << endl; 
		}
		else if(status == 0){
			domain = KandyDomain(DomainName,ProjectName);
			domain.setDomainApi(jresData["result"]["domain_api_key"].asString(),jresData["result"]["domain_api_secret"].asString());
		
		}
	}
}
void KandyAccount:: DeleteDomain(string DomainKey){
	if(accessToken != ""){
		printf("\nDeleting Domain... \n");
		string url = apiUrl+"accounts/domains?key="+accessToken+"&domain_api_key="+DomainKey;
		jsonData resData = httpClient.GetJsonToURL(url);
	}
}
string KandyAccount::GetListDomains(){
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



