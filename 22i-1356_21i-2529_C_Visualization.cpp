#include <iostream>  // Include to use std::cerr for error handling
#include "Visualization.h"

Visualization::Visualization(sf::RenderWindow &win, TrafficLightController &tlc, VehicleManager &vm, QueueManager &qm)
    : window(win), trafficLightController(tlc), vehicleManager(vm), queueManager(qm) {}

void Visualization::render() {
    window.clear();  // Clear the window before drawing new content

    // **Draw Roads**
    sf::RectangleShape roadNS(sf::Vector2f(600, 50));  // 600x50 for North-South road
    roadNS.setFillColor(sf::Color(150, 150, 150));  // Gray color for the road
    roadNS.setPosition(150, 100);  // Position for the North-South road
    window.draw(roadNS);

    // East-West Road (Vertical)
    sf::RectangleShape roadEW(sf::Vector2f(50, 600));  // 50x600 for East-West road
    roadEW.setFillColor(sf::Color(150, 150, 150));  // Gray color for the road
    roadEW.setPosition(100, 150);  // Position for the East-West road
    window.draw(roadEW);

    // **Render Lanes**
    sf::RectangleShape lane(sf::Vector2f(50, 100));  // Lane size (50x100 for lanes)
    lane.setFillColor(sf::Color(0, 0, 255));  // Blue color for lanes

    // North-South Lanes (2 lanes for the North-South road)
    lane.setPosition(150, 200);  // Position for the first lane (North-South)
    window.draw(lane);

    lane.setPosition(200, 200);  // Position for the second lane (North-South)
    window.draw(lane);

    // East-West Lanes (2 lanes for the East-West road)
    lane.setSize(sf::Vector2f(100, 50));  // Adjust size for East-West lanes
    lane.setPosition(100, 150);  // Position for the first lane (East-West)
    window.draw(lane);

    lane.setPosition(100, 200);  // Position for the second lane (East-West)
    window.draw(lane);

    // **Render Traffic Lights**
    sf::CircleShape light(20);  // Create a circular shape for the traffic light
    light.setFillColor(trafficLightController.getCurrentLight() == NORTH_SOUTH ? sf::Color::Green : sf::Color::Red);
    light.setPosition(350, 220);  // Position the traffic light at the intersection
    window.draw(light);

    // **Render Vehicles**
    for (const auto &vehicle : vehicleManager.getTrafficData()) {
        sf::CircleShape vehicleShape(10);  // Vehicle shape (circle)
        vehicleShape.setFillColor(vehicle.type == LIGHT ? sf::Color::Blue :
                                  vehicle.type == HEAVY ? sf::Color::Red : sf::Color::Yellow);
        vehicleShape.setPosition(300 + vehicle.id * 15, 300);  // Position vehicles based on their ID
        window.draw(vehicleShape);
    }

    // **Render Vehicle Queue Text**
    sf::Font font;
    if (!font.loadFromFile("/home/faizan588/Desktop/Project/arial/ARIAL.TTF")) {
        std::cerr << "Error loading font!" << std::endl;  // Error message if font is not loaded
    }

    sf::Text queueText("Vehicles in Queue: " + std::to_string(queueManager.getLanes()[0].size()), font, 20);
    queueText.setPosition(20, 500);  // Position for queue text
    window.draw(queueText);  // Draw the text on the window

    window.display();  // Display the window contents
}

