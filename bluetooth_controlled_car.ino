//intechrobo bluetooth controlled car
// Define motor control pins
const int LeftMotorForward = 6;
const int LeftMotorBackward = 7;
const int RightMotorForward = 4;
const int RightMotorBackward = 5;

// Define variables for Bluetooth
char command; // Variable to store Bluetooth command

void setup() {
  // Set motor pins as output
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
 
  // Initialize Bluetooth communication at 9600 baud
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read(); // Read the incoming Bluetooth command
    switch (command) {
      case 'F':
        moveForward();
        break;
      case 'B':
        moveBackward();
        break;
      case 'L':
        turnLeft();
        break;
      case 'R':
        turnRight();
        break;
      case 'S':
        moveStop();
        break;
      default:
        moveStop();
        break;
    }
  }
}
void moveStop() {
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward() {
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}

void moveBackward() {
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
}

void turnRight() {
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  delay(250);
  moveStop();
}

void turnLeft() {
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  delay(250);
  moveStop();
}
