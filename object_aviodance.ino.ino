#include <Servo.h>

// Motor A (Left)
#define ENA 11
#define IN1 4
#define IN2 5

// Motor B (Right)
#define ENB 10
#define IN3 6
#define IN4 7

// Ultrasonic Sensor
#define TRIG 2
#define ECHO 3

// Servo
#define SERVO_PIN 8

Servo myservo;

const int obstacleDistance = 30;

void setup() {

  Serial.begin(9600);

  // Motor pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Ultrasonic pins
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  // Servo
  myservo.attach(SERVO_PIN);

  // Servo startup test
  myservo.write(90);
  delay(1000);

  myservo.write(30);
  delay(1000);

  myservo.write(150);
  delay(1000);

  myservo.write(90);
  delay(1000);

  Serial.println("Robot Started");
}

void loop() {

  int distance = getDistance();

  Serial.print("Front Distance = ");
  Serial.println(distance);

  if (distance > obstacleDistance) {

    forward();
  }
  else {

    Serial.println("Obstacle Detected");

    stopRobot();
    delay(300);

    backward();
    delay(800);

    stopRobot();
    delay(300);

    // Look Left
    myservo.write(150);
    delay(700);

    int leftDistance = getDistance();

    Serial.print("Left Distance = ");
    Serial.println(leftDistance);

    // Look Right
    myservo.write(30);
    delay(700);

    int rightDistance = getDistance();

    Serial.print("Right Distance = ");
    Serial.println(rightDistance);

    // Center
    myservo.write(90);
    delay(300);

    if (leftDistance > rightDistance) {

      Serial.println("Turning Left");

      turnLeft();
      delay(700);
    }
    else {

      Serial.println("Turning Right");

      turnRight();
      delay(700);
    }

    stopRobot();
    delay(200);
  }
}

// =======================
// Distance Function
// =======================
int getDistance() {

  digitalWrite(TRIG, LOW);
  delayMicroseconds(5);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 30000);

  if (duration == 0) {
    return 250;
  }

  int distance = duration * 0.034 / 2;

  return distance;
}

// =======================
// Forward
// =======================
void forward() {

  analogWrite(ENA, 255);
  analogWrite(ENB, 255);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// =======================
// Backward
// =======================
void backward() {

  analogWrite(ENA, 255);
  analogWrite(ENB, 255);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// =======================
// Left Turn
// =======================
void turnLeft() {

  analogWrite(ENA, 255);
  analogWrite(ENB, 255);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// =======================
// Right Turn
// =======================
void turnRight() {

  analogWrite(ENA, 255);
  analogWrite(ENB, 255);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// =======================
// Stop
// =======================
void stopRobot() {

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}