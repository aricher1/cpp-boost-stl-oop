// LessThan.hpp
// Header file for LessThan class.
// CPP Certificate
// Author: Aidan Richer
// Date: July 31, 2025

#ifndef LessThan_HPP
#define LessThan_HPP

class LessThan {
    private:
        double m_threshold;

    public:
        LessThan(); //Default constructor
        LessThan(double val); //Parameter constructor
        LessThan(const LessThan& other); //Copy constructor
        virtual ~LessThan(); //Virtual destructor

        LessThan& operator = (const LessThan& other); //Assignment operator

        bool operator()(double val) const; //Round bracket operator, checks if input is less than threshold
};

#endif //LessThan_HPP