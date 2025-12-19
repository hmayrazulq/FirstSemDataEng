// NAME: HUMAYRA' BINTI ZULQARNAIN
// MATRICS NUMBER: A25CS0068
// DATE: 19TH DECEMBER 2025, FRIDAY
// LAB EXERCISE 3

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void dispStatus(int);
void getInput(int&, int&, int&, int&);
void dispOutput(int);
int calcAverage(int, int);

int main() {
    char stateName[20], highestState[20];
    int numOfState = 0, totalActiveCases = 0, average = 0, highestCase = 0;
    int totalCase, newCase, totalDeath, totalRecovered, activeCases;
    string enter;
    
    do {
    
    numOfState +=1;
    
    cout << "<<<<<<<<<<<<<< DATA >>>>>>>>>>>>>" << endl;
    cout << "State name     : ";
    cin.getline(stateName, 20);
    getInput(totalCase, newCase, totalDeath, totalRecovered);
    
    activeCases = totalCase + newCase - totalDeath - totalRecovered;
    totalActiveCases += activeCases;
    
    if (activeCases > highestCase)
    {
        highestCase = activeCases;
        strcpy(highestState, stateName);
    }
    
    cout << "<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>" << endl;
    cout << "Active cases   : " << activeCases << endl;
    dispOutput(activeCases);
    
    cout << "Press <ENTER> to continue...";
    cin.ignore();
    getline(cin, enter);
    cout << endl;
    
    }while (enter == "");
    
    cout << "<<<<<<<<< ACTIVE CASES >>>>>>>>>>" << endl;
    average = calcAverage(numOfState, totalActiveCases);
    cout << "Total  : " << totalActiveCases << endl;
    cout << "Highest: " << highestCase << " (" << highestState << ")" << endl;
    cout << "Average for " << numOfState << " states: " << average;

    return 0;
}

void dispStatus (int active_cases)
{
    char zone[10];
    
    if (active_cases > 40)
    strcpy (zone, "Red");
    else if (active_cases >= 21 && active_cases <= 40 )
    strcpy (zone, "Orange");
    else if (active_cases >= 1 && active_cases <=20)
    strcpy (zone, "Yellow");
    else
    strcpy (zone, "Green");
    
    cout << "Status         : " << zone << " zone" << endl << endl;
}

void getInput(int& total_case, int& new_case, int& total_death, int& total_recovered)
{
    cout << "Total cases    : ";
    cin >> total_case;
    cout << "New cases      : ";
    cin >> new_case;
    cout << "Total death    : ";
    cin >> total_death;
    cout << "Total recovered: ";
    cin >> total_recovered;
    cout << endl;
}

void dispOutput(int active_cases)
{
    dispStatus(active_cases);
}

int calcAverage(int num_ofstate, int total_activecases)
{
    int getAverage;
    getAverage = total_activecases/num_ofstate;
    return getAverage;
}