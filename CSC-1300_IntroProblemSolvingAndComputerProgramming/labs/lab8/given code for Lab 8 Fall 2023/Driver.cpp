/*******************************************************************
	Title:   Driver.cpp
	Author:  April R. Crockett
	Date:    October 20, 2023
	Purpose: This program allows the user to enter in
	         10 elephant's names and consumption of each elephant
	         per month.  The program finds & prints the total
	         and average number of pounds eaten by all the 
			 elephants as well as the name & consumption amount of
	         the elephant that eats the most.
********************************************************************/

int main()
{
	char zooName[100];
	float elephantFood[SIZE];
	string elephantNames[SIZE];
	float total, average;
	int highestIndex;
	
	cout << "\n\nHello!  What is the name of your elephant zoo?\n";
	getline(cin, zooName, 100);
	
	getElephantData(elephantFood, elephantNames);
	getStats(elephantFood, total, average, highestIndex);
	
	cout << "-----------------------------------------------------------------";
	cout << "\nThe total amount of food consumed by all " << SIZE << " elephants\nat ";
	cout << << " is " << total << " pounds in one month.\n\n";
	cout << "The average amount of food consumed at\n" << zooName;
	cout << " is " << average << " pounds.";
	cout << "\n\nThe elephant who eats the most (" << elephantFood;
	cout << " pounds) is " << elephantNames[];
	cout << "!!\n";
	cout << "-----------------------------------------------------------------";
	cout << "\n\n";
	return 0;
}