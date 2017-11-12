/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 by Daniel Eichhorn
 * Copyright (c) 2016 by Fabrice Weinberg
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */
//Sorapon Pondsomchai,, Faculty of Computer Engineering @Chulalongkorn University
// Include the correct display library
// For a connection via I2C using Wire include
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"`
#include <TimeLib.h>
#include <ESP8266WiFi.h>
#include <TaskScheduler.h>
#include <ESP8266WebServer.h>
#include <WebSocketsServer.h>
#include <ESP8266mDNS.h>
#include <WiFiClient.h>

// Include the UI lib
#include "OLEDDisplayUi.h"

// Include custom images
#include "images.h"

#define debounce 50

SSD1306  display(0x3c, D2, D1);
OLEDDisplayUi ui     ( &display );
Scheduler scheduler;
ESP8266WebServer server ( 80 );

const char* ssid = "ASUS";
const char* password = "12234567";
const int redBtn = D5;
const int greenBtn = D8;
const int leftBtn = D7;
const int rightBtn = D6;

const char* lightState[] = {lightOff, lightOff, lightOff};

String twoDigits(int digits){
  if(digits < 10) {
    String i = '0'+String(digits);
    return i;
  }
  else {
    return String(digits);
  }
}

void testcallback(){
  delay(1000);
}

void updateLoadingState(String stage, uint8_t progress){
   display.clear();
   display.setTextAlignment(TEXT_ALIGN_CENTER);
   display.setFont(ArialMT_Plain_10);
   display.drawString(64, 18, stage);
   display.drawProgressBar(4, 32, 120, 8, progress);
   display.display();
}
//-------------------------------Frames and Overlays-------------------------------
void msOverlay(OLEDDisplay *display, OLEDDisplayUiState* state) {
  String timenow = String(hour())+":"+twoDigits(minute())+":"+twoDigits(second());
  display->setTextAlignment(TEXT_ALIGN_RIGHT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(128, 0, timenow);
}

void homeFrame(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {

  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setFont(ArialMT_Plain_10);
  display->drawString(64 + x, 17 + y, "Info");
  display->drawString(64 + x, 28 + y, WiFi.localIP().toString());
  display->drawString(64 + x, 39 + y, WiFi.macAddress());

}

void lightFrame(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {

  display->drawXbm(x + 48, y + 20, icon_res, icon_res, lightOn);
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setFont(ArialMT_Plain_10);
  display->drawString(64 + x, 50 + y, "Light Control");
}

void acFrame(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {

  display->drawXbm(x + 48, y + 20, icon_res, icon_res, ac);
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setFont(ArialMT_Plain_10);
  display->drawString(64 + x, 50 + y, "AC Control");
}

void lightMenu1(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->drawXbm(x + 48, y + 20, icon_res, icon_res, lightState[0]);
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setFont(ArialMT_Plain_10);
  display->drawString(64 + x, 50 + y, "Light 1");
}

void lightMenu2(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->drawXbm(x + 48, y + 20, icon_res, icon_res, lightState[1]);
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setFont(ArialMT_Plain_10);
  display->drawString(64 + x, 50 + y, "Light 2");
}

void lightMenu3(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->drawXbm(x + 48, y + 20, icon_res, icon_res, lightState[2]);
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setFont(ArialMT_Plain_10);
  display->drawString(64 + x, 50 + y, "Light 3");
}

void acMenu1(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {

  display->drawXbm(x + 48, y + 20, icon_res, icon_res, ac);
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setFont(ArialMT_Plain_10);
  display->drawString(64 + x, 50 + y, "AC 1");
}

void acMenu2(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {

  display->drawXbm(x + 48, y + 20, icon_res, icon_res, ac);
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setFont(ArialMT_Plain_10);
  display->drawString(64 + x, 50 + y, "AC 2");
}

void acMenu3(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {

  display->drawXbm(x + 48, y + 20, icon_res, icon_res, ac);
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setFont(ArialMT_Plain_10);
  display->drawString(64 + x, 50 + y, "AC 3");
}
FrameCallback frames[] = { homeFrame, lightFrame, acFrame};
FrameCallback lightframes[] = { lightMenu1, lightMenu2, lightMenu3};
FrameCallback acframes[] = { acMenu1, acMenu2, acMenu3};
int frameCount = 3;
int lightCount = 3;
int acCount = 3;
OverlayCallback overlays[] = { msOverlay };
int overlaysCount = 1;

int menuState = 0;
int currentFrame = 0;
int tempFrame = 0;
int maxFrame = frameCount;
void nextMenu(){
  currentFrame++;
  if(currentFrame == maxFrame) currentFrame = 0;
  ui.transitionToFrame(currentFrame);
}
void previousMenu(){
  currentFrame--;
  if(currentFrame == -1) currentFrame = maxFrame-1;
  ui.transitionToFrame(currentFrame);
}
void selectMenu(){
  if(menuState == 0){
    if(currentFrame == 1){ ui.setFrames(lightframes, lightCount); menuState = 1;}
    else if(currentFrame == 2){ ui.setFrames(acframes, acCount); menuState = 2;}
    tempFrame = currentFrame;
    currentFrame = 0;
  }
  else if(menuState == 1){
    if(lightState[currentFrame] == lightOff) lightState[currentFrame] = lightOn;
    else if(lightState[currentFrame] == lightOn) lightState[currentFrame] = lightOff;
  }
}
void exitMenu(){
  ui.setFrames(frames, frameCount);
  if(menuState != 0) currentFrame = tempFrame;
  ui.switchToFrame(currentFrame);
  menuState = 0;
}

//----------------------------------------------------------------------------
void setup() {
  Serial.begin(115200);

  ui.setTargetFPS(60);
  
  ui.setActiveSymbol(activeSymbol);
  ui.setInactiveSymbol(inactiveSymbol);
  
  ui.setIndicatorPosition(TOP);
  ui.setIndicatorDirection(LEFT_RIGHT);

  ui.setFrameAnimation(SLIDE_LEFT);

  ui.setFrames(frames, frameCount);
  ui.setOverlays(overlays, overlaysCount);

  ui.disableAutoTransition();
  ui.setTimePerTransition(100);

  ui.init();

  display.flipScreenVertically();
  
  display.clear();
  display.drawXbm(41, 18, Logo_width, Logo_height, Logo_bits);
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setFont(ArialMT_Plain_10);
  display.drawString(64, 0, "Ai2 Prototype");
  display.display();
  delay(2000);
  updateLoadingState("Initializing...", 0);
  delay(100);
  updateLoadingState("Connecting WiFi...", 10);
  while (WiFi.status() != WL_CONNECTED)
  {
    WiFi.begin(ssid, password);
    delay(500);
  }
  Serial.println(WiFi.localIP());
  updateLoadingState("Starting MDNS...", 20);
  delay(100);
  if ( MDNS.begin ( "esp8266" ) ) {
    delay(100);
  }
  updateLoadingState("Initializing Server...", 30);
  server.on ( "/", []() {
   server.send ( 200, "text/plain", "this works as well" );
  } );
  server.begin();
  updateLoadingState("Pins Initialized...", 65);
  //pins setup
  pinMode(redBtn, INPUT);
  pinMode(greenBtn, INPUT);
  pinMode(leftBtn, INPUT);
  pinMode(rightBtn, INPUT);
  updateLoadingState("Time Initialized...", 85);
  //Time
  unsigned long secsSinceStart = millis();
  // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
  const unsigned long seventyYears = 2208988800UL;
  // subtract seventy years:
  unsigned long epoch = secsSinceStart - seventyYears * SECS_PER_HOUR;
  setTime(epoch);
  updateLoadingState("Finished...", 100);
  delay(500);
}
//debounce and one-pulse
int redVal, greenVal, leftVal, rightVal;
int lRed, lGreen, lLeft, lRight;
int sRed, sGreen, sLeft, sRight;
void loop() {
  server.handleClient();
  int remainingTimeBudget = ui.update();
  
  if (remainingTimeBudget > 0) { 
    
    redVal = digitalRead(redBtn);
    greenVal = digitalRead(greenBtn);
    leftVal = digitalRead(leftBtn);
    rightVal = digitalRead(rightBtn);
    
    if(((millis()-lLeft) > debounce) && sLeft && leftVal){
      previousMenu();
      lLeft = millis();
      sLeft = 0;
    }else{
      sLeft = !leftVal;
    }
    if(((millis()-lRight) > debounce) && sRight && rightVal){
      nextMenu();
      lRight = millis();
      sRight = 0;
    }else{
      sRight = !rightVal;
    }
    if(((millis()-lGreen) > debounce) && sGreen && greenVal){
      selectMenu();
      lGreen = millis();
      sGreen = 0;
    }else{
      sGreen = !greenVal;
    }
    if(((millis()-lRed) > debounce) && sRed && redVal){
      exitMenu();
      lRed = millis();
      sRed = 0;
    }else{
      sRed = !redVal;
    }
    
    remainingTimeBudget = ui.update();
    delay(remainingTimeBudget);
  }
}

