#include <TFT_eSPI.h>
#include <string.h>
#include <bits/stdc++.h>
#include "ESP32_NOW.h"
#include "WiFi.h"

//EspNOW requirements
#include <Arduino.h>
#include "ESP32_NOW.h"
#include "WiFi.h"
#include <esp_mac.h> 
#include <vector>

TFT_eSPI tft = TFT_eSPI();

//ESPNOW stuff

#define ESPNOW_WIFI_CHANNEL 6

class ESP_NOW_Peer_Class : public ESP_NOW_Peer {
public:
  // Constructor of the class
  ESP_NOW_Peer_Class(const uint8_t *mac_addr, uint8_t channel, wifi_interface_t iface, const uint8_t *lmk) : ESP_NOW_Peer(mac_addr, channel, iface, lmk) {}

  // Destructor of the class
  ~ESP_NOW_Peer_Class() {}

  // Function to register the master peer
  bool add_peer() {
    if (!add()) {
      log_e("Failed to register the broadcast peer");
      return false;
    }
    return true;
  }

  // Function to print the received messages from the master
  void onReceive(const uint8_t *data, size_t len, bool broadcast) {
    Serial.printf("  Message: %s\n", (char *)data);
  }
};

/* Global Variables */

// List of all the masters. It will be populated when a new master is registered
// Note: Using pointers instead of objects to prevent dangling pointers when the vector reallocates
std::vector<ESP_NOW_Peer_Class *> masters;

/* Callbacks */

// Callback called when an unknown peer sends a message
void register_new_master(const esp_now_recv_info_t *info, const uint8_t *data, int len, void *arg) {
    ESP_NOW_Peer_Class *new_master = new ESP_NOW_Peer_Class(info->src_addr, ESPNOW_WIFI_CHANNEL, WIFI_IF_STA, nullptr);
    if (!new_master->add_peer()) {
      Serial.println("Failed to register the new master");
      delete new_master;
      return;
    }
    masters.push_back(new_master);
} 

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

  //espnow stuff

  Serial.begin(115200);

  // Initialize the Wi-Fi module
  WiFi.mode(WIFI_STA);
  WiFi.setChannel(ESPNOW_WIFI_CHANNEL);
  while (!WiFi.STA.started()) {
    delay(100);
  }

  // Initialize the ESP-NOW protocol
  if (!ESP_NOW.begin()) {
    tft.fillScreen(TFT_WHITE);
    tft.drawString("ESPNOW ERROR", 20, 100, 4);
    tft.drawString("CONTACT REPAIR", 20, 130, 4);
    tft.drawString("DEVICE UNUSABLE", 20, 160, 4);
    ESP.restart();
  }
  // Register the new peer callback
  ESP_NOW.onNewPeer(register_new_master, nullptr);
}

/*void displayItems(incoming) { //will do this in the future hopefully
  if (quantity[incoming] >= 0) {
    quantity[incoming] ++; //adds to the quantity, for testing purposes
    tft.setTextColor(TFT_BLACK, TFT_WHITE); // The one on the left is the text colour, on the right is background colour
    tft.drawString("Choc Berry", x, texty[incoming], fontSize); // What you want to display, x, y and font size in that order
    tft.drawString(String(quantity[0]), rx, texty[incoming], 4); //String() turns an int into a string
} */

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

