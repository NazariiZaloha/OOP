#ifndef TRAINSCHEDULE_H
#define TRAINSCHEDULE_H

#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <limits>

using namespace std;

// Structure to store train data
struct Train {
    string departurePoint;
    string destinationPoint;
    string type;
    int departureTime; // Time in minutes from the start of the day (0-1439)
};

// Core program functions
void showMenu();
void addTrain(multimap<string, Train>& schedule);
void viewAll(const multimap<string, Train>& schedule);
void findByTime(const multimap<string, Train>& schedule);
void findByDeparture(const multimap<string, Train>& schedule);
void findByDestination(const multimap<string, Train>& schedule);

// Utility functions
int getValidInt();
int inputTime();
string minutesToTimeStr(int totalMinutes);
void printHeader();
void printTrain(const Train& t);

#endif