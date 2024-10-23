// Pin connections
int latchPin = 12;   // ST_CP pin on the 74HC595
int clockPin = 13;   // SH_CP pin on the 74HC595
int dataPin = 11;    // DS pin on the 74HC595

// Data to send to the shift register
byte ledData = 0;

void setup() {
  // Set pins as outputs
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  // Turn LEDs on in sequence
  for (int i = 0; i < 8; i++) {
    ledData = 1 << i;  // Shift 1 left by 'i' positions to create the desired bit pattern
    updateShiftRegister(ledData);
    delay(200);  // Delay to visualize the change
  }

  // Turn LEDs off in sequence
  for (int i = 7; i >= 0; i--) {
    ledData = 1 << i;  // Shift 1 left by 'i' positions
    updateShiftRegister(ledData);
    delay(200);  // Delay to visualize the change
  }
}

// Function to send data to the shift register
void updateShiftRegister(byte data) {
  digitalWrite(latchPin, LOW);    // Bring latch LOW to start sending data
  shiftOut(dataPin, clockPin, MSBFIRST, data);  // Send data (MSB first)
  digitalWrite(latchPin, HIGH);   // Bring latch HIGH to lock data in place
}
