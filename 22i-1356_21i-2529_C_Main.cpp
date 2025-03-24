#include <SFML/Graphics.hpp>
#include "TrafficLightController.h"
#include "VehicleManager.h"
#include "Visualization.h"
#include "QueueManager.h"
#include "ChallanGenerator.h"
#include "AnalyticsManager.h"
#include "DeadlockHandler.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SmartTraffix");
    window.setFramerateLimit(60);

    TrafficLightController trafficLightController;
    VehicleManager vehicleManager;
    QueueManager queueManager;
    Visualization visualization(window, trafficLightController, vehicleManager, queueManager);
    ChallanGenerator challanGenerator;
    AnalyticsManager analyticsManager;
    DeadlockHandler deadlockHandler;

    sf::Clock simulationClock;
    bool isRunning = true;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (isRunning) {
            trafficLightController.update();
            vehicleManager.update();
            queueManager.update(vehicleManager.getVehicleQueue());
            challanGenerator.processSpeedingVehicles(vehicleManager.getSpeedingVehicles());
            analyticsManager.collect(vehicleManager.getTrafficData());
            deadlockHandler.checkForDeadlock(vehicleManager.getVehicleQueue());

            if (simulationClock.getElapsedTime().asSeconds() >= 300) {
                isRunning = false; // Stop simulation after 5 minutes
            }
        }

        window.clear();
        visualization.render();
        window.display();
    }

    analyticsManager.displayFinalAnalytics();
    return 0;
}

