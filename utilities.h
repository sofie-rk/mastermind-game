#pragma once
#include <vector>
#include <string>

using namespace std;

int incrementByValueNumTimes(int startValue, int increment, int numTimes);

void incrementByValueNumTimesRef(int &startValue, int increment, int numTimes);

void swapNumbers(int &a, int &b);

void randomizeVector(vector<int>& vec, int n);

void sortVector(vector<int>& vec);

double medianOfVector(vector<int>& vec);

struct Student {

    string name;
    string studyProgram;
    int age;

};

void printStudent(Student student);

string randomizeString(int n, char lower, char upper);

string readInputToString(int n, char lower, char upper);