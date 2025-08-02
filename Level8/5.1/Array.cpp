// Array.cpp
// Header file for Array class.
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#ifndef Array_CPP
#define Array_CPP

#include "Array.hpp"

namespace AidanRicher {
namespace Containers {

//Initialize static variable -> default array size
template <typename T> int Array<T>::default_size = 10;

//Constructors and Destructors
template <typename T> Array<T>::Array() : m_data(new T[default_size]), m_size(default_size) {} //Default constructor (defualt size to 10 elements)
template <typename T> Array<T>::Array(int size) : m_data(new T[size]), m_size(size) {} //Parameter constructor
template <typename T> Array<T>::Array(const Array& source) : m_data(new T[source.m_size]), m_size(source.m_size) { //Copy constructor
    for (int i = 0; i < m_size; i++) {
        m_data[i] = source.m_data[i]; //Copy array elements
    }
}
template <typename T> Array<T>::~Array() { delete[] m_data; } //Destructor

//Assignment operator
template <typename T> Array<T>& Array<T>::operator = (const Array<T>& source) {
    if (this == &source) return *this; //Self-assignment check

    delete[] m_data; //Delete old array    
    
    //Allocate new memory and copy elements
    m_size = source.m_size;
    m_data = new T[m_size];
    for (int i = 0; i < m_size; i++) {
        m_data[i] = source.m_data[i]; //Copy array elements
    }

    return *this;
}

//Return the size of the array
template <typename T> int Array<T>::Size() const { return m_size; }

//Set element in array
template <typename T> void Array<T>::SetElement(int index, const T& element) {
    if (index < 0 || index >= m_size) {
        throw OutOfBoundsException(index); //Error handling
    }
    m_data[index] = element;
}

//Const version of GetElement()
template <typename T> const T& Array<T>::GetElement(int index) const {
    if (index < 0 || index >= m_size) {
        throw OutOfBoundsException(index); //Error handling
    }
    return m_data[index];
}

//Non const version of [] operator (array accessing)
template <typename T> T& Array<T>::operator [] (int index) {
    if (index < 0 || index >= m_size) {
        throw OutOfBoundsException(index); //Error handling
    }
    return m_data[index];
}

//Const version of [] operator
template <typename T> const T& Array<T>::operator [] (int index) const {
    if (index < 0 ||index >= m_size) {
        throw OutOfBoundsException(index);
    }
    return m_data[index];    
}

template <typename T> int Array<T>::DefaultSize() { return default_size; } //Get default size
template <typename T> void Array<T>::DefaultSize(int new_size) { default_size = new_size; } //Set default size

} //namespace Containers
} //namespace AidanRicher

#endif //Array_CPP