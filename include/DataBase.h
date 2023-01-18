/**
* @file DataBase.h
* @brief defines the database class with its attributes, methods, and constructor
* @author Ana Martínez Albendea
* @date 2022-11-23
*************************************************/

//we define the database class
#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include "User.h"
#include <set>

using namespace std;

class DataBase {
public:
  DataBase();//database class constructor
  //class functions

  /**
  * Checks if the user exixts
  */
  bool checkUser(int, int);

  /**
  * Checks that both the user number and password are the correct size
  * Adds a new user that is entered by an admin in the terminal
  */
  void addUser(string, string, string, bool);

  /**
  * Deletes the user that is entered by an admin in the terminal
  */
  void deleteUser(int);

  /**
  * Shows the users that are saved in the database
  */
  void showUsers();

  /**
  * Displays the manage users options menu, that only an Admin can use
  */
  void showAdminChoices();

  /**
  * Saves the users found in the set to the file users.dat
  */
  void saveFile();
  

  User userNow;
  User userDeleted;
  
private:
  //class attributes
  set<User> dataBaseUser; //set where users are stored
  set<User>::iterator it;
  int choice;
  std::string userNumberStr;
  std::string NIFStr;
  int userNumber;
  int NIF;
  string name;
  int type;
  bool isAdmin;

};
#endif
