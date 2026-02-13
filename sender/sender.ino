void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, 16, 17);
}

void loop() {
  // PC → Sender → Receiver
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    Serial2.println(cmd);
  }

  // Receiver → Sender → PC
  if (Serial2.available()) {
    String msg = Serial2.readStringUntil('\n');
    Serial.println(msg);
  }
}