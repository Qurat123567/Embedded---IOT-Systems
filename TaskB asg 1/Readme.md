Task B — Button Press-Type Detection (Short / Long Press)

Course: Embedded IoT Systems (Fall 2025)  
Student Name:Qura-tul-ain  
Registration #:23-NTU-CS-1085  
Class / Section:BSCS-5B  

Objective
Design a system using a single push button that performs two different actions based on the press duration:

Short Press (< 1.5 seconds) Toggle the LED state (ON/OFF).  
Long Press (> 1.5 seconds) Play a buzzer tone sequence.  

An OLED display (SSD1306) shows the current system status.

 Components & Pin Configuration

 Component Description  GPIO Pin 

 LED : Visual output indicator :23 
 Push Button : Input control : 14 
 Buzzer : Audio output : 27 
 OLED Display (SSD1306) : I²C display module : SDA = 21, SCL = 22 :

 Working Principle

1.Button Press Detection
   - The system detects when the button is pressed (`LOW`).
   - It records the press start time using `millis()`.
   - When the button is released, the press duration determines the action.

2. Short Press
   Toggles the LED between ON and OFF states.
   - Updates the OLED display message accordingly.

3. Long Press
   - Plays a tone sequence on the buzzer.
   - Displays BUZZER! on the OLED screen.

4. OLED Display Feedback
   - Shows READY  on startup.
   - Updates to LED ON, LED OFF, or BUZZER! based on user input.

 Code Overview

cpp
if (pressDuration < 1500) {
  // Short press — toggle LED
  ledState = !ledState;
  digitalWrite(LED1, ledState ? HIGH : LOW);
  display.println(ledState ? "LED ON" : "LED OFF");
} else {
  // Long press — play buzzer melody
  playBuzzerTone();
  display.println("BUZZER!");
}


SCREENSHOTS:
Circuit Diagram (Wokwi)
(Screenshots/ready.png)

OLED Display - OFF
(Screenshots/OFF.png)

OLED Display - ON
(Screenshots/ON.png)

OLED Display - Buzzer
(Screenshots/Buzzer.png)