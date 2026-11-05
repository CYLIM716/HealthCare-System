#include <iostream>
#include <iomanip>
#include <chrono> // For execution time (Performance)
#include "patient.h"
#include "search.h"

using namespace std;

void printSearchReport(Patient patient[], int patientCount, int searchAge)
{
    auto start = chrono::high_resolution_clock::now();
    cout << "------------------------------------------------------------------------------------"
         << endl;

    cout << left
         << setw(20) << "Patient ID"
         << setw(10) << "Age"
         << setw(20) << "Care Type"
         << setw(15) << "Length of Stay"
         << setw(20) << "Base Cost Per Hour"
         << endl;

    cout << "------------------------------------------------------------------------------------"
         << endl;

    int totalFound = 0;
    int comparisons = 0;

    for (int i = 0; i < patientCount; i++)
    {
        comparisons++;

        // Search for exact age
        if (patient[i].age == searchAge)
        {
            cout << left
                 << setw(20) << patient[i].patientID
                 << setw(10) << patient[i].age
                 << setw(20) << patient[i].careType
                 << setw(15) << patient[i].lengthOfStay
                 << setw(20) << patient[i].baseCostPerHour
                 << endl;

            totalFound++;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(
          end - start
    ).count();

    cout << "------------------------------------------------------------------------------------"
         << endl;

    cout << "Total Records Found: "
         << totalFound
         << endl;
     cout << "Comparisons: " << comparisons << endl;
     cout << "Execution Time Search By Age: " << duration << " microseconds" << endl;
}

void printSearchCareType(Patient patient[], int patientCount, string careType) {
     auto start = chrono::high_resolution_clock::now();
    cout << "------------------------------------------------------------------------------------"
         << endl;

    cout << left
         << setw(20) << "Patient ID"
         << setw(10) << "Age"
         << setw(20) << "Care Type"
         << setw(15) << "Length of Stay"
         << setw(20) << "Base Cost Per Hour"
         << endl;

    cout << "------------------------------------------------------------------------------------"
         << endl;

    int totalFound = 0;
    int comparisons = 0;

    for (int i = 0; i < patientCount; i++)
    {
        comparisons++;
        if (patient[i].careType == careType)
        {
            cout << left
                 << setw(20) << patient[i].patientID
                 << setw(10) << patient[i].age
                 << setw(20) << patient[i].careType
                 << setw(15) << patient[i].lengthOfStay
                 << setw(20) << patient[i].baseCostPerHour
                 << endl;

            totalFound++;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(
          end - start
    ).count();

    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "Total Records Found: " << totalFound << endl;
    cout << "Comparisons: " << comparisons << endl;
     cout << "Execution Time Search By Care Type: " << duration << " microseconds" << endl;
    
}


void printSearchID(Patient patient[], int patientCount, string id) {
     auto start = chrono::high_resolution_clock::now();
    cout << "------------------------------------------------------------------------------------"
         << endl;

    cout << left
         << setw(20) << "Patient ID"
         << setw(10) << "Age"
         << setw(20) << "Care Type"
         << setw(15) << "Length of Stay"
         << setw(20) << "Base Cost Per Hour"
         << endl;

    cout << "------------------------------------------------------------------------------------"
         << endl;

    int totalFound = 0;
    int comparisons = 0;

    for (int i = 0; i < patientCount; i++)
    {
        comparisons++;
        if (patient[i].patientID == id)
        {

            cout << left
                 << setw(20) << patient[i].patientID
                 << setw(10) << patient[i].age
                 << setw(20) << patient[i].careType
                 << setw(15) << patient[i].lengthOfStay
                 << setw(20) << patient[i].baseCostPerHour
                 << endl;

            totalFound++;
        }
    }
     auto end = chrono::high_resolution_clock::now();
     auto duration = chrono::duration_cast<chrono::microseconds>(
          end - start
     ).count();
    cout << "------------------------------------------------------------------------------------" << endl;

    cout << "Total Records Found: " << totalFound << endl;
    cout << "Comparisons: " << comparisons << endl;
     cout << "Execution Time Search By Patient ID: " << duration << " microseconds" << endl;
}

