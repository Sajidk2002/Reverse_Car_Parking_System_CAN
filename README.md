# Reverse Car Parking System (CAN Bus)

This project implements a Reverse Car Parking Assistance System using ARM7 LPC21xx Microcontroller and the CAN (Controller Area Network) bus protocol.  
It demonstrates how multiple microcontroller nodes can communicate over CAN to measure distance using an ultrasonic sensor and provide obstacle alerts using a buzzer.

---

## Project Overview
- Node A:  
  - Sends remote frames to request distance data.  
  - Processes data received from Node B.  
  - Controls the buzzer alert system.  

- Node B:  
  - Uses an ultrasonic sensor to measure distance.  
  - Sends measured data back to Node A via CAN.  

The system alerts the driver with variable buzzer frequencies depending on the distance to an obstacle.

---

## Features
- Ultrasonic sensor distance measurement  
- CAN Bus communication between Node A and Node B  
- Real-time buzzer alerts:  
  - Continuous beep (very close < 50 cm)  
  - Fast beeps (50–100 cm)  
  - Medium beeps (100–200 cm)  
  - Slow beeps (200–400 cm)  

---

## Project Structure
Reverse_Car_Parking_System_CAN/
│── README.md # Project documentation
│── .gitignore # Ignore build files
│── src/ # Source code
│ ├── headerA.h
│ ├── headerB.h
│ ├── CAN2_NodeA_Driver.c
│ ├── CAN2_NodeB_Driver.c
│ ├── CAN2_interrupt_nodeA.c
│ ├── CAN2_interrupt_nodeB.c
│ ├── external_interrupt_nodeA.c
│ ├── ultrasonic.c
│ ├── delay.c
│ ├── main_nodeA.c
│ └── main_nodeB.c

---

## Hardware Requirements
- ARM7 LPC21xx Microcontroller  
- Ultrasonic Sensor (HC-SR04 or equivalent)  
- Buzzer and LED indicators  
- CAN Transceiver (MCP2551 or SN65HVD230)  
- Power Supply (5V regulated)  

---

## How It Works
1. Node A sends a CAN remote frame (ID = 0x100) requesting distance data.  
2. Node B measures distance using the ultrasonic sensor and sends back a data frame.  
3. Node A receives the data, processes it, and activates the buzzer based on distance range.  
4. If Node A sends a frame with ID = 0x200, Node B stops sending distance updates.  

---

## Getting Started
1. Clone this repository:
   ```bash
   git clone https://github.com/Sajidk2002/Reverse_Car_Parking_System_CAN.git
