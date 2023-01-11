/**
* @file Login.h
* @brief defines the login class with its attributes, methods, and constructor
* @author Ana Martínez Albendea
* @date 2022-11-23
*************************************************/

//we define the login class
#ifndef LOGIN_H
#define LOGIN_H

#include "Login.h"
#include "DataBase.h"
#include <iostream>
//using namespace std;

class Login {
public:
  Login();//login class constructor
  //class functions
  //DataBase *d;

  /**
  * Returns if the login is correct
  */
  bool checkLogin(DataBase*);

  /**
  * Show the extra admin option in case the user entered is an admin
  */
  void adminMenu(DataBase*);

private:
  //class attributes
  std::string userNumberStr;
  std::string NIFStr;
  int userNumber;
  int NIF;
  User userNow;
  User* userNowPtr;
};
#endif
