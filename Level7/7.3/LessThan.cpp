// LessThan.cpp
// Implementation file for LessThan class.
// CPP Certificate
// Author: Aidan Richer
// Date: July 31, 2025

#include "LessThan.hpp"

LessThan::LessThan() {} //Default constructor
LessThan::LessThan(double val) : m_threshold(val) {} //Parameter constructor
LessThan::LessThan(const LessThan& other) : m_threshold(other.m_threshold) {} //Copy constructor
LessThan::~LessThan() {} //Virtual destructor

LessThan& LessThan::operator = (const LessThan& other) { //Assignment operator
    if (this != &other) { //Self-assignment check
        m_threshold = other.m_threshold;
    }
    return *this;
}

bool LessThan::operator()(double val) const { //Round bracket operator, checks if input is less than threshold
    return val < m_threshold;
}