#include <iostream>
#include <iomanip>
#include "patient.h"
using namespace std;

string getAgeGroup(int age){
    if (age >= 0 && age <= 17)
        return "0-17 (Pediatrics & Adolescents)" ;
    else if (age >= 18 && age <= 25)
        return "18-25 (Young Adults / University Students )";
    else if (age >= 26 && age <= 45)
        return "26-45 (Working Adults (Early Career)  )";
    else if (age >= 46 && age <= 60)
        return "46-60 (Working Adults (Late Career))";
    else if (age >= 61 && age <= 100)
        return "61-100 (Senior Citizens / Geriatric Care)";
    else
        return "Invalid";
}

double calcmedicalCost(double lengthOfStay, double baseCostPerHour, int daysVisitsPerYear){
  
    return lengthOfStay * baseCostPerHour * daysVisitsPerYear;
}

/* void printDetails(){

    Patient patient;

    patient.age = 42;
    patient.lengthOfStay = 12;
    patient.baseCostPerHour = 150;
    patient.daysVisitsPerYear = 2;

    cout << "Age: " << patient.age << endl;
    cout << "Length Of Stay: " << patient.lengthOfStay << endl;
    cout << "Base Cost Per Hour: " << patient.baseCostPerHour << endl;
    cout << "Days Visits Per Year: " << patient.daysVisitsPerYear << endl;
    cout << "Medical Cost: "
         << calcmedicalCost(patient.lengthOfStay,
                            patient.baseCostPerHour,
                            patient.daysVisitsPerYear)
         << endl;
}*/