// Array.hpp
// Header file for Array class.
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#ifndef Array_HPP
#define Array_HPP

#include "OutOfBoundsException.hpp"

namespace AidanRicher {
namespace Containers {

template <typename T>
class Array {
    private:
        T* m_data; //Dynamic array of elements of type T
        int m_size; //Size of the array
        static int default_size; //Static variable indicating default array construction size

    public:
        //Constructors and Destructors
        Array(); //Default construtor
        Array(int size); //Parameter constructor
        Array(const Array<T>& source); //Copy constructor
        ~Array(); //Destructor

        Array<T>& operator = (const Array<T>& source); //Assignment operator

        //Other methods
        int Size() const; //Function to return the size of the array
        void SetElement(int index, const T& element); //Function to set element
        const T& GetElement(int index) const; //Const version
        T& operator [] (int index); //Square bracket operator, array accessing
        const T& operator [] (int index) const; //Const version of the square bracket operator
        static int DefaultSize(); //Get the default size of array
        static void DefaultSize(int new_size); //Set the default size
};

} //namespace Containers
} //namespace AidanRicher

#ifndef Array_CPP
#include "Array.cpp"
#endif

#endif //Array_HPP