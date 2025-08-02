// TestProgram.cpp
// The purpose of this file is to test our program.
// CPP Certificate
// Author: Aidan Richer
// Date: Aug 2, 2025

#include <iostream>
#include <boost/shared_ptr.hpp>
#include "Array.hpp"
#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

using namespace AidanRicher::Containers;
using namespace AidanRicher::CAD;
using namespace std;

typedef boost::shared_ptr<Shape> ShapePtr;
typedef Array<ShapePtr> ShapeArray;

int main() {
    ShapeArray shapeArr(3); //Create an array to hold shared_ptrs
    
    //Assign values to shapes
    shapeArr[0] = ShapePtr(new Point(1.2, 4.3));
    shapeArr[1] = ShapePtr(new Line(Point(4.0, 3.0), Point(3.0, 1.0)));
    shapeArr[2] = ShapePtr(new Circle(Point(2.0, 2.0), 3.14));

    //Print each shape
    cout << "Printing shapes in array with smart pointers: " << endl;
    for (int i = 0; i < shapeArr.Size(); ++i) {
        cout << *shapeArr[i] << endl;
        cout << "Pointer address at index " << i << shapeArr[i].get() << endl;
    }

    cout << "Calling destructors automatically" << endl;
    //Destructor messages called

    return 0;
}