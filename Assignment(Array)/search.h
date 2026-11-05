#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <string>
#include "patient.h"

using namespace std;

void printSearchReport(Patient patient[], int patientCount, int searchAge);
void printSearchCareType(Patient patient[], int patientCount, string careType);
void printSearchID(Patient patient[], int patientCount, string id);


#endif