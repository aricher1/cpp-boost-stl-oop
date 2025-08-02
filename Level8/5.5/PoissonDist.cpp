// PoissonDist.cpp
// Experimenting with the exponential and Poission distributions in Boost library
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions/poisson.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions

#include <vector>
#include <iostream>
#include <iomanip> //For std::fixed and std::setprecision

using namespace std;

int main() {
    using namespace boost::math;

    //Exponential distribution params
    double lambda = 0.5; // Rate parameter
    exponential_distribution<> myExponential(lambda);

    cout << "\n*** Exponential Distribution (lambda = " << lambda << "): " << endl;
    cout << "Mean: " << mean(myExponential) << ", standard deviation: " << standard_deviation(myExponential) << endl;

    //Distributional properties
    double x = 10.25;
    cout << "PDF at x = " << x << ": " << pdf(myExponential, x) << endl;
    cout << "CDF at x = " << x << ": " << cdf(myExponential, x) << endl;

    //Choose precision
    cout << fixed << setprecision(5); // Number of values behind the comma

    //Other properties
    cout << "\n*** Exponential Distribution Properties:\n";
    cout << "Mean: " << mean(myExponential) << endl;
    cout << "Variance: " << variance(myExponential) << endl;
    cout << "Median: " << median(myExponential) << endl;
    cout << "Mode: " << mode(myExponential) << endl;
    cout << "Skewness: " << skewness(myExponential) << endl;
    cout << "Kurtosis excess: " << kurtosis_excess(myExponential) << endl;
    cout << "Kurtosis: " << kurtosis(myExponential) << endl;
    cout << "Characteristic function: " << chf(myExponential, x) << endl;
    cout << "Hazard: " << hazard(myExponential, x) << endl;

    //Poisson distribution params
    double mu = 3.0;
    poisson_distribution<> myPoisson(mu);

    cout << "\n*** Poisson Distribution ***" << endl;
	cout << "Mean: " << mean(myPoisson) << ", Standard deviation: " << standard_deviation(myPoisson) << endl;

    double k = 13.0;

    cout << "PDF at k = " << k << ": " << pdf(myPoisson, k) << endl;
    cout << "CDF at k = " << k << ": " << cdf(myPoisson, k) << endl;

    //Other properties
    cout << "\n*** Poission Distribution Properties:\n";
    cout << "Skewness: " << skewness(myPoisson) << endl;
    cout << "Kurtosis excess: " << kurtosis_excess(myPoisson) << endl;
    cout << "Kurtosis: " << kurtosis(myPoisson) << endl;
    cout << "Characteristic function: " << chf(myPoisson, k) << endl;
    cout << "Hazard: " << hazard(myPoisson, k) << endl;
    
    vector<double> expPdfList, expCdfList;
    vector<double> poisPdfList, poisCdfList;

    double start = 0.0;
    double end = 10.0;
    long N = 30; //Number of subdivisions
    double val = 0.0;
    double h = (end - start) / double(N);

    for (long j = 0; j <= N; ++j) {
        expPdfList.push_back(pdf(myExponential, val));
        expCdfList.push_back(cdf(myExponential, val));
        val += h;
    }

    //Collect Poisson values for k = 0 to 20
    long N_poisson = 20;

    for (long k = 0; k <= N_poisson; ++k) {
        poisPdfList.push_back(pdf(myPoisson, k));
        poisCdfList.push_back(cdf(myPoisson, k));
    }

    //Output Exponential PDF
    cout << "\nExponential PDF values: ";
    for (long j = 0; j < (long)expPdfList.size(); ++j) {
        cout << expPdfList[j] << ", ";
    }
    cout << endl;

    //Output Exponential CDF
    cout << "Exponential CDF values: ";
    for (long j = 0; j < (long)expCdfList.size(); ++j) {
        cout << expCdfList[j] << ", ";
    }
    cout << endl;

    //Output Poisson PDF
    cout << "Poisson PDF values: ";
    for (long k = 0; k < (long)poisPdfList.size(); ++k) {
        cout << "k=" << k << ": " << poisPdfList[k] << ", ";
    }
    cout << endl;

    //Output Poisson CDF
    cout << "Poisson CDF values: ";
    for (long k = 0; k < (long)poisCdfList.size(); ++k) {
        cout << "k=" << k << ": " << poisCdfList[k] << ", ";
    }
    cout << endl;

    return 0;
}