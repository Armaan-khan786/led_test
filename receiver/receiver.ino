#define LED_PIN 2

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, 16, 17);

  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);

  delay(5000);   // IMPORTANT: wait for full boot

  Serial.println("[Info]: Running Application");
  Serial2.println("[Info]: Running Application");
}

void loop() {
  if (Serial2.available()) {
    String cmd = Serial2.readStringUntil('\n');
    cmd.trim();

    if (cmd == "LED_ON") {
      digitalWrite(LED_PIN, HIGH);
      Serial2.println("LED_IS_ON");
    }
    else if (cmd == "LED_OFF") {
      digitalWrite(LED_PIN, LOW);
      Serial2.println("LED_IS_OFF");
    }
    else if (cmd == "PING") {
      Serial2.println("RUNNING");
    }
    else {
      Serial2.println("ERROR");
    }
  }
}