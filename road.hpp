#ifndef ROAD_H
#define ROAD_H
#include <iostream>
#include <map>
#include <list>
#include "sui.hpp"
using namespace std;

enum Heading { North, South, East, West };

class TrafficLight {
    private:
        char current = 'x';
        map<char, char> next;
        map<char, int> dur;
        int changeCounter;
        double location;
        void change();
        
    public:
        TrafficLight(double loc, int redDur, int yellowDur, int greenDur);
        void update();
        char getCurrent();
        double getLocation();

};

class IPrintDriver;
class Object;

class Road {
    private:
        string name;
        double length;
        double xlocation;
        double ylocation;
        Heading heading;

    public:
        static int NumOfRoads;
        list<TrafficLight*> lights;

        Road(string streetName, double locX, double locY, double len, Heading hdg);
        double GetLength();
        double GetXLocation();
        double GetYLocation();
        Heading GetHeading();
        string GetRoadName();
        void Print(IPrintDriver* print, Object* o);
        void addLight(double loc, int redDur, int yellowDur, int greenDur);
        void update();

};

#endif