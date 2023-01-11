//we include the .h of the classes that we are going to use
#include "User.h"
#include <iostream>
#include <cstring>
#include "UserNumException.h"
#include "NIFException.h"
using namespace std;

User::User(){} //we define the default constructor

User::User(float userNumber, float NIF, string name, bool isAdmin) { //we define the constructor with parameters
  this -> userNumber = userNumber;
  this -> NIF = NIF;
  strcpy(this->name,name.c_str());
  this -> isAdmin = isAdmin;
};

int User::getUserNum(){
  if (userNumber < 1 || userNumber > 99999){
    throw UserNumException();
  }  
  return userNumber;
}
int User::getNIF(){
  if (NIF < 9999999 || NIF > 99999999){
    throw NIFException();
  }
  return NIF;
}

bool User::checkAdmin(){
  return isAdmin;
}

string User::getUserName(){
  return name;
}

void User::showUser(){
  cout << userNumber << "\t" << name;
}

bool User::operator< (const User &user) const{
  return userNumber < user.userNumber;
}
