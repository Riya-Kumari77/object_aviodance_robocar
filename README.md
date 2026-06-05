# Object Avoidance Robocar using Arduino Uno

## Overview

This project is an autonomous obstacle-avoiding robot built using an Arduino Uno, HC-SR04 ultrasonic sensor, SG90 servo motor, L298N motor driver, and DC geared motors. The robot can detect obstacles in its path, scan its surroundings, and automatically choose a safer direction to continue moving without human intervention.

## Features

* Autonomous navigation
* Real-time obstacle detection
* Automatic collision avoidance
* Left and right path scanning using a servo motor
* Direction selection based on available space
* Low-cost and beginner-friendly robotics project

## Components Used

| Component                 | Quantity    |
| ------------------------- | ----------- |
| Arduino Uno               | 1           |
| HC-SR04 Ultrasonic Sensor | 1           |
| SG90 Servo Motor          | 1           |
| L298N Motor Driver Module | 1           |
| DC Geared Motors          | 2           |
| Robot Chassis             | 1           |
| Wheels                    | 2           |
| Battery Pack              | 1           |
| Jumper Wires              | As Required |

## Hardware Connections

### Ultrasonic Sensor

| HC-SR04 Pin | Arduino Pin |
| ----------- | ----------- |
| VCC         | 5V          |
| GND         | GND         |
| TRIG        | D2          |
| ECHO        | D3          |

### Servo Motor

| Servo Pin | Arduino Pin |
| --------- | ----------- |
| Signal    | D8          |
| VCC       | 5V          |
| GND       | GND         |

### L298N Motor Driver

#### Left Motor

| L298N Pin | Arduino Pin |
| --------- | ----------- |
| ENA       | D11         |
| IN1       | D4          |
| IN2       | D5          |

#### Right Motor

| L298N Pin | Arduino Pin |
| --------- | ----------- |
| ENB       | D10         |
| IN3       | D6          |
| IN4       | D7          |

## Working Principle

1. The robot moves forward continuously.
2. The ultrasonic sensor measures the distance to objects in front of the robot.
3. If an obstacle is detected within the predefined threshold distance:

   * The robot stops.
   * Moves backward slightly.
   * Rotates the ultrasonic sensor using the servo motor.
4. The sensor scans both left and right directions.
5. The Arduino compares the measured distances.
6. The robot turns toward the side with more free space.
7. The robot resumes forward movement and continues navigating.

## Project Flow

```text
Start
  |
Move Forward
  |
Check Distance
  |
Obstacle Detected?
  |
 No -----------------> Continue Forward
  |
 Yes
  |
Stop Robot
  |
Move Backward
  |
Scan Left
  |
Scan Right
  |
Compare Distances
  |
Turn Towards Clear Path
  |
Continue Forward
```

## Applications

* Autonomous mobile robots
* Robotics learning projects
* Obstacle detection systems
* Educational STEM projects
* Smart navigation prototypes

## Learning Outcomes

Through this project, I gained practical experience in:

* Arduino programming
* Embedded systems
* Sensor interfacing
* Servo motor control
* Motor driver integration
* Autonomous robotics
* Real-time decision making

## Future Improvements

* Bluetooth/Wi-Fi control
* Line-following capability
* IoT monitoring
* Camera-based navigation
* Machine learning-based obstacle detection

## Author

Riya Kumari

## License

This project is open-source and available under the MIT License.
