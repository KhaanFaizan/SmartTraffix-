#ifndef CHALLANGENERATOR_H
#define CHALLANGENERATOR_H

#include <vector>
#include <string>
#include <mutex>
#include "VehicleManager.h"

struct Challan {
    int challanId;
    int vehicleId;
    int fineAmount;
    std::string status; // Paid, Unpaid, Overdue
};

class ChallanGenerator {
private:
    std::vector<Challan> challans;
    std::mutex challanMutex;
    int nextChallanId;

public:
    ChallanGenerator();
    void processSpeedingVehicles(const std::vector<Vehicle>& speedingVehicles);
    void updateChallanStatus(int challanId, const std::string& status);
    std::vector<Challan> getChallans() ;
};

#endif
