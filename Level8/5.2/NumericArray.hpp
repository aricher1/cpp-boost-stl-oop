// NumericArray.hpp
// Header file is for Array arithmetic.
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#ifndef NumericArray_HPP
#define NumericArray_HPP

#include "Array.hpp"

namespace AidanRicher {
namespace Containers {

template <typename T>
class NumericArray : public Array<T> {
    public: 
        NumericArray(); //Default constructor
        NumericArray(int size); //Parameter constructor
        NumericArray(const NumericArray<T>& source); //Copy constructor
        ~NumericArray(); //Destructor

        NumericArray<T>& operator = (const NumericArray<T>& source); //Assignment operator

        //Other methods
        NumericArray<T> operator + (const NumericArray<T>& source) const; //Addition operator
        NumericArray<T> operator * (double factor) const; //Scaling operator
        T DotProduct(const NumericArray<T>& source) const;
};

} //Namespace Containers
} //Namespace AidanRicher

#endif //NumericArray_HPP