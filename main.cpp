#include "kendyClient.h"

string apiKey="DAK8d4953ad50b645cabca174f794792d7a";
string apiSecretKey="DAS8e5d1a3cdd104c03960b4ff0ea34c4c1";

int main(){
	KendyClient kendyClient(apiKey,apiSecretKey);
	kendyClient.Connect();
	//kendyClient.Disconnect();
	
	kendyClient.CreateDomain("test.com","test domain for my account");
	string lists = kendyClient.GetListDomains();
	
	cout << lists << endl;
	
	return 0;
}