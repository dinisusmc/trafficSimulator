#ifndef COMMON_H
#define COMMON_H

#include <iostream>
using namespace std;

class Constants {
    public:
        static const double AccRate;
        static const double AccRateEmpty;
        static const double AccRateFull;
        static const double DecRate;
        static const double DecRateEmpty;
        static const double DecRateFull;
        static const double MpsToMph;
        static const double MpsToKph;
        static const double MetersToMiles;
        static const double MetersToKm;
        static const int CharMapSize;
        static const double WorldSize;
};


class Conversions {
    public: 
        static int WCpointToCCpoint(double val);
        static int WClengthToCClength(double val);
};

#endif