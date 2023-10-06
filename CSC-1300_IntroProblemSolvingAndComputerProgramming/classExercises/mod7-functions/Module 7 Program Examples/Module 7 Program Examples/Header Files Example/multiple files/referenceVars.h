/*********************************************************************************
	Title:  	referenceVars.h
	Author:  	April Crockett
	Date:		10/20/2021
	
	Purpose:  	This is the header file for my program.
				A program can require multiple header files from either
				the C++ library or that are on the local machine.
				
				The header file typically contains the C++ library files
				that need included, the namespaces required,
				function prototypes of programmer-defined functions,
				and any programmer-defined data types.
				
				Note that we have not yet learned how to create 
				programmer-defined data types....that will come
				later in this semester.
*********************************************************************************/

/*
	Any line that begins with a '#' is a preprocessor directive. The
	preprocessor will eximine the code before actual compilation of code begins
	and resolves all these directives before any code is actually generated
	by regular statements.  They must only extend across a single line of code.
*/

/*
	#ifndef & #define preprocessor directives are the beginning of an 
	include guard.
	Include guards make sure you do not include a file multiple times, which
	would cause definition syntax errors.  
	More information:  http://cplusplus.com/forum/general/71787/
	
	These should always be the first thing in all header files (ignoring comments)
*/

#ifndef REFERENCEVARS_H
#define REFERENCEVARS_H

#include <iostream>
using namespace std;

// Function prototypes. 
//Both functions use reference variables as parameters.
void doubleNum(int &);
void getNum(int &);

//the line below ends the include guard and should always be the very
//last thing in the header file.
#endif