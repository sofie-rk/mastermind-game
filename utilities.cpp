#include "utilities.h"

#include <vector>
#include <iostream>

using namespace std;

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i=0; i<numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimesRef(int &startValue, int increment, int numTimes) {
    for (int i=0; i<numTimes; i++) {
        startValue += increment;
    }
}

void swapNumbers(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void randomizeVector(vector<int>& vec, int n) {
    
    for (int i = 0; i < n; i++) {
        vec.push_back(rand() % 101);
    }
}

void sortVector(vector<int>& vec) {
    // Insertion sort algorithm

    int i = 1;
    while (i < vec.size()) {
        int j = i;
        while (j > 0 && vec[j-1] > vec[j]) {
            swapNumbers(vec[j-1], vec[j]);
            j--;
        }
        i++;
    }
}

double medianOfVector(vector<int>& vec) {
    // Assuming sorted vector

    if (vec.size() % 2 == 0){
        // Even number of elements in vector
        int m = static_cast<int>(vec.size() / 2 - 1);
        int n = static_cast<int>(vec.size() / 2);
        return static_cast<double>((vec[m]+vec[n]) / 2.0);
    }
    // Odd number of elements in vector
    return static_cast<double>(vec[static_cast<int>(vec.size() / 2)]);
}

void printStudent(Student student) {
    cout << "Name: " << student.name 
        << "\nStudy program: " << student.studyProgram
        << "\nAge: " << student.age << endl;

}

string randomizeString(int n, char lowerLimit, char upperLimit) {

    string resultString;
    for (int i = 0; i < n; i++){
        resultString += lowerLimit + (rand() % (upperLimit-lowerLimit));
    }

    return resultString;
}


string readInputToString(int n, char lowerLimit, char upperLimit) {
    
    // Convert to upper letters
    lowerLimit = toupper(lowerLimit);
    upperLimit = toupper(upperLimit);

    cout << "Please enter " << n << " characters between " << lowerLimit << " and " << upperLimit << ": " << endl;
    
    string str;
    char ch;
    cin >> str;

    for (int i=0; i<n; i++){
        cin >> ch;
        ch = toupper(ch);
        while (ch < lowerLimit or ch > upperLimit) {
            cout << "Please enter a character between " << lowerLimit << " and " << upperLimit << endl;
            cin >> ch;
            ch = toupper(ch);
        }
        str += ch;
    }


    return str;

}

