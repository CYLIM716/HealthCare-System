#include <iostream>
#include <iomanip>
#include <chrono> // For execution time (Performance)
#include "analysis.h"
using namespace std;

void sortByMedicalCost(Patient patient[], int patientCount)
{
    for (int i = 0; i < patientCount - 1; i++)
    {
        for (int j = 0; j < patientCount - i - 1; j++)
        {
            double cost1 = calcmedicalCost(
                patient[j].lengthOfStay,
                patient[j].baseCostPerHour,
                patient[j].daysVisitsPerYear
            );

            double cost2 = calcmedicalCost(
                patient[j + 1].lengthOfStay,
                patient[j + 1].baseCostPerHour,
                patient[j + 1].daysVisitsPerYear
            );

            if (cost1 > cost2)
            {
                Patient temp = patient[j];
                patient[j] = patient[j + 1];
                patient[j + 1] = temp;
            }
        }
    }
}

void printSortedAgeGroupReport(Patient patient[], int patientCount, string ageGroup)
{
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

    double totalCost[6] = {0};
    int patientCountForCare[6] = {0};

    double totalGroupCost = 0;

    // Calculate each Care Type
    for (int c = 0; c < numberOfCareTypes; c++)
    {
        for (int i = 0; i < patientCount; i++)
        {
            if (getAgeGroup(patient[i].age) == ageGroup &&
                patient[i].careType == careTypes[c])
            {
                double medicalCost = calcmedicalCost(
                    patient[i].lengthOfStay,
                    patient[i].baseCostPerHour,
                    patient[i].daysVisitsPerYear
                );

                patientCountForCare[c]++;
                totalCost[c] += medicalCost;
            }
        }
    }

    // Bubble Sort by Total Medical Cost (High to Low)

    for (int i = 0; i < numberOfCareTypes - 1; i++)
    {
        for (int j = 0; j < numberOfCareTypes - i - 1; j++)
        {
            if (totalCost[j] < totalCost[j + 1])
            {
                // Swap Care Type
                string tempCareType = careTypes[j];
                careTypes[j] = careTypes[j + 1];
                careTypes[j + 1] = tempCareType;

                // Swap Total Cost
                double tempCost = totalCost[j];
                totalCost[j] = totalCost[j + 1];
                totalCost[j + 1] = tempCost;

                // Swap Patient Count
                int tempCount = patientCountForCare[j];
                patientCountForCare[j] =
                    patientCountForCare[j + 1];

                patientCountForCare[j + 1] = tempCount;
            }
        }
    }

    // Display
    
    cout << "\nAge Group: " << ageGroup << endl;

    cout << "-------------------------------------------------------------------------------"
         << endl;

    cout << left
         << setw(20) << "Care Type"
         << setw(15) << "Patient Count"
         << setw(20) << "Total Cost ($)"
         << setw(30) << "Average Cost per Patient ($)"
         << endl;

    cout << "-------------------------------------------------------------------------------"
         << endl;

    int comparisons;
    for (int i = 0; i < numberOfCareTypes; i++)
    {
        comparisons++;
        if (patientCountForCare[i] > 0)
        {
            double averageCost =
                totalCost[i] / patientCountForCare[i];

            cout << left
                 << setw(20) << careTypes[i]
                 << setw(15) << patientCountForCare[i]
                 << setw(20) << fixed
                 << setprecision(2)
                 << totalCost[i]
                 << setw(30)
                 << averageCost
                 << endl;

            totalGroupCost += totalCost[i];
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(
          end - start
    ).count();

    cout << "-------------------------------------------------------------------------------"
         << endl;

    cout << "Total Billing for Age Group: $" << fixed << setprecision(2) << totalGroupCost << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Execution Time for Sorting: " << duration << " microseconds" << endl;
}