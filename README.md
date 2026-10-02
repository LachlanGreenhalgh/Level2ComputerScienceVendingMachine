# Vending Machine README
#### Lachlan Greenhalgh Level 2 CSC NCL

Hi! Welcome to the README!

I do reccommend using a proper markdown reader for this, however, its your choice. (if you are in VS Code its just on the top right where it says "Text Editor" and has the dropdown, go into markdown preview)

This README is seperated into a couple parts, this section being the introduction, the what each code does section, the materials used section, the in depth user guide for the vending machine section, the resources I used section and lastly the detailed comments timeline (In this order). 

How I will be running this is for my ESPMotors code, I will be coding directly into VSCode, however, my ESPMotors and ESPDisplay sections will be coded in Arduino IDE and then have the code copied into VS code periodically as needed. This is because uploading ESP32 C++ code is done much easier in Arduino IDE as it is the default (and expected) environment. However, Micropython much perfers VSCode, as most of the framework was built for that. 

## What Each Code Does

Wow, this is emptier than my cats food bowl at 3 am. I suppose I have to go feed him 

## Materials Used

* ESP32-S3 Sense N16R8 with OV3660 camera module
* x4 N20 Gear Motors
* ESP32-S3 (for the motors)
* ESP32 CYD (Cheap Yellow Display), 240x320 resolution, 2.8 inch, no touch screen functionality
* 3D Printer Filament (PLA for non structural, PETG for structural, TPU for dampening)
* Bambulab printers (A1, A1 Mini and P2S)
* MDF (3 and 6 MM sizes)
* Lazer Cutter (unsure what type, will update that in a later iteration) 
* Bambu Studio (3D Printer Slicer)
* Onshape (3D Modelling Website)
* Lightburn (Lazer Cutting Software)
* VS Code
* Arduino IDE
* USB-C Cable
* Macbook Pro


## Vending Machine User Guide

*Always read all steps to a section first before performing the section*

### First Setup, Power Outage and Restocking. 
1. Open the back of the vending machine
2. Take out the storage modules gently as to not move anything else, making sure there is no cables that are stuck around the storage modules.
3. While covering the exit hole for a storage module, fill from the top down, making sure everything is oriented flat as to prevent clogs.
4. Push the storage modules in gently until it cannot move any further, ensuring no food got stuck. 
4. Repeat steps 3 and 4 for remaining storage modules
5. Ensure all cables going to the motor ESP, display ESP and camera ESP are connected to both the esp and the power brick in the extention cord inside the chassis
6. close up the back of the vending machine, making sure to guide the extention cord into one of the openings in the back panel. 
7. plug built in extention cord into an outlet
8. Step out of cameras frame while it boots up
9. When the display shows the "Describe Stock" UI, move into the frame and select the food and quantity you put into the first storage module. 
10. Repeat for remaining storage modules. 
11. Ensure that it is running the "Customer" UI as to prevent any issues. 

### How To Flash ESP32(Camera and Display ONLY) With Code
#### Using Arduino IDE for the first time
1. Download Arduino IDE from this website here: [Link to arduino website](https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE)
2. Follow the install guide
3. Plug in your ESP32 with a data USB-C cable, and in the top left click on the dropdown box that says "Select Board"
4. Choose the one that might be called "Unconfirmed board" or similar. (if you are having trouble figuring out which one is the esp32, unplug and plug back in the esp and try to find the one that dissapears and reappears)
5. A popup window should appear. In this window on the left search for "ESP32S3 Dev Module", and click that. Click OK in the bottom left. (There is a weird bug in the software (at least on mac) that means it will only show exactly one random board. If you get that, keyboard spam of numbers on the keyboard seems to work sometimes)
6. In the top of the window, select tools. Set Flash Size to 16MB, PSRAM to OPI PSRAM. 

#### Uploading code to the ESP32s
1. Download and open or copy paste code into arduino IDE
2. in the top left click the green tick to verify code
3. Unplug the ESP32, and press and hold the "BOOT" button. IMPORTANT: You will need to do this throughout the entirety of the next step
3. If that goes through successfully, click the right arrow next to it. DO NOT release your finger from the boot BOOT button until it says uploaded successfully
4. Let go of the boot button and press the RST button once. The code should now be uploaded. 

If the code did not verify successfully, that is usually an issue with the code. However it could also be an issue with the setup when plugging the ESP32 into the computer. 
If the code verified successfully but didn't upload, its usually because the ESP32 didn't have the BOOT button held down the entire time, the cable isn't a data transfer cable or it was plugged into the wrong port on the ESP32. 

The instructions sure are a bit lacking aren't they. More will be added in the future i'm sure. However, if you are in the future, just pop into one of the later versions of this repo. I'm sure I wrote some more then.

## Resources

[Medium: Getting ESP32-S3 Sense OV3660 Camera Working](https://medium.com/@manjotkhangura/getting-esp32-s3-sense-ov3660-camera-working-a-weekend-deep-dive-941d9c1a05d8) - This is the closest example code that exists for the camera section. 

As of this point there isn't many resourses, is there... oh well more do seem to just appear when the commit button is pressed. 

## Detailed Comments Timeline

**29/9 11.20AM:** This is the first test commit, just to see if its working

**29/9 11.54AM:** Added a title to the README, and created ESPMotors.py, ESPCamera.cpp and ESPDisplay.cpp

**29/9 12.31PM:** Used markdown styling to set up sections within the README file, including a step by step process for restocking the machine (which is to be changed in the future)

**29.9 12.56PM:** After battling with GIT and somehow pushing everything to a sub-directory I managed to put everything back onto the main directory. and some slight spelling changes. 

**29.9 2.44PM:** Added the lightburn lazer cutter files and 3D printing STLs into some folders here.

**1.10 9.09PM** Added the materials used section, aswell as changed some things around here and there to make the readme more enjoyable as its getting longer. 

**3.10 10.17AM** Added the Using Arduino IDE for the first time and Uploading code to the esp32s sections to the readme, updated the way I handle links

If you are reading this, you must be a time traveler because I haven't completed this project yet! (or you know, you are just going back through the history of the repository, which, is less fun). 

.

.

.

You've reached the end of this README file.

You can now either: 

Stay here and re-read this README a couple more times

Go have a quick coffee or food break

Have a quick walk for some fresh air

And if its past midnight, GO TO SLEEP!! 

Any of these (except maybe rereading the README) will help you work much better 

