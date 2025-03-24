#ifndef ANALYTICSMANAGER_H
#define ANALYTICSMANAGER_H

#include <map>
#include <string>
#include <vector>
#include "VehicleManager.h"
#include "ChallanGenerator.h"

class AnalyticsManager {
private:
    std::map<std::string, int> vehicleCounts; // e.g., "Light" -> 5
    int totalChallans;
    int activeChallans;

public:
    AnalyticsManager();
    void collect(const std::vector<Vehicle>& vehicles);
    void displayFinalAnalytics();
};

#endif


