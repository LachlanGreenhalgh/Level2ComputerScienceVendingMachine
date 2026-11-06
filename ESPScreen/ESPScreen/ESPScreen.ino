#include <TFT_eSPI.h>
#include <string.h>
#include <bits/stdc++.h>

TFT_eSPI tft = TFT_eSPI();

int texty0 = 10, texty1 = 40, texty2 = 70, texty3 = 100;
int quantity0 = 1, quantity1 = 1, quantity2 = 1, quantity3 = 1;
int x = 5;
int rightx = 210;


void setup() {
 // // Clear the screen before writing to it
 // tft.fillScreen(TFT_BLACK);
//
 // tft.setTextColor(TFT_WHITE, TFT_BLACK);
  //int x = 5;
 // int fontNum = 4; 
 // tft.drawString("Hello", x, y, fontNum); // Left Aligned
 // x = 240 /2;
 // y += 16;
 // tft.setTextColor(TFT_BLUE, TFT_BLACK);
 // tft.drawCentreString("World", x, y, fontNum);
  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_WHITE);

  tft.fillRect(0, 270, 240, 50, TFT_BLACK); // adds a black rectangle to the bottom of the screen so I can add instructions
  tft.setTextColor(TFT_WHITE); //Sets text to White for the rectangle
  tft.drawString("Thumbs up to confirm", 100, 280, 2);
  tft.drawString("Thumbs down to cancel", 92, 295, 2); 
  
  tft.setTextColor(TFT_BLACK, TFT_WHITE); //Sets text to black, backgroung to white. 
}
 

void loop() {
  // put your main code here, to run repeatedly:
  int total = quantity0 + quantity1 + quantity2 + quantity3;
  tft.drawString("Total", x, 240, 4); // 
  tft.drawString(String(total), rightx, 241, 4); // looks visually wrong on 240
  if (quantity0 > 0) {
    tft.setTextColor(TFT_BLACK, TFT_WHITE); // The one on the left is the text colour, on the right is background colour
    tft.drawString("Choc Berry", x, texty0, 4); // What you want to display, x, y and font size in that order
    tft.drawString(String(quantity0), rightx, texty0, 4); //String() turns an int into a string
    quantity0 ++; //adds to the quantity, for testing purposes
    delay(1000);
  }
  if (quantity1 > 0) {
    tft.setTextColor(TFT_BLACK, TFT_WHITE);
    tft.drawString("Choc Dark", x, texty1, 4);
    tft.drawString(String(quantity1), rightx, texty1, 4);
    quantity1 ++;
    delay(1000);
  }
  if (quantity2 > 0) {
    tft.setTextColor(TFT_BLACK, TFT_WHITE);
    tft.drawString("Choc Orange", x, texty2, 4);
    tft.drawString(String(quantity2), rightx, texty2, 4);
    quantity2 ++;
    delay(1000);
  }
  if (quantity3 > 0) {
    tft.setTextColor(TFT_BLACK, TFT_WHITE);
    tft.drawString("Choc Milk", x, texty3, 4);
    tft.drawString(String(quantity3), rightx, texty3, 4);
    quantity3 ++;
    delay(1000);
  }
}

