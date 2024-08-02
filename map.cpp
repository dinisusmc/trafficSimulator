#include "map.hpp"
#include "sui.hpp"
#include "road.hpp"

Map::Map() {}

void Map::AddRoad(Road* road) {
    roads.push_back(road);
}

void Map::Print(IPrintDriver* pd, Object* o) {
    for (Road* road : roads) {
        road->Print(pd, o);
    }
}

void Map::update() {
    for (Road* road : roads) {
        road->update();
    }
}
