//we include the .h of the classes that we are going to use
#include "../include/User.h"
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "../include/DataBase.h"
#include "../include/TypeError.h"
#include "../include/UserNumException.h"
#include "../include/NIFException.h"
#include "../include/StringException.h"
#include <unistd.h>
#include <iostream>
#include <set>

using namespace std;

DataBase::DataBase() { //we define the constructor with the initial users that we are gonna have
  /*this->dataBaseUser.insert(User(1,13172409,"Ana",true));
  this->dataBaseUser.insert(User(2,13172408,"Paula",false));
  this->dataBaseUser.insert(User(3,12345678,"Carlos",false));*/

  // Reads the users found in the users.dat file and dumps them into the database set
  ifstream inUsersFile ("users.dat", ios::in | ios::binary);

  if (!inUsersFile) { // fstream could not open file
    cerr << "File could not be opened." << endl;
    exit (1);
  }

  User user;
  inUsersFile.read (reinterpret_cast <char *>(&user), sizeof (User));
  while (inUsersFile && !inUsersFile.eof()) {
    this->dataBaseUser.insert(user);
    inUsersFile.read (reinterpret_cast <char *>(&user), sizeof (User));
  }
}

bool DataBase::checkUser(int userNumber, int NIF) {
  bool authentication = false;
  //checks if the user exixts
  do{
    for(it=dataBaseUser.begin(); it!=dataBaseUser.end(); it++){
      User user = *it;
      if(userNumber==user.getUserNum() && NIF==user.getNIF()){
          userNow = user;
          return true;
          authentication = true;
      }
    }
  }while(authentication == false);

  return false;
}

void DataBase::addUser(string userNumberStr, string NIFStr, string name, bool isAdmin){    
  //checks that both the user number and password are the correct size
  try{
    for(int n = 0; n < userNumberStr.length(); n++){
      if(int(userNumberStr[n]) < 47 || int(userNumberStr[n] > 57)){
        throw StringException();
      }
      userNumber = stoi(userNumberStr);
    }

    if (userNumber < 1 || userNumber > 99999){
      throw UserNumException();
    }

    for(int n = 0; n < NIFStr.length(); n++){
      if(int(NIFStr[n]) < 47 || int(NIFStr[n] > 57)){
        throw StringException();
      }
      NIF = stoi(NIFStr);
    }

    if (NIF < 9999999 || NIF > 99999999){
      throw NIFException();
    }

    if(isAdmin != 1 && isAdmin != 0){
      throw TypeError();
    }

    //adds a new user that is entered by an admin in the terminal
    this->dataBaseUser.insert(User(userNumber, NIF, name, isAdmin));
  }

  catch(UserNumException &except){
    cout << "Exception: " << except.what() << endl;
  }

  catch(NIFException &except){
    cout << "Exception: " << except.what() << endl;
  }

  catch(TypeError &except){
    cout << "Exception: " << except.what() << endl;
  }  

  catch(StringException &except){
    cout << "Exception: " << except.what() << endl;
  }
}

void DataBase::deleteUser(int userNumber){
  //deletes the user that is entered by an admin in the terminal
  for(it=dataBaseUser.begin(); it!=dataBaseUser.end(); it++){
    User user = *it;
    if(userNumber==user.getUserNum()){
      userDeleted = user;
    }   
  }
  this->dataBaseUser.erase(userDeleted);
  cout << "El usuario ha sido eliminado" << endl;  
}

void DataBase::showUsers(){
  //shows the users that are saved in the database
  for(it=dataBaseUser.begin(); it!=dataBaseUser.end(); it++){
    User user = *it;
    user.showUser();
    if(user.checkAdmin()){
      cout << "\t\tAdmin" << endl;
    }else{
      cout << "\t\tEmployee" << endl;    
    }
  }
}

void DataBase::showAdminChoices(){
  //displays the manage users options menu, that only an Admin can use
  while (true) {
    cout << "\n                             MANAGE USERS" << endl
      << "---------------------------------------------------------------------" << endl;
    cout << "                    1. ADD USER" << endl 
        << "                    2. DELETE USER" << endl 
        << "                    3. SHOW USERS LIST" << endl 
        << "                    4. BACK TO MENU" << endl;
    cout << "Enter your choice number: ";
    cin >> choice;
    
    switch (choice)
    {
    case 1:
      cout << "Enter a new user" << endl;
      cout << "User number: ";
      cin >> userNumberStr;
      cout << "User password: ";
      cin >> NIFStr;
      cout << "User name: ";
      cin >> name;
      cout << "User type (1=Admin, 0=User): ";
      cin >> type;

      if (type == 1){
        isAdmin = true;
      }else{  isAdmin = false; }

      addUser(userNumberStr, NIFStr, name, isAdmin);
      break;

    case 2:
      cout << "Enter the user number that you want to delete: ";
      cin >> userNumber;
      deleteUser(userNumber);
      break;

    case 3:
      cout << "USERS LIST: " << endl;
      cout << "Nº\tNAME\t\tTYPE" << endl;
      showUsers();
      break;

    case 4:
      return;
      break;
    }
  }
}

void DataBase::saveFile(){
  fstream outUsersFile ("users.dat", ios::in | ios::out | ios::trunc | ios::binary); // ios::in will require an existing file
  // Uses: "users.dat", generated in previous example
  if (!outUsersFile) { // fstream could not open file
    cerr << "File could not be opened." << endl;
    exit (1);
  }

  int position = 0;
  
  for(it=dataBaseUser.begin(); it!=dataBaseUser.end(); it++){
    User user = *it;
    outUsersFile.seekp (position * sizeof (User));
    outUsersFile.write (reinterpret_cast <const char *> (&user), sizeof (User));
    position ++;
  }
}

/*int main(){
  DataBase D;
  D.saveFile();
}*/
