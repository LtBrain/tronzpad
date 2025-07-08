# **Tronzpad**
Tronzpad is a 12 key + 1 encoder macropad that has 12 individually addressable LEDs to provide underglow & backlighting.
It was developed for an entry for **Hackclub Highway**'s YSWS project (Hackpad) and has the ability to perform **macros** and other
cool stuff with VIAL & QMK.


![tronzpad 1 (1)](https://github.com/user-attachments/assets/6a4746cd-92b8-45e1-8ab6-4d9c48a2bef1)

## Features
   - [x] **12 Cherry MX switches**  
   - [x] **EC-11 Rotary Encoder + Push Button**  
   - [x] **12 Individually Adressable SK6812 MINI LEDs**  
   - [x] **Custom QMK and VIAL Features**  
   - [x] **Powered By A XIAO RP2040**

## PCB

All of the circuitry and PCB design was done with KiCAD 8.0 on Windows 11

#### Schematic

![tronzpad_sch-1](https://github.com/user-attachments/assets/a59e2026-ff48-4aca-8f87-1cd586d7ff5d)  

#### PCB Design

![image](https://github.com/user-attachments/assets/7225c51e-16d8-41e6-81f2-1466e0e91ab4)

Credits to Joe Scotto for the footprints.

## Firmware

QMK and VIAL are meant to be used on Tronzpad for firmware.
   - [x] **Customizable keymap and layout**
   - [x] **12 keys for macros**
   - [x] **Compilable with QMK MSYS on Win11 and Linux (MacOS not tested)**
   - [x] **Real-time/On the fly configuration**
   - [x] **Layer Switching**  
### **How to Compile the Firmware**  
```qmk compile -kb tronzpad -km default```  
  
Paste this into a **MSYS** terminal on Windows or into a Linux terminal with **QMK** already setup.  
(You have to be in the **directory** for this to work)

## Case Assembly
   The case for the Tronzpad was designed to be minimalistic, exposing the graphics on the PCB silkscreen. It is composed of two 3D printed parts, a plate piece and the main assembly.
   The case has 4 2.9mm holes designed to accommodate M3 screws to hold the PCB in place. The plate sits on top of the PCB's top layer to provide a cosmetic/semi-functional layer for 
   the switches to be seated in. 

   ### Plate
   ![tronzpad 1 (2)](https://github.com/user-attachments/assets/d26cf02f-f786-46ef-9ef3-2593b20badfe)

   ### Main Case
   ![tronzpad 1 (3)](https://github.com/user-attachments/assets/5db9a6ba-11bc-4787-be42-7c94eafe2cd0)




## Bill of Materials  

| Quantity | Component | Description |
| --- | --- | --- |
| `1` | **Seeed Studio XIAO RP2040** | MCU |
| `12` | **Cherry MX Keyswitches** | I/O |
| `1` | **EC11 Rotary Encoder** | I/O |
| `13` | **1N4148 Diodes** | Support |
| `15` | **SK6812 MINI LEDs** | I/O | 
| `12` | **DSA Keycaps** | Support |
| `4` | **M3x16mm Screws**| Support |
| `1` | **Case Plate**| Support |
| `1` | **Main Case**| Support |
| `1` | **PCB (From JLCPCB)**| Circuit |  





**Summer, 2025**




