#ifndef DEADLOCKHANDLER_H
#define DEADLOCKHANDLER_H

#include <vector>
#include "VehicleManager.h"

class DeadlockHandler {
public:
    DeadlockHandler();
    void checkForDeadlock(const std::vector<Vehicle>& vehicles);
    void resolveDeadlock();
};

#endif

