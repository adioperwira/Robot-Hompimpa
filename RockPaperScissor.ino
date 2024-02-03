#include <Servo.h>

#define tombolPin 2
#define servo1Pin 3
#define servo2Pin 4
#define servo3Pin 5
#define buzzPin 9

Servo servo1;
Servo servo2;
Servo servo3;

void setup() {
  pinMode(tombolPin, INPUT_PULLUP);
  pinMode(buzzPin, OUTPUT);

  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo3.attach(servo3Pin);

  servo1.write(0);
  servo2.write(0);
  servo3.write(0);  

  randomSeed(analogRead(0));
}

void loop() {
  if (digitalRead(tombolPin) == LOW) {
    int servoNumber = random(1, 4); // Memilih angka random dari 1 sampai 3
    Buzzer();
    if (servoNumber == 1) {
      servo1.write(180);
      servo2.write(0);
      servo3.write(180);            // Gunting
    } else if (servoNumber == 2) {
      servo1.write(180);
      servo2.write(180);
      servo3.write(180);             // Batu
    } else if (servoNumber == 3) {
      servo1.write(0);
      servo2.write(0);
      servo3.write(0);            // Kertas
    }

    delay(500);
  }
}

void Buzzer(){
  tone(buzzPin,262,500);
  delay(1000);
  tone(buzzPin,262,500);
  delay(1000);
  tone(buzzPin,262,500);
  delay(1000);
  tone(buzzPin,523,1000);
  delay(500);
}
