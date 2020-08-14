#include <iostream>
#include <vector>

#include "utilities.h"


using namespace std;

void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);

    cout << "v0: " << v0
        << " increment: " << increment 
        << " iterations: " << iterations
        << " result: " << result << endl;
}

void testCallByRef() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimesRef(v0, increment, iterations);

    cout << "v0: " << v0
        << " increment: " << increment 
        << " iterations: " << iterations << endl;

}

void testVectorSorting() {
    vector<int> percentages;

    randomizeVector(percentages, 24);

    cout << "Vector: \n";
    for (int n : percentages) {
        cout << n << " ";
    } 

    sortVector(percentages);

    cout << "\nSorted vector: \n";
    for (int n : percentages) {
        cout << n << " ";
    } 

    double median = medianOfVector(percentages);
    cout << "\nMedian: " << median << endl;
    
}

void testString() {
    string grades = randomizeString(8, 'A', 'F');
    cout << "Grades: " << grades << endl;
}