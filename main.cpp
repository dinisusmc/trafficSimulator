#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h> 
#include "vehicle.hpp"
#include "common.hpp"
#include "map.hpp"
#include "sui.hpp"
#include "gui.hpp"
using namespace std;

void Clear(){
	#if defined _WIN32
		system("cls");
		//clrscr(); // including header file : conio.h
	#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
		system("clear");
		//std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
	#elif defined (__APPLE__)
		system("clear");
	#endif
}


int main() {
	
	GUI* simInput;
	simInput = new MetricGUI();
	IPrintDriver* cp = new ConsolePrint();
	CharMatrix* cm = new CharMatrix();
	Map map;

	// Creating road pointers and adding them to the map
	Road* Uptown = simInput->CreateRoad("Uptown", .5, 0, 1.0, Heading::North);
	Uptown->addLight(.7, 5, 5, 5);
	Uptown->addLight(.3, 3, 3, 3);
	map.AddRoad(Uptown);

	Road* Crosstown = simInput->CreateRoad("Crosstown", 0, 0.5, 1.0, Heading::East);
	Crosstown->addLight(.5, 7, 7, 7);
	map.AddRoad(Crosstown);
	

	while (true){
		//map saves to the char matrix
		map.Print(cp, cm);

		// printing the char matrix
		for (int i = 0; i < Constants::CharMapSize; i++) {
			string s = "";
			for (int j = 0; j < Constants::CharMapSize; j++) {
				s = s + cm->map[i][j];
			}
			cout << s << endl;
		}

		this_thread::sleep_for(chrono::seconds(1));
		map.update();
		
		Clear();

	}
}
