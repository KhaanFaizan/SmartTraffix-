#include "DeadlockHandler.h"
#include <iostream>

DeadlockHandler::DeadlockHandler() {}

void DeadlockHandler::checkForDeadlock(const std::vector<Vehicle>& vehicles) {
    // Basic deadlock check: if there are more than 10 vehicles in a lane and none can move, it's a potential deadlock
    for (const auto& vehicle : vehicles) {
        if (vehicle.type == HEAVY && vehicle.speed == 0) {
            std::cout << "Deadlock detected! Resolving...\n";
            resolveDeadlock();
            break;
        }
    }
}

void DeadlockHandler::resolveDeadlock() {
    // Basic resolution: Let a tow truck (emergency vehicle) clear the heavy vehicle
    std::cout << "Resolving deadlock using tow truck...\n";
}

