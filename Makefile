# *****************************************************
# Julio Vega
# Example of Makefile
# *****************************************************
# NOTES: it uses '>' as prefix of my recipes (.RECIPEPREFIX is set in line 11)
# since all actions of every Makefile's rule are identified by tabs and I do not
# use tabs in my file editor. Otherwise, I will get the 'missing separator' error.
#
# To check whether a tab character is used, run: cat -e -t -v Makefile
# It shows the presence of tabs (-t) with ^I and line endings (-e) with $
# *****************************************************

CC = g++ 
CFLAGS = -Wall -g
.RECIPEPREFIX = >
prefix_h = include
VPATH = include src build

main: main.o Sensor.o TemperatureSensor.o HumiditySensor.o LigthLevelSensor.o AirConditionSensor.o Camera.o RGBCamera.o ThermalCamera.o User.o Microphone.o DataBase.o Login.o Dashboard.o TypeError.o UserNumException.o NIFException.o StringException.o
>$(CC) $(CFLAGS) -o build/main main.o Sensor.o TemperatureSensor.o HumiditySensor.o LigthLevelSensor.o AirConditionSensor.o Camera.o RGBCamera.o ThermalCamera.o User.o Microphone.o DataBase.o Login.o Dashboard.o TypeError.o UserNumException.o NIFException.o StringException.o

main.o: main.cpp Sensor.h TemperatureSensor.h HumiditySensor.h LigthLevelSensor.h AirConditionSensor.h Camera.h RGBCamera.h ThermalCamera.h User.h Microphone.h DataBase.h Login.h Dashboard.h TypeError.h UserNumException.h NIFException.h StringException.h
>$(CC) $(CFLAGS) -c src/main.cpp
 
Sensor.o: Sensor.h 
TemperatureSensor.o: TemperatureSensor.h 
HumiditySensor.o: HumiditySensor.h 
LigthLevelSensor.o: LigthLevelSensor.h 
AirConditionSensor.o: AirConditionSensor.h 
Camera.o: Camera.h 
RGBCamera.o: RGBCamera.h
ThermalCamera.o: ThermalCamera.h 
User.o: User.h 
Microphone.o: Microphone.h 
DataBase.o: DataBase.h 
Login.o: Login.h 
Dashboard.o: Dashboard.h 
TypeError.o: TypeError.h 
UserNumException.o: UserNumException.h 
NIFException.o: NIFException.h 
StringException.o: StringException.h

clean:
>rm *.o main
