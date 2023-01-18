//we include the .h of the classes that we are going to use
#include "../include/Login.h"
#include <iostream>
#include "../include/StringException.h"
#include "../include/DataBase.h"
using namespace std;

Login::Login() {} //we define the constructor

bool Login::checkLogin(DataBase* d){
  bool excep = true;
  while (excep == true){
    try{
      cout<<"\n                                User: ";
      cin>>userNumberStr;
      for(int n = 0; n < userNumberStr.length(); n++){
        if(int(userNumberStr[n]) < 47 || int(userNumberStr[n] > 57)){
          throw StringException();
          excep = false;
        }
        userNumber = stoi(userNumberStr);
      }

      //returns the password entered
      cout<<"                                Password: ";
      cin>>NIFStr;
      for(int n = 0; n < NIFStr.length(); n++){
        if(int(NIFStr[n]) < 47 || int(NIFStr[n] > 57)){
          throw StringException();
          excep = false;
        }
        NIF = stoi(NIFStr);
      }
    }
    
    catch(StringException &except){
      cout << "Exception: " << except.what() << endl;
      continue;
    }

    return d->checkUser(userNumber, NIF);
  }
  return false;
}


/*int main(){
  Login LG;
  LG.checkLogin();
}*/

