#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
using namespace std;

struct Patient {
    string patientID;
    int age;
    string careType;
    double lengthOfStay;
    double baseCostPerHour;
    int daysVisitsPerYear;
    double medicalCost;
};

double calcmedicalCost(double lengthOfStay, double baseCostPerHour, int daysVisitsPerYear);

void printDetails();

string getAgeGroup(int age);

void readDatabase(Patient patients[], int &patientCount);
void displayPatients(Patient patients[], int patientCount);

#endif

