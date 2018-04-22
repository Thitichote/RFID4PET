# RFID4PET

นำเทคโนโลยี RFID มาใช้เพื่อการระบุตัวตนของสัตว์เลี้ยง โดยที่จะแสกนรหัสออกมาแล้วส่งเข้าสู่ Firebase เพื่อนำมาแสดงผล


### Prerequisites

Install all of these in order to run.

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

ต่อวงจรดังนี้
![30849593_1884567464901540_1185405761_o](https://user-images.githubusercontent.com/32869870/39094851-b6f4d5b6-4660-11e8-902d-565304c937fe.jpg)

### Installing & Deployment

1. เปิดโปรแกรม arduino
2. เสียบสาย USB ระหว่าง NodeMCU และคอมพิวเตอร์เพื่อเชื่อมต่อกัน
3. แสกนบัตรเพื่อดู Serial ID ของการ์ด
4. Restart board
5. รอจนกว่าบอร์ดจะเชื่อมต่อกับ WIFI
6. ทดลองใช้โดยการแตะบัตร
   - ถ้าบัตรมีตัวตนในฐานข้อมูล
     - ก็จะแสดงข้อมูลออกมาโดยดึงจาก Firebase
   - ถ้าไม่มีตัวตนในฐานข้อมูล
     - ก็จะให้กรอกข้อมูลผ่าน Serial และข้อมูลจะถูกบันทึกใน Firebase
7. เป็นอันเสร็จสิ้น

![31120749_1521537947974140_4591657383335297024_n](https://user-images.githubusercontent.com/32869870/39095766-1ebd74aa-4670-11e8-904f-c762290325df.png)
![30768448_1884632678228352_1377096472_o](https://user-images.githubusercontent.com/32869870/39095773-2e234d16-4670-11e8-8a7b-db4b269bff10.png)



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

* ผศ. ดร. กิติ์สุชาติ พสุภา
* ผศ. ดร. ปานวิทย์ ธุวะนุติ

     รายงานนี้เป็นส่วนหนึ่งของวิชา Computer Programming (รหัส 06016206) 
เทคโนโลยีสารสนเทศ สถาบันเทคโนโลยีพระจอมเกล้าเจ้าคุณทหารลาดกระบัง
