#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// ----- LCD -----
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ----- DHT11 -----
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// ----- Pins -----
#define SOIL_SENSOR A0
#define TRIG 9
#define ECHO 10
#define RELAY 8
#define BUZZER 4
#define PIR 7

// ----- Variables -----
int soilValue;
long duration;
int distance;
int motionState;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  pinMode(SOIL_SENSOR, INPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(PIR, INPUT);

  digitalWrite(RELAY, HIGH);  // Pump OFF initially
  digitalWrite(BUZZER, LOW);

  dht.begin();

  // ---- Welcome Screen ----
  lcd.setCursor(0, 0);
  lcd.print("SMART MONITOR");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2500);
  lcd.clear();

  // ---- Serial Banner ----
  Serial.println("=========================================");
  Serial.println("   SMART PLANT & MOTION MONITOR SYSTEM   ");
  Serial.println("=========================================");
  Serial.println("Sensors Initialized Successfully!");
  Serial.println("System Starting...\n");
}

void loop() {
  // ---- Soil Sensor ----
  soilValue = analogRead(SOIL_SENSOR);

  // ---- Ultrasonic Tank Level ----
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2;

  // ---- DHT11 ----
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // ---- PIR Sensor ----
  motionState = digitalRead(PIR);

  // ---- Serial Monitor Output ----
  Serial.println("-----------------------------------------");
  Serial.print("🌡 Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("💧 Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("🌱 Soil Moisture: ");
  Serial.print(soilValue);
  Serial.println(soilValue > 600 ? " (Dry)" : " (Wet)");

  Serial.print("🚰 Tank Level: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (motionState == HIGH) {
    Serial.println("🚶 Motion Detected!");
  } else {
    Serial.println("No Motion Detected.");
  }

  // ---- Pump Logic ----
  if (distance > 20) { // Tank empty
    Serial.println("⚠ Tank LOW! Pump OFF");
    digitalWrite(RELAY, HIGH);
  } 
  else if (soilValue > 600) { // Soil Dry
    Serial.println("🌾 Soil Dry → Pump ON");
    digitalWrite(RELAY, LOW);
  } 
  else { // Soil Wet
    Serial.println("💧 Soil Wet → Pump OFF");
    digitalWrite(RELAY, HIGH);
  }

  Serial.println("-----------------------------------------\n");

  // ---- LCD Display (Switching Screens) ----
  // Screen 1 - Temperature & Humidity
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temperature, 1);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Hum:");
  lcd.print(humidity, 0);
  lcd.print("%");
  delay(2000);

  // Screen 2 - Soil Moisture
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Soil: ");
  lcd.print(soilValue);
  lcd.setCursor(0, 1);
  lcd.print(soilValue > 600 ? "Status: DRY" : "Status: WET");
  delay(2000);

  // Screen 3 - Tank Level & Pump
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tank: ");
  lcd.print(distance);
  lcd.print("cm");
  lcd.setCursor(0, 1);
  lcd.print("Pump: ");
  lcd.print(digitalRead(RELAY) == LOW ? "ON " : "OFF");
  delay(2000);
}
