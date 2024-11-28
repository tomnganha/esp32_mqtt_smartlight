
// #include <Arduino.h>
// #include <ezButton.h>


// //5 butoon [15,16,17,18,19]
// //dieu khien 5 den [21,33,23,25,26]
// // Khai báo chân LED và nút nhấn
// const int BUTTON_PINS[] = {15, 16, 4, 18, 19}; // GPIO cho 5 nút nhấn
// const int LED_PINS[] = {17,22,23,25,26};         // GPIO cho 5 bóng đèn
// const int NUM_BUTTONS=5;

// // Tạo mảng quản lý nút nhấn và khởi tạo ngay
// ezButton buttons[NUM_BUTTONS] = {
//   ezButton(BUTTON_PINS[0]),
//   ezButton(BUTTON_PINS[1]),
//   ezButton(BUTTON_PINS[2]),
//   ezButton(BUTTON_PINS[3]),
//   ezButton(BUTTON_PINS[4])
// };


// // Trạng thái của LED
// bool ledStates[NUM_BUTTONS] = {false};
// void setup(){
//   Serial.begin(9600);
//   for(int i=0;i<NUM_BUTTONS;i++){
    
//     pinMode(LED_PINS[i],OUTPUT);
//     digitalWrite(LED_PINS[i],LOW);
//     buttons[i].setDebounceTime(50); // Chống rung
    
//   }
//   pinMode(LDR_PIN,INPUT);
//    pinMode(LED_LDR,OUTPUT);
// }
// void loop(){
  
//   digitalWrite(LED_LDR,digitalRead(LDR_PIN));
//   for(int i=0;i<NUM_BUTTONS;i++){
//     buttons[i].loop();
//     if(buttons[i].isPressed()){
//       ledStates[i]=!ledStates[i];
//       digitalWrite(LED_PINS[i],ledStates[i]);
//       Serial.print(digitalRead(LED_PINS[i]));
//       Serial.print("LED");
//       Serial.print(i);
//       Serial.println(" toggle");
//     }
//   }
// }






