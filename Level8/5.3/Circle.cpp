// Circle.cpp
// Header file is for a Circle class.
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#define _USE_MATH_DEFINES //For pi constant
#include <iostream>
#include <sstream> //for std::stringstream
#include "Circle.hpp" //Header file for Circle

namespace AidanRicher {
namespace CAD {

//Constructors and Destructors
Circle::Circle() : m_radius(0.0), center(Point(0.0, 0.0)) {} //Default constructor
Circle::Circle(const Point& p, double r) : Shape(), m_radius(r), center(p) {} //Parameter constructor
Circle::Circle(const Circle& source) : Shape(source), m_radius(source.m_radius), center(source.center) {} //Copy constructor
Circle::~Circle() {} //Destructor

//Getters
double Circle::Radius() const { return m_radius; }
Point Circle::Center() const { return center; }

//Setters
void Circle::Radius(double r) { m_radius = r; }
void Circle::Center(const Point& p) { center = p; }

//Assignment operator
Circle& Circle::operator = (const Circle& source) {
    if (this == &source) return *this; //Self-assingment check
    Shape::operator = (source); //Call base class Shape assignment
    m_radius = source.m_radius;
    center = source.center;
    return *this;
}

//Center Point of Circle
Point Circle::CenterPoint() const { 
    return center; //returns center in (x, y)
}

double Circle::Diameter() const { 
    return 2.0 * m_radius;
}

double Circle::Area() const { 
    return M_PI * m_radius * m_radius; 
}

double Circle::Circumference() const { 
    return 2.0 * M_PI * m_radius; 
}

//Description of Circle Shape w/ ID's
std::string Circle::ToString() const {
    std::string s = Shape::ToString(); //Get base class ToString() to get ID string
    std::stringstream ss;
    ss << s << " Circle(CenterPoint: " << CenterPoint().ToString()
    << ", Radius: " << Radius()
    << ", Diameter: " << Diameter()
    << ", Area: " << Area()
    << ", Circumference: " << Circumference()
    << ")";
    return ss.str();
}

//Draw our Circle Shape
void Circle::Draw() const {
    std::cout << "Drawing the Circle: " << ToString() << std::endl;
}

//Global function for ostream << operator
std::ostream& operator << (std::ostream& os, const Circle& c) {
    os << c.ToString();
    return os;
} 

} //namespace CAD
} //namespace AidanRicher