#define motor1_pin1  5
#define motor1_pin2  4
#define motor2_pin1  3
#define motor2_pin2  2
#define ENA  7
#define ENB  6
char x;
void setup() {
  Serial.begin(9600);
  pinMode(motor1_pin1, OUTPUT);
  pinMode(motor1_pin2, OUTPUT);
  pinMode(motor2_pin1, OUTPUT);
  pinMode(motor2_pin2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    x = Serial.read();
    Serial.print(x);
    if (x == 'F') {
      stright();
    }
    else if (x == 'L') {
      car_left();
    }
    else if (x == 'R') {
      car_right();
    }
    else if (x == 'S') {
      car_stop();
    }
    else if (x == 'B') {
      backforwd();
    }
  }

}


void stright() {
  analogWrite(ENA , car_speed);
  analogWrite(ENB , car_speed);
  digitalWrite (motor1_pin1 , HIGH);
  digitalWrite (motor1_pin2 , LOW);
  digitalWrite (motor2_pin1 , HIGH);
  digitalWrite (motor2_pin2 , LOW);
}

void backforwd() {
  analogWrite(ENA , car_speed);
  analogWrite(ENB , car_speed);
  digitalWrite (motor1_pin1 , LOW);
  digitalWrite (motor1_pin2 , HIGH);
  digitalWrite (motor2_pin1 , LOW);
  digitalWrite (motor2_pin2 , HIGH);
}

void car_stop() {
  digitalWrite (motor1_pin1 , LOW);
  digitalWrite (motor1_pin2 , LOW);
  digitalWrite (motor2_pin1 , LOW);
  digitalWrite (motor2_pin2 , LOW);
}
void car_left() {
  analogWrite(ENA , car_speed);
  analogWrite(ENB , car_speed);
  digitalWrite (motor1_pin1 , HIGH);
  digitalWrite (motor1_pin2 , LOW);
  digitalWrite (motor2_pin1 , LOW);
  digitalWrite (motor2_pin2 , HIGH);
}
void car_right() {
  analogWrite(ENA , car_speed);
  analogWrite(ENB , car_speed);
  digitalWrite (motor1_pin1 , LOW);
  digitalWrite (motor1_pin2 , HIGH);
  digitalWrite (motor2_pin1 , HIGH);
  digitalWrite (motor2_pin2 , LOW);
}
