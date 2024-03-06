all				:	TravelAgent

TravelAgent		:	TravelAgent.o
					g++ -std=c++11 -o TravelAgent TravelAgent.o
				
TravelAgent.o	:	TravelAgent.cpp
					g++ -std=c++11 -I ./ -c TravelAgent.cpp

### Compiling on Windows with Zig
# TravelAgent		:	TravelAgent.o
# 					zig c++ -std=c++11 -o TravelAgent TravelAgent.o -target x86_64-windows-gnu
				
# TravelAgent.o	:	TravelAgent.cpp
# 					zig c++ -std=c++11 -I ./ -c TravelAgent.cpp -target x86_64-windows-gnu					