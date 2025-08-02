// Stack.hpp
// Header file is for Stack class.
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#ifndef Stack_HPP
#define Stack_HPP

#include "Array.hpp"
#include "OutOfBoundsException.hpp" //Error handling
#include "StackException.hpp" //To translate array to stack exceptions

namespace AidanRicher {
namespace Containers {

template <typename T, int size>
class Stack {
    private:
        Array<T> m_array; //Array member
        int m_current; //Element at the top of array

    public:
        Stack(); //Defualt constructor
        Stack(const Stack<T, size>& source); //Copy constructor
        ~Stack(); //Destructor

        Stack<T, size>& operator = (const Stack<T, size>& source); //Assignment operator

        void Push(const T& element); //Push an element
        T Pop(); //Pop an element
};

} //Namespace Containers
} //Namespace AidanRicher

#include "Stack.cpp"

#endif //Stack_HPP