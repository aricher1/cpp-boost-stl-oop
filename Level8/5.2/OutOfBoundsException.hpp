// OutOfBoundsException.hpp
// Header file is for OutOfBoundsException class, which represents an exception thrown
// when an invalid array index is accessed.
// This class is implimented within this header file for simplicity.
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#ifndef OutOfBoundsException_HPP
#define OutOfBoundsException_HPP

#include "ArrayException.hpp"
#include <string>
#include <sstream>

namespace AidanRicher {
namespace Containers {

class OutOfBoundsException : public ArrayException {
    private:
        int m_index; 
    public: 
        //Constructors and Destructors
        OutOfBoundsException() : m_index(-1) {} //Default constructor
        OutOfBoundsException(int index) : m_index(index) {} //Parameter constructor
        OutOfBoundsException(const OutOfBoundsException& other) : m_index(other.m_index) {} //Copy constructor
        ~OutOfBoundsException() override {} //Destructor

        //Override our GetMessage() function from ArrayException.hpp
        std::string GetMessage() const override {
            std::ostringstream s;
            s << "Index " << m_index << " out of bounds.";
            return s.str();
        }
};

} //Namespace Containers
} //Namespace AidanRicher

#endif //OutOfBoundsException_HPP