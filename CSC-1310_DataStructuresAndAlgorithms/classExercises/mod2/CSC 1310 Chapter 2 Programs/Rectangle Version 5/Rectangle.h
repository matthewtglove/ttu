// Specification file for the Rectangle class
// This version has a constructor.
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
using namespace std;

class Rectangle
{
   private:
      double width;
      double length;
   public:
      Rectangle(double, double);	//Constructor
	  ~Rectangle()					//Destructor
	  {
		  cout << "\nI am in the destructor!\n";
	  }
      void setWidth(double);
      void setLength(double);
      
      double getWidth() const
         { return width; }

      double getLength() const
         { return length; }

      double getArea() const
         { return width * length; }
};
#endif