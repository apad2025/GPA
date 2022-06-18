// GPA Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Created by apad on 6/6/2022.


#include <iostream>
#include <array>
#include <numeric>

using namespace std;

string weighted(), unweighted();
int choice, anotherChoice, exiter;
double info[2][7];
array<double, 7> unweightedInfo;
double sum, classGrade, anotherSum;

int main() {
    cout << "Made by APAD";
    cout << "\n\nWeighted or unweighted? [type 1 for weighted, 2 for unweighted] ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << weighted();
        break;
    case 2:
        cout << unweighted();
        break;
    default:
        cout << "Defaulting to weighted\n";
        cout << weighted();
        break;
    }
    cout << "\n\nType anything then press enter to exit: ";
    cin >> exiter;
    return 0;
}

string weighted() {
    for (int i = 0; i < 7; i++) {
        cout << "\nEnter class #";
        cout << (i + 1);
        cout << "'s grade: ";
        cin >> info[0][i];

        cout << "\nSpecify the class's level such as regular or AP [1 for regular, 2 for preAP, 3 for AP]: ";
        cin >> anotherChoice;

        switch (anotherChoice) {
        case 1:
            info[1][i] = 4.0;
            break;
        case 2:
            info[1][i] = 5.0;
            break;
        case 3:
            info[1][i] = 6.0;
            break;
        default:
            cout << "Invalid level";
            break;
        }

        double subtrahend = (100 - info[0][i]) / 10.0;
        info[1][i] = info[1][i] - subtrahend;
    }

    for (int z = 0; z < 7; z++) {
        sum += info[1][z];
    }

    cout << "\nYour weighted GPA is: \n";
    cout.precision(4);
    cout << sum / 7.0;

    return "";
}

string unweighted() {
    unweightedInfo.fill(4.0);

    for (int i = 0; i < 7; i++) {
        cout << "\nEnter class #";
        cout << (i + 1);
        cout << "'s grade: ";
        cin >> classGrade;

        unweightedInfo[i] = unweightedInfo[i] - ((100 - classGrade) / 10.0);
    }

    for (int f = 0; f < 7; f++) {
        anotherSum += unweightedInfo[f];
    }

    cout << "\nYour unweighted GPA is: \n";
    cout.precision(4);
    cout << anotherSum / 7.0;
    cout << "\n\nPlease remember that harder courses are taken into account when calculating "
        "unweighted GPA. \nFor example, a 95 in an AP course will be looked at differently by colleges "
        "than a 95 in a \nregular course, even though they both translate to the same unweighted GPA.";

    return "";
}