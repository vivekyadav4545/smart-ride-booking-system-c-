# smart-ride-booking-system-c-
Graph-based ride booking system in C++ implementing BFS for nearest driver allocation with OOP design and STL.
#  Smart Ride Booking System (C++)

Graph-based ride booking system in C++ implementing BFS for nearest driver allocation with OOP design and STL.

# Features :
 Add users and drivers
 Find nearest available driver using BFS
 Book and complete rides
 Track driver availability
 City is represented using a graph

# Concepts Used
 Graph (Adjacency List)
 BFS (Breadth-First Search)
 Object-Oriented Programming (OOP)
 STL (vector, queue)

#  How it Works:
 The city is stored as a graph of connected locations
 When a user requests a ride, the system searches for the nearest driver
 BFS is used to find the closest available driver
 Once assigned, the driver becomes unavailable
 After ride completion, the driver becomes available again

# How to Run:

```bash
g++ main.cpp -o ride
./ride
```

#  Sample Output:

```
--- Available Drivers ---
ID: 101 Name: John Location: 2 Available: Yes

--- Booking Ride ---
Driver Assigned: John
```

# Future Improvements:
- Add distance-based pricing
- Add driver ratings
- Build GUI or web version

#  Author:
Vivek Yadav
