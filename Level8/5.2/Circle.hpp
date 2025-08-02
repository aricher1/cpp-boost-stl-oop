// Circle.hpp
// Header file for a Circle class.
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#ifndef Circle_HPP
#define Circle_HPP

#define _USE_MATH_DEFINES //Enable pi constant in cmath
#include <cmath>
#include <string>
#include <ostream> //For ostream << operator
#include "Shape.hpp" //Base class
#include "Point.hpp" //Header file for Point class, a file for points on a 2D plane

namespace AidanRicher {
namespace CAD {

class Circle : public Shape {
    private:
        double m_radius; //Radius
        Point center; //Center point

    public:
        //Constructors and Destructors
        Circle(); //Default constructor
        Circle(const Point& c, double r); //Parameter constructor
        Circle(const Circle& source); //Copy constructor
        ~Circle(); //Destructor

        //Getters
        double Radius() const;
        Point Center() const;

        //Setters
        void Radius(double r);
        void Center(const Point& p);

        Circle& operator = (const Circle& source); //Assignment operator

        //Other methods
        Point CenterPoint() const; //Point for (x, y) coordinates
        double Diameter() const;
        double Area() const;
        double Circumference() const;
        std::string ToString() const override; //Description of Circle in string
        void Draw() const override; //Draw our Circle Shape
};

//Global function for ostream << operator
std::ostream& operator << (std::ostream& os, const Circle& c);

} //namespace CAD
} //namespace AidanRicher

#endif //Circle_HPP