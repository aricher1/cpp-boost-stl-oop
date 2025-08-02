// ArrayException.hpp
// Header file is the base class for our array error handling.
// This class is implimented within the header file for simplicity.
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#ifndef ArrayException_HPP
#define ArrayException_HPP

#include <string>

namespace AidanRicher {
namespace Containers {

class ArrayException {
    public:
        //Constructors and Destructors
        ArrayException() {} //Default constructor
        ArrayException(const ArrayException&) {} //Copy constructor
        virtual ~ArrayException() {} //Virtual destructor (base class)

        ArrayException& operator = (const ArrayException&) { return *this; } //Assignment operator

        virtual std::string GetMessage() const = 0; //Virtual method for error message
};

} //Namespace Containers
} //Namespace AidanRicher

#endif //ArrayException_HPP

