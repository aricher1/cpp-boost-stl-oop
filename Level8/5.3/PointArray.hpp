// PointArray.hpp
// Header file is for the PointArray class
// To create an array of Points by instantiating the Array class for the Point class
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#ifndef PointArray_HPP
#define PointArray_HPP

#include "Array.hpp"
#include "Point.hpp"

namespace AidanRicher {
namespace Containers {

using CAD::Point; //For our Point class accessing

class PointArray : public Array<Point> {
    public:
        PointArray(); //Default constructor
        PointArray(int size); //Parameter constructor
        PointArray(const PointArray& source); //Copy constructor
        ~PointArray(); //Destructor

        PointArray& operator = (const PointArray& source); //Assignment operator

        double Length() const; //Return length between the Points in the array
};

} //Namespace Containers
} //Namespace AidanRicher

#endif //PointArray_HPP