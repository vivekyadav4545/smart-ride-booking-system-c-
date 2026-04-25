#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
// ---------------- DRIVER CLASS ----------------
class Driver {
public:
    int id;
    string name;
    int location;
    bool available;

    Driver(int id, string name, int loc) {
        this->id = id;
        this->name = name;
        this->location = loc;
        this->available = true;
    }
};

// ---------------- USER CLASS ----------------
class User {
public:
    int id;
    string name;
    int location;

    User(int id, string name, int loc) {
        this->id = id;
        this->name = name;
        this->location = loc;
    }
};

// ---------------- GRAPH CLASS ----------------
class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS to find nearest driver
    int findNearestDriver(int src, vector<Driver>& drivers) {
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto &d : drivers) {
                if (d.available && d.location == node) {
                    return d.id;
                }
            }

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return -1;
    }
};

// ---------------- RIDE SYSTEM ----------------
class RideSystem {
    vector<User> users;
    vector<Driver> drivers;
    Graph city;

public:
    RideSystem(int locations) : city(locations) {}

    void addRoad(int u, int v) {
        city.addEdge(u, v);
    }

    void addUser(int id, string name, int loc) {
        users.push_back(User(id, name, loc));
    }

    void addDriver(int id, string name, int loc) {
        drivers.push_back(Driver(id, name, loc));
    }

    void bookRide(int userId) {
        User *userPtr = nullptr;

        for (auto &u : users) {
            if (u.id == userId) {
                userPtr = &u;
                break;
            }
        }

        if (!userPtr) {
            cout << "User not found!\n";
            return;
        }

        int driverId = city.findNearestDriver(userPtr->location, drivers);

        if (driverId == -1) {
            cout << "No drivers available!\n";
            return;
        }

        for (auto &d : drivers) {
            if (d.id == driverId) {
                d.available = false;
                cout << "Ride Booked!\n";
                cout << "Driver: " << d.name << " (ID: " << d.id << ")\n";
                return;
            }
        }
    }

    void completeRide(int driverId, int newLocation) {
        for (auto &d : drivers) {
            if (d.id == driverId) {
                d.available = true;
                d.location = newLocation;
                cout << "Ride completed. Driver is now available.\n";
                return;
            }
        }
        cout << "Driver not found!\n";
    }

    void showDrivers() {
        for (auto &d : drivers) {
            cout << "ID: " << d.id
                 << " Name: " << d.name
                 << " Location: " << d.location
                 << " Available: " << (d.available ? "Yes" : "No") << endl;
        }
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    RideSystem system(6);

    // Create city graph
    system.addRoad(0, 1);
    system.addRoad(1, 2);
    system.addRoad(2, 3);
    system.addRoad(3, 4);
    system.addRoad(4, 5);

    // Add users
    system.addUser(1, "Alice", 0);
    system.addUser(2, "Bob", 3);

    // Add drivers
    system.addDriver(101, "John", 2);
    system.addDriver(102, "Mike", 5);

    cout << "\n--- Available Drivers ---\n";
    system.showDrivers();

    cout << "\n--- Booking Ride for User 1 ---\n";
    system.bookRide(1);

    cout << "\n--- Drivers After Booking ---\n";
    system.showDrivers();

    cout << "\n--- Completing Ride ---\n";
    system.completeRide(101, 0);

    cout << "\n--- Drivers After Completion ---\n";
    system.showDrivers();

    return 0;
}