// STL_Iterators.cpp
// Main program to practice with STL iterators
// CPP Certificate
// Author: Aidan Richer
// Date: July 31, 2025

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>

using namespace std;

//Template function that accepts template T as argument and returns a double
template <typename T> double Sum(const T& container) {
    double sum = 0.0;
    typename T::const_iterator itr; //Initialize iterator
    typename T::const_iterator itrEnd = container.end();
    for (itr = container.begin(); itr != itrEnd; ++itr) { //Iterate through container
        sum += *itr; //Dereference iterator
    }
    return sum; //For containers
}

//Sum function to calculate the sum between two iterators
template <typename Iterator> double Sum(Iterator begin, Iterator end) {
    double sum = 0.0;
    for (Iterator itr = begin; itr != end; ++itr) {
        sum += *itr; //Dereference iterator
    }
    return sum; //Of iterators
}

//Sum function for map type
template <typename T1, typename T2> double Sum(const map<T1, T2>& m) {
    double sum = 0.0;
    typename map<T1, T2>::const_iterator itr; //Initialize iterator
    typename map<T1, T2>::const_iterator itrEnd = m.end();
    for (itr = m.begin(); itr != itrEnd; ++itr) {
        sum += itr->second; //Dereference
    }
    return sum; //Map type
}

int main() {
    list<double> listDoubles = {1.0, 2.0, 3.0, 4.0, 5.0}; //Create list of doubles
    vector<double> vectorDoubles = {5.0, 4.0, 3.0, 2.0, 1.0}; //Create vector of doubles
    map<string, double> mapStringDouble; //Create map of strings as doubles
    
    //Fill the map
    mapStringDouble["Call option"] = 1.0;
    mapStringDouble["Put option"] = 2.0;
    mapStringDouble["Share price"] = 3.0;
    
    //Use Sum() function with containers
    cout << "Sum of listDoubles: " << Sum(listDoubles) << endl;
    cout << "Sum of vectorDoubles: " << Sum(vectorDoubles) << endl;

    //Use Sum() function with iterators
    cout << "Sum of first 3 elements in vectorDoubles: " << Sum(vectorDoubles.begin(), vectorDoubles.begin() + 3) << endl;

    //Use Sum() function with map
    cout << "Sum of map values: " << Sum(mapStringDouble) << endl;

    return 0;
}