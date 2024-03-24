all			:	Zoo

Zoo			:	Creature.o Zoo.o CreatureBinaryTree.o
				g++ -o Zoo.exe Creature.o Zoo.o CreatureBinaryTree.o
				
Creature.o	:	Creature.cpp
				g++ -I ./ -c Creature.cpp
				
Zoo.o		:	Zoo.cpp
				g++ -I ./ -c Zoo.cpp

CreatureBinaryTree.o	:	CreatureBinaryTree.cpp
							g++ -I ./ -c CreatureBinaryTree.cpp
				
clean		:	Zoo.exe
				del *.o
				del Zoo.exe