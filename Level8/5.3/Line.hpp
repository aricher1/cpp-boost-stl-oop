// Line.hpp
// Header file for a Line class.
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#ifndef Line_HPP
#define Line_HPP

#include "Shape.hpp" //Base class
#include "Point.hpp" //for ToString() and Distance() functions
#include <string>
#include <ostream> //For ostream << operator

namespace AidanRicher {
namespace CAD {

class Line : public Shape {
    private:
        Point m_p1; //Start point
        Point m_p2; //End point

    public:
        //Constructors and Destructors
        Line(); //Default constructor
        Line(const Point& p1, const Point& p2); //Parameter constructor
        Line(const Line& source); //Copy constructor
        ~Line(); //Destructor

        //Getters
        Point P1() const; 
        Point P2() const; 

        //Setters
        void P1(const Point& p); 
        void P2(const Point& p); 

        Line& operator = (const Line& source); //Assignment operator

        //Friend function for ostream << operator
        friend std::ostream& operator << (std::ostream& os, const Line& l);
        std::string ToString() const override; //Returns description of the line
        double Length() const; //Returns length of line
        void Draw() const override; //Draws our Line Shape
};

} //namespace CAD
} //namespace AidanRicher

#endif //Line_HPP