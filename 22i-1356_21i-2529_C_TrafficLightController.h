#ifndef TRAFFICLIGHTCONTROLLER_H
#define TRAFFICLIGHTCONTROLLER_H

#include <string>

enum LightState { NORTH_SOUTH, EAST_WEST };

class TrafficLightController {
private:
    LightState currentLight;
    int timer;
    bool emergencyOverride;

public:
    TrafficLightController();  // Constructor declaration
    void update();             // update() function declaration
    LightState getCurrentLight() const; // getCurrentLight() function declaration
    void setEmergencyOverride(bool status);
    
    // Add this declaration for the switchLights function
    void switchLights();  // Declare switchLights() here
};

#endif

