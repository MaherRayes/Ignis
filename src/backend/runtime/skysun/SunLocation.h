#pragma once

#include "ElevationAzimuth.h"

namespace IG {

// Default is Saarbruecken 2020.05.06 12:00:00 (midday)
// which results in Elevation: 52.87 Azimuth: 323.271 (west of south)
struct TimePoint {
    int Year      = 2020;
    int Month     = 5;
    int Day       = 6;
    int Hour      = 12;
    int Minute    = 0;
    float Seconds = 0.0f;
};

struct MapLocation {
    float Longitude = -6.9965744f; // Degrees west
    float Latitude  = 49.235422f;  // Degrees north
    float Timezone  = -2;          // Offset to UTC
};

ElevationAzimuth computeSunEA(const TimePoint& timepoint, const MapLocation& location);
} // namespace IG