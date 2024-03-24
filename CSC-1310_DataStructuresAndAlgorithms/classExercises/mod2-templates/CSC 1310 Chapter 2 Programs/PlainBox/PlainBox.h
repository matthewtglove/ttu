/*
	Title:  PlainBox.h
*/

#ifndef PLAINBOX_H
#define PLAINBOX_H

//class declaration
template<typename ItemType> 
class PlainBox
{
	private:
		ItemType item;
	   
	public:
		PlainBox();
		PlainBox(const ItemType& theItem);
		void setItem(const ItemType& theItem);

		ItemType getItem() const;
}; 

#include "PlainBox.cpp"

#endif










