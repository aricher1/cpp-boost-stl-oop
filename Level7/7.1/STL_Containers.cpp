// STL_Containers.cpp
// Main program to practice with different STL containers
// CPP Certificate
// Author: Aidan Richer
// Date: July 31, 2025

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>

using namespace std;

int main() {
    
    //Part 1: Create a list of doubles and add data. Access using front() and back() functions
    list<double> listDoubles = {13.2, 64.5, 30.6, 99.0, 65.4}; //Create list of doubles

    cout << "Front of listDoubles: " << listDoubles.front() << endl; //Call .front()
    cout << "Back of listDoubles " << listDoubles.back() << endl; //Call .back()

    //Part 2: Create a vector of doubles and add data. Use index operator to access. Make vector grow
    vector<double> vectorDoubles = {13.2, 64.5, 30.6, 99.0, 65.4}; //Create vector of doubles

    cout << "vectorDoubles element at index 0: " << vectorDoubles[0] << endl; //Use [] operator
    cout << "vectorDoubles element at index 4: " << vectorDoubles[4] << endl;
    //Grow vector with push_back() function
    vectorDoubles.push_back(100.0); 
    vectorDoubles.push_back(50.0);
    vectorDoubles.push_back(73.0);
    //Print grown vector
    for (int i = 0; i < vectorDoubles.size(); i++) {
        cout << "Index [" << i << "] " << vectorDoubles[i] << endl;
    }

    //Part 3: Create a map that maps strings to doubles. Fill and access using [] operator
    map<string, double> mapStringDouble;
    //Fill the map
    mapStringDouble["Call option"] = 10.0;
    mapStringDouble["Put option"] = 12.0;
    mapStringDouble["Share price"] = 184.39;
    //Output
    cout << "Call option: " << mapStringDouble["Call option"] << endl;
    cout << "Put option: " << mapStringDouble["Put option"] << endl;
    cout << "Share price: " << mapStringDouble["Share price"] << endl;

    return 0;
}