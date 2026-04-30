# Camera CTR - High-Speed & Lightning Photography Trigger

### Description
**Arduino-based camera trigger for high-speed lightning photography. Features include auto-threshold light sensors, sound triggers, time-lapse, long exposure, and interval timers. Developed in 2015, this field-tested prototype uses an LCD interface and EEPROM to store settings for professional storm chasing.**

## Prototype
The device was developed through multiple iterations, moving from breadboards to a finalized prototype with a dedicated housing and interface.

![Camera CTR Prototype](Docs/Photos/20161024_200539.jpg)

## Features
* **Lightning Auto-Trigger:** Automatically calculates sensitivity thresholds based on ambient light to capture strikes instantly.
* **Lightning Manual Mode:** Manual adjustment of light sensitivity for specific atmospheric conditions.
* **Sound Sensor Trigger:** Fires the camera based on acoustic events (like thunder) with adjustable sensitivity.
* **Time-Lapse Mode:** Captures sequences with programmable intervals.
* **Long Exposure Controller:** Precision shutter control for exposures up to 120 seconds.
* **Interval Timer:** Countdown timer for delayed photography.
* **Manual Mode:** Standard digital remote shutter functionality.

## Hardware Configuration
The project is built on the Arduino platform using an ATmega chip and a 16x2 LCD. 
The pin mapping as defined in the source code is:

| Component | Pin |
| :--- | :--- |
| **Camera Shutter (Trigger)** | 10 |
| **Ready/Status LED** | 9 |
| **Photometer (Light Sensor)** | A1 |
| **Sound Sensor** | A2 |
| **LCD Backlight Control** | A5 |
| **Keypad (Analog Buttons)** | A0 |

### LCD Pinout (LiquidCrystal)
* **RS:** 2, **Enable:** 3, **D4-D7:** 4, 5, 6, 7.

## Software Logic & Memory
The system utilizes the internal EEPROM to persist user settings across power cycles, ensuring your field configurations are never lost:
* **EEPROM 01:** Time Lapse Delay settings.
* **EEPROM 02:** Long Exposure parameters.
* **EEPROM 03:** Timer Delay.
* **EEPROM 04:** Lightning Manual Sensitivity.
* **EEPROM 05:** Sound Sensor Thresholds.

## Sample Photos
These images were captured using the Camera CTR trigger, demonstrating its ability to sync the shutter with lightning discharges during actual storms.

| | |
|:---:|:---:|
| ![Lightning Sample 1](Docs/Photos/2015-01-26%2009.17.11-2.jpg) | ![Lightning Sample 2](Docs/Photos/DSC_0063.NEF.jpg) |
| ![Lightning Sample 3](Docs/Photos/DSC_0080.NEF.jpg) | ![Lightning Sample 4](Docs/Photos/DSC_0083.NEF.jpg) |
| ![Lightning Sample 5](Docs/Photos/DSC_0090.NEF.jpg) | |

## Video Documentation & Tutorials
A comprehensive video series covers the hardware assembly, programming logic, and real-world field tests. You can follow the development and see the device in action:

**[📺 Camera CTR Project - YouTube Playlist](https://www.youtube.com/playlist?list=PLX2YtMdpQuUke00zPxl_PeEOyKNRLNvi6)**

### Key Technical Insights
* **Programming Logic:** Detailed breakdown of the Arduino code structure, including the custom `ReadKeypad` functions and menu navigation.
* **Field Testing:** Real footage of the sensor triggering the camera during lightning storms.

## Version History (2015-2016)
* **v0.1 - v0.3:** Initial counters for Time Lapse and Long Exposure.
* **v0.5 - v0.7:** Implementation of Lightning Photo and auto-threshold logic.
* **v0.8 - v0.10:** Integration of Sound Sensor and timing corrections.
* **v0.12 - v0.16:** Final UI refinements, Manual Mode, and Backlight management.

---
*Project by Renato Brant.*
