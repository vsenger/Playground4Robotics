//Upload Instructions
//  Tools
//  Board: Node32s
//  UploadSpeed: 230400
//  FlashFrequency: 80MHz



/****** ESP32 GPIO MAP ******  

GPIO0 -> Firmware Upload Mode
GPIO1 -> TXD
GPIO3 -> RXD

GPIO5 -> Led 1
GPIO4 -> Led 2
GPIO12 -> Led 3
GPIO15 -> Led 4

GPIO16 -> Serial 2 (RX)
GPIO17 -> Serial 2 (TX)

GPIO21 -> I2C (SDA)
GPIO22 -> I2C (SCL)

GPIO23 -> User Button (0=pressed / 1=not pressed)

GPIO26 -> ADXL345 sensor Interrupt Input (optional- must be configured conecting SJ4 or SJ5)

GPIO27 -> Sensors and Display Power control (0=Power OFF / 1=Power ON)

GPIO32 -> Battery voltage (Analog INPUT)
GPIO33   -> (External Analog INPUT)
GPIO34   -> (External Analog INPUT)
GPIO35   -> (External Analog INPUT)  
GPIO36 SENSORVP -> (External Analog INPUT) 

GPIO18 -> RIGHT MOTOR - BAK
GPIO19 -> RIGHT MOTOR - FOR

GPIO13 -> LEFT MOTOR - BAK
GPIO14 -> LEFT MOTOR - FOR

GPIO20 -> ENCODER
GPIO25 -> ENCODER

GPIO6 a GPIO11 -> Do not Use (Flash Memory)

GPIO2 -> External GPIO
GPIO4 -> External GPIO
GPIO5 ->  External GPIO
GPI12 ->  External GPIO
GPI15 ->  External GPIO
GPI12 ->  External GPIO
SensorVN - >  External GPIO

*/

#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <Wire.h>
#include "ssd1306.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

// Include logo images
#include "Logo_AWS.h"

#include <SparkFun_ATECCX08a_Arduino_Library.h> //Click here to get the library: http://librarymanager/All#SparkFun_ATECCX08a
//#include <Wire.h>

ATECCX08A atecc;


#define hostName "PCB_PlayGround4Robotics_1"

/* Assign a unique ID to this sensor at the same time */
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

#define SSD1306_128_64

long startTime;

#define led1 5
#define led2 4
#define led3 12
#define led4 15
#define delayLeds 100
bool direcao = false;
int userButtonState = 1;


// Motor A (Right)
int motor1_IA = 13; 
int motor1_IB = 14; 

// Motor B (Left)
int motor2_IA = 18; 
int motor2_IB = 19; 

double AN_36_voltage;
double AN_35_voltage;
double AN_34_voltage;
double AN_33_voltage;

double batteryVoltage;
bool batteryChargeStatus ;  //(1-CHARGED)
int batteryStatusPerCent;

#define batteryStatusPin 25

float Xacc;
float Yacc;
float Zacc;

const char* ssid = "ASSIST";
const char* password = "Assist@2017";

#define SSD1306_128_32

void setup() {
  pinMode(27,OUTPUT);       //power ON sensors and OLED display
  digitalWrite(27,HIGH);
  pinMode(25,INPUT);        
  pinMode(23,INPUT_PULLUP);    //enable user button pull-up
  delay(2000);

  Serial.begin(115200);
  Serial2.begin(115200);

  //checkAttec608();
  
  // sets the pins as outputs:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(motor1_IA, OUTPUT);
  pinMode(motor1_IB, OUTPUT);
  pinMode(motor2_IA, OUTPUT);
  pinMode(motor2_IB, OUTPUT);
  digitalWrite(motor1_IA,LOW);
  digitalWrite(motor1_IB,LOW);
  digitalWrite(motor2_IA,LOW);
  digitalWrite(motor2_IB,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);


  Wire.begin();  
  ssd1306_128x64_i2c_init();                     // Initialze SSD1306 OLED display
  ssd1306_clearScreen( );
  ssd1306_drawBitmap(0, 0, 128, 64, Logo_AWS);
  delay(3000);

  ssd1306_clearScreen( );
  ssd1306_setFixedFont(ssd1306xled_font5x7);            // Set font type (default 6x8)
  //oled.setTextXY(0,0);              // Set cursor position, start of line 0


  inicializaAcelerometro();

  Serial.println("Booting");
  Serial2.print("Ready...");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  inicializa_OTA();

  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  IPoled();

  motor_left_Forward();
  delay(2000);
  motor_left_Stop();
  delay(2000);
  motor_left_Backwards();
  delay(2000);
  motor_left_Stop();
  delay(2000);
  motor_right_Forward();
  delay(2000);
  motor_right_Stop();
  delay(2000);
  motor_right_Backwards();
  delay(2000);
  motor_right_Stop();
  delay(2000);
  motor_left_Forward();
  motor_right_Forward();
  delay(2000);
  motor_left_Stop();
  motor_right_Stop();
  delay(2000);
  motor_left_Backwards();
  motor_right_Backwards();
  delay(2000);
  motor_left_Stop();
  motor_right_Stop();
  delay(2000);


  
}

void loop() {
  ArduinoOTA.handle();
  //testeLeds();
  delay(500);
  leAcelerometro();
  //le_voltagem_painelSolar();
  le_voltagem_bateria();
  le_battery_status();
  userButtonState = digitalRead(23);
  buttonOled();

  le_voltagem_portasAnalogicas();

  if (Serial2.available()>0){
    String serialText = "";
    while(Serial2.available()>0){
      serialText = serialText + char(Serial2.read()); 
    }
    serialtextToOled(serialText);
  }

}
