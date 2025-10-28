# Reverse Car Parking System using CAN

## Overview
This project is a microcontroller-based reverse parking assistance system that uses the **CAN protocol** for reliable communication between ECUs.  
The system detects obstacles using **ultrasonic sensors** and provides feedback through a **buzzer** and **LCD display**.  
It’s designed to simulate a real-world automotive parking assist feature.

## Objective
To design and implement a reverse car parking system with real-time obstacle detection and inter-ECU communication using the CAN protocol.

## Hardware Used
- ARM Cortex-M based Microcontroller  
- Ultrasonic Sensor (HC-SR04)  
- Buzzer  
- 16x2 LCD Display  
- CAN Transceiver (MCP2551)  
- Power Supply Unit and connecting circuits  

## Software & Tools
- **Keil µVision IDE** for coding and debugging  
- **Embedded C** for firmware development  
- **Proteus** for simulation (if available)  

## Working Principle
The ultrasonic sensor measures the distance between the vehicle and the obstacle behind it.  
The microcontroller processes this data and sends it to another ECU via the CAN bus.  

Based on the received distance data:
- The **LCD** displays the measured distance in real-time.  
- The **buzzer** gives alerts with varying tones depending on proximity.  
- The system ensures communication reliability and response within **100 ms**.

## CAN Communication
- Used **standard CAN frames** for data transfer between ECUs.  
- Each ECU handles different functionalities:  
  - **Master ECU** – Sensor data acquisition and transmission  
  - **Slave ECU** – Display and alert control  
- Ensures proper synchronization and low latency.

## Features
- Real-time obstacle detection  
- Fast and reliable CAN communication  
- Modular firmware structure  
- Scalable for future automotive integration  

## Future Improvements
- Integrate with actual car ECU network  
- Add a visual dashboard display  
- Implement distance-based motor control for auto braking  

## Author
**Muhammad Sajid K**  
Embedded Systems Enthusiast | Automotive & IoT Developer  
[LinkedIn Profile](https://linkedin.com/in/muhammad-sajid-k-620b68257)
