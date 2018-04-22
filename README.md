# RFID4PET

นำเทคโนโลยี RFID มาใช้เพื่อการระบุตัวตนของสัตว์เลี้ยง โดยที่จะแสกนรหัสออกมาแล้วส่งเข้าสู่ Firebase เพื่อนำมาแสดงผล


### Prerequisites

install all of these in order to run.

Software

* [arduino software](https://www.arduino.cc/)
* [Firebase](https://firebase.google.com/)
* [ArduinoJson](https://github.com/bblanchon/ArduinoJson)
* [Firebase arduino master](https://github.com/googlesamples/firebase-arduino/archive/master.zip)
* [MFRC522](https://www.arduinolibraries.info/libraries/mfrc522)
* [NodeMCU](http://arduino.esp8266.com/stable/package_esp8266com_index.json)
* [USB-TTL](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)

Hardware
* NodeMCU
* MFRC522
* Breadboard
* Jumper wire
* USB

### Installing & Deployment

1. เปิดโปรแกรม arduino
2. เสียบสาย USB ระหว่าง NodeMCU และคอมพิวเตอร์เพื่อเชื่อมต่อกัน
3. แสกนบัตรเพื่อดู Serial ID ของการ์ด
4. restart board
5. รอจนกว่าบอร์ดจะเชื่อมต่อกับ WIFI
6. ทดลองใช้โดยการแตะบัตร
   - ถ้าบัตรมีตัวตนในฐานข้อมูล
     - ก็จะแสดงข้อมูลออกมาโดยดึงจากfirebase
   - ถ้าไม่มีตัวตนในฐานข้อมูล
     - ก็จะให้กรอกข้อมูลผ่านserial และข้อมูลจะถูกบันทึกใน Firebase
7. เป็นอันเสร็จสิ้น


## Running the tests

Explain how to run the automated tests for this system

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```


## Built With

* [arduino](https://www.arduino.cc/)
* [Firebase](https://firebase.google.com/)
* [ArduinoJson](https://github.com/bblanchon/ArduinoJson)
* [Firebase arduino master](https://github.com/googlesamples/firebase-arduino/archive/master.zip)
* [MFRC522](https://www.arduinolibraries.info/libraries/mfrc522)
* [NodeMCU](http://arduino.esp8266.com/stable/package_esp8266com_index.json)
* [USB-TTL](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)


## Authors

* **จิรพัส วงษ์พิทักษ์** - *60070009* - [glass123451](https://github.com/glass123451)
* **เจตวัฒน์ อรรถการพงษ์** - *60070011* - [seenosea](https://github.com/seenosea)
* **ฐิติโชติ ใจเมือง** - *60070019* - [Thitichote](https://github.com/Thitichote)


## Acknowledgments

* Hat tip to anyone who's code was used
* Inspiration
* etc
