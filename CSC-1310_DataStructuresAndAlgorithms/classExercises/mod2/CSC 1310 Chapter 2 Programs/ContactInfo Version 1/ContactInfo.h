// Specification file for the ContactInfo class.
#ifndef CONTACTINFO_H
#define CONTACTINFO_H

#include <cstring>	// Needed for strlen and strcpy
#include <iostream>
using namespace std;

// ContactInfo class declaration.
class ContactInfo
{
	private:
		const char *name;	// The contact's name
		const char *phone;	// The contact's phone number
	public:
		// Constructor
		ContactInfo(char *n, char *p)
		{ 
			char * tempArrayName;
			char * tempArrayPhone;
			
			// Allocate just enough memory for the name and phone number.
			tempArrayName = new char[strlen(n) + 1];
			tempArrayPhone = new char[strlen(p) + 1];

			// Copy the name and phone number to the allocated memory.
			strcpy(tempArrayName, n);
			strcpy(tempArrayPhone, p); 
			
			//set the name & phone pointer attribute to the new arrays
			this->name = tempArrayName;
			this->phone = tempArrayPhone;
		}

		// Destructor
		~ContactInfo()
		{ 
			delete [] name;
			delete [] phone; 
		}

		const char *getName() const
		{ 
			return name; 
		}

		const char *getPhoneNumber() const
		{ 
			return phone; 
		}	
		
		//overloaded << operator
		friend ostream & operator << (ostream& os, const ContactInfo& c)
		{
			os << "\n\nNAME:  " << c.name << "\n" << "PHONE NUMBER:  " << c.phone;
			return os;
		}
};
#endif 