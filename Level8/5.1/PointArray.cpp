// PointArray.cpp
// Header file is for the PointArray class
// To create an array of Points by instantiating the Array class for the Point class
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#include "PointArray.hpp"

namespace AidanRicher {
namespace Containers {

PointArray::PointArray() : Array<Point>() {} //Default constructor
PointArray::PointArray(int size) : Array<Point>(size) {} //Parameter constructor
PointArray::PointArray(const PointArray& source) : Array<Point>(source) {} //Copy constructor
PointArray::~PointArray() {} //Destructor

PointArray& PointArray::operator = (const PointArray& source) { //Assignment operator
    if (this != &source) 
        return *this; //Self-assignment check
    Array<Point>::operator = (source);
    return *this;
}

double PointArray::Length() const {
    double Length = 0.0; //Initialize length to zero
    int size = this->Size(); //Get array size
    for (int i = 0; i < size - 1; ++i) {
        Length += this->GetElement(i).Distance(this->GetElement(i + 1)); 
        //GetElement() from Array class
        //Distance() in Point class to calculate the distance between two points
    }
    return Length;
} 

} //Namespace Containers
} //Namespace AidanRicher