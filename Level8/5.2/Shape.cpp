// Shape.cpp
// Header file for Shape class.
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#include "Shape.hpp"
#include <iostream>
#include <sstream> //for std::stringstream

namespace AidanRicher {
namespace CAD {

//Constructors and Destructors
Shape::Shape() : m_id(rand()) {} //Default constructor (randomizes ID number)
Shape::Shape(const Shape& source) : m_id(source.m_id) {} //Copy constructor
Shape::~Shape() { std::cout << "Shape destructor called" << std::endl; } //Virtual destructor

//Assignment operator
Shape& Shape::operator = (const Shape& source) {
    if (this == &source) return *this; //Self-assignment check

    m_id = source.m_id;
    return *this;
} 

//Retrieve the ID of the shape
int Shape::ID() const { return m_id; }

//Returns the ID of the shape as a string
std::string Shape::ToString() const {
    std::ostringstream ss;
    ss << "ID: " << m_id;
    return ss.str();
}

//Print the information of a Shape
void Shape::Print() const {
    std::cout << ToString() << std::endl;
}

//Global << operator
std::ostream& operator << (std::ostream& os, const Shape& shape) {
    os << shape.ToString();
    return os;
}

} //Namespace CAD
} //Namespace AidanRicher