#ifndef VEHICLEMANAGER_H
#define VEHICLEMANAGER_H

#include <vector>
#include <string>
#include <mutex>

enum VehicleType { LIGHT, HEAVY, EMERGENCY };

struct Vehicle {
    int id;
    VehicleType type;
    int speed;
    bool hasChallan;
};

class VehicleManager {
private:
    std::vector<Vehicle> vehicles;
    int nextId;
    std::mutex vehicleMutex;

public:
    VehicleManager();
    void update();
    void spawnVehicles();
    std::vector<Vehicle> getSpeedingVehicles() ;
    std::vector<Vehicle> getVehicleQueue() ;
    std::vector<Vehicle> getTrafficData() ;
};

#endif
