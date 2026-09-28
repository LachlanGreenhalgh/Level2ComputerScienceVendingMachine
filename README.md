# Vending Machine README
#### Lachlan Greenhalgh Level 2 CSC NCL

Hi! Welcome to the README!

I do reccommend using a proper markdown reader for this, however, its your choice. (if you are in VS Code its just on the top right where it says "Text Editor" and has the dropdown, go into markdown preview)

This README is seperated into a couple parts, this section being the introduction, the what each code does section, the in depth user guide for the vending machine section, the resources I used section and lastly the detailed comments timeline (In this order). 

## What Each Code Does

Come back here when theres actually some code in my files 

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

*More sections will be added as needed. Come back later for a more in depth and accurate step by step process.*

## Resources

https://medium.com/@manjotkhangura/getting-esp32-s3-sense-ov3660-camera-working-a-weekend-deep-dive-941d9c1a05d8 - This might be used but as it isn't identical to my ESP32S3cam it may not be all that helpful

## Detailed Comments Timeline

**29/9 11.20AM:** This is the first test commit, just to see if its working

**29/9 11.54AM:** Added a title to the README, and created ESPMotors.py, ESPCamera.cpp and ESPDisplay.cpp

**29/9 12.31PM:** Used markdown styling to set up sections within the README file, including a step by step process for restocking the machine (which is to be changed in the future)

**29.9 12.56PM:** after battling with GIT and somehow pushing everything to a sub-directory I managed to put everything back onto the main directory. and some slight spelling changes. 

.

.

.

*You've reached the end of this README file. you can either stay here and enjoy reading it another couple times or go have a quick break (seriously if you are reading this and you aren't me then go have a break, you almost certainly deserve it), your choice!*