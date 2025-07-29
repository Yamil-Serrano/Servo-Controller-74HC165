# 74HC165-Servo-Control

A basic controller setup for two servos using an **input shift register** (74HC165) to read button states with minimal GPIO usage. The servos respond to specific button presses, allowing directional control (left/right) for each servo.

---

> ⚠️ Note: This is a simple project to demonstrate reading inputs using a shift register and controlling servos accordingly. It serves as a great starting point for robotics or remote-controlled mechanisms.

---

## 🧩 Part of the Shift Register I/O Expansion Series

This project builds upon concepts introduced in earlier repos:

- **Part 1**:  [74HC595-Microcontroller-Output-Expansion](https://github.com/Yamil-Serrano/74HC595-Microcontroller-Output-Expansion)  
- **Part 2**:  [74HC165-Microcontroller-Input-Expansion](https://github.com/Yamil-Serrano/74HC595-Microcontroller-Input-Expansion)

---

## What You'll Learn

* How to read multiple button inputs using the 74HC165
* How to decode button states with bitwise operations
* How to control two servos with only a few GPIO pins
* How to synchronize hardware inputs and mechanical movement

---

## How It Works

* The 74HC165 shift register reads the state of 8 buttons.
* The microcontroller reads this byte using a shared clock and latch system.
* If a specific bit is `HIGH`, the corresponding servo rotates:

  * D7 → Servo 0 Left
  * D6 → Servo 0 Right
  * D5 → Servo 1 Left
  * D4 → Servo 1 Right
* If no relevant buttons are pressed, both servos return to center (90°).

---

## Hardware Used

* Arduino UNO microcontroller
* 74HC165 (Input shift register)
* 2 Push buttons for each servo (4 total)
* 2 Servos (MG996R or similar)
* Breadboard + jumper wires
* Pull-down resistors (10kΩ)

---

## Getting Started

1. Clone this repository:

```bash
git clone https://github.com/Yamil-Serrano/74HC165-Servo-Control
```

2. Open `src/main.cpp` in Arduino IDE or PlatformIO.
3. Wire the circuit using the pin definitions in the code.
4. Upload and interact with your servos using buttons!

---

## Pinout Summary

| Function         | Pin (ESP/Arduino) |
| ---------------- | ----------------- |
| 74HC165 Clock    | D13               |
| 74HC165 Latch    | D12               |
| 74HC165 Data Out | D11               |
| Servo 0          | D10               |
| Servo 1          | D9                |

---
# Diagram

![Screenshot 2025-07-29 144918](https://github.com/user-attachments/assets/a340de93-ccc4-4e35-84c3-de20e3b95bcc)


## License

This project is licensed under the MIT License – see the [LICENSE](LICENSE.md) file for details.

---

## Contact

If you have any questions or suggestions, feel free to reach out to me:

GitHub: [Neowizen](https://github.com/Yamil-Serrano)
