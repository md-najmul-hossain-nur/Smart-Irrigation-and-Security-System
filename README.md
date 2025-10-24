# Smart Plant & Motion Monitor System 🌱🚨

This project is a **Smart Irrigation and Motion Detection System** using Arduino.  
It monitors **soil moisture, temperature, humidity, motion, and water tank level** and automatically controls a **water pump** based on soil conditions. The system displays real-time data on an **LCD display** and also logs information to the **Serial Monitor**.

---

## ✅ Features

| Feature                            | Description |
|------------------------------------|-------------|
| 🌡 Temperature Monitoring          | Measures environment temperature using **DHT11** |
| 💧 Humidity Monitoring             | Measures humidity using **DHT11** |
| 🌱 Soil Moisture Detection         | Checks soil moisture using analog soil sensor |
| 🚰 Automatic Pump Control          | Activates pump when soil is dry |
| 🛢️ Water Level Monitoring          | Uses ultrasonic sensor to track water tank level |
| 🚶 Motion Detection                | Detects movement using PIR sensor |
| 🔊 Alert System                    | Buzzer alerts when motion is detected |
| 🖥 LCD Display                     | Displays sensor readings on a 16x2 I2C LCD |
| 🔧 Serial Monitor Logs             | Prints detailed formatted logs for debugging |

---

## 🔧 Components Used

| Component | Quantity | Description |
|-----------|----------|-------------|
| Arduino Uno | 1 | Main controller |
| DHT11 Sensor | 1 | Temperature & Humidity sensor |
| Soil Moisture Sensor | 1 | For soil readings |
| HC-SR04 Ultrasonic Sensor | 1 | Water level measurement |
| HC-SR501 PIR Motion Sensor | 1 | Detects motion |
| Relay Module (1-channel) | 1 | Controls water pump |
| Submersible Water Pump | 1 | For irrigation |
| Buzzer | 1 | Alarm |
| 16x2 I2C LCD Display | 1 | Visual output |
| Jumper Wires | - | Connections |
| External Power Supply (12V for pump) | 1 | Optional |

---

## 🔌 Pin Connections

### Arduino Pin Mapping

| Module / Sensor | Arduino Pin |
|------------------|-------------|
| DHT11 Sensor     | D2 |
| Soil Sensor (Analog) | A0 |
| Ultrasonic Trigger Pin | D9 |
| Ultrasonic Echo Pin | D10 |
| Relay Module (Pump Control) | D8 |
| Buzzer | D4 |
| PIR Motion Sensor | D7 |
| LCD (I2C) SDA | A4 |
| LCD (I2C) SCL | A5 |

---

## 💻 Software Requirements

- Arduino IDE
- Required Libraries:
  - `LiquidCrystal_I2C`
  - `Wire`
  - `DHT`

Install libraries from Arduino IDE → **Sketch → Include Library → Manage Libraries**

---

## 🚀 How It Works

1. When soil becomes dry, pump turns **ON** automatically.
2. If tank water level is low (distance > 20cm), pump stays **OFF**.
3. PIR detects motion and triggers sound alert.
4. LCD cycles between:
   - Screen 1: Temperature + Humidity
   - Screen 2: Soil Moisture
   - Screen 3: Tank Water Level + Pump Status
5. Serial Monitor prints detailed logs for monitoring.

---


