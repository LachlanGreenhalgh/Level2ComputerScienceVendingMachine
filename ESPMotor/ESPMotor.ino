#include <Arduino.h>
#include "ESP32_NOW.h"
#include "WiFi.h"
#include <esp_mac.h> 
#include <vector>

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
  void onReceive(const uint8_t *data, size_t len, bool broadcast) { //when it recieves data from a message
    Serial.printf("  Message: %s\n", (char *)data); // it prints it to the serial, repeating for each character inside data (might not work anymore)
    memcpy(quantity, data, len); //and then copies the data to quantity using memory copy (I couldn't find any easier ways to do it so here we are)
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

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 14 as an output.
  pinMode(L14, OUTPUT);

  Serial.begin(115200);

  // Initialize the Wi-Fi module
  WiFi.mode(WIFI_STA);
  WiFi.setChannel(ESPNOW_WIFI_CHANNEL);
  while (!WiFi.STA.started()) {
    delay(100);
  }

  // Initialize the ESP-NOW protocol
  if (!ESP_NOW.begin()) { //espnow protocol doesnt start
    ESP.restart(); //restarts the entire esp
  }
  // Register the new peer callback
  ESP_NOW.onNewPeer(register_new_master, nullptr); 
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(14, HIGH);  // change state of the LED by setting the pin to the HIGH voltage level
  delay(1285);                      // wait for a second
  digitalWrite(14, LOW);   // change state of the LED by setting the pin to the LOW voltage level
  delay(500);                      // wait for a second
}
