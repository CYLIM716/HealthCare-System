#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <iostream>
#include <string>
#include "patient.h"

using namespace std;

void printAgeGroupReport(Patient patient[], int patientCount, string ageGroup);
void sortByMedicalCost(Patient patient[], int patientCount);
void printSortedAgeGroupReport(Patient patient[], int patientCount, string ageGroup);

#endif