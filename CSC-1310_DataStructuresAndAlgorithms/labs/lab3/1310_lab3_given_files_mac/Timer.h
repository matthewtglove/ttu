/*
	Filename:  Timer.h
	Author:  Dr. Brown, modified by April Crockett
	Date:  3/14/2018
	Purpose:  provides function to get the current time and get the total time given an
		end and start time.
*/
#include <ctime>
#include <cmath>
#include <cstdlib>

/*
	Pre: None
	Post: Returns the current system time
*/
time_t getTime();
/*
	Pre: start and end are variables of type time_t containing 2 different system times, start is before end
	Post: Will return the number of seconds separating two times
*/
double totalTime (time_t start, time_t end);
