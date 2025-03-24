#ifndef QUEUEMANAGER_H
#define QUEUEMANAGER_H

#include <queue>
#include <vector>
#include <mutex>
#include "VehicleManager.h"

class QueueManager {
private:
    std::vector<std::queue<Vehicle>> lanes; // Two lanes for each direction
    std::mutex queueMutex;
    const int laneCapacity = 10;

public:
    QueueManager();
    void update(const std::vector<Vehicle>& vehicles);
    void prioritizeEmergencyVehicles();
    std::vector<std::queue<Vehicle>> getLanes();
};

#endif
