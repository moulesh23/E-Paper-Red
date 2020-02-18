// mapping suggestion for ESP32, e.g. LOLIN32, see .../variants/.../pins_arduino.h for your board
// NOTE: there are variants with different pins for SPI ! CHECK SPI PINS OF YOUR BOARD
// BUSY -> 4, RST -> 16, DC -> 17, CS -> SS(5), CLK -> SCK(18), DIN -> MOSI(23), GND -> GND, 3.3V -> 3.3V
// include library, include base class, make path known
#include "images.h"
#include "offer.h"
#include <GxEPD.h>
//#include <GxGDEW075T8/GxGDEW075T8.h>      // 7.5" b/w
//#include <GxGDEW075T8/GxGDEW075T8.cpp>
// select the display class to use, only one
//#include <GxGDEW075Z09/GxGDEW075Z09.h>    // 7.5" b/w/r
#include <GxGDEW075Z08/GxGDEW075Z08.h>    // 7.5" b/w/r 800x480
//#include GxEPD_BitmapExamples

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

//#if defined(ESP32)

// for SPI pin definitions see e.g.:
// C:\Users\xxx\Documents\Arduino\hardware\espressif\esp32\variants\lolin32\pins_arduino.h

GxIO_Class io(SPI, /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16); // arbitrary selection of 17, 16
GxEPD_Class ePaper(io, /*RST=*/ 16, /*BUSY=*/ 4); // arbitrary selection of (16), 4

//#endif

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup....");
  ePaper.init(115200);

  //display.init(115200); // enable diagnostic output on Serial

  Serial.println("setup done");

  
  ePaper.setTextColor(GxEPD_BLACK);
  
  //ePaper.fillRect(, 200, 24, 24, GxEPD_BLACK);
  ePaper.drawPaged(epaperUpdate);
 }

/*void epaperUpdate()
{
  ePaper.eraseDisplay();
  
  ePaper.fillScreen(GxEPD_RED);
  ePaper.fillRect(400,380,400,100, GxEPD_WHITE);
  const GFXfont* f = &FreeMonoBold24pt7b;
  ePaper.setFont(f);
  ePaper.setCursor(410, 480);
  ePaper.println("Hello Makoniss!");
  void updateDisplay() {
  Serial.println("Updating Display");
  ePaper.init(115200); // enable diagnostic output on Serial
  Serial.println("Init Display");
  ePaper.drawPaged(epaperUpdate);
}*/


void epaperUpdate() {

  char dis[]="50%";
  double prev_price=4999;
  double off_price=2499;
  char ssize[]="XXL";
  char mat[]="Cotton";
  char brand[]="Peter England";
  char comm_name[]="SHIRT";
  
  ePaper.eraseDisplay();
  
  //*****************Client LOGO**************
  ePaper.drawBitmap(gImage_new, 0, 0, 100, 100, GxEPD_BLACK);
  ePaper.update();
  

  //*************Product Name*******************
  ePaper.fillRect(101,0,800-101,100,GxEPD_BLACK);  
  ePaper.setTextColor(GxEPD_WHITE);
  const GFXfont* h = &FreeMonoBold24pt7b;
  ePaper.setFont(h);
  ePaper.setCursor(400,80);
  ePaper.println(comm_name);

  //************Border**************************
  ePaper.fillRect(0,98,101,2,GxEPD_BLACK);
  ePaper.fillRect(600,100,2,301,GxEPD_BLACK);
  ePaper.fillRect(300,100,2,301,GxEPD_BLACK);

  //**************Product Description*********
  ePaper.setTextColor(GxEPD_BLACK);
  const GFXfont* f = &FreeMonoBold12pt7b;
  ePaper.setFont(f);
  ePaper.setCursor(0,120);
  ePaper.println("Brand");
  ePaper.setTextColor(GxEPD_RED);
  ePaper.println(brand);
  ePaper.println("");
  
  ePaper.setTextColor(GxEPD_BLACK);
  ePaper.println("Size");
  ePaper.setTextColor(GxEPD_RED);
  ePaper.println(ssize);
  ePaper.println("");
  
  ePaper.setTextColor(GxEPD_BLACK);
  ePaper.println("Material");
  ePaper.setTextColor(GxEPD_RED);
  ePaper.println(mat);

  //************Product Prize*****************
  
  ePaper.setTextColor(GxEPD_BLACK);
  ePaper.setFont(f);
  ePaper.setCursor(310,130);
  ePaper.println("MRP \t");
  const GFXfont* g = &FreeMonoBold18pt7b;
  ePaper.setFont(g);
  ePaper.setTextColor(GxEPD_RED);
  ePaper.setCursor(310,170);
  ePaper.println(prev_price);

  ePaper.setTextColor(GxEPD_BLACK);
  ePaper.setFont(f);
  ePaper.setCursor(310,220);
  ePaper.println("Offer Price \t");
  ePaper.setFont(g);
  ePaper.setTextColor(GxEPD_RED);
  ePaper.setCursor(310,260);
  ePaper.println(off_price);
  

  //*************Discount**********************
  ePaper.setTextColor(GxEPD_RED);
  ePaper.setFont(h);
  ePaper.setCursor(640,170);
  ePaper.println(dis);
  ePaper.drawBitmap(gImage_offer, 640, 200, 130, 130, GxEPD_RED);
  ePaper.update();

  
  

  //************Server Name*********************
  ePaper.fillRect(0,401,800,480-301,GxEPD_BLACK);
  //const GFXfont* g = &FreeMonoBold12pt7b;
  ePaper.setTextColor(GxEPD_WHITE);
  ePaper.setFont(f);
  ePaper.setCursor(20,420 );
  ePaper.println("MAKONIS SOFTWARE SOLUTIONS Pvt.Ltd");
 
}

void loop()
{
}
