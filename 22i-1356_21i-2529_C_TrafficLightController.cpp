#include "TrafficLightController.h"
#include <iostream>

// Constructor definition
TrafficLightController::TrafficLightController() : currentLight(NORTH_SOUTH), timer(10), emergencyOverride(false) {}

void TrafficLightController::update() {
    if (!emergencyOverride) {
        timer--;
        if (timer <= 0) {
            switchLights();  // Now this function is properly declared and defined
            timer = 10;  // Reset the timer
        }
    }
}

LightState TrafficLightController::getCurrentLight() const {
    return currentLight;
}

void TrafficLightController::setEmergencyOverride(bool status) {
    emergencyOverride = status;
}

// Define switchLights() function here
void TrafficLightController::switchLights() {
    if (currentLight == NORTH_SOUTH) {
        currentLight = EAST_WEST;
    } else {
        currentLight = NORTH_SOUTH;
    }
    std::cout << "Light switched to: " << (currentLight == NORTH_SOUTH ? "North-South" : "East-West") << std::endl;
}

