#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include <SFML/Graphics.hpp>
#include "QueueManager.h"
#include "TrafficLightController.h"
#include "VehicleManager.h"

class Visualization {
private:
    sf::RenderWindow &window;
    TrafficLightController &trafficLightController;
    VehicleManager &vehicleManager;
    QueueManager &queueManager;  // Make sure QueueManager is passed

public:
    Visualization(sf::RenderWindow &win, TrafficLightController &tlc, VehicleManager &vm, QueueManager &qm);
    void render();
};

#endif

