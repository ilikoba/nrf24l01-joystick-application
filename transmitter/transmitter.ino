#include "nRF24L01.h" // nRF24L01 kütüphanesini porjemize ekledik 
#include "RF24.h" // RF24 kütüphanesini projemize ekledik
#include "SPI.h" // SPI kütüphanesini projemize ekledik
#define JOYSTICK_X A0 // joystick modülümüzde bulunan x pinini analog 0 (sıfır) pinine bağladığımızı söyledik
#define JOYSTICK_Y A1 // joystick modülümüzde bulunan y pinini analog 1 (bir) pinine bağladığımızı söyledik
int msg[2]; // msg adında bir değişken tanımladık
RF24 radio(9,10); // nRF24L01'in CE pininin Arduino'daki 9. pine, CSN pininin Arduino'daki 10. pine bağlı olduğunu söyledik
const uint64_t pipe = 0xE6E6E6E6E6E6; // iki nRF24L01'in haberleşmesi için bir kanal oluşturduk
void setup() {
  Serial.begin(9600); // seri port ekranını başlattık ve baudrate değerini 9600 olarak belirledik
  radio.begin(); // nRF24L01'i başlattık
  radio.openWritingPipe(pipe); // nRF24L01'in veriyi diğer nRF24L01'e göndermek için oluşturduğumuz kanalı kullanmasını söyledik
}

void loop() {
  msg[0] = analogRead(JOYSTICK_X); // msg[0] değişkeninin A0 pininden okunacak değer olduğunu söyledik
  msg[1] = analogRead(JOYSTICK_Y); // msg[1] değişkeninin A1 pininden okunacak değer olduğunu söyledik
  
  radio.write( msg, sizeof(msg)); // msg[0] ve msg[1] değişkenlerini diğer nRF24L01'e gönderdik

}
