/*
	This program was created to randomly generate songs in the manySongs.txt
	text file so that we could have over 100,000 songs in the file without me taking
	80 years of my life to type in all the song data.  
	
	You do not need to modify or use this file.  I am only including it if you 
	were curious how & why I did this.
*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

string generate_random_string(int);

int main()
{
	ofstream outFile;
	srand(time(0));
	
	outFile.open("manySongs.txt", ios::app); //open file in append mode
	int counter = 0;
	while(counter < 50000)
	{
		//write movie title to file
		outFile << generate_random_string(50) << endl; 
		
		//write artist to file
		outFile << generate_random_string(20) << endl; 
		
		//write time to file
		outFile << setprecision(2) << fixed << (3.0 + rand() / double(RAND_MAX)) << endl;
		
	
		counter++;
	}
	outFile.close();
	outFile.clear();
	
	return 0;
}

string generate_random_string(int max_length)
{
	const string alphabet = "ABCEDEFHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz ";
	
	int stringLength = 1 + rand() % max_length;
	//cout << "\nString Length: " << stringLength << endl;
	int index;
	
	string generatedString = "";
	index = rand() % 25; 
	generatedString += alphabet[index];
	for(int x=1; x<stringLength; x++)
	{
		index = rand() % 54;  //55 is length of alphabet string
		generatedString += alphabet[index];
	}
	//cout << "\nGenerated String: " << generatedString << endl;
	return generatedString;
}