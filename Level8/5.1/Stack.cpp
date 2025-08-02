// Stack.cpp
// Header file is for Stack class.
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#ifndef Stack_CPP
#define Stack_CPP

#include "Stack.hpp"

namespace AidanRicher {
namespace Containers {

template <typename T, int size> Stack<T, size>::Stack() : m_array(size), m_current(0) {} //Default constructor
template <typename T, int size> Stack<T, size>::Stack(const Stack<T, size>& source) : m_array(source.m_array), m_current(source.m_current) {} //Copy constructor
template <typename T, int size> Stack<T, size>::~Stack() {} //Destructor

template <typename T, int size> Stack<T, size>& Stack<T, size>::operator = (const Stack<T, size>& source) { //Assignment operator
    if (this == &source)
        return *this; //Self-assignment check
    m_array = source.m_array;
    m_current = source.m_current;
    return *this;
}

template <typename T, int size> void Stack<T, size>::Push(const T& element) { //Push an element
    //Try-catch block
    try { //To push element
        m_array[m_current] = element;
        ++m_current;
    } catch (const OutOfBoundsException&) { //Error handling
        throw StackFullException(); //Transalte to stack
    }
}

template <typename T, int size> T Stack<T, size>::Pop() { //Pop an element
    //Try-catch block
    try { //To pop element
        --m_current;
        return m_array[m_current];
    } catch (OutOfBoundsException&) { //Error handling
        m_current = 0; //Set current index back to zero
        throw StackEmptyException(); //Translate to stack
    }
}

} //Namespace Containers
} //Namespace AidanRicher

#endif //Stack_HPP