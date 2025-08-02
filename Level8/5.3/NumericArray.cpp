// NumericArray.cpp
// Header file is for Array arithmetic.
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#include "NumericArray.hpp"
#include "OutOfBoundsException.hpp"

namespace AidanRicher {
namespace Containers {

template <typename T> NumericArray<T>::NumericArray() : Array<T>() {} //Defualt constructor
template <typename T> NumericArray<T>::NumericArray(int size) : Array<T>(size) {} //Parameter constructor
template <typename T> NumericArray<T>::NumericArray(const NumericArray<T>& source) : Array<T>(source) {} //Copy constructor
template <typename T> NumericArray<T>::~NumericArray() {} //Destructor

template <typename T> NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source) { //Assignment operator
    if (this == &source) return *this; //Self-assignment check
    Array<T>::operator = (source);
    return *this;
}

template <typename T> NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& source) const { //Addition operator
    if (this->Size() != source.Size()) { //Make sure arrays are the same size
        throw OutOfBoundsException();
    }
    //If pass the bounds check proceed and add elements
    NumericArray<T> result(this->Size());
    for (int i = 0; i != this->Size(); ++i) {
        result[i] = (*this)[i] + source[i]; //Add each element
    }
    return result;
}

template <typename T> NumericArray<T> NumericArray<T>::operator * (double factor) const {
    //No bounds check as we are just scaling each element
    NumericArray<T> result(this->Size());
    for (int i = 0; i < this->Size(); ++i) {
        result[i] = (*this)[i] * factor; //Scale each element by factor
    }
    return result;
}

template <typename T> T NumericArray<T>::DotProduct(const NumericArray<T>& source) const {
    if (this->Size() != source.Size()) { //Make sure arrays are the same size
        throw OutOfBoundsException(); 
    }
    //If pass bounds check proceed and calculate dot product
    T sum = T(); //Initialize defualt sum
    for (int i = 0; i < this->Size(); ++i) { 
        sum += (*this)[i] * source[i]; //Dot product
    }
    return sum;
}

//Template instantiation
template class NumericArray<int>;
template class NumericArray<double>;
template class NumericArray<float>;

} //Namespace Containers
} //Namespace AidanRicher