# Simple Calculator (Decimal-Binary-Octal) Project

This repository contains the source code for an embedded calculator project. The project implements a simple calculator using a 16x2 LCD, 4x4 keypad, and PIC18F4620 microcontroller.
The calculator supports addition, subtraction, multiplication, and division of two decimal, binary, or octal numbers.

## Features

- Arithmetic operations: Addition, subtraction, multiplication, and division.
- Number systems: Decimal, binary, and octal.
- User interface: 16x2 LCD for display and a 4x4 keypad for input.
- Mode switching: Change number system mode by pressing the mode button and entering the corresponding number on the keypad (1 for decimal, 2 for octal, 3 for binary).
- Error handling: Appropriate error messages for invalid input or division by zero.

## Hardware Requirements

- PIC18F4620 microcontroller
- 16x2 LCD module
- 4x4 keypad
- Supporting circuitry (resistors, PushButton, etc.)

## Software Requirements

- MPLAB X IDE
- XC8 compiler

## Usage

1. Connect the hardware components (LCD, keypad, and microcontroller) following the provided circuit diagram.
2. Open the project in MPLAB X IDE.
3. Build and program the code onto the PIC18F4620 microcontroller.
4. Power up the embedded system.
5. The calculator will start in the default decimal mode.
6. Enter the first number using the keypad.
7. Press the appropriate arithmetic operation key (+, -, *, or /).
8. Enter the second number using the keypad.
9. Press the "=" key to perform the calculation and display the result on the LCD.
10. To switch the number system mode, press the mode button and enter the corresponding number on the keypad (1 for decimal, 2 for octal, 3 for binary).
11. Repeat steps 6-10 for further calculations.

## Contributing

Contributions to this project are welcome. If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request.

