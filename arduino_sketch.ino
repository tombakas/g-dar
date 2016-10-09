const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int j=3;j<=13;j++) {
    pinMode(j, OUTPUT);
  };

  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) { // botton pressed down

    digitalWrite(5, HIGH);

    long gaynessLevel = random(3,14);

    Serial.print("Gayness level ");
    Serial.println(gaynessLevel);

    if (buttonState == LOW) {
      // turn LED on:
      for(int k=1;k<=3;k++) {
        for(int i=3;i<=13;i++) {
          digitalWrite(i, HIGH);
          delay(10+i*10);
        };

        for(int i=14;i>=3;i--) {
          digitalWrite(i, LOW);
          delay(10+i*10);
        };
      }

      for(int i=3;i<=gaynessLevel;i++) {
        digitalWrite(i, HIGH);
        delay(100+i*100);
      };

      delay(1000);
      flash(3, gaynessLevel, 20);
      delay(5000);
    }

  } else {
    // waiting
    int randomLED = random(3,14);
    digitalWrite(randomLED, HIGH);
    delay(100);
    digitalWrite(randomLED, LOW);
    delay(500);
  }
}

void flash(int from, int to, int times) {
  for(int j=1;j<=times;j++) {
    for(int i=from;i<=to;i++) {
      digitalWrite(i, HIGH); 
    }
    delay(100);
    for(int i=from;i<=to;i++) {
      digitalWrite(i, LOW); 
    }
    delay(100);
  }
}
