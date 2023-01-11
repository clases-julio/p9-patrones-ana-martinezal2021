//we include the .h of the classes that we are going to use
#include "TemperatureSensor.h"
#include "HumiditySensor.h"
#include "LigthLevelSensor.h"
#include "AirConditionSensor.h"
#include "RGBCamera.h"
#include "ThermalCamera.h"
#include "Microphone.h"
#include "DataBase.h"
#include "Login.h"
#include "Dashboard.h"
#include "Sensor.h"
#include "Camera.h"
#include "UserNumException.h"
#include "NIFException.h"

#include <iostream>
using namespace std;

Dashboard::Dashboard(){ //we define the constructor
  this -> option = option;
}

void Dashboard::showSensorChoices(Sensor sensor){
  //displays the temperature sensor options menu
  while (true) {
    cout << "                               __  __  _____  _   _  _   _ " << endl 
          << "                              |  \\/  || ____|| \\ | || | | |" << endl 
          << "                              | |\\/| ||  _|  |  \\| || | | |" << endl 
          << "                              | |  | || |___ | |\\  || |_| |" << endl 
          << "                              |_|  |_||_____||_| \\_| \\___/ " << endl 
          << "                                                                             " << endl          
          << "-----------------------------------------------------------------------------------------------" << endl
          << "ººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººº\n" << endl;
    cout << "                                   1. TURN ON" << endl 
        << "                                   2. TURN OFF" << endl 
        << "                                   3. SHOW DATA INFO" << endl 
        << "                                   4. BACK TO MENU" << endl;
    cout << "\nEnter your choice number: ";
    cin >> choice;
    
    //Depending on the option that is entered, it calls its respective function
    switch (choice)
    {
    case 1:
      sensor.turnOn();
      system("sleep 3");
      system("clear");
      break;

    case 2:
      sensor.turnOff();
      system("sleep 3");
      system("clear");
      break;

    case 3:
      sensor.Sensor::getInfo();
      system("sleep 3");
      system("clear");
      break;

    case 4:
      //go back to the main menu
      return;
      break;
    }
  }
}

void Dashboard::showCameraChoices(Camera camera){
  //displays the temperature sensor options menu
  while (true) {
    cout << "                               __  __  _____  _   _  _   _ " << endl 
          << "                              |  \\/  || ____|| \\ | || | | |" << endl 
          << "                              | |\\/| ||  _|  |  \\| || | | |" << endl 
          << "                              | |  | || |___ | |\\  || |_| |" << endl 
          << "                              |_|  |_||_____||_| \\_| \\___/ " << endl 
          << "                                                                             " << endl          
          << "-----------------------------------------------------------------------------------------------" << endl
          << "ººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººº\n" << endl;
    cout << "                                   1. TURN ON" << endl 
        << "                                   2. TURN OFF" << endl 
        << "                                   3. SHOW DATA INFO" << endl 
        << "                                   4. BACK TO MENU" << endl;
    cout << "\nEnter your choice number: ";
    cin >> choice;
    
    //Depending on the option that is entered, it calls its respective function
    switch (choice)
    {
    case 1:
      camera.turnOn();
      system("sleep 3");
      system("clear");
      break;

    case 2:
      camera.turnOff();
      system("sleep 3");
      system("clear");
      break;

    case 3:
      camera.getInfo();
      system("sleep 3");
      system("clear");
      break;

    case 4:
      //go back to the main menu
      return;
      break;
    }
  }
}

bool Dashboard::getOption(){
  //depending on the option entered, performs an action
  cout << "Enter the number of the action you want to do: ";
  cin >> option;

  switch (option)
  {
    case 1:  
      system("clear"); 
      showSensorChoices(T);
      break;

    case 2:
      system("clear");
      showSensorChoices(H);
      break;
    
    case 3:
      system("clear");
      showSensorChoices(Li);
      break;

    case 4:
      system("clear");
      showSensorChoices(A);
      break;

    case 5:
      system("clear");
      showCameraChoices(RC);
      break;

    case 6:
      system("clear");
      showCameraChoices(TC);
      break;

    case 7:
      system("clear");
      M.showChoice();
      break;

    case 8:
      return true;
      break;

    case 9:
      D.saveFile();
      exit(EXIT_SUCCESS);
      break;

    case 10:
      system("clear");
      D.showAdminChoices();
      break;
  }
  return false;
}

void Dashboard::showMenu(){
    try{    
      //displays the login screen and, depending on whether the user exists, displays the main menu
      if (L.checkLogin(&D)){
        while (true){
          system("clear");
          cout << "               __  __     _     ___  _   _       __  __  _____  _   _  _   _ " << endl 
          << "              |  \\/  |   / \\   |_ _|| \\ | |     |  \\/  || ____|| \\ | || | | |" << endl 
          << "              | |\\/| |  / _ \\   | | |  \\| |     | |\\/| ||  _|  |  \\| || | | |" << endl 
          << "              | |  | | / ___ \\  | | | |\\  |     | |  | || |___ | |\\  || |_| |" << endl 
          << "              |_|  |_|/_/   \\_\\|___||_| \\_|     |_|  |_||_____||_| \\_| \\___/ " << endl 
          << "                                                                             " << endl          
          << "-----------------------------------------------------------------------------------------------" << endl
          << "ººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººº\n" << endl;


          cout << "                                   1. TEMPERATURE SENSOR" << endl << "                                   2. HUMIDITY SENSOR" << endl 
          << "                                   3. LIGTH LEVEL SENSOR" << endl << "                                   4. AIR CONDITION SENSOR" << endl 
          << "                                   5. RGB CAMERA" << endl << "                                   6. THERMAL CAMERA" << endl 
          << "                                   7. MICROPHONE" << endl << "                                   8. SIGN OFF" << endl 
          << "                                   9. EXIT" << endl;

          //checks that the user entered is of type Admin
          if(D.userNow.checkAdmin()){
            cout << "                                   10. MANAGE USERS\n" << endl;
          }
            
          //allows the showMenu() function to be called again when you want to log out and re-enter a user 
          //in case of not putting it, it does not verify that the user exists
          if (getOption()){
            return;
          }
        }
      }
    }

    catch(UserNumException &except){
      cout << "Exception: " << except.what() << endl;
    }

    catch(NIFException &except){
      cout << "Exception: " << except.what() << endl;
    }    
}

Dashboard* Dashboard::singleDashboard = nullptr;

Dashboard* Dashboard::getDashboard(){
  if(singleDashboard == nullptr){
    singleDashboard = new Dashboard();
  }else{
    cout << "Error: trying to get another instance of a Ball singleton class!\n";
  }
  
  return singleDashboard;
}
/*int main(){
  Dashboard DS;
  DS.showMenu();
}*/
