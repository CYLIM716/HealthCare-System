#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "patient.h"
using namespace std;

void readDatabase(Patient patients[], int &patientCount)
{
    string fileNames[3] = {
        "dataset1_facility_a.csv",
        "dataset2_facility_b.csv",
        "dataset3_facility_c.csv"
    };

    for (int index = 0; index < 3; index++) {
        ifstream file(fileNames[index]);

        if (!file)
        {
            cout << "Error opening file." << fileNames[index]<< endl;
            continue;
        }

        string line;

        // Skip the header
        getline(file, line);

        // Read patient data
        while (getline(file, line))
        {
            stringstream ss(line);

            string patientID;
            string age;
            string careType;
            string lengthOfStay;
            string baseCostPerHour;
            string daysVisitsPerYear;

            getline(ss, patientID, ',');
            getline(ss, age, ',');
            getline(ss, careType, ',');
            getline(ss, lengthOfStay, ',');
            getline(ss, baseCostPerHour, ',');
            getline(ss, daysVisitsPerYear, ',');

            patients[patientCount].patientID = patientID;
            patients[patientCount].age = stoi(age);
            patients[patientCount].careType = careType;
            patients[patientCount].lengthOfStay = stod(lengthOfStay);
            patients[patientCount].baseCostPerHour = stod(baseCostPerHour);
            patients[patientCount].daysVisitsPerYear = stoi(daysVisitsPerYear);

            patients[patientCount].medicalCost =
                calcmedicalCost(
                    patients[patientCount].lengthOfStay,
                    patients[patientCount].baseCostPerHour,
                    patients[patientCount].daysVisitsPerYear
                );

            patientCount++;
        }

        file.close();
    }

}

void displayPatients(Patient patients[], int patientCount)
{
    cout << string(125, '=') << endl;

    cout << left
         << setw(10) << "PatientID" << " | "
         << setw(5) << "Age" << " | "
         << setw(10) << "Age Group" << " | "
         << setw(20) << "Care Type" << " | "
         << setw(14) << "Length Stay" << " | "
         << setw(18) << "Base Cost/Hour" << " | "
         << setw(18) << "Visits/Year" << " | "
         << setw(15) << "Medical Cost"
         << endl;

    cout << string(125, '=') << endl;

    for (int i = 0; i < patientCount; i++)
    {
        cout << left
             << setw(10) << patients[i].patientID << " | "
             << setw(5) << patients[i].age << " | "
             << setw(10) << getAgeGroup(patients[i].age) << " | "
             << setw(20) << patients[i].careType << " | "
             << setw(14) << patients[i].lengthOfStay << " | "
             << setw(18) << patients[i].baseCostPerHour << " | "
             << setw(18) << patients[i].daysVisitsPerYear << " | "
             << setw(15) << patients[i].medicalCost
             << endl;
    }
}