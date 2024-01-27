# Hydration Reminder
Hydration reminder developed with Arduino platform. 

## Introduction
The designed hydration reminder can collect room temperature data from TMP36 temperature sensor, determine the suitable hydration interval and send visual notifications through LEDs and LCD. The program measures time interval without pausing which implements real-time monitoring on user response. 

## Workflow:
1. Collect room temperature data
2. Determine suitable hydration interval
3. Display room temperature during the interval
4. At the end of the interval, send visual notification, including:
    * LCD display
    * LEDs blink in sequence
5. Wait for user reponse
6. Stop the notification then repeat step 1-5

## Schematic
<img width="578" alt="schematic" src="https://github.com/Zixuan-Qiao/Hydration_Reminder/assets/102449059/e83d5005-bdf1-4474-ba3f-ddfecc1aad67">

## Demonstration
<img src="https://github.com/Zixuan-Qiao/learn/assets/102449059/6b949805-7307-40a2-81c9-891114550cc8" width="320" height="400">

<img src="https://github.com/Zixuan-Qiao/learn/assets/102449059/0c4530fa-10b6-43fa-aae0-801472a77f83" width="320" height="400">

## Language
C/C++

## Author
Zixuan (Alex) Qiao

## References
[1] https://www.arduino.cc/reference/en/

[2] https://www.arduino.cc/en/uploads/Main/TemperatureSensor.pdf

[3] https://docs.arduino.cc/built-in-examples/digital/BlinkWithoutDelay
