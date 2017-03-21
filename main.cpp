#include "kandyClient.h"

string apiKey="DAK8d4953ad50b645cabca174f794792d7a";
string apiSecretKey="DAS8e5d1a3cdd104c03960b4ff0ea34c4c1";

int main(){
	KandyClient kandyClient(apiKey,apiSecretKey);
	kandyClient.Connect();
	//kendyClient.Disconnect();
	
	kandyClient.CreateDomain("test.com","test domain for my account");
	
	return 0;
}