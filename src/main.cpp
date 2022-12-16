// #include "Arduino.h"
// #include "TFT_eSPI.h" /* Please use the TFT library provided in the library. */
// #include "img_logo.h"
// #include "ESP32S3_PinOut.h"
// #include "lvgl.h"
// #include "ui.h"

// // TFT_eSPI tft = TFT_eSPI();
// // #define WAIT 1000
// // unsigned long targetTime = 0; // Used for testing draw times

// /*Change to your screen resolution*/
// /*改变你的屏幕分辨率*/
// static const uint16_t screenWidth  = 320;
// static const uint16_t screenHeight = 172;
// // #define LV_USE_LOG 1
// static lv_disp_draw_buf_t draw_buf;
// static lv_color_t buf1[ screenWidth * 10 ];
// static lv_color_t buf2[ screenWidth * 10 ];

// TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

// /* Display flushing 显示填充 */
// void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
// {
//     uint32_t w = ( area->x2 - area->x1 + 1 );
//     uint32_t h = ( area->y2 - area->y1 + 1 );

//     tft.startWrite();
//     tft.setAddrWindow( area->x1, area->y1, w, h );
//     tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
//     tft.endWrite();

//     lv_disp_flush_ready( disp );
// }

// void my_print(const char * buf)
// {
//     Serial.printf(buf);
//     Serial.flush();
// }

// void setup() {
//   // pinMode(PIN_POWER_ON, OUTPUT);
//   // digitalWrite(PIN_POWER_ON, HIGH);

//   // Serial.begin(115200);
//   // Serial.println("Hello T-Display-S3");

//   // tft.begin();
//   // tft.setRotation(3);
//   // tft.setSwapBytes(true);
//   // tft.pushImage(0, 0, 320, 170, (uint16_t *)img_logo);
//   // delay(2000);

//   // ledcSetup(0, 2000, 8);
//   // ledcAttachPin(PIN_LCD_BL, 0);
//   // ledcWrite(0, 255);

//     // tft.begin();          /* TFT init TFT初始化*/
//     // tft.init();
//     // tft.initDMA();
//     lv_init();
//     lv_log_register_print_cb( my_print );
//     tft.begin();  

//     tft.setRotation( 1 ); /* Landscape orientation, flipped 设置方向*/
//     if (TFT_BL > 0) {
//         pinMode(TFT_BL, OUTPUT);
//         digitalWrite(TFT_BL, HIGH);
//     }
    

//     lv_disp_draw_buf_init( &draw_buf, buf1, buf2, screenWidth * 40 );
    
//     /*Initialize the display*/
//     /*初始化显示*/
//     static lv_disp_drv_t disp_drv;
//     lv_disp_drv_init( &disp_drv );
//     /*Change the following line to your display resolution*/
//     /*将以下行更改为您的显示分辨率*/
//     disp_drv.hor_res = screenWidth;
//     disp_drv.ver_res = screenHeight;
//     disp_drv.flush_cb = my_disp_flush;
//     disp_drv.draw_buf = &draw_buf;
//     lv_disp_drv_register( &disp_drv );
    
    
//     /*Initialize the (dummy) input device driver*/
//     /*初始化（虚拟）输入设备驱动程序*/
//     // static lv_indev_drv_t indev_drv;
//     // lv_indev_drv_init( &indev_drv );
//     // indev_drv.type = LV_INDEV_TYPE_POINTER;
//     // indev_drv.read_cb = my_touchpad_read;
//     // lv_indev_drv_register( &indev_drv );
//     ui_init();
//     lv_scr_load(ui_Screen1);
//     // tft.drawString(" !\"#$%&'()*+,-.", 0, 0, 4);
//     // delay(5000);
// }

// void loop() {
//   lv_timer_handler();
//   lv_scr_load(ui_Screen1);
//   delay(50);
//   // targetTime = millis();

//   // // First we test them with a background colour set
//   // tft.setTextSize(1);
//   // tft.fillScreen(TFT_BLACK);
//   // tft.setTextColor(TFT_GREEN, TFT_BLACK);

//   // tft.drawString(" !\"#$%&'()*+,-./0123456", 0, 0, 2);
//   // tft.drawString("789:;<=>?@ABCDEFGHIJKL", 0, 16, 2);
//   // tft.drawString("MNOPQRSTUVWXYZ[\\]^_`", 0, 32, 2);
//   // tft.drawString("abcdefghijklmnopqrstuvw", 0, 48, 2);
//   // int xpos = 0;
//   // xpos += tft.drawString("xyz{|}~", 0, 64, 2);
//   // tft.drawChar(127, xpos, 64, 2);
//   // delay(WAIT);

//   // tft.fillScreen(TFT_BLACK);
//   // tft.setTextColor(TFT_GREEN, TFT_BLACK);

//   // tft.drawString(" !\"#$%&'()*+,-.", 0, 0, 4);
//   // tft.drawString("/0123456789:;", 0, 26, 4);
//   // tft.drawString("<=>?@ABCDE", 0, 52, 4);
//   // tft.drawString("FGHIJKLMNO", 0, 78, 4);
//   // tft.drawString("PQRSTUVWX", 0, 104, 4);
//   // delay(WAIT);

//   // tft.fillScreen(TFT_BLACK);
//   // tft.drawString("YZ[\\]^_`abc", 0, 0, 4);
//   // tft.drawString("defghijklmno", 0, 26, 4);
//   // tft.drawString("pqrstuvwxyz", 0, 52, 4);
//   // xpos = 0;
//   // xpos += tft.drawString("{|}~", 0, 78, 4);
//   // tft.drawChar(127, xpos, 78, 4);
//   // delay(WAIT);

//   // tft.fillScreen(TFT_BLACK);
//   // tft.setTextColor(TFT_BLUE, TFT_BLACK);

//   // tft.drawString("012345", 0, 0, 6);
//   // tft.drawString("6789", 0, 40, 6);
//   // tft.drawString("apm-:.", 0, 80, 6);
//   // delay(WAIT);

//   // tft.fillScreen(TFT_BLACK);
//   // tft.setTextColor(TFT_RED, TFT_BLACK);

//   // tft.drawString("0123", 0, 0, 7);
//   // tft.drawString("4567", 0, 60, 7);
//   // delay(WAIT);

//   // tft.fillScreen(TFT_BLACK);
//   // tft.drawString("890:.", 0, 0, 7);
//   // tft.drawString("", 0, 60, 7);
//   // delay(WAIT);

//   // tft.fillScreen(TFT_BLACK);
//   // tft.setTextColor(TFT_YELLOW, TFT_BLACK);

//   // tft.drawString("01", 0, 0, 8);
//   // delay(WAIT);

//   // tft.drawString("23", 0, 0, 8);
//   // delay(WAIT);

//   // tft.drawString("45", 0, 0, 8);
//   // delay(WAIT);

//   // tft.drawString("67", 0, 0, 8);
//   // delay(WAIT);

//   // tft.drawString("89", 0, 0, 8);
//   // delay(WAIT);

//   // tft.drawString("0:.", 0, 0, 8);
//   // delay(WAIT);

//   // tft.setTextColor(TFT_MAGENTA);
//   // tft.drawNumber(millis() - targetTime, 0, 100, 4);
//   // delay(4000);

//   // // Now test them with transparent background
//   // targetTime = millis();

//   // tft.setTextSize(1);
//   // tft.fillScreen(TFT_BROWN);
//   // tft.setTextColor(TFT_GREEN);

//   // tft.drawString(" !\"#$%&'()*+,-./0123456", 0, 0, 2);
//   // tft.drawString("789:;<=>?@ABCDEFGHIJKL", 0, 16, 2);
//   // tft.drawString("MNOPQRSTUVWXYZ[\\]^_`", 0, 32, 2);
//   // tft.drawString("abcdefghijklmnopqrstuvw", 0, 48, 2);
//   // xpos = 0;
//   // xpos += tft.drawString("xyz{|}~", 0, 64, 2);
//   // tft.drawChar(127, xpos, 64, 2);
//   // delay(WAIT);

//   // tft.fillScreen(TFT_BROWN);
//   // tft.setTextColor(TFT_GREEN);

//   // tft.drawString(" !\"#$%&'()*+,-.", 0, 0, 4);
//   // tft.drawString("/0123456789:;", 0, 26, 4);
//   // tft.drawString("<=>?@ABCDE", 0, 52, 4);
//   // tft.drawString("FGHIJKLMNO", 0, 78, 4);
//   // tft.drawString("PQRSTUVWX", 0, 104, 4);

//   // delay(WAIT);
//   // tft.fillScreen(TFT_BROWN);
//   // tft.drawString("YZ[\\]^_`abc", 0, 0, 4);
//   // tft.drawString("defghijklmno", 0, 26, 4);
//   // tft.drawString("pqrstuvwxyz", 0, 52, 4);
//   // xpos = 0;
//   // xpos += tft.drawString("{|}~", 0, 78, 4);
//   // tft.drawChar(127, xpos, 78, 4);
//   // delay(WAIT);

//   // tft.fillScreen(TFT_BROWN);
//   // tft.setTextColor(TFT_BLUE);

//   // tft.drawString("012345", 0, 0, 6);
//   // tft.drawString("6789", 0, 40, 6);
//   // tft.drawString("apm-:.", 0, 80, 6);
//   // delay(WAIT);

//   // tft.fillScreen(TFT_BROWN);
//   // tft.setTextColor(TFT_RED);

//   // tft.drawString("0123", 0, 0, 7);
//   // tft.drawString("4567", 0, 60, 7);
//   // delay(WAIT);

//   // tft.fillScreen(TFT_BROWN);
//   // tft.drawString("890:.", 0, 0, 7);
//   // tft.drawString("", 0, 60, 7);
//   // delay(WAIT);

//   // tft.fillScreen(TFT_BROWN);
//   // tft.setTextColor(TFT_YELLOW);

//   // tft.drawString("0123", 0, 0, 8);
//   // delay(WAIT);

//   // tft.fillScreen(TFT_BROWN);
//   // tft.drawString("4567", 0, 0, 8);
//   // delay(WAIT);

//   // tft.fillScreen(TFT_BROWN);
//   // tft.drawString("890:.", 0, 0, 8);
//   // delay(WAIT);

//   // tft.setTextColor(TFT_MAGENTA);

//   // tft.drawNumber(millis() - targetTime, 0, 100, 4);
//   // delay(4000);
// }


// // #include "Wire.h"
// // #include <lvgl.h>
// // #include "ESP32S3_PinOut.h"
// // #include <TFT_eSPI.h>
// // #include "ui.h"
// // // #include<ps5Controller.h>
// // #include <SPI.h>
// // #include <RF24.h>

// // //nRF24
// // RF24 radio(19, 33); // CE, CSN
// // SPIClass* hspi = nullptr; // we'll instantiate this in the `setup()` function
// // // by default the HSPI bus predefines the following pins
// // # define My_HSPI_MISO  21
// // # define My_HSPI_MOSI  22
// // # define My_HSPI_SCLK  26
// // # define My_HSPI_SS    33

// // // #define LV_COLOR_16_SWAP 1
// // #define DEBUG 0

// // /*Change to your screen resolution*/
// // /*改变你的屏幕分辨率*/
// // static const uint16_t screenWidth  = 320;
// // static const uint16_t screenHeight = 240;
// // // #define LV_USE_LOG 1
// // static lv_disp_draw_buf_t draw_buf;
// // static lv_color_t buf1[ screenWidth * 10 ];
// // static lv_color_t buf2[ screenWidth * 10 ];

// // TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

// // #if LV_USE_LOG != 0
// // /* Serial debugging */
// // void my_print(const char * buf)
// // {
// //     Serial.printf(buf);
// //     Serial.flush();
// // }
// // #endif


// // void lv_checkbox_set_state(lv_obj_t * checkbox, bool checked)
// // {
// //     if(checked)
// //     {
// //       lv_obj_add_state(checkbox, LV_STATE_CHECKED);
// //     }
// //     else
// //     {
// //       lv_obj_clear_state(checkbox, LV_STATE_CHECKED);
// //     }
    
// // }


// // // void PS5_Debug()
// // // {
// // //         if (ps5.Right()) Serial.println("Right Button");
// // //         if (ps5.Down()) Serial.println("Down Button");
// // //         if (ps5.Up()) Serial.println("Up Button");
// // //         if (ps5.Left()) Serial.println("Left Button");

// // //         if (ps5.Square()) Serial.println("Square Button");
// // //         if (ps5.Cross()) Serial.println("Cross Button");
// // //         if (ps5.Circle()) Serial.println("Circle Button");
// // //         if (ps5.Triangle()) Serial.println("Triangle Button");

// // //         if (ps5.UpRight()) Serial.println("Up Right");
// // //         if (ps5.DownRight()) Serial.println("Down Right");
// // //         if (ps5.UpLeft()) Serial.println("Up Left");
// // //         if (ps5.DownLeft()) Serial.println("Down Left");

// // //         if (ps5.L1()) Serial.println("L1 Button");
// // //         if (ps5.R1()) Serial.println("R1 Button");

// // //         if (ps5.Share()) Serial.println("Share Button");
// // //         if (ps5.Options()) Serial.println("Options Button");
// // //         if (ps5.L3()) Serial.println("L3 Button");
// // //         if (ps5.R3()) Serial.println("R3 Button");

// // //         if (ps5.PSButton()) Serial.println("PS Button");
// // //         if (ps5.Touchpad()) Serial.println("Touch Pad Button");

// // //         if (ps5.L2()) {
// // //         Serial.printf("L2 button at %d\n", ps5.L2Value());
       
// // //         }
        
// // //         if (ps5.R2()) {
// // //         Serial.printf("R2 button at %d\n", ps5.R2Value());
// // //         }

// // //         if (ps5.LStickX()) {
// // //         Serial.printf("Left Stick x at %d\n", ps5.LStickX());
// // //         }
// // //         if (ps5.LStickY()) {
// // //         Serial.printf("Left Stick y at %d\n", ps5.LStickY());
// // //         }
// // //         if (ps5.RStickX()) {
// // //         Serial.printf("Right Stick x at %d\n", ps5.RStickX());
// // //         }
// // //         if (ps5.RStickY()) {
// // //         Serial.printf("Right Stick y at %d\n", ps5.RStickY());
// // //         }
// // // }



// // /* Display flushing 显示填充 */
// // void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
// // {
// //     uint32_t w = ( area->x2 - area->x1 + 1 );
// //     uint32_t h = ( area->y2 - area->y1 + 1 );

// //     tft.startWrite();
// //     tft.setAddrWindow( area->x1, area->y1, w, h );
// //     tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
// //     tft.endWrite();

// //     lv_disp_flush_ready( disp );
// // }

// // // Let these addresses be used for the pair
// // uint8_t address[][6] = { "1Node", "2Node" };
// // // It is very helpful to think of an address as a path instead of as
// // // an identifying device destination

// // // to use different addresses on a pair of radios, we need a variable to
// // // uniquely identify which address this radio will use to transmit
// // bool radioNumber = 1;  // 0 uses address[0] to transmit, 1 uses address[1] to transmit

// // // Used to control whether this node is sending or receiving
// // bool role = false;  // true = TX role, false = RX role

// // // For this example, we'll be using a payload containing
// // // a single float number that will be incremented
// // // on every successful transmission
// // float payload = 0.0;



// // void setup()
// // {
// //     Serial.begin( 115200 ); /* prepare for possible serial debug 为可能的串行调试做准备*/
// //     lv_init();

// // #if LV_USE_LOG != 0
// //     lv_log_register_print_cb( my_print ); /* register print function for debugging 注册打印功能以进行调试*/
// // #endif
// //     hspi = new SPIClass(HSPI); // by default VSPI is used
// //     hspi->begin(My_HSPI_SCLK,My_HSPI_MISO,My_HSPI_MOSI,My_HSPI_SS);
// //     if (!radio.begin(hspi)) {
// //         Serial.println(F("radio hardware not responding!!"));
// //         while (1) {
// //     } // hold program in infinite loop to prevent subsequent errors
// //     }

// //     Serial.println(F("RF24/examples/GettingStarted"));

// //     // To set the radioNumber via the Serial monitor on startup
// //   Serial.println(F("Which radio is this? Enter '0' or '1'. Defaults to '0'"));
// //   while (!Serial.available()) {
// //     // wait for user input
// //   }
// //   char input = Serial.parseInt();
// //   radioNumber = input == 1;
// //   Serial.print(F("radioNumber = "));
// //   Serial.println((int)radioNumber);

// //   // role variable is hardcoded to RX behavior, inform the user of this
// //   Serial.println(F("*** PRESS 'T' to begin transmitting to the other node"));

// //   // Set the PA Level low to try preventing power supply related problems
// //   // because these examples are likely run with nodes in close proximity to
// //   // each other.
// //   radio.setPALevel(RF24_PA_LOW);  // RF24_PA_MAX is default.

// //   // save on transmission time by setting the radio to only transmit the
// //   // number of bytes we need to transmit a float
// //   radio.setPayloadSize(sizeof(payload));  // float datatype occupies 4 bytes

// //   // set the TX address of the RX node into the TX pipe
// //   radio.openWritingPipe(address[radioNumber]);  // always uses pipe 0

// //   // set the RX address of the TX node into a RX pipe
// //   radio.openReadingPipe(1, address[!radioNumber]);  // using pipe 1

// //   // additional setup specific to the node's role
// //   if (role) {
// //     radio.stopListening();  // put radio in TX mode
// //   } else {
// //     radio.startListening();  // put radio in RX mode
// //   }





// //     tft.begin();          /* TFT init TFT初始化*/
// //     tft.setRotation( 1 ); /* Landscape orientation, flipped 设置方向*/
// //     if (TFT_BL > 0) {
// //         pinMode(TFT_BL, OUTPUT);
// //         digitalWrite(TFT_BL, HIGH);
// //     }

// //     lv_disp_draw_buf_init( &draw_buf, buf1, buf2, screenWidth * 10 );

// //     /*Initialize the display*/
// //     /*初始化显示*/
// //     static lv_disp_drv_t disp_drv;
// //     lv_disp_drv_init( &disp_drv );
// //     /*Change the following line to your display resolution*/
// //     /*将以下行更改为您的显示分辨率*/
// //     disp_drv.hor_res = screenWidth;
// //     disp_drv.ver_res = screenHeight;
// //     disp_drv.flush_cb = my_disp_flush;
// //     disp_drv.draw_buf = &draw_buf;
// //     lv_disp_drv_register( &disp_drv );

// //     /*Initialize the (dummy) input device driver*/
// //     /*初始化（虚拟）输入设备驱动程序*/
// //     static lv_indev_drv_t indev_drv;
// //     lv_indev_drv_init( &indev_drv );
// //     indev_drv.type = LV_INDEV_TYPE_POINTER;
// //     // indev_drv.read_cb = my_touchpad_read;
// //     lv_indev_drv_register( &indev_drv );
    
// //     ui_init();
// //     lv_scr_load(ui_Screen2);
// //     // ps5.begin("bc:c7:46:33:11:d2");
// //     //  ps5.begin("f8:4d:89:66:16:9d");//F8-4D-89-66-16-9D
    
    
// // }
// // // static void newScreen()
// // // {
// // //     lv_scr_load_anim(ui_Screen1, LV_SCR_LOAD_ANIM_MOVE_TOP, 300, 0, true);
// // // }

// // void loop()
// // {
// //    if (role) {
// //     // This device is a TX node

// //     unsigned long start_timer = micros();                // start the timer
// //     bool report = radio.write(&payload, sizeof(float));  // transmit & save the report
// //     unsigned long end_timer = micros();                  // end the timer

// //     if (report) {
// //       Serial.print(F("Transmission successful! "));  // payload was delivered
// //       Serial.print(F("Time to transmit = "));
// //       Serial.print(end_timer - start_timer);  // print the timer result
// //       Serial.print(F(" us. Sent: "));
// //       Serial.println(payload);  // print payload sent
// //       payload += 0.01;          // increment float payload
// //     } else {
// //       Serial.println(F("Transmission failed or timed out"));  // payload was not delivered
// //     }

// //     // to make this example readable in the serial monitor
// //     delay(1000);  // slow transmissions down by 1 second

// //   } else {
// //     // This device is a RX node

// //     uint8_t pipe;
// //     if (radio.available(&pipe)) {              // is there a payload? get the pipe number that recieved it
// //       uint8_t bytes = radio.getPayloadSize();  // get the size of the payload
// //       radio.read(&payload, bytes);             // fetch payload from FIFO
// //       Serial.print(F("Received "));
// //       Serial.print(bytes);  // print the size of the payload
// //       Serial.print(F(" bytes on pipe "));
// //       Serial.print(pipe);  // print the pipe number
// //       Serial.print(F(": "));
// //       Serial.println(payload);  // print the payload's value
// //     }
// //   }  // role

// //   if (Serial.available()) {
// //     // change the role via the serial monitor

// //     char c = toupper(Serial.read());
// //     if (c == 'T' && !role) {
// //       // Become the TX node

// //       role = true;
// //       Serial.println(F("*** CHANGING TO TRANSMIT ROLE -- PRESS 'R' TO SWITCH BACK"));
// //       radio.stopListening();

// //     } else if (c == 'R' && role) {
// //       // Become the RX node

// //       role = false;
// //       Serial.println(F("*** CHANGING TO RECEIVE ROLE -- PRESS 'T' TO SWITCH BACK"));
// //       radio.startListening();
// //     }
// //   }
  
  
  
// //   lv_timer_handler(); /* let the GUI do its work 让 GUI 完成它的工作 */
// //   //  if(ps5.isConnected()) Serial.println("Connected!");
// //   //   while (ps5.isConnected()) {
        
// //   //       #if DEBUG==1
// //   //       PS5_Debug();
// //   //       #endif
// //   //       // lv_scr_load(ui_Screen1);
// //   //       lv_scr_load_anim(ui_Screen1, LV_SCR_LOAD_ANIM_MOVE_TOP, 300, 0, true);
// //   //       lv_timer_handler();
// //   //       lv_bar_set_value(ui_LStickX, ps5.LStickX(), LV_ANIM_ON);
// //   //       lv_bar_set_value(ui_LStickY, ps5.LStickY(), LV_ANIM_ON);
// //   //       lv_bar_set_value(ui_RStickX, ps5.RStickX(), LV_ANIM_ON);
// //   //       lv_bar_set_value(ui_RStickY, ps5.RStickY(), LV_ANIM_ON);

// //   //       lv_bar_set_value(ui_L2, ps5.L2Value(), LV_ANIM_ON);
// //   //       lv_bar_set_value(ui_R2, ps5.R2Value(), LV_ANIM_ON);

// //   //       lv_checkbox_set_state(ui_L1, ps5.L1());
// //   //       lv_checkbox_set_state(ui_R1, ps5.R1());

// //   //       lv_checkbox_set_state(ui_CROSS, ps5.Cross());
// //   //       // lv_checkbox_set_state(ui_CROSS, ps5.Cross());
// //   //       lv_checkbox_set_state(ui_CIRCLE, ps5.Circle());
// //   //       lv_checkbox_set_state(ui_SQUARE, ps5.Square());
// //   //       lv_checkbox_set_state(ui_TRIANGLE, ps5.Triangle());

// //   //       lv_checkbox_set_state(ui_UP, ps5.Up());
// //   //       lv_checkbox_set_state(ui_DOWN, ps5.Down());
// //   //       lv_checkbox_set_state(ui_LEFT, ps5.Left());
// //   //       lv_checkbox_set_state(ui_RIGHT, ps5.Right());

// //   //       delay( 5 );
// //   //   }
    
// // }
// //-------------------------------------------------------------


// #ifndef USEPLATFORMIO
// #error "This example can only be run on platformIO"
// #endif
#include "ui.h"
// #include "ps5Controller.h"
#define TOUCH_MODULES_CST_MUTUAL
#include <SPI.h>
#include <RF24.h>
#include "printf.h"

#define MY_MISO 10
#define MY_MOSI 11
#define MY_SCLK 3
#define MY_SS   2

RF24 radio(1, 2);//ce,csn
SPIClass* hspi = nullptr;
uint8_t address[][6] = { "1Node", "2Node" };
// It is very helpful to think of an address as a path instead of as
// an identifying device destination

// to use different addresses on a pair of radios, we need a variable to
// uniquely identify which address this radio will use to transmit
bool radioNumber = 1;  // 0 uses address[0] to transmit, 1 uses address[1] to transmit

// Used to control whether this node is sending or receiving
bool role = false;  // true = TX role, false = RX role

// For this example, we'll be using a payload containing
// a single float number that will be incremented
// on every successful transmission
float payload = 0.0;


// #include "TouchLib.h"
// #define TOUCH_READ_FROM_INTERRNUPT
// String LVGL_Arduino = "Hello Arduino! ";

/* 
This example can only be run on platformIO. 
Because Arduino cannot index into the demos directory. 
*/
// #include "demos/lv_demos.h"
// #include<lv_demo.h>
// #include "lv_conf.h"
// #include "lvgl.h" /* https://github.com/lvgl/lvgl.git */

#include "Arduino.h"
#include "Wire.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_vendor.h"
#include "ESP32S3_PinOut.h"
#include "lvgl.h"

esp_lcd_panel_io_handle_t io_handle = NULL;
static lv_disp_draw_buf_t disp_buf; // contains internal graphic buffer(s) called draw buffer(s)
static lv_disp_drv_t disp_drv;      // contains callback functions
static lv_color_t *lv_disp_buf;
static bool is_initialized_lvgl = false;

// TouchLib touch(Wire, PIN_IIC_SDA, PIN_IIC_SCL, CTS328_SLAVE_ADDRESS, PIN_TOUCH_RES);

bool inited_touch = false;
#if defined(TOUCH_READ_FROM_INTERRNUPT)
bool get_int_signal = false;
#endif

static bool example_notify_lvgl_flush_ready(esp_lcd_panel_io_handle_t panel_io, esp_lcd_panel_io_event_data_t *edata, void *user_ctx) {
  if (is_initialized_lvgl) {
    lv_disp_drv_t *disp_driver = (lv_disp_drv_t *)user_ctx;
    lv_disp_flush_ready(disp_driver);
  }
  return false;
}


void lv_checkbox_set_state(lv_obj_t * checkbox, bool checked)
{
    if(checked)
    {
      lv_obj_add_state(checkbox, LV_STATE_CHECKED);
    }
    else
    {
      lv_obj_clear_state(checkbox, LV_STATE_CHECKED);
    }
    
}


static void example_lvgl_flush_cb(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_map) {
  esp_lcd_panel_handle_t panel_handle = (esp_lcd_panel_handle_t)drv->user_data;
  int offsetx1 = area->x1;
  int offsetx2 = area->x2;
  int offsety1 = area->y1;
  int offsety2 = area->y2;
  // copy a buffer's content to a specific area of the display
  esp_lcd_panel_draw_bitmap(panel_handle, offsetx1, offsety1, offsetx2 + 1, offsety2 + 1, color_map);
}

// static void lv_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data) {
// #if defined(TOUCH_READ_FROM_INTERRNUPT)
//   if (get_int_signal) {
//     get_int_signal = false;
//     touch.read();
// #else
//   if (touch.read()) {
// #endif
//     TP_Point t = touch.getPoint(0);
//     data->point.x = t.x;
//     data->point.y = t.y;
//     data->state = LV_INDEV_STATE_PR;
//   } else
//     data->state = LV_INDEV_STATE_REL;
// }

void setup() {
  pinMode(PIN_POWER_ON, OUTPUT);
  digitalWrite(PIN_POWER_ON, HIGH);
  Serial.begin(115200);

  pinMode(PIN_LCD_RD, OUTPUT);
  digitalWrite(PIN_LCD_RD, HIGH);
  esp_lcd_i80_bus_handle_t i80_bus = NULL;
  esp_lcd_i80_bus_config_t bus_config = {
      .dc_gpio_num = PIN_LCD_DC,
      .wr_gpio_num = PIN_LCD_WR,
      .clk_src = LCD_CLK_SRC_PLL160M,
      .data_gpio_nums =
          {
              PIN_LCD_D0,
              PIN_LCD_D1,
              PIN_LCD_D2,
              PIN_LCD_D3,
              PIN_LCD_D4,
              PIN_LCD_D5,
              PIN_LCD_D6,
              PIN_LCD_D7,
          },
      .bus_width = 8,
      .max_transfer_bytes = LVGL_LCD_BUF_SIZE * sizeof(uint16_t),
  };
  esp_lcd_new_i80_bus(&bus_config, &i80_bus);

  esp_lcd_panel_io_i80_config_t io_config = {
      .cs_gpio_num = PIN_LCD_CS,
      .pclk_hz = EXAMPLE_LCD_PIXEL_CLOCK_HZ,
      .trans_queue_depth = 20,
      .on_color_trans_done = example_notify_lvgl_flush_ready,
      .user_ctx = &disp_drv,
      .lcd_cmd_bits = 8,
      .lcd_param_bits = 8,
      .dc_levels =
          {
              .dc_idle_level = 0,
              .dc_cmd_level = 0,
              .dc_dummy_level = 0,
              .dc_data_level = 1,
          },
  };
  ESP_ERROR_CHECK(esp_lcd_new_panel_io_i80(i80_bus, &io_config, &io_handle));
  esp_lcd_panel_handle_t panel_handle = NULL;
  esp_lcd_panel_dev_config_t panel_config = {
      .reset_gpio_num = PIN_LCD_RES,
      .color_space = ESP_LCD_COLOR_SPACE_RGB,
      .bits_per_pixel = 16,
  };
  esp_lcd_new_panel_st7789(io_handle, &panel_config, &panel_handle);
  esp_lcd_panel_reset(panel_handle);
  esp_lcd_panel_init(panel_handle);
  esp_lcd_panel_invert_color(panel_handle, true);

  esp_lcd_panel_swap_xy(panel_handle, true);
  esp_lcd_panel_mirror(panel_handle, false, true);
  // the gap is LCD panel specific, even panels with the same driver IC, can
  // have different gap value
  esp_lcd_panel_set_gap(panel_handle, 0, 35);

  /* Lighten the screen with gradient */
  ledcSetup(0, 10000, 8);
  ledcAttachPin(PIN_LCD_BL, 0);
  for (uint8_t i = 0; i < 0xFF; i++) {
    ledcWrite(0, i);
    delay(2);
  }

  lv_init();
  lv_disp_buf = (lv_color_t *)heap_caps_malloc(LVGL_LCD_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA | MALLOC_CAP_INTERNAL);

  lv_disp_draw_buf_init(&disp_buf, lv_disp_buf, NULL, LVGL_LCD_BUF_SIZE);
  /*Initialize the display*/
  lv_disp_drv_init(&disp_drv);
  /*Change the following line to your display resolution*/
  disp_drv.hor_res = EXAMPLE_LCD_H_RES;
  disp_drv.ver_res = EXAMPLE_LCD_V_RES;
  disp_drv.flush_cb = example_lvgl_flush_cb;
  disp_drv.draw_buf = &disp_buf;
  disp_drv.user_data = panel_handle;
  lv_disp_drv_register(&disp_drv);

  /* Register touch brush with LVGL */
//   Wire.begin(PIN_IIC_SDA, PIN_IIC_SCL, 800000);
//   inited_touch = touch.init();
//   if (inited_touch) {
//     touch.setRotation(1);
//     static lv_indev_drv_t indev_drv;
//     lv_indev_drv_init(&indev_drv);
//     indev_drv.type = LV_INDEV_TYPE_POINTER;
//     indev_drv.read_cb = lv_touchpad_read;
//     lv_indev_drv_register(&indev_drv);
//   }
//   is_initialized_lvgl = true;
// #if defined(TOUCH_READ_FROM_INTERRNUPT)
//   attachInterrupt(
//       PIN_TOUCH_INT, [] { get_int_signal = true; }, FALLING);
// #endif

// #if LV_USE_DEMO_WIDGETS
//   lv_demo_widgets();
// #elif LV_USE_DEMO_BENCHMARK
//   lv_demo_benchmark();
// #elif LV_USE_DEMO_STRESS
//   lv_demo_stress();
// #elif LV_USE_DEMO_KEYPAD_AND_ENCODER
//   lv_demo_keypad_encoder();
// #elif LV_USE_DEMO_MUSIC
//   lv_demo_music();
// // #else UseMyGUI
// //   myGUI();
// #endif
// lv_obj_t *label = lv_label_create( lv_scr_act() );
//     lv_label_set_text( label, LVGL_Arduino.c_str() );
//     lv_obj_align( label, LV_ALIGN_CENTER, 0, 0 );
// ps5.begin("bc:c7:46:33:11:d2");
ui_init();

Serial.begin(115200);
  // while (!Serial) {} //some boards need this
 
  // hspi = new SPIClass(HSPI); // by default VSPI is used
  // hspi->begin();
  // // to use the custom defined pins, uncomment the following
  // // hspi->begin(MY_SCLK, MY_MISO, MY_MOSI, MY_SS)
 
  // if (!radio.begin(hspi)) {
  //   Serial.println(F("radio hardware not responding!!"));
  //   while (1) {} // hold program in infinite loop to prevent subsequent errors
  // }
  // char input = Serial.parseInt();
  // radioNumber = input == 1;
  // Serial.print(F("radioNumber = "));
  // Serial.println((int)radioNumber);

  // // role variable is hardcoded to RX behavior, inform the user of this
  // Serial.println(F("*** PRESS 'T' to begin transmitting to the other node"));

  // // Set the PA Level low to try preventing power supply related problems
  // // because these examples are likely run with nodes in close proximity to
  // // each other.
  // radio.setPALevel(RF24_PA_LOW);  // RF24_PA_MAX is default.

  // // save on transmission time by setting the radio to only transmit the
  // // number of bytes we need to transmit a float
  // radio.setPayloadSize(sizeof(payload));  // float datatype occupies 4 bytes

  // // set the TX address of the RX node into the TX pipe
  // radio.openWritingPipe(address[radioNumber]);  // always uses pipe 0

  // // set the RX address of the TX node into a RX pipe
  // radio.openReadingPipe(1, address[!radioNumber]);  // using pipe 1

  // // additional setup specific to the node's role
  // if (role) {
  //   radio.stopListening();  // put radio in TX mode
  // } else {
  //   radio.startListening();  // put radio in RX mode
  // }
  lv_scr_load(ui_Screen2);

}

// int myGUI()
// {
//   lv_obj_t *obj = lv_obj_create(lv_scr_act());
//   lv_obj_set_align(obj, LV_ALIGN_CENTER);
//   delay(1000);
// }

void loop() {
  Serial.printf("loop\n");
  lv_timer_handler();
  delay(5000);
  lv_scr_load_anim(ui_Screen1, LV_SCR_LOAD_ANIM_MOVE_LEFT, 5000, 0, false);
  
  // if (role) {
    // This device is a TX node

  //   unsigned long start_timer = micros();                // start the timer
  //   bool report = radio.write(&payload, sizeof(float));  // transmit & save the report
  //   unsigned long end_timer = micros();                  // end the timer

  //   if (report) {
  //     Serial.print(F("Transmission successful! "));  // payload was delivered
  //     Serial.print(F("Time to transmit = "));
  //     Serial.print(end_timer - start_timer);  // print the timer result
  //     Serial.print(F(" us. Sent: "));
  //     Serial.println(payload);  // print payload sent
  //     payload += 0.01;          // increment float payload
  //   } else {
  //     Serial.println(F("Transmission failed or timed out"));  // payload was not delivered
  //   }

  //   // to make this example readable in the serial monitor
  //   delay(1000);  // slow transmissions down by 1 second

  // } else {
  //   // This device is a RX node

  //   uint8_t pipe;
  //   if (radio.available(&pipe)) {              // is there a payload? get the pipe number that recieved it
  //     uint8_t bytes = radio.getPayloadSize();  // get the size of the payload
  //     radio.read(&payload, bytes);             // fetch payload from FIFO
  //     Serial.print(F("Received "));
  //     Serial.print(bytes);  // print the size of the payload
  //     Serial.print(F(" bytes on pipe "));
  //     Serial.print(pipe);  // print the pipe number
  //     Serial.print(F(": "));
  //     Serial.println(payload);  // print the payload's value
  //   }
  // }  // role

  // if (Serial.available()) {
  //   // change the role via the serial monitor

  //   char c = toupper(Serial.read());
  //   if (c == 'T' && !role) {
  //     // Become the TX node

  //     role = true;
  //     Serial.println(F("*** CHANGING TO TRANSMIT ROLE -- PRESS 'R' TO SWITCH BACK"));
  //     radio.stopListening();

  //   } else if (c == 'R' && role) {
  //     // Become the RX node

  //     role = false;
  //     Serial.println(F("*** CHANGING TO RECEIVE ROLE -- PRESS 'T' TO SWITCH BACK"));
  //     radio.startListening();
  //   }
  // }
  // myGUI();
  // lv_timer_handler(); /* let the GUI do its work 让 GUI 完成它的工作 */
    // while (ps5.isConnected()) {
    
    //     // lv_scr_load(ui_Screen1);
    //     lv_timer_handler();
        

    //     lv_bar_set_value(ui_LStickX, ps5.LStickX(), LV_ANIM_ON);
    //     lv_bar_set_value(ui_LStickY, ps5.LStickY(), LV_ANIM_ON);
    //     lv_bar_set_value(ui_RStickX, ps5.RStickX(), LV_ANIM_ON);
    //     lv_bar_set_value(ui_RStickY, ps5.RStickY(), LV_ANIM_ON);

    //     lv_bar_set_value(ui_L2, ps5.L2Value(), LV_ANIM_ON);
    //     lv_bar_set_value(ui_R2, ps5.R2Value(), LV_ANIM_ON);

    //     lv_checkbox_set_state(ui_L1, ps5.L1());
    //     lv_checkbox_set_state(ui_R1, ps5.R1());

    //     lv_checkbox_set_state(ui_CROSS, ps5.Cross());
    //     // lv_checkbox_set_state(ui_CROSS, ps5.Cross());
    //     lv_checkbox_set_state(ui_CIRCLE, ps5.Circle());
    //     lv_checkbox_set_state(ui_SQUARE, ps5.Square());
    //     lv_checkbox_set_state(ui_TRIANGLE, ps5.Triangle());

    //     lv_checkbox_set_state(ui_UP, ps5.Up());
    //     lv_checkbox_set_state(ui_DOWN, ps5.Down());
    //     lv_checkbox_set_state(ui_LEFT, ps5.Left());
    //     lv_checkbox_set_state(ui_RIGHT, ps5.Right());

         

    //     // if (ps5.Charging()) Serial.println("The controller is charging"); //doesn't work
    //     // if (ps5.Audio()) Serial.println("The controller has headphones attached"); //doesn't work
    //     // if (ps5.Mic()) Serial.println("The controller has a mic attached"); //doesn't work

    //     // Serial.printf("Battery Level : %d\n", ps5.Battery()); //doesn't work
    //     // delay(10);
    //     // tft.fillScreen(TFT_BLACK);
    //     // Serial.println();
    //     // ps5.setRumble(ps5.L2Value(), ps5.R2Value());
    //     // tft.fillScreen(TFT_BLACK);
    // // This delay is to make the output more human readable
    // // Remove it when you're not trying to see the output
    // // delay(50);
    
    // }
    // // delay( 15 );
  delay(2);
}

//-------------------------------------------------------------------------------
// // #include <Arduino.h>
// // #include "TFT_eSPI.h"
// // #include "ESP32S3_PinOut.h"
// // #include "img_logo.h"


// // TFT_eSPI tft = TFT_eSPI();
// // #define WAIT 1000
// // unsigned long targetTime = 0; // Used for testing draw times


// // void setup() {
// //   // put your setup code here, to run once:
// //   pinMode(PIN_POWER_ON, OUTPUT);
// //   digitalWrite(PIN_POWER_ON, HIGH);

// //   Serial.begin(115200);
// //   Serial.println("Hello T-Display-S3");

// //   tft.begin();
// //   tft.setRotation(1);
// //   tft.setSwapBytes(true);
// //   tft.pushImage(0, 0, 320, 170, (uint16_t *)img_logo);
// //   delay(2000);

// //   ledcSetup(0, 2000, 8);
// //   ledcAttachPin(PIN_LCD_BL, 0);
// //   ledcWrite(0, 255);
// // }

// // void loop() {
// //   // put your main code here, to run repeatedly:
// //   targetTime = millis();

// //   // First we test them with a background colour set
// //   tft.setTextSize(1);
// //   tft.fillScreen(TFT_BLACK);
// //   tft.setTextColor(TFT_GREEN, TFT_BLACK);

// //   tft.drawString(" !\"#$%&'()*+,-./0123456", 0, 0, 2);
// //   tft.drawString("789:;<=>?@ABCDEFGHIJKL", 0, 16, 2);
// //   tft.drawString("MNOPQRSTUVWXYZ[\\]^_`", 0, 32, 2);
// //   tft.drawString("abcdefghijklmnopqrstuvw", 0, 48, 2);
// //   int xpos = 0;
// //   xpos += tft.drawString("xyz{|}~", 0, 64, 2);
// //   tft.drawChar(127, xpos, 64, 2);
// //   delay(WAIT);

// //   tft.fillScreen(TFT_BLACK);
// //   tft.setTextColor(TFT_GREEN, TFT_BLACK);

// //   tft.drawString(" !\"#$%&'()*+,-.", 0, 0, 4);
// //   tft.drawString("/0123456789:;", 0, 26, 4);
// //   tft.drawString("<=>?@ABCDE", 0, 52, 4);
// //   tft.drawString("FGHIJKLMNO", 0, 78, 4);
// //   tft.drawString("PQRSTUVWX", 0, 104, 4);
// //   delay(WAIT);

// //   tft.fillScreen(TFT_BLACK);
// //   tft.drawString("YZ[\\]^_`abc", 0, 0, 4);
// //   tft.drawString("defghijklmno", 0, 26, 4);
// //   tft.drawString("pqrstuvwxyz", 0, 52, 4);
// //   xpos = 0;
// //   xpos += tft.drawString("{|}~", 0, 78, 4);
// //   tft.drawChar(127, xpos, 78, 4);
// //   delay(WAIT);

// //   tft.fillScreen(TFT_BLACK);
// //   tft.setTextColor(TFT_BLUE, TFT_BLACK);

// //   tft.drawString("012345", 0, 0, 6);
// //   tft.drawString("6789", 0, 40, 6);
// //   tft.drawString("apm-:.", 0, 80, 6);
// //   delay(WAIT);

// //   tft.fillScreen(TFT_BLACK);
// //   tft.setTextColor(TFT_RED, TFT_BLACK);

// //   tft.drawString("0123", 0, 0, 7);
// //   tft.drawString("4567", 0, 60, 7);
// //   delay(WAIT);

// //   tft.fillScreen(TFT_BLACK);
// //   tft.drawString("890:.", 0, 0, 7);
// //   tft.drawString("", 0, 60, 7);
// //   delay(WAIT);

// //   tft.fillScreen(TFT_BLACK);
// //   tft.setTextColor(TFT_YELLOW, TFT_BLACK);

// //   tft.drawString("01", 0, 0, 8);
// //   delay(WAIT);

// //   tft.drawString("23", 0, 0, 8);
// //   delay(WAIT);

// //   tft.drawString("45", 0, 0, 8);
// //   delay(WAIT);

// //   tft.drawString("67", 0, 0, 8);
// //   delay(WAIT);

// //   tft.drawString("89", 0, 0, 8);
// //   delay(WAIT);

// //   tft.drawString("0:.", 0, 0, 8);
// //   delay(WAIT);

// //   tft.setTextColor(TFT_MAGENTA);
// //   tft.drawNumber(millis() - targetTime, 0, 100, 4);
// //   delay(4000);

// //   // Now test them with transparent background
// //   targetTime = millis();

// //   tft.setTextSize(1);
// //   tft.fillScreen(TFT_BROWN);
// //   tft.setTextColor(TFT_GREEN);

// //   tft.drawString(" !\"#$%&'()*+,-./0123456", 0, 0, 2);
// //   tft.drawString("789:;<=>?@ABCDEFGHIJKL", 0, 16, 2);
// //   tft.drawString("MNOPQRSTUVWXYZ[\\]^_`", 0, 32, 2);
// //   tft.drawString("abcdefghijklmnopqrstuvw", 0, 48, 2);
// //   xpos = 0;
// //   xpos += tft.drawString("xyz{|}~", 0, 64, 2);
// //   tft.drawChar(127, xpos, 64, 2);
// //   delay(WAIT);

// //   tft.fillScreen(TFT_BROWN);
// //   tft.setTextColor(TFT_GREEN);

// //   tft.drawString(" !\"#$%&'()*+,-.", 0, 0, 4);
// //   tft.drawString("/0123456789:;", 0, 26, 4);
// //   tft.drawString("<=>?@ABCDE", 0, 52, 4);
// //   tft.drawString("FGHIJKLMNO", 0, 78, 4);
// //   tft.drawString("PQRSTUVWX", 0, 104, 4);

// //   delay(WAIT);
// //   tft.fillScreen(TFT_BROWN);
// //   tft.drawString("YZ[\\]^_`abc", 0, 0, 4);
// //   tft.drawString("defghijklmno", 0, 26, 4);
// //   tft.drawString("pqrstuvwxyz", 0, 52, 4);
// //   xpos = 0;
// //   xpos += tft.drawString("{|}~", 0, 78, 4);
// //   tft.drawChar(127, xpos, 78, 4);
// //   delay(WAIT);

// //   tft.fillScreen(TFT_BROWN);
// //   tft.setTextColor(TFT_BLUE);

// //   tft.drawString("012345", 0, 0, 6);
// //   tft.drawString("6789", 0, 40, 6);
// //   tft.drawString("apm-:.", 0, 80, 6);
// //   delay(WAIT);

// //   tft.fillScreen(TFT_BROWN);
// //   tft.setTextColor(TFT_RED);

// //   tft.drawString("0123", 0, 0, 7);
// //   tft.drawString("4567", 0, 60, 7);
// //   delay(WAIT);

// //   tft.fillScreen(TFT_BROWN);
// //   tft.drawString("890:.", 0, 0, 7);
// //   tft.drawString("", 0, 60, 7);
// //   delay(WAIT);

// //   tft.fillScreen(TFT_BROWN);
// //   tft.setTextColor(TFT_YELLOW);

// //   tft.drawString("0123", 0, 0, 8);
// //   delay(WAIT);

// //   tft.fillScreen(TFT_BROWN);
// //   tft.drawString("4567", 0, 0, 8);
// //   delay(WAIT);

// //   tft.fillScreen(TFT_BROWN);
// //   tft.drawString("890:.", 0, 0, 8);
// //   delay(WAIT);

// //   tft.setTextColor(TFT_MAGENTA);

// //   tft.drawNumber(millis() - targetTime, 0, 100, 4);
// //   delay(4000);
// // }