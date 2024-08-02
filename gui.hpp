#ifndef GUI_H
#define GUI_H

#include "road.hpp"
#include "vehicle.hpp"
#include "map.hpp"
#include <iostream>
using namespace std;

class ISimOutput {
  public:
    virtual double GetSpeed(Vehicle& v) = 0;
};

class ISimInput {
  public:
    virtual void SetSpeedLimit(Vehicle& v, double speed) = 0;
};

class GUI : public ISimInput, public ISimOutput {
  public:
    virtual Road* CreateRoad(string name, double locx, double locy, double len, Heading hdg) = 0;
    virtual double GetSpeed(Vehicle& v) = 0;
    virtual void SetSpeedLimit(Vehicle& v, double speed) = 0;
    void update(Map*);
};

class MetricGUI : public GUI {
  public:
    Road* CreateRoad(string name, double locx, double locy, double len, Heading hdg) override;
    double GetSpeed(Vehicle& v) override;
    void SetSpeedLimit(Vehicle& v, double speed) override;
};

class ImperialGUI : public GUI {
  public:
    Road* CreateRoad(string name, double locx, double locy, double len, Heading hdg) override;
    double GetSpeed(Vehicle& v) override;
    void SetSpeedLimit(Vehicle& v, double speed) override;
};

#endif