#Makefile for program 1 - video game library

all					:	Program1

Program1			:	Program1.o VideoGame.o VideoGameLibrary.o Text.o
						g++ -std=c++11 -o Program1.exe Program1.o VideoGame.o VideoGameLibrary.o Text.o

Program1.o			:	Program1.cpp
						g++ -std=c++11 -I ./ -c Program1.cpp
				
VideoGame.o			:	VideoGame.cpp
						g++ -std=c++11 -I ./ -c VideoGame.cpp
			
VideoGameLibrary.o	:	VideoGameLibrary.cpp
						g++ -std=c++11 -I ./ -c VideoGameLibrary.cpp
			
Text.o				:	Text.cpp
						g++ -std=c++11 -I ./ -c Text.cpp