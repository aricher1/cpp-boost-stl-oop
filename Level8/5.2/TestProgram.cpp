// TestProgram.cpp
// The purpose of this file is to test our program.
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#include <iostream>
#include <string>
#include <boost/tuple/tuple.hpp> //For tuple class
#include <boost/tuple/tuple_io.hpp> //For input/output simplicity

using namespace std;

typedef tuple<string, int, double> Person; //Typedef for person

void PrintPersonTuple(const Person& p) { //Function to print the person tuple
    cout << "Name: " << get<0>(p) << endl; //Use get<>() member function
    cout << "Age: " << get<1>(p) << endl;
    cout << "Height: " << get<2>(p) << endl;
}

int main() {
    //Create person tuple instances
    Person p1 = make_tuple("Neymar Jr.", 33, 1.75);   
    Person p2 = make_tuple("Kylian Mbappe", 26, 1.78);    
    Person p3 = make_tuple("Cristiano Ronaldo", 40, 1.87);
    
    //Print tuples
    PrintPersonTuple(p1);
    PrintPersonTuple(p2);
    PrintPersonTuple(p3);

    get<1>(p3) += 10; //Increment Ronaldo's age by 10
    cout << "Incremented Ronaldo's age by 10: " << endl;
    PrintPersonTuple(p3); //Print new tuple

    return 0;
}