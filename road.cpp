#include "road.hpp"
#include "sui.hpp"
using namespace std;
#include <iostream>


TrafficLight::TrafficLight(double loc, int redDur, int yellowDur, int greenDur){
	location=loc;
	next['o'] = '-'; 
	next['-'] = 'x';
	next['x'] = 'o';
	dur['o'] = greenDur;
	dur['-'] = yellowDur;
	dur['x'] = redDur;
	changeCounter = redDur;
}

void TrafficLight::change(){
	current = next[current];
	changeCounter = dur[current];
}

void TrafficLight::update(){
	changeCounter -= 1;
	if (changeCounter < 1){
		change();
	}
}

char TrafficLight::getCurrent(){
	return current;
}

double TrafficLight::getLocation(){
	return location;
}


int Road::NumOfRoads = 0;

Road::Road(std::string streetName, double locX, double locY, double len, Heading hdg) {
	name = streetName;
	length = len;
	heading = hdg;
	xlocation = locX;
	ylocation = locY;
	NumOfRoads++;
}

double Road::GetLength() {
	return length;
}

double Road::GetXLocation() {
	return xlocation;
}

double Road::GetYLocation() {
	return ylocation;
}

Heading Road::GetHeading() {
	return heading;
}

string Road::GetRoadName() {
	return name;
}

void Road::Print(IPrintDriver* print, Object* o) {
	print->PrintRoad(this, o);
}

void Road::addLight(double loc, int redDur, int yellowDur, int greenDur){
	lights.push_back(new TrafficLight(loc, redDur, yellowDur, greenDur));
}

void Road::update(){
	for (auto i:lights){
		i->update();
	}

}