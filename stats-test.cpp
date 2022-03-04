#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"
#include "alerter.h"

#include <cmath>

TEST_CASE("reports average, minimum and maximum") {
    std::vector<float> data{1.5, 8.9, 3.1, 4.5};
    auto computedStats = Statistics::ComputeStatistics(data);
    float epsilon = 0.001;
    REQUIRE(std::abs(computedStats.m_avg  - 4.5) < epsilon);
    REQUIRE(std::abs(computedStats.m_max  - 8.9) < epsilon);
    REQUIRE(std::abs(computedStats.m_min  - 1.5) < epsilon);
}

TEST_CASE("average is NaN for empty array") {
    std::vector<float> data;
    auto computedStats = Statistics::ComputeStatistics(data);
    //All fields of computedStats (average, max, min) must be
    //NAN (not-a-number), as defined in math.h
    
    //Design the REQUIRE statement here.
    //Use http://www.cplusplus.com/reference/cmath/isnan/
    
    REQUIRE(isnan(computedStats.m_avg));
    REQUIRE(isnan(computedStats.m_max));
    REQUIRE(isnan(computedStats.m_min));
}

TEST_CASE("raises alerts when max is greater than threshold") {
    EmailAlert emailAlert;
    LEDAlert ledAlert;
    std::vector<IAlerter*> alerters = {&emailAlert, &ledAlert};
    
    const float maxThreshold = 10.2;
    StatsAlerter statsAlerter(maxThreshold, alerters);
    statsAlerter.checkAndAlert({99.8, 34.2, 4.5, 6.7});

    REQUIRE(emailAlert.emailSent == 1);
    REQUIRE(ledAlert.ledGlows == 1);
}
