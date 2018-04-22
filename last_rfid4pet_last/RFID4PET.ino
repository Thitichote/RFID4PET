#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <SPI.h>
#include <MFRC522.h>
#include "config.h"

String Value = "";

MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

MFRC522::MIFARE_Key key; 

// Init array that will store new NUID 
byte nuidPICC[4];

void setup() { 
  Serial.begin(baud);
  Serial.println(WiFi.localIP());
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting\n");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(250);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_KEY); //init database
  /*FirebaseNew("30c3d449", "1", "Job", "Dog", "Bulldog", "Male", "5/17/2549", "Brown", "Jettawat", "086 770 3121");*/ //Test on empty serial card
  FirebaseNew("a024f56b", "2", "Donut", "Cat", "Persian", "Male", "12/12/2557", "Black", "Supakit", "085 551 2134");
  FirebaseNew("f255ddc1", "3", "Nine", "Boar", "Scrofa", "Female", "6/2/2560", "Yellow", "Somsak", "086 143 4422");
  FirebaseNew("4c51d322", "4", "Pee", "Crocodie", "Philippine", "Male", "2/25/2541", "Rainbow", "Sumet", "1669");
  FirebaseNew("f255dd49", "5", "Tew", "Rabbit", "Alaska", "Female", "1/27/2558", "Grey", "Sorayut", "090 231 5759");
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522 
  
  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }
  Serial.println(F("This code scan the MIFARE Classsic NUID."));
  Serial.print(F("Using the following key:"));
  printHex(key.keyByte, MFRC522::MF_KEY_SIZE);
}
 
void loop() {
  // Look for new cards
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&  
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }

    Serial.println(F("A new card has been detected."));

    // Store NUID into nuidPICC array
    for (byte i = 0; i < 4; i++) {
      nuidPICC[i] = rfid.uid.uidByte[i];
    }
   
    Serial.println(F("The NUID tag is:"));
    Serial.print(F("In hex: "));
    printHex(rfid.uid.uidByte, rfid.uid.size);
    Serial.println();
    sentValue(rfid.uid.uidByte, rfid.uid.size);
    Serial.println();
    Serial.print(F("In dec: "));
    printDec(rfid.uid.uidByte, rfid.uid.size);
    Serial.println();
    //Serial.println(Value);
    // Start Firebase
    FirebaseObject data = Firebase.get(Value);
    if(data.isNullString()){
      // If null
      Serial.println("Card wasn't found");    //if no data correlation with card, start to push data
      Serial.println("--------------------------------------------------");
      /*Serial.print("Enter number : ");
      delay(10000);
      Serial.println(gotnumber);*/
      String gotnumber = Serial.readString();
      
      Serial.print("Enter name : ");
      delay(10000);
      String gotname = Serial.readString();
      Serial.println(gotname);
      
      Serial.print("Enter kind : ");
      delay(10000);
      String gotkind = Serial.readString();
      Serial.println(gotkind);
      
      Serial.print("Enter specie : ");
      delay(10000);
      String gotspecie = Serial.readString();
      Serial.println(gotspecie);
      
      Serial.print("Enter sex : ");
      delay(10000);
      String gotsex = Serial.readString();
      Serial.println(gotsex);
      
      Serial.print("Enter date of birth : ");
      delay(10000);
      String gotdob = Serial.readString();
      Serial.println(gotdob);
      
      Serial.print("Enter color : ");
      delay(10000);
      String gotcolor = Serial.readString();
      Serial.println(gotcolor);
      
      Serial.print("Enter owner name : ");
      delay(10000);
      String gotown = Serial.readString();
      Serial.println(gotown);
      
      Serial.print("Enter contact : ");
      delay(10000);
      String gotcon = Serial.readString();
      Serial.println(gotcon);
      
      FirebaseNew(Value,gotnumber,gotname,gotkind,gotspecie,gotsex,gotdob,gotcolor,gotown,gotcon);
      String Target = "";
      Serial.println("Card has updated successful!!!");
      Serial.println("--------------------------------------------------");
    }else{
      // If have data
      String Target = Value;
      Serial.println("--------------------------------------------------");
      
      Serial.print("RFID code : ");
      Serial.println(Target);
      
      /*Serial.print("Number : ");
      String Number = Firebase.getString(Target+"/NUMBER");
      Serial.println(Number);*/

      Serial.print("Pet's Name : ");
      String Name = Firebase.getString(Target+"/NAME");
      Serial.println(Name);
      
      Serial.print("Kind : ");
      String Kind = Firebase.getString(Target+"/KIND");
      Serial.println(Kind);

      Serial.print("Specie : ");
      String Specie = Firebase.getString(Target+"/SPECIE");
      Serial.println(Specie);

      Serial.print("Gender : ");
      String Gender = Firebase.getString(Target+"/GENDER");
      Serial.println(Gender);

      Serial.print("Date of Birth : ");
      String Dateofbirth = Firebase.getString(Target+"/DATEOFBIRTH");
      Serial.println(Dateofbirth);

      Serial.print("Colors : ");
      String Colors = Firebase.getString(Target+"/COLORS");
      Serial.println(Colors);

      Serial.print("Owner : ");
      String Owner = Firebase.getString(Target+"/OWNER");
      Serial.println(Owner);

      Serial.print("Contact tel : ");
      String Contact = Firebase.getString(Target+"/CONTACT");
      Serial.println(Contact);

      Serial.println("------------------------------------------------");
    }

  // Halt PICC
  rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
  Value = "";
}


/**
 * Helper routine to dump a byte array as hex values to Serial. 
 */
void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

/**
 * Helper routine to dump a byte array as dec values to Serial.
 */
void printDec(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], DEC);
  }
}

void sentValue(byte *buffer, byte bufferSize) {
  
  for (byte i = 0; i < bufferSize; i++) {
    buffer[i] < 0x10 ? " 0" : " ";
    Value += String(buffer[i], HEX);
  }
  Serial.println(String(Value));
  Serial.print("Sent successful");
}

void FirebaseNew(String Target, String Number, String Name, String Kind, String Specie, String Gender, String Dateofbirth, String Colors, String Owner, String Contact){
  Firebase.setString(Target+"/NUMBER", Number);
  Firebase.setString(Target+"/NAME", Name);
  Firebase.setString(Target+"/KIND", Kind);
  Firebase.setString(Target+"/SPECIE", Specie);
  Firebase.setString(Target+"/GENDER", Gender);
  Firebase.setString(Target+"/DATEOFBIRTH", Dateofbirth);
  Firebase.setString(Target+"/COLORS", Colors);
  Firebase.setString(Target+"/OWNER", Owner);
  Firebase.setString(Target+"/CONTACT", Contact);
}

