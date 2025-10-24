# 🌱 Smart Irrigation and Security System

This project is an Arduino-based smart automation system that combines **plant irrigation** and **home security** features. The system intelligently waters plants based on soil moisture levels and monitors motion near the system for basic security alerts. It also displays real-time sensor data on an LCD display and in the Serial Monitor.

---

## ✅ Features

| Feature | Description |
|----------|-------------|
| 🌱 Soil Moisture Monitoring | Detects dry or wet soil using a soil moisture sensor |
| 🚰 Automatic Water Pump | Pump turns ON when soil is dry and water tank has water |
| 💧 Water Level Monitoring | Ultrasonic sensor checks tank water level |
| 🌡 Environment Tracking | DHT11 shows temperature and humidity |
| 🚨 Security Motion Alert | PIR sensor detects movement |
| 🔊 Alert Buzzer | Activates for motion or dry soil warnings |
| 📟 LCD Display | Shows live sensor status |
| 🖥 Serial Monitor Output | For system debugging |

---

## 🔧 Components Used

| Component | Quantity |
|-----------|----------|
| Arduino Uno | 1 |
| Soil Moisture Sensor | 1 |
| Ultrasonic Sensor (HC-SR04) | 1 |
| PIR Motion Sensor (HC-SR501) | 1 |
| DHT11 Temperature & Humidity Sensor | 1 |
| Relay Module (4-channel or 1-channel) | 1 |
| Submersible Water Pump (3–6V) | 1 |
| Buzzer | 1 |
| 16x2 LCD Display with I2C | 1 |
| Jumper Wires & Breadboard | As needed |
| 5V Power Supply | 1 |

---

## 🔌 Pin Connections

| Module / Component | Arduino Pin |
|--------------------|-------------|
| Soil Moisture Sensor (AO) | A0 |
| Ultrasonic TRIG | D9 |
| Ultrasonic ECHO | D10 |
| Relay (Pump Control) | D8 |
| Buzzer | D4 |
| PIR Motion Sensor | D7 |
| DHT11 Data Pin | D2 |
| LCD SDA | A4 |
| LCD SCL | A5 |
| Power (VCC & GND) | 5V, GND |

---

## 🛠 Circuit Diagram

A simple wiring diagram connects all sensors to the Arduino Uno with a relay controlling the water pump. **Make sure to use a separate power source for the water pump if needed** to avoid damaging the Arduino.

---

## 💻 Code

The full Arduino code for this project is included in this repository:  
`Smart-Irrigation-and-Security-System.ino`

---

## 🔄 System Workflow

1. The system reads soil moisture.
2. If **Soil = Dry** and **Tank = Not Empty** → Pump ON.
3. If **Soil = Wet** or **Tank = Empty** → Pump OFF.
4. PIR sensor detects motion → Trigger buzzer security alert.
5. DHT11 tracks room temperature and humidity.
6. LCD continuously displays:
   - Soil Moisture Status
   - Temperature & Humidity
   - Water Tank Level
   - Motion Detection Status
7. Same data also prints on Serial Monitor.

---

## 🚀 Setup Instructions

### Upload Code
1. Open `.ino` file in Arduino IDE or VS Code.
2. Select **Arduino Uno** as the board.
3. Select the correct **COM Port**.
4. Click **Upload**.

### VS Code (Optional)
```bash
git clone https://github.com/md-najmul-hossain-nur/Smart-Irrigation-and-Security-System.git
cd Smart-Irrigation-and-Security-System
