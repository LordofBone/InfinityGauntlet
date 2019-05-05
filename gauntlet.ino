// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int buttonPin1 = 3;     // the number of the pushbutton1 pin

// bright level int
int brightLevel;

// int for loops
int i;


// sets glow mode
int glowMode = 0;

// button state variables
int buttonState = 0;         // variable for reading the pushbutton status
int buttonState1 = 0; 

// list of all led pins
int ledNos[] = {9, 8, 7, 6, 5, 4};

void setup() {                
  // initialize the led pins as outputs
  for (i = 0; i < 6; i++) {
    pinMode(ledNos[i], OUTPUT);

  // begin serial
  Serial.begin(9600);
  }
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin1, INPUT);   
}

void loop() {
    // read the state of the pushbutton values:
    buttonState = digitalRead(buttonPin);
    buttonState1 = digitalRead(buttonPin1);
    
    // button for lighting the stones when closing fist
    if (buttonState == HIGH) {
      if (glowMode < 7) {
        glowMode++;
        delay(500);
      }
      else
      {
        allLED(0);
        glowMode = 0;
        delay(500);
      }
    }

    // button for fully lighting when snapping fingers and sending the serial info to the pi
    if (buttonState1 == HIGH) {
      if (glowMode == 0) {
        glowMode = 8;
        Serial.println("snap");
        delay(500);
      }
      else {
        pattern(0);
        glowMode = 0;
        delay(500);
      }
    }

	// modes for indidual stone/full stones control
    if (glowMode == 1) {
      analogWrite(ledNos[0], 155);
      analogWrite(ledNos[1], 0);
      analogWrite(ledNos[2], 0);
      analogWrite(ledNos[3], 0);
      analogWrite(ledNos[4], 0);
      analogWrite(ledNos[5], 0);
    }

    if (glowMode == 2) {
       analogWrite(ledNos[1], 155);
       analogWrite(ledNos[0], 0);
       analogWrite(ledNos[2], 0);
       analogWrite(ledNos[3], 0);
       analogWrite(ledNos[4], 0);
       analogWrite(ledNos[5], 0);
    }

    if (glowMode == 3) {
      analogWrite(ledNos[2], 155);
      analogWrite(ledNos[1], 0);
      analogWrite(ledNos[0], 0);
      analogWrite(ledNos[3], 0);
      analogWrite(ledNos[4], 0);
      analogWrite(ledNos[5], 0);
    }

    if (glowMode == 4) {
      analogWrite(ledNos[3], 155);
      analogWrite(ledNos[1], 0);
      analogWrite(ledNos[2], 0);
      analogWrite(ledNos[0], 0);
      analogWrite(ledNos[4], 0);
      analogWrite(ledNos[5], 0);
    }

    if (glowMode == 5) {
      analogWrite(ledNos[4], 155);
      analogWrite(ledNos[1], 0);
      analogWrite(ledNos[2], 0);
      analogWrite(ledNos[3], 0);
      analogWrite(ledNos[0], 0);
      analogWrite(ledNos[5], 0);
    }

    if (glowMode == 6) {
      analogWrite(ledNos[5], 155);
      analogWrite(ledNos[1], 0);
      analogWrite(ledNos[2], 0);
      analogWrite(ledNos[3], 0);
      analogWrite(ledNos[4], 0);
      analogWrite(ledNos[0], 0);
    }

    if (glowMode == 7) {
      allLED(155);
    }

    if (glowMode == 8) {
      pattern(200);
    }
}

// illuminates the stones one at a time
void pattern(int brightLevel) {
    for (i = 0; i < 6; i++) {
    analogWrite(ledNos[i],brightLevel); 
    delay(50);
  }
}

// controls all stones at once
void allLED(int brightLevel) {
    analogWrite(ledNos[0], brightLevel);
    analogWrite(ledNos[1], brightLevel);
    analogWrite(ledNos[2], brightLevel);
    analogWrite(ledNos[3], brightLevel);
    analogWrite(ledNos[4], brightLevel);
    analogWrite(ledNos[5], brightLevel);
}