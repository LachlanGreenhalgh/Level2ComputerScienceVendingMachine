#include <TFT_eSPI.h>
#include <string.h>
#include <bits/stdc++.h>

TFT_eSPI tft = TFT_eSPI();

int texty0 = 10, texty1 = 40, texty2 = 70, texty3 = 100;
int quantity0 = 1, quantity1 = 1, quantity2 = 1, quantity3 = 1;


void setup() {
  /// Start the tft display and set it to black
 // tft.init();
 // tft.setRotation(0); //This is the display in portrait
 // 
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
}
 

void loop() {
  // put your main code here, to run repeatedly:

  if (quantity0 > 0) {
    tft.setTextColor(TFT_BLACK, TFT_WHITE); // The one on the left is the text colour, on the right is background colour
    tft.drawString("Choc Berry", 5, texty0, 4); // What you want to display, x, y and font size in that order
    tft.drawString(String(quantity0), 210, texty0, 4); //String() turns an int into a string
    quantity0 ++; //adds to the quantity, for testing purposes
    delay(1000);
  }
  if (quantity1 > 0) {
    tft.setTextColor(TFT_BLACK, TFT_WHITE);
    tft.drawString("Choc Dark", 5, texty1, 4);
    tft.drawString(String(quantity1), 210, texty1, 4);
    quantity1 ++;
    delay(1000);
  }
  if (quantity2 > 0) {
    tft.setTextColor(TFT_BLACK, TFT_WHITE);
    tft.drawString("Choc Orange", 5, texty2, 4);
    tft.drawString(String(quantity2), 210, texty2, 4);
    quantity2 ++;
    delay(1000);
  }
  if (quantity3 > 0) {
    tft.setTextColor(TFT_BLACK, TFT_WHITE);
    tft.drawString("Choc Milk", 5, texty3, 4);
    tft.drawString(String(quantity3), 210, texty3, 4);
    quantity3 ++;
    delay(1000);
  }
}

