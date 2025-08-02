// MoveVisitor.hpp
// Header file is for a visitor class derived from boost::static_visitor<T>
// Moves a shape by m_dx and m_dy coordinates
// Implemented in header file for simplicity
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#ifndef MoveVisitor_HPP
#define MoveVisitor_HPP

#include <boost/variant.hpp>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

namespace AidanRicher {
namespace CAD {

class MoveVisitor : public boost::static_visitor<void> {
    private:
        double m_dx, m_dy, m_dr; //X, Y, and Radius members
    
    public: 
        MoveVisitor(double dx, double dy, double dr) : m_dx(dx), m_dy(dy), m_dr(dr) {} //Parameter constructor
        
        //Create a () operator to visit each shape
        void operator () (Point& p) const { //Point shape
            p.X(p.X() + m_dx); //X coord
            p.Y(p.Y() + m_dy); //Y coord
        }

        void operator () (Line& l) const { //Line shape
            Point newP1 = l.P1(); //Start
            Point newP2 = l.P2(); //End
            newP1.X(newP1.X() + m_dx); //X_Start
            newP1.Y(newP1.Y() + m_dy); //Y_Start
            newP2.X(newP2.X() + m_dx); //X_End
            newP2.Y(newP2.Y() + m_dy); //Y_End
            l.P1(newP1);
            l.P2(newP2);
        }

        void operator () (Circle& c) const { //Circle shape
            Point newCenter = c.Center();
            newCenter.X(newCenter.X() + m_dx); //X_Center
            newCenter.Y(newCenter.Y() + m_dy); //Y_Center
            c.Center(newCenter); //Center
            c.Radius(c.Radius() + m_dr); //Radius
        }
};

} //Namespace CAD
} //Namespace AidanRicher

#endif //MoveVisitor_HPP