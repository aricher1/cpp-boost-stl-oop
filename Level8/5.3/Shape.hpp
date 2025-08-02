// Shape.hpp
// Header file for Shape class.
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#ifndef Shape_HPP
#define Shape_HPP

#include <string>
#include <stdlib.h> //For rand()

namespace AidanRicher {
namespace CAD {

class Shape {
    private:
        int m_id; //Data member for id number
    
    public:
        //Constructors and Destructors
        Shape(); //Default constructor
        Shape(const Shape& source); //Copy constructor
        virtual ~Shape(); //Virtual destructor (prevent memory leaks)

        Shape& operator = (const Shape& source); //Assignment operator

        //Other methods
        int ID() const; //Retrieve the id of the shape
        virtual std::string ToString() const; //Returns the ID as a string
        virtual void Draw() const = 0; //Pure virtual function to draw our shapes in derived classes
        void Print() const; //Print the information of a Shape
};

std::ostream& operator << (std::ostream& os, const Shape& shape); //Global << operator

} //Namespace CAD
} //Namespace AidanRicher

#endif //Shape_HPP