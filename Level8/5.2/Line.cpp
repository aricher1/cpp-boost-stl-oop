// Line.cpp
// CPP Certificate
// Header file is for a Line class.
// Author: Aidan Richer
// Date: Aug 2, 2025

#include "Line.hpp" //Line class header file
#include <iostream>
#include <sstream> //For std::stringstream
#include <cmath> //For std::sqrt()

namespace AidanRicher {
namespace CAD {

//Constructors and Destructors
Line::Line() : m_p1(Point(0.0, 0.0)), m_p2(Point(0.0, 0.0)) {} //Default constructor
Line::Line(const Point& p1, const Point& p2) : Shape(), m_p1(p1), m_p2(p2) {} //Parameter constructor
Line::Line(const Line& source) : Shape(source), m_p1(source.m_p1), m_p2(source.m_p2) {} //Copy constructor
Line::~Line() { std::cout << "Line destructor called" << std::endl; } //Destructor

//Getters
Point Line::P1() const { return m_p1; }
Point Line::P2() const { return m_p2; }

//Setters
void Line::P1(const Point& p) { m_p1 = p; }
void Line::P2(const Point& p) {m_p2 = p; }

//Assignment operator
Line& Line::operator = (const Line& source) {
    if (this == &source) return *this; //Self-assignment check
    Shape::operator = (source); //Call base class Shape assignment
    m_p1 = source.m_p1;
    m_p2 = source.m_p2;
    return *this;
}

//Friend function for ostream << operator
std::ostream& operator << (std::ostream& os, const Line& l) {
    os << "Line(Start: " << l.m_p1 << ", End: " << l.m_p2 << ")";
    return os;
}

//Description of Line Shape w/ ID
std::string Line::ToString() const {
    std::string s = Shape::ToString(); //Call base class to get ID
    std::stringstream ss;
    ss << s << ": Line(" << m_p1.ToString() << ", " << m_p2.ToString() << ")";
    return ss.str();
}

//Length of Line
double Line::Length() const {
    return m_p1.Distance(m_p2); //Use Distance() func from "Point.hpp"
}

//Draw our Line Shape
void Line::Draw() const {
    std::cout << "Drawing the Line: " << ToString() << std::endl;
}

} //namespace CAD
} //namespace AidanRicher