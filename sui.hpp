#ifndef SUI_H
#define SUI_H

#include <vector>
#include "vehicle.hpp"
#include "road.hpp"
using namespace std;

class Road;
class Car;

class Object {
    public:
        virtual ~Object() = 0;
};

class CharMatrix : public Object {
    public:
        vector<vector<char> > map;    
        CharMatrix();                       
};

class IPrintDriver {
    public:
        ~IPrintDriver() = default;
        virtual void PrintRoad(Road* road, Object* o) = 0;
        virtual void PrintCar(Car* car, Object* o) = 0;
};

class ConsolePrint : public IPrintDriver {
    public:
        ~ConsolePrint() = default;
        void PrintRoad(Road* road, Object* o);
        void PrintCar(Car* car, Object* o);
        char lightCheck(char curChar, char roadSym);
};


#endif
