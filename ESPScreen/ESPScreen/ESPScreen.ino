#include <TFT_eSPI.h>
#include <string.h>
#include <bits/stdc++.h>

TFT_eSPI tft = TFT_eSPI();

//Variables, arrays etc. 
int texty[4] = {50, 80, 110, 140}; //creates an array rather than 4 seperate variables
int quantity[4] = {0, 0, 0, 0}; // used for keeping track of the quantities of each product
int x = 10; // used for left alignment
int rx = 210; // used for right alignment
int fontSize = 4; // sets the font size to 4
int incoming = 0; // this is for when the code for the ESPNow communication is added, but in the meanwhile will have a random number picker attached to it

void setup() {
  tft.init(); //starts the screen
  tft.setRotation(0); // sets the screen to portrait
  tft.fillScreen(TFT_WHITE); //clears the screen

  tft.fillRect(10, 45, 220, 1, TFT_BLACK); // line below the Items text
  tft.fillRect(10, 235, 220, 1, TFT_BLACK); //line above the total for seperation of sections
  tft.fillRect(0, 270, 240, 50, TFT_BLACK); // adds a black rectangle to the bottom of the screen so I can add instructions
  tft.setTextColor(TFT_WHITE); //Sets text to White for the rectangle and top text
  tft.drawString("Thumbs up to confirm", 100, 280, 2);
  tft.drawString("Thumbs down to cancel", 92, 295, 2); 
  tft.setTextColor(TFT_BLACK, TFT_WHITE); //Sets text to black, backgroung to white. 
  tft.drawCentreString("Items", 120, 15, fontSize);
}

void displayItems() { //will do this in the future hopefully
}

void displayTotal() {
  int total = quantity[0] + quantity[1] + quantity[2] + quantity[3]; //totals up the quantities of each item so that it can be displayed
  tft.drawString("Total", x, 242, fontSize);
  if (total < 10) { // if total is a 1 digit number then use normal spacing
    tft.drawString(String(total), rx, 241, fontSize); // looks visually wrong on 240
  }
  else { // otherwise make it go to the left by 10 pixels so it looks better
    tft.drawString(String(total), (rx - 10), 241, fontSize); 
  }
  
}

void loop() {
  
  displayTotal(); //calls on the function I made earlier
  if (quantity[0] >= 0) {
    quantity[0] ++; //adds to the quantity, for testing purposes
    tft.setTextColor(TFT_BLACK, TFT_WHITE); // The one on the left is the text colour, on the right is background colour
    tft.drawString("Choc Berry", x, texty[0], fontSize); // What you want to display, x, y and font size in that order
    tft.drawString(String(quantity[0]), rx, texty[0], 4); //String() turns an int into a string
    
  }
  displayTotal();
  delay(1000);
  if (quantity[1] >= 0) {
    quantity[1] ++;
    tft.setTextColor(TFT_BLACK, TFT_WHITE);
    tft.drawString("Choc Dark", x, texty[1], fontSize);
    tft.drawString(String(quantity[1]), rx, texty[1], fontSize);
    
  }
  displayTotal();
  delay(1000);
  if (quantity[2] >= 0) {
    quantity[2] ++;
    tft.setTextColor(TFT_BLACK, TFT_WHITE);
    tft.drawString("Choc Orange", x, texty[2], fontSize);
    tft.drawString(String(quantity[2]), rx, texty[2], fontSize);
    
  }
  displayTotal();
  delay(1000);
  if (quantity[3] >= 0) {
    quantity[3] ++;
    tft.setTextColor(TFT_BLACK, TFT_WHITE);
    tft.drawString("Choc Milk", x, texty[3], fontSize);
    tft.drawString(String(quantity[3]), rx, texty[3], fontSize);
    
  }
  displayTotal();
  delay(1000);

  /*
  incoming = std::rand() % 4; // picks a random number from 0 to 3 by using the rounded remainder of 4 divided by all numbers
  displayTotal();
  displayItems();
  displayTotal();
  */
}

