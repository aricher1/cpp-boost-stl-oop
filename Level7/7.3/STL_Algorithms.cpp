// STL_Algorithms.cpp
// Main program to practice with different STL containers
// CPP Certificate
// Author: Aidan Richer
// Date: July 31, 2025

#include <iostream>
#include <vector>
#include <algorithm>

#include "LessThan.hpp"

using namespace std;

bool isLessThanTen(double val) {
    return val < 10.0;
}

int main() {
    vector<double> data = {30.0, 40.0, 5.0, 1.0, 4.0, 3.0, 50.0, 99.0}; //Create a vector of doubles

    //Use global function with count_if()
    int countGlobal = count_if(data.begin(), data.end(), isLessThanTen); //count_if()
    cout << "Count less than 10.0 using global function: " << countGlobal << endl;

    //Use function in class with count_if(), passing the threshold to constructor
    LessThan lessThan(10.0); //Pass
    int countFunctor = count_if(data.begin(), data.end(), lessThan); //count_if()
    cout << "Count less than 10.0 using functor from class: " << countFunctor << endl; //Output

    return 0;
}