#include "sui.hpp"
#include "common.hpp"
#include "vehicle.hpp"
#include "road.hpp"
#include <vector>
using namespace std;

Object::~Object(){}

CharMatrix::CharMatrix() {
	for (int i = 0; i < Constants::CharMapSize; i++) {
		vector<char> tempVec;
		for (int j = 0; j < Constants::CharMapSize; j++) {
			tempVec.push_back(' ');
		}
		map.push_back(tempVec);
	}
}

char ConsolePrint::lightCheck(char curChar, char roadSym){
	if (curChar == ' '){
		return roadSym;
	}
	if (curChar == 'x' || curChar == '-' || curChar == 'x'){
		return curChar;
	}
	return roadSym;
}

void ConsolePrint::PrintRoad(Road* road, Object* o) {
	CharMatrix* cm = dynamic_cast<CharMatrix*>(o); //// Instatiation object of type charmatrix ////
	int x;
	int y;
	int CCx = Conversions::WCpointToCCpoint(road->GetXLocation());
	int CCy = Conversions::WCpointToCCpoint(road->GetYLocation());
	int distance = 0;
	int CCRoadLength = Conversions::WClengthToCClength(road->GetLength());

	cout << "ccx: " << CCx << endl << "ccy: " << CCy << endl << "Road Len: " << CCRoadLength << endl << "light count: " << road->lights.size() << endl;

    //Printing from bottom left coordinat (ccx, ccy) for len of road
	switch (road->GetHeading()) {
	case North:
		x = CCx;
		if (x >= 0 && x < Constants::CharMapSize) {
			while (distance < CCRoadLength) {
				y = (int)(CCy - distance);
				if (y >= 0 && y < Constants::CharMapSize) {
					cm->map[y][x] = '|';
					cm->map[y][x + 2] = lightCheck(cm->map[y][x + 2], '|');
					cm->map[y][x + 4] = '|';
				}
				distance++;
			}
			for (auto light:road->lights){
				cm->map[CCy-(CCRoadLength*light->getLocation())][x+2] = light->getCurrent();
			}
			
		}
		break;
	case South:
		break;
	case East:
		y = CCy;
		if (y >= 0 && y < Constants::CharMapSize) {
			while (distance < CCRoadLength) {
				x = (CCx + distance);
				if (x >= 0 && x < Constants::CharMapSize) {
					cm->map[y][x] = '_';
					cm->map[y + 2][x] = lightCheck(cm->map[y + 2][x], '_');
					cm->map[y + 4][x] = '_';
				}
				distance++;
			}
			for (auto light:road->lights){
				cm->map[y+2][CCx+(CCRoadLength*light->getLocation())] = light->getCurrent();
			}
		}
		break;
	case West:
		break;
	default:
		break;
	}

}

void ConsolePrint::PrintCar(Car* car, Object* o) {}