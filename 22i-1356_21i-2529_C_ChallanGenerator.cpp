#include "ChallanGenerator.h"
#include <iostream>

ChallanGenerator::ChallanGenerator() : nextChallanId(1) {}

void ChallanGenerator::processSpeedingVehicles(const std::vector<Vehicle>& speedingVehicles) {
    std::lock_guard<std::mutex> lock(challanMutex);

    for (const auto& vehicle : speedingVehicles) {
        Challan challan = {
            nextChallanId++,
            vehicle.id,
            (vehicle.type == LIGHT ? 5000 : 7000), // Fine amounts
            "Unpaid"
        };
        challans.push_back(challan);
        std::cout << "Generated Challan for Vehicle " << vehicle.id << ": Fine = " << challan.fineAmount << "\n";
    }
}

void ChallanGenerator::updateChallanStatus(int challanId, const std::string& status) {
    std::lock_guard<std::mutex> lock(challanMutex);

    for (auto& challan : challans) {
        if (challan.challanId == challanId) {
            challan.status = status;
            std::cout << "Challan " << challanId << " status updated to " << status << "\n";
            return;
        }
    }
}

std::vector<Challan> ChallanGenerator::getChallans()  {
    std::lock_guard<std::mutex> lock(challanMutex);
    return challans;
}
