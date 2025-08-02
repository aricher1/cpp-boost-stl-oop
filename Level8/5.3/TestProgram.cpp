// TestProgram.cpp
// The purpose of this file is to test our program.
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#include <iostream>
#include <string>
#include <boost/variant.hpp>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "MoveVisitor.hpp" //Header file for visitor class

using namespace AidanRicher::CAD;
using namespace std;

typedef boost::variant<Point, Line, Circle> ShapeType; //Typedef for a ShapeType variant

ShapeType CreateShape() { //Function to return the variant based on user input
    int choice; //User input
    cout << "What variant of Shape would you like to create?\n1. Point\n2. Line\n3. Circle" << endl;
    cout << "Your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: { //Point
            double x, y;
            cout << "Enter x and y for the Point: ";
            cin >> x >> y;
            return Point(x, y);
        } 
        case 2: { //Line
            double x1, y1, x2, y2;
            cout << "Enter start point of line (x1, y1): ";
            cin >> x1 >> y1;
            cout << "Enter end point of line (x2, y2): ";
            cin >> x2 >> y2;
            return Line(Point(x1, y1), Point(x2, y2));
        }
        case 3: { //Circle
            double cx, cy, r;
            cout << "Enter center point for Circle (x, y): ";
            cin >> cx >> cy;
            cout << "Enter radius of Circle: ";
            cin >> r;
            return Circle(Point(cx, cy), r);
        } 
        default: { //Invalid
            cout << "Invalid input. Returning defualt Point." << endl;
            return Point(); //Call defualt constructor
        }
    } 
}

int main() {
    ShapeType shape = CreateShape(); //User input
    cout << shape << endl; //Output

    //Visitor function params, move by this much
    double dx = 10.0; //X
    double dy = 20.0; //Y
    double dr = 30.0; //Radius
    MoveVisitor visitor(dx, dy, dr); //Create an instance of the visitor
    boost::apply_visitor(visitor, shape); //Apply the visitor

    cout << "Shape after applying visitor: " << shape << endl;
    
    /*
    //Try-catch for get<T>() function
    try {
        Line l = boost::get<Line>(shape);
        cout << l << endl;
    } catch (const boost::bad_get& e) {
        cout << "Error: " << e.what() << endl;
    }
    */

    return 0;
}