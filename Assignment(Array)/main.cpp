#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>
#include "patient.h"
#include "analysis.h"
#include "sorting.h"
#include "search.h"


using namespace std;

int main()
{
    const int MAX_PATIENTS = 1000;

    Patient patients[MAX_PATIENTS];

    int patientCount = 0;
    int num;
    int selectNum;
    
    
    readDatabase(patients, patientCount);

    while (true){
        cout << "=======================================" << endl;
        cout << "1 Analysis Age Group, Total Cost, and Average Cost" << endl;
        cout << "2 Sorted by Total Medical Cost" << endl;
        cout << "3 Searching Patient Records" << endl;
        cout << "4 Exit Program" << endl;
        cout << "=======================================" << endl;
        cout << "Select the number: ";
        cin >> num;

        if (num == 1) {
            int age;
            cout << "Enter age: ";
            cin >> age;
            string group = getAgeGroup(age);
            if (group == "Invalid")
            {
                cout << "Invalid age." << endl;
                continue;
            }

            cout << "\nYou belong to age group: "
                << group << endl;

            printAgeGroupReport(
                patients,
                patientCount,
                group
            );
        }

        else if (num == 2 ){
            int age;

            cout << "Enter age: ";
            cin >> age;

            string group = getAgeGroup(age);

            if (group == "Invalid")
            {
                cout << "Invalid age." << endl;
                continue;
            }

            cout << "\nYou belong to age group: "
                << group << endl;

            printSortedAgeGroupReport(
                patients,
                patientCount,
                group
            );    
        }
        else if (num == 3)
        {
            while (true){
                cout << "\nSearch By: " << endl;
                cout << "1. Exact Age" << endl;
                cout << "2. Care Type" << endl;
                cout << "3. Patient ID" << endl;
                cout << "4. Back To Main Menu" << endl;

                cout << "Select number: ";
                cin >> selectNum;

                // search by age
                if (selectNum == 1)
                {
                    int age;

                    cout << "Enter age: ";
                    cin >> age;

                    printSearchReport(
                        patients,
                        patientCount,
                        age
                    );
                }

                // search by Care Type
                else if (selectNum == 2) {
                    string type; 

                    cout << "Enter Care Type (Vaccination, Rehabilitation, Emergency, Outpatient, Inpatient, Routine Checkup): ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, type);
                    printSearchCareType(
                        patients,
                        patientCount,
                        type
                    );
                }

                // search by PatientID
                else if (selectNum == 3) {
                    string id;

                    cout << "Enter PatientID(PTxxxx): ";
                    cin >> id;

                    printSearchID(
                        patients, 
                        patientCount,
                        id
                    );
                }

                else if (selectNum == 4){
                    break;
                }
                else {
                    cout << "Invalid option. Please try again." << endl;
                }
            }
        }

        else if (num == 4) {
            cout << "Existing program..." << endl;
            break;
        }
        else {
            cout << "Invalid option. Please try again." << endl;
        }

    }
    return 0;

}