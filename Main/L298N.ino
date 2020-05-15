void turnOnA() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void turnOnB() {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnOffA() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void turnOffB() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void turnOnReverseA() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void turnOnReverseB() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
