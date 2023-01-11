/**
* @file User.h
* @brief defines the user class with its attributes, methods, and constructor
* @author Ana Martínez Albendea
* @date 2022-11-23
*************************************************/

//we define the user class
#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User {
public:
  User();//default user class constructor
  User(float userNumber, float NIF, string name, bool isAdmin); //user class constructor with parameters
  //class functions

  /**
  * Returns the user number
  */
  int getUserNum();

  /**
  * Returns the NIF
  */
  int getNIF();

  /**
  * Returns if a user is admin o not by true or false
  */
  bool checkAdmin();

  /**
  * Returns the user name
  */
  string getUserName();

  /**
  * Returns the user name
  */
  void showUser();

  /**
  * Overloads the < operator to compare in the set
  */
  bool operator< (const User &) const;

private:
  //class attributes
  int userNumber;
  int NIF;
  char name[10];
  bool isAdmin;
};
#endif
