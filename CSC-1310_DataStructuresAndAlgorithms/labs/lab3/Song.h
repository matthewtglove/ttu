/////////////////////////////
// Song class
/////////////////////////////
#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>
using namespace std;

class Song
{

	private:
		string title;
		string artist;
		float length;		

	public:
		Song() 
		{
		}
	
		Song(string t, string a, float len ) 
		{
			title = t;
			artist = a;
			length = len;
		}

		//***********************ACCESSOR FUNCTIONS***************************
		string getTitle() const
		{
			return title;
		}
		string getArtist() const
		{
			return artist;
		}
		float getLength() const
		{
			return length;
		}
		
		//***********************MUTATOR FUNCTIONS***************************
		void setTitle(string t)
		{
			title = t;
		}
		void setArtist(string a)
		{
			artist = a;
		}
		void setLength(float len)
		{
			length = len;
		}
		
		//***********************OVERLOADED OPERATORS***************************
		
		friend ostream &operator << (ostream &strm, Song &s)
		{
			strm << "Song Title: " << s.title << "\nArtist: " << s.artist << "\nSong Length: " << s.length << endl << endl;
			return strm;
		}
};

#endif