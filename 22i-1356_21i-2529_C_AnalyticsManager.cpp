#include "AnalyticsManager.h"
#include <iostream>

AnalyticsManager::AnalyticsManager() : totalChallans(0), activeChallans(0) {}

void AnalyticsManager::collect(const std::vector<Vehicle>& vehicles) {
    vehicleCounts.clear();
    for (const auto& vehicle : vehicles) {
        std::string type = (vehicle.type == LIGHT ? "Light" : vehicle.type == HEAVY ? "Heavy" : "Emergency");
        vehicleCounts[type]++;
    }

    // Update challan analytics (example: retrieve from ChallanGenerator)
    totalChallans = vehicles.size(); // Example logic
    activeChallans = 0;             // Example logic
}

void AnalyticsManager::displayFinalAnalytics() {
    std::cout << "\n--- Final Analytics ---\n";
    for (const auto& pair : vehicleCounts) {
        std::cout << pair.first << " Vehicles: " << pair.second << "\n";
    }
    std::cout << "Total Challans Issued: " << totalChallans << "\n";
    std::cout << "Active Challans: " << activeChallans << "\n";
}
