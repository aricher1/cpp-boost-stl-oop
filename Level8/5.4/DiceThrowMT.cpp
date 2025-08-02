// DiceThrowMT.cpp
// The purpose of this file is to test our program.
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#include <iostream>
#include <map>
#include <ctime>
#include <boost/random.hpp>

using namespace std;

int main() {
    //Throwing dice via Mersenne Twister random number generator
    
    long NumTrials;
    cout << "How many trials? ";
    cin >> NumTrials;

    boost::random::mt19937 myRng; //Mersenne Twister random number generator
    myRng.seed(static_cast<boost::uint32_t> (std::time(0))); //Set the seed
    boost::random::uniform_int_distribution<int> six(1, 6); //Uniform in range [1,6]

    map<int, long> statistics; //Structure to hold outcome + frequencies
    int outcome;

    for (long i = 0; i < NumTrials; ++i) {
        outcome = six(myRng); //Random dice roll
        ++statistics[outcome];
    }

    //Output results
    cout << "\nResults: " << endl;
    for (int i = 1; i <= 6; ++i) {
        double percentage = (static_cast<double> (statistics[i]) / NumTrials) * 100; //Convert to percentage
        cout << "Trial " << i << " has " << percentage << "% outcomes\n";
    }    

    return 0;
}