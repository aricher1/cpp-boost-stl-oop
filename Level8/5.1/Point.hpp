// Point.hpp
// Header file for Point class.
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#ifndef Point_HPP
#define Point_HPP

#include "Shape.hpp" //Base class
#include <string>
#include <ostream> //For ostream << operator

namespace AidanRicher {
namespace CAD {

class Point : public Shape {
    private:
        double m_x; //X coordinate
        double m_y; //Y coordinate

    public:
        //Constructors and Destructors
        Point(); //Default constructor
        Point(const Point& source); //Copy constructor
        Point(double x, double y); //Parameter constructor
        ~Point(); //Destructor
        
        //Getters
        double X() const;
        double Y() const;

        //Setters
        void X(double x);
        void Y(double y);

        Point& operator = (const Point& source); //Assignment operator

        //Friend function for ostream << operator
        friend std::ostream& operator << (std::ostream& os, const Point& p);

        //Other methods
        std::string ToString() const override; //String description of the point
        double Distance() const; //Distance to origin
        double Distance(const Point& p) const; //Calculate the distance between two points
        void Draw() const override; //Override the Draw() function in our Point derived class

        //Operater overloads
        Point operator - () const; //Negate the coordinates
        Point operator * (double factor) const; //Scale the coordinates
        Point operator + (const Point& p) const; //Add coordinates
        bool operator == (const Point& p) const; //Equally compare operator
        Point& operator *= (double factor); //Scale the coordinates and assign
};

} //namespace CAD
} //namespace AidanRicher

#endif //Point_HPP