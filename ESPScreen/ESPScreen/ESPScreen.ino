#include <TFT_eSPI.h>
#include <string.h>
#include <bits/stdc++.h>

TFT_eSPI tft = TFT_eSPI();

//Variables, arrays etc. 
int texty[4] = {10, 40, 70, 100}; //creates an array rather than 4 seperate variables
int quantity[4] = {1, 1, 1, 1}; // used for keeping track of the quantities of each product
int x = 5; // used for left alignment
int rx = 210; // used for right alignment
int fontSize = 4; // sets the font size to 4

void setup() {
  tft.init(); //starts the screen
  tft.setRotation(0); // sets the screen to portrait
  tft.fillScreen(TFT_WHITE); //clears the screen

  tft.fillRect(0, 270, 240, 50, TFT_BLACK); // adds a black rectangle to the bottom of the screen so I can add instructions
  tft.setTextColor(TFT_WHITE); //Sets text to White for the rectangle
  tft.drawString("Thumbs up to confirm", 100, 280, 2);
  tft.drawString("Thumbs down to cancel", 92, 295, 2); 
  
  tft.setTextColor(TFT_BLACK, TFT_WHITE); //Sets text to black, backgroung to white. 
}

void loop() {
  // put your main code here, to run repeatedly:
  int total = quantity[0] + quantity[1] + quantity[2] + quantity[3];
  tft.drawString("Total", x, 240, fontSize);
  tft.drawString(String(total), rx, 241, fontSize); // looks visually wrong on 240
  if (quantity[0] > 0) {
    tft.setTextColor(TFT_BLACK, TFT_WHITE); // The one on the left is the text colour, on the right is background colour
    tft.drawString("Choc Berry", x, texty[0], fontSize); // What you want to display, x, y and font size in that order
    tft.drawString(String(quantity[0]), rx, texty[0], 4); //String() turns an int into a string
    quantity[0] ++; //adds to the quantity, for testing purposes
    delay(1000);
  }
  if (quantity[1] > 0) {
    tft.setTextColor(TFT_BLACK, TFT_WHITE);
    tft.drawString("Choc Dark", x, texty[1], fontSize);
    tft.drawString(String(quantity[1]), rx, texty[1], fontSize);
    quantity[1] ++;
    delay(1000);
  }
  if (quantity[2] > 0) {
    tft.setTextColor(TFT_BLACK, TFT_WHITE);
    tft.drawString("Choc Orange", x, texty[2], fontSize);
    tft.drawString(String(quantity[2]), rx, texty[2], fontSize);
    quantity[2] ++;
    delay(1000);
  }
  if (quantity[3] > 0) {
    tft.setTextColor(TFT_BLACK, TFT_WHITE);
    tft.drawString("Choc Milk", x, texty[3], fontSize);
    tft.drawString(String(quantity[3]), rx, texty[3], fontSize);
    quantity[3] ++;
    delay(1000);
  }
}

