#include "QueueManager.h"
#include <iostream>

QueueManager::QueueManager() : lanes(4, std::queue<Vehicle>()) {} // 4 directions: N, S, E, W

void QueueManager::update(const std::vector<Vehicle>& vehicles) {
    std::lock_guard<std::mutex> lock(queueMutex);

    for (const auto& vehicle : vehicles) {
        int direction = vehicle.id % 4; // Assign to a direction (0=N, 1=S, 2=E, 3=W)

        if (lanes[direction].size() < laneCapacity) {
            lanes[direction].push(vehicle);
        } else {
            std::cout << "Lane " << direction << " is full. Vehicle " << vehicle.id << " is waiting.\n";
        }
    }

    prioritizeEmergencyVehicles();
}

void QueueManager::prioritizeEmergencyVehicles() {
    for (auto& lane : lanes) {
        std::queue<Vehicle> tempQueue;
        while (!lane.empty()) {
            Vehicle v = lane.front();
            lane.pop();
            if (v.type == EMERGENCY) {
                tempQueue.push(v);
            }
        }
        // Add remaining vehicles back to the queue
        while (!tempQueue.empty()) {
            lane.push(tempQueue.front());
            tempQueue.pop();
        }
    }
}

std::vector<std::queue<Vehicle>> QueueManager::getLanes()  {
    std::lock_guard<std::mutex> lock(queueMutex);
    return lanes;
}
