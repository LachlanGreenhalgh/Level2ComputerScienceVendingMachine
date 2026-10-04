#include "esp_camera.h" //Imports all the camera libraries needed
#include <WiFi.h>  //Imports the wifi connection part (will be removed later as I will be using ESPNOW (or the other esp protocol) instead)

#define BOARD_CONFIG_H
#define CAMERA_MODEL_ESP32S3_EYE // Sets the esp model to the ESP32 S3 Camera option (called "eye" in this for whatever reason)

#define PWDN_GPIO_NUM  -1 //power button and...
#define RESET_GPIO_NUM -1 // reset button both seem to do the same thing. ittl choose the one that is defined later, so it will reset
#define XCLK_GPIO_NUM  15 
#define SIOD_GPIO_NUM  4
#define SIOC_GPIO_NUM  5

#define Y2_GPIO_NUM 11
#define Y3_GPIO_NUM 9
#define Y4_GPIO_NUM 8
#define Y5_GPIO_NUM 10
#define Y6_GPIO_NUM 12
#define Y7_GPIO_NUM 18
#define Y8_GPIO_NUM 17
#define Y9_GPIO_NUM 16

#define VSYNC_GPIO_NUM 6
#define HREF_GPIO_NUM  7
#define PCLK_GPIO_NUM  13

const char* ssid     = "Hpinkjet6140"; //Wifi name and password, it connects automatically and assigns an ip adress that you can visit
const char* password = "IsntAnHPPrinter";
camera_config_t config;

void startCameraServer();
void camera_init();

void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();

  camera_init();

  WiFi.begin(ssid, password);
  WiFi.setSleep(false);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  while (WiFi.STA.hasIP() != true) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");

  startCameraServer();

  Serial.print("Camera Ready! Use 'http://");
  Serial.print(WiFi.localIP());
  Serial.println("' to connect");
}

void loop() {
  // Do nothing. Everything is done in another task by the web server
  delay(10000);
}

void camera_init() {
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sccb_sda = SIOD_GPIO_NUM;
  config.pin_sccb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 10000000;
  config.frame_size = FRAMESIZE_QVGA; //Sets to 320 by 240 resolution, HVGA is highest functional
  config.pixel_format = PIXFORMAT_JPEG; // The streaming resolution
  config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;
  config.fb_location = CAMERA_FB_IN_PSRAM;
  config.jpeg_quality = 10; // Lower is higher quality, however too low and it stops functioning. too high and it turns into a potato
  config.fb_count = 2; // Frame buffer needed for smoother recording, will help keeping things like hand tracking from bugging out. 
  // one is too low and causes jittering, 3 is too high and both is about 2 seconds behind but also somehow jittery (possibly too much to store)
  
  // camera init
  esp_err_t err = esp_camera_init(&config); //any error in the camera init section above
  if (err != ESP_OK) { 
    if(err==ESP_ERR_NOT_SUPPORTED){
      config.pixel_format = PIXFORMAT_RGB565;
      esp_err_t err = esp_camera_init(&config);
      if (err != ESP_OK) {
        Serial.printf("Camera init failed with error 0x%x", err); //prints error code in serial
        return;
      }
    }
  }

  sensor_t * s = esp_camera_sensor_get();
  // drop down frame size for higher initial frame rate
  
  s->set_hmirror(s, 1);
  s->set_vflip(s, 1);     
  s->set_brightness(s, -1);  // Slightly decrease brightness
  s->set_saturation(s, 1);  // Slightly increase saturation
  s->set_ae_level(s, -3);   // Set exposure compensation level
  s->set_sharpness(s, 4); // Sets sharpness to the max
}
