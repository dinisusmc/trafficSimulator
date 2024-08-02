#include "vehicle.hpp"
#include "common.hpp"
#include <iostream>
using namespace std;

double Vehicle::GetCurrentSpeed() {
	return currentSpeed;
}

void Vehicle::SetDesiredSpeed(double mph) {
	desiredSpeed = mph;
}

void Vehicle::SetCurrentSpeed(double speed) {
	if (currentSpeed <= speed) { 
		if (speed > desiredSpeed) currentSpeed = desiredSpeed;
		else currentSpeed = speed;
	}
	else {                 
		if (speed < desiredSpeed) currentSpeed = desiredSpeed;
		else currentSpeed = speed;
	}
}

void Vehicle::UpdateSpeed(int seconds) {
	if (currentSpeed > desiredSpeed) Decelerate(seconds);
	else if (currentSpeed < desiredSpeed) Accelerate(seconds);
}

void Car::Accelerate(int secondsDelta) {
	SetCurrentSpeed(GetCurrentSpeed() + Constants::AccRate * secondsDelta);
}

void Car::Decelerate(int secondsDelta) {
	SetCurrentSpeed(GetCurrentSpeed() - Constants::DecRate * secondsDelta);
}

Truck::Truck(int weight) {
	loadWeight = weight;
}

void Truck::Accelerate(int secondsDelta) {
	if (loadWeight <= 5) SetCurrentSpeed(GetCurrentSpeed() + Constants::AccRateEmpty * secondsDelta);
	else SetCurrentSpeed(GetCurrentSpeed() + Constants::AccRateFull * secondsDelta);
}

void Truck::Decelerate(int secondsDelta) {
	if (loadWeight <= 5) SetCurrentSpeed(GetCurrentSpeed() - Constants::DecRateEmpty * secondsDelta);
	else SetCurrentSpeed(GetCurrentSpeed() - Constants::DecRateFull * secondsDelta);
}