# Mongoose-ESP32
Minimal example for ESP32 microcontrollers in combination with mongoose wizard.

## Config
Provides a website over access point for configuring a local wifi network.  
1. Download the repo
2. Open Mongoose.ino
3. Flash the code to your board
4. Connect end device to wifi AP of the board `ESP32-C3` (in my case)
5. Open browser with address `192.168.4.1`
6. Configure your wifi credencials

All configuration is permanently stored in FLASH.  
<img width="565" height="272" alt="mongoose-wifi" src="https://github.com/user-attachments/assets/178fd711-e498-4f4b-aea1-088f5c435605" />  
Access your board from your local network in your browser:  
`devboard.local`  
The given device name is the address!

## OTA
Easily update OTA from website:  
<img width="546" height="169" alt="mongoose-ota" src="https://github.com/user-attachments/assets/de8733b7-880d-4094-a311-d9fd578d462e" />  

## Modify
To modify the website for your project:
1. Download the repo
2. Open mongoose.wz in Chrome and start the wizard
3. Choose to `Create a new C/C++ project`
4. Choose directory for new project (does not matter at this point) and select Arduino as target platform
5. Select blank dashboard and finish
6. Upload `Mongoose/src/mongoose_wizard.json`
7. In Settings select Integration mode to `Integrate into...` and choose repo directory
   The wizard will overwrite your changes
8. After modification `Generate C/C++ code`
9. Add your custom code for your project
10. Build the code in Arduino IDE and upload to board OR
11. Sketch -> Export compiled binaray and upload binary OTA

