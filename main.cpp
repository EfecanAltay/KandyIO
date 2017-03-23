#include "kandyClient.h"

string apiKey="AAK15fd135fbc9f448889f5dea46fd1687b";
string apiSecretKey="AASed864b1c7a8a42628d03c0c616e4e753";

int main(){
	KandyClient kandyClient(apiKey,apiSecretKey);
	kandyClient.Connect();
	//kendyClient.Disconnect();
	
	kandyClient.CreateDomain("efecanaltay.com","test domain for my account");
	return 0;
}