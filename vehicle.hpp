#ifndef VEHICLE_H
#define VEHICLE_H


#include "road.hpp"
#include <iostream>


class Vehicle {
  private:
    double currentSpeed = 0.0;
    double desiredSpeed;

  protected:
    virtual void Accelerate(int secondsDelta) = 0;
    virtual void Decelerate(int secondsDelta) = 0;

  public:
    double GetCurrentSpeed();
    void SetDesiredSpeed(double mph);
    void SetCurrentSpeed(double speed);
    void UpdateSpeed(int seconds);
};

class Car : public Vehicle {
  protected:
    void Accelerate(int secondsDelta) override;
    void Decelerate(int secondsDelta) override;
};

class Truck : public Vehicle {
  private:
    int loadWeight; 

  protected:
    void Accelerate(int secondsDelta) override;
    void Decelerate(int secondsDelta) override;

  public:
    Truck(int weight);
};

#endif