# EVENT-BOARD-RTC-DRIVEN-MESSAGE-DISPLAY-SYSTEM
## 📌 Overview

EventBoard is an Embedded Systems project developed using the **LPC2148 ARM7 Microcontroller**. The system automatically displays predefined messages on a **16x2 LCD** based on real-time clock (RTC) data.

The project allows authorized users to enter **Admin Mode** through a keypad interface, modify RTC settings, and enable or disable scheduled events. When no event is active, the system displays the current date, time, and room temperature measured using an **LM35 temperature sensor**. 

---

## 🚀 Features

* RTC-based automatic message scheduling
* 10 predefined event messages stored in memory
* Secure Admin Mode access
* RTC Time and Date Editing
* Event Enable/Disable Control
* LCD Message Scrolling
* LM35 Temperature Monitoring
* Real-Time Clock Display
* Keypad-Based User Interface
* Modular Embedded C Code Structure

---

## 🛠 Hardware Requirements

* LPC2148 ARM7 Development Board
* 16x2 LCD Display
* 4x4 Matrix Keypad
* LM35 Temperature Sensor
* Buzzer
* LEDs
* Power Supply (5V)

---

## 💻 Software Requirements

* Embedded C
* Keil uVision
* Flash Magic

---

# 📂 Project Structure

```text
MINI-PROJECT1
│
├── ADC
│   ├── adc.c
│   ├── adc.h
│   └── adc_defines.h
│
├── LCD
│   ├── lcd.c
│   ├── lcd.h
│   └── lcd_defines.h
│
├── KPM
│   ├── kpm.c
│   ├── kpm.h
│   └── kpm_defines.h
│
├── RTC
│   ├── rtc.c
│   └── rtc.h
│
├── MAIN
│   ├── maincontrol.c
│   ├── admin.c
│   └── admin.h
│
├── delay.c
├── delay.h
├── defines.h
└── types.h
```

---

# 🔌 Hardware Connections

## LCD Connections

| LCD Pin | LPC2148 Pin   |
| ------- | ------------- |
| D0-D7   | P0.16 – P0.23 |
| RS      | P0.28         |
| EN      | P0.29         |
| RW      | P0.30         |

---

## Keypad Connections

### Rows

| Keypad Row | LPC2148 Pin |
| ---------- | ----------- |
| ROW0       | P1.16       |
| ROW1       | P1.17       |
| ROW2       | P1.18       |
| ROW3       | P1.19       |

### Columns

| Keypad Column | LPC2148 Pin |
| ------------- | ----------- |
| COL0          | P1.20       |
| COL1          | P1.21       |
| COL2          | P1.22       |
| COL3          | P1.23       |

---

## Admin Switch

| Device       | LPC2148 Pin |
| ------------ | ----------- |
| Admin Switch | P1.24       |

---

## LM35 Sensor

| LM35 Pin | LPC2148 Pin               |
| -------- | ------------------------- |
| Output   | AD0.1 (P0.28 ADC Channel) |
| VCC      | +5V                       |
| GND      | GND                       |

---

# ⚙️ Working Principle

### Normal Mode

1. LPC2148 reads current time from RTC.
2. The controller continuously checks all scheduled events.
3. If an event time matches:

   * Message is displayed on LCD.
   * LCD scrolls the message.
   * Remaining time is shown.
4. If no event is active:

   * RTC Time is displayed.
   * RTC Date is displayed.
   * Temperature from LM35 is displayed.

---

### Admin Mode

Admin Mode is entered using a dedicated switch.

Available options:

```text
1. RTC Edit
2. Event Edit
3. Exit
```

### RTC Edit Menu

```text
1. Hour
2. Minute
3. Second
4. Date
5. Month
6. Year
7. Week
8. Exit
```

User can modify RTC values directly using the keypad.

---

### Event Edit Menu

User can:

* Select Event Number
* Activate Event
* Deactivate Event

Example:

```c
messageList[event_no].enabled = 1;
```

Enable Event

```c
messageList[event_no].enabled = 0;
```

Disable Event

---

# 📝 Event Data Structure

```c
#define TOTAL_MESSAGES 10

typedef struct
{
    u8 hour;
    u8 minute;
    char text[80];
    u8 enabled;
} Message;
```

---

# 📋 Default Scheduled Events

Examples:

```c
{7,45,"Good Morning! Classes Start Soon",1}
{13,45,"C Programming Session in Classroom Number 2",1}
{12,45,"Lunch Break from 1PM - 2PM",1}
{17,45,"End of Day - See You Tomorrow!",1}
```

Initially all messages are enabled. 

---

# 🔄 System Workflow

```text
Start
  │
  ▼
Initialize RTC
Initialize LCD
Initialize Keypad
Initialize ADC
  │
  ▼
Read Current RTC Time
  │
  ▼
Check Admin Switch
  │
  ├── Pressed → Admin Mode
  │
  └── Not Pressed
          │
          ▼
Check Scheduled Events
          │
          ├── Event Active
          │      │
          │      ▼
          │ Display Event
          │ Show Remaining Time
          │
          └── No Event
                 │
                 ▼
          Display RTC
          Display Date
          Display Temperature
```

---

# 📊 Temperature Calculation

The LM35 outputs:

```text
10 mV / °C
```

Formula:

```text
Temperature (°C) =
ADC Voltage / 10mV
```

For LPC2148 ADC:

```text
Voltage =
(ADC_Value × 3.3) / 1023
```

---

# 🔑 Key Learning Concepts

* RTC Programming
* LCD Interfacing
* Keypad Interfacing
* ADC Programming
* Embedded C Modular Design
* Event Scheduling
* Time-Based Automation
* ARM7 LPC2148 Programming

---

# 🎯 Applications

* College Notice Boards
* Smart Classrooms
* Office Reminder Systems
* Event Scheduling Systems
* Industrial Information Displays
* Automated Announcement Systems

---

# 👨‍💻 Author

**Mohammad Abdul Rehaman Baig**

B.Tech – Electronics and Communication Engineering (ECE)

Embedded Systems Project using LPC2148 ARM7 Microcontroller.

---


