// Point.cpp
// Header file is for Point class.
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#include "Point.hpp" //Point class header file
#include <iostream>
#include <sstream> //For std::stringstream
#include <cmath> //For std::sqrt

namespace AidanRicher {
namespace CAD {

//Constructors and Destructors
Point::Point() : m_x(0.0), m_y(0.0) {} //Default constructor
Point::Point(const Point& source) : Shape(source), m_x(source.m_x), m_y(source.m_y) {} //Copy constructor
Point::Point(double x, double y) : Shape(), m_x(x), m_y(y) {} //Parameter constructor
Point::~Point() {} //Destructor

//Getters
double Point::X() const { return m_x; }
double Point::Y() const { return m_y; }

//Setters
void Point::X(double x) { m_x = x; }
void Point::Y(double y) { m_y = y; }

//Assignment operator
Point& Point::operator = (const Point& source) {
    if (this == &source) return *this; //Self-assignment check
    Shape::operator = (source); //Call the base class Shape assignment
    m_x = source.m_x;
    m_y = source.m_y;
    return *this;
}

//Friend function for ostream << operator
std::ostream& operator << (std::ostream& os, const Point& p) {
    os << "Point(" << p.m_x << ", " << p.m_y << ")";
    return os;
}

//Description of Point Shape w/ ID
std::string Point::ToString() const {
    std::string s = Shape::ToString(); //Call base class to get ID
    std::stringstream ss;
    ss << s << ": Point(" << m_x << ", " << m_y << ")";
    return ss.str();   
}

//Distance to origin
double Point::Distance() const {
    return std::sqrt(m_x * m_x + m_y * m_y);
}

//Distance between two points
double Point::Distance(const Point& p) const {
    double dx = m_x - p.m_x;
    double dy = m_y - p.m_y;
    return std::sqrt(dx * dx + dy * dy);
}

//Draw our Point shape
void Point::Draw() const {
    std::cout << "Drawing the Point: " << ToString() << std::endl;
}

//Negate coordinates
Point Point::operator - () const {
    return Point(-m_x, -m_y);
}

//Scale the coordinates
Point Point::operator * (double factor) const {
    return Point(m_x * factor, m_y * factor);
}

//Add coordinates
Point Point::operator + (const Point& p) const { 
    return Point(m_x + p.m_x, m_y + p.m_y);
}

//Equally compare two points
bool Point::operator == (const Point& p) const {
    return (m_x == p.m_x) && (m_y == p.m_y);
}

//Scale the coordinates and assign
Point& Point::operator *= (double factor) {
    m_x *= factor;
    m_y *= factor;
    return *this;
}

} //namespace CAD
} //namespace AidanRicher