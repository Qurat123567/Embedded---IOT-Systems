Assignment 1 — ESP32 LED Mode Control with Dual Buttons

Name:Qura-tul-ain  
Registration No:23-NTU-CS-1085  
Course:Embedded IoT Systems (Fall 2025)  
Class/Section:BSCS-5B  



Task Description
Task A:
Use one button to cycle through LED modes
Use a second button to reset all LEDs to OFF 

This project demonstrates how to use interrupts,timers, and PWM on the ESP32 with an OLED display to show the current LED mode.


Components and Pin Configuration

Component : ESP32 Pin :Description 

 LED1 : GPIO 23 : Output LED 1 
 LED2 : GPIO 19 : Output LED 2 
 LED3 : GPIO 17 : PWM (fade) LED 
 Button1 : GPIO 14 : Mode change button 
 Button2 : GPIO 13 : Reset button 
 OLED SDA : GPIO 21 : I2C data line 
 OLED SCL : GPIO 22 : I2C clock line 

Working Principle
The system uses two push buttons to control multiple LED modes displayed on an OLED screen 
Button 1:Cycles through LED modes (0 → 1 → 2 → 3 → 0).  
Button 2:Instantly resets to “ALL OFF”.  
A hardware timer provides debounce handling to ensure reliable button detection.



LED Modes
0 : BOTH OFF All LEDs are OFF 
1 :ALTERNATE LED1 and LED2 blink alternately 
2:BOTH ON LED1 and LED2 remain ON 
3:PWM FADE LED3 fades in and out using PWM 


OLED Display Messages
0 “BOTH OFF” 
1 “ALTERNATE” 
2 “BOTH ON” 
3 “PWM FADE”

Each mode update is shown clearly on the OLED using the `Adafruit_SSD1306` and `Adafruit_GFX` libraries.
-

Wokwi Simulation
Wokwi Link: https://wokwi.com/projects/445781067971415041


Screenshots

Circuit Diagram (Wokwi)
(Screenshots/circuit.png)

OLED Display - BOTH OFF
(Screenshots/Both off.png)

OLED Display - BOTH ON
(Screenshots/Both ON.png)

OLED Display - ALTERNATE
(Screenshots/Alternate.png)

OLED Display - PWM FADE
(Screenshots/pwm fade.png)







