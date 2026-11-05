#include <iostream>
#include <iomanip>
#include <chrono> // For execution time (Performance)
#include "patient.h"
using namespace std;

void printAgeGroupReport(Patient patient[], int patientCount, string ageGroup) {
    auto start = chrono::high_resolution_clock::now();
    string careTypes[] = {
        "Vaccination",
        "Rehabilitation",
        "Emergency",
        "Outpatient",
        "Inpatient",
        "Routine Checkup"
    };

    int numberOfCareTypes = 6;

    double totalGroupCost = 0;

    cout << "\nAge Group: " << ageGroup << endl;

    cout << "-------------------------------------------------------------------------------" << endl;

    cout << left
         << setw(20) << "Care Type"
         << setw(15) << "Patient Count"
         << setw(20) << "Total Cost ($)"
         << setw(30) << "Average Cost per Patient ($)"
         << endl;

    cout << "-------------------------------------------------------------------------------" << endl;
    
    int comparisons = 0;

    for (int c = 0; c < numberOfCareTypes; c++)
    {
        comparisons++;
        string currentCareType = careTypes[c];

        int patientCountForCare = 0;
        double totalCostForCare = 0;

        for (int i = 0; i < patientCount; i++)
        {
            // Check age group
            if (getAgeGroup(patient[i].age) == ageGroup)
            {
                // Check care type
                if (patient[i].careType == currentCareType)
                {
                    double medicalCost = calcmedicalCost(
                        patient[i].lengthOfStay,
                        patient[i].baseCostPerHour,
                        patient[i].daysVisitsPerYear
                    );

                    patientCountForCare++;
                    totalCostForCare += medicalCost;
                }
            }
        }

        // Only print care type if there are patients
        if (patientCountForCare > 0)
        {
            double averageCost =
                totalCostForCare / patientCountForCare;

            cout << left
                 << setw(20) << currentCareType
                 << setw(15) << patientCountForCare
                 << setw(20) << fixed << setprecision(2) << totalCostForCare
                 << setw(30) << averageCost
                 << endl;

            totalGroupCost += totalCostForCare;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(
          end - start
    ).count();

    cout << "-------------------------------------------------------------------------------" << endl;

    cout << "Total Billing for Age Group: $" << fixed << setprecision(2) << totalGroupCost << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Execution Time for Analysis: " << duration << " microseconds" << endl;
}