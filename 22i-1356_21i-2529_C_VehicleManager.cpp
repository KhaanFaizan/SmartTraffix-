#include "VehicleManager.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

VehicleManager::VehicleManager() : nextId(1) {
    std::srand(std::time(0));
}

void VehicleManager::update() {
    std::lock_guard<std::mutex> lock(vehicleMutex);
    spawnVehicles();
    for (auto &vehicle : vehicles) {
        vehicle.speed += 5;
        if (vehicle.speed > 60 && vehicle.type == LIGHT)
            vehicle.hasChallan = true;
        else if (vehicle.speed > 40 && vehicle.type == HEAVY)
            vehicle.hasChallan = true;
    }
}

void VehicleManager::spawnVehicles() {
    Vehicle newVehicle;
    newVehicle.id = nextId++;
    int randomType = std::rand() % 3;
    newVehicle.type = (randomType == 0) ? LIGHT : (randomType == 1) ? HEAVY : EMERGENCY;
    newVehicle.speed = (newVehicle.type == LIGHT) ? 1 : (newVehicle.type == HEAVY) ? 2 : 3;
    newVehicle.hasChallan = false;

    vehicles.push_back(newVehicle);
    std::cout << "Spawned vehicle ID: " << newVehicle.id << ", Type: " << randomType << "\n";
}

std::vector<Vehicle> VehicleManager::getSpeedingVehicles() {
    std::lock_guard<std::mutex> lock(vehicleMutex);  // This is allowed now because vehicleMutex is no longer const
    std::vector<Vehicle> speedingVehicles;
    for (const auto &vehicle : vehicles) {
        if (vehicle.hasChallan)
            speedingVehicles.push_back(vehicle);
    }
    return speedingVehicles;
}

std::vector<Vehicle> VehicleManager::getVehicleQueue()  {
    std::lock_guard<std::mutex> lock(vehicleMutex);
    return vehicles;
}

std::vector<Vehicle> VehicleManager::getTrafficData() {
    std::lock_guard<std::mutex> lock(vehicleMutex);
    return vehicles;
}

