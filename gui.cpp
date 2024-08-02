#include "gui.hpp"
#include "road.hpp"
#include "common.hpp"
#include "vehicle.hpp"
#include "map.hpp"
#include <iostream>
using namespace std;


void GUI::update(Map* gui){
	gui->update();
}

Road* MetricGUI::CreateRoad(string name, double locx, double locy, double len, Heading hdg) {
	//return Road(name, locx / Constants::MetersToKm, locy / Constants::MetersToKm, len / Constants::MetersToKm, hdg);
	return new Road(name, locx, 1.0-locy, len, hdg);
}

double MetricGUI::GetSpeed(Vehicle& v) {
	return v.GetCurrentSpeed() * Constants::MpsToKph;
}

void MetricGUI::SetSpeedLimit(Vehicle& v, double speed) {
	v.SetDesiredSpeed(speed / Constants::MpsToKph);
}

Road* ImperialGUI::CreateRoad(string name, double locx, double locy, double len, Heading hdg) {
	//return Road(name, locx / Constants::MetersToMiles, locy / Constants::MetersToMiles, len / Constants::MetersToMiles, hdg);
	return new Road(name, locx, 1.0 - locy, len, hdg);
}

double ImperialGUI::GetSpeed(Vehicle& v) {
	return v.GetCurrentSpeed() * Constants::MpsToMph;
}

void ImperialGUI::SetSpeedLimit(Vehicle& v, double speed) {
	v.SetDesiredSpeed(speed / Constants::MpsToMph);
}