#ifndef MAP_H
#define MAP_H

#include <list>
#include "road.hpp"
#include "sui.hpp"
using namespace std;

class Map {
        private:
            list<Road*> roads;

        public:
            Map();
            void AddRoad(Road* road);
            void Print(IPrintDriver* pd, Object* o);
            void update();
};

#endif