#include "kandyAccount.h"
#include "kandyDomain.h"

string apiKey="AAK15fd135fbc9f448889f5dea46fd1687b";
string apiSecretKey="AASed864b1c7a8a42628d03c0c616e4e753";


string domainApiKey = "DAKc8801264d0b54464a71df135ddeaf170";
string domainSecretApiKey = "DASff493e5b119543f2900d7494bb0db5a5";

int main(){
	//---------------------------#KandyAccount  Test#-------------------------------------
	KandyAccount kandyAccount(apiKey,apiSecretKey);
	kandyAccount.Connect();
	kandyAccount.Disconnect();
	
	//kandyAccount.CreateDomain("efe.com","test domain for my account");
	
	//string list = kandyClient.GetListDomains();
    //cout << list;
	
	//---------------------------#KandyDomain Test#----------------------------------------
	//KandyDomain kandyDomain("efe.com","test domain");
	//kandyDomain.setDomainApi(domainApiKey,domainSecretApiKey);
	//kandyDomain.Connect();
	//kandyDomain.Disconnect();
	
	
	
	return 0;
	
}