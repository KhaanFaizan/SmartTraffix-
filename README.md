# 🚦 SmartTraffix - Intelligent Traffic Management System
SmartTraffix is a C++-based traffic management system that efficiently regulates traffic flow using real-time analytics and vehicle queue management. It ensures smooth traffic movement by prioritizing emergency vehicles and tracking traffic congestion levels.

# Features
 Real-Time Traffic Queue Management - Handles multiple lanes (N, S, E, W) and distributes vehicles accordingly.
 Emergency Vehicle Prioritization - Ensures that ambulances, fire trucks, and police vehicles get priority.
 Traffic Analytics - Collects and analyzes vehicle data to track congestion and challan issuance.
 Multi-Threaded Implementation - Uses mutex locks for safe concurrent updates to vehicle queues.

# Tech Stack
Programming Language: C++

Concurrency: std::mutex, std::lock_guard

Data Structures: Queues (std::queue), Vectors (std::vector)

File Handling: For storing traffic data

# How It Works

Manages traffic lanes (N, S, E, W).

Prioritizes emergency vehicles.

Implements real-time queue updates with std::mutex.


Tracks traffic data and vehicle counts.

Maintains challan records.

Displays final traffic analytics.
