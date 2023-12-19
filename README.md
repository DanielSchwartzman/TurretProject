# About TurretProject
"Turret" is a Python-Arduino project that uses facial recognition python libraries to detect and track human faces in real-time.
Once a face is identified, the Arduino-controlled Nerf dart shooter automatically aims and fires a Nerf dart at the target. 
An interactive and engaging project that combines facial recognition and robotics for fun and entertainment.

## Instruction:
Upload the Arduino code from the "Arduino" directory to your arduino, connect any camera device to your computer and simply launch
the Python program.

## ⚠️Notes⚠️:
1. In Main.py line-7 "arduino = serial.Serial('COM6', 9600)", COM6 port name may be different on your device, to find which port you use
   on your arduino, got to Start menu/"Device Manager"/Ports(COM & LPT)
3. The project is divided into two parts, the Python code and Arduino code(Which can be found under "Arduino" folder)

## Authors
- [@DanielSchwartzman](https://github.com/DanielSchwartzman)
