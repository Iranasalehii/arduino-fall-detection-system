# Arduino-Based Fall Detection System

A prototype fall detection system developed as my bachelor's final project using an Arduino Uno and an MPU6050 motion sensor.

## Overview

The system was designed to detect potential falls by monitoring changes in body orientation using the MPU6050 accelerometer.

When the sensor detects a significant tilt, the system activates a buzzer as an alert.

## Hardware

- Arduino Uno
- MPU6050 accelerometer and gyroscope
- Active-low buzzer
- Connecting wires

## How It Works

The MPU6050 measures acceleration along the X, Y, and Z axes.

The raw accelerometer data is converted to acceleration values in units of g. The system then monitors the Z-axis acceleration.

If the absolute value of `az` falls below `0.6 g`, the system considers this a significant change in orientation and activates the buzzer.

The sensor data is also displayed through the Serial Monitor at 9600 baud.

## Technical Details

- Microcontroller: Arduino Uno
- Motion sensor: MPU6050
- I2C address: `0x68`
- Accelerometer register: `0x3B`
- Wake-up register: `0x6B`
- Accelerometer scale: `16384 LSB/g`
- Buzzer pin: `11`
- Serial communication: `9600 baud`
- Tilt threshold: `|az| < 0.6 g`

## Project Purpose

This project demonstrates the use of:

- Embedded programming
- Arduino-based system design
- Sensor interfacing
- I2C communication
- Motion data acquisition
- Basic fall detection logic

## Files

- `fall_detection.ino` — Arduino source code

## Note

This project is a prototype developed for academic purposes. The detection method is based on sensor orientation and is not intended to replace a clinically validated fall detection system.
