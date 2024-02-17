#include "Timer.h"

using namespace std;

time_t getTime()
{
	return time(NULL);
}

double totalTime (time_t start, time_t end)
{
	return difftime (end, start);
}