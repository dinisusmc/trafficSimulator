#include "common.hpp"

const double Constants::AccRate = 3.5;          // Acceleration rate for cars in m/s
const double Constants::AccRateEmpty = 2.5;     // Acceleration rate for light trucks in m/s
const double Constants::AccRateFull = 1.0;      // Acceleration rate for heavy trucks in m/s
const double Constants::DecRate = 7.0;          // Braking rate for cars in m/s
const double Constants::DecRateEmpty = 5.0;     // Braking rate for light trucks in m/s
const double Constants::DecRateFull = 2.0;      // Braking rate for light trucks in m/s
const double Constants::MpsToMph = 2.237;
const double Constants::MpsToKph = 3.6;
const double Constants::MetersToMiles = 0.000621371;
const double Constants::MetersToKm = 0.001;
const int Constants::CharMapSize = 50;
const double Constants::WorldSize = 200.0;

            
int Conversions::WCpointToCCpoint(double val) {
    //return val * (Constants::CharMapSize / Constants::WorldSize) + (Constants::CharMapSize / 2);
    return val * Constants::CharMapSize;
}

int Conversions::WClengthToCClength(double val) {
    //return val * (Constants::CharMapSize / Constants::WorldSize);
    return val * Constants::CharMapSize;
}
