#include "nRF24L01.h" // nRF24L01 kütüphanesini porjemize ekledik 
#include "RF24.h" // RF24 kütüphanesini projemize ekledik
#include "SPI.h" // SPI kütüphanesini projemize ekledik
int msg[2]; // msg adında bir değişken tanımladık
RF24 radio(9,10); // nRF24L01'in CE pininin Arduino'daki 9. pine, CSN pininin Arduino'daki 10. pine bağlı olduğunu söyledik
const uint64_t pipe = 0xE6E6E6E6E6E6; // iki nRF24L01'in haberleşmesi için bir kanal oluşturduk
#define led 5
void setup() {
  Serial.begin(9600); // seri port ekranını başlattık ve baudrate değerini 9600 olarak belirledik
  radio.begin(); // nRF24L01'i başlattık
  radio.openReadingPipe(1,pipe); // nRF24L01'in veriyi diğer nRF24L01'den alması için oluşturduğumuz kanalı kullanmasını söyledik
  radio.startListening(); // diğer nRF24L01'den veriyi alması için ortamdaki sinyalleri dinlemesini söyledik
  pinMode(led,OUTPUT);
}

void loop() {
  if ( radio.available() ) // eğer nRF24L01 bağlantısı müsaitse
  {
    bool done = false; // bool veri tipinde bir değişken tanımladık ve false olarak belirledik
    while (!done)
    {
      done = radio.read( msg, sizeof(msg) ); // tanımladığımız değişkenin nRF24L01'den alınan msg değişkeni olduğunu söyledik
      

      if(msg[0] >= 482 && msg[0] <= 520 && msg[1] >= 482 && msg[1] <= 520)
      {
        // DUR
        Serial.println("DUR");
      }
      if(msg[0] >=525 && msg[0] <=1023)
      {
        // İLERİ
        Serial.println("İLERİ");
      }

      if(msg[0] >= 0 && msg[0] <= 480)
      {
        // GERİ
        Serial.println("GERİ");
      }
      
      if(msg[1] >= 525 && msg[1] <= 1023)
      {
        // SAĞA
        Serial.println("SAĞA");
      }

      if(msg[1] >= 0 && msg[1] <= 480)
      {
        // SOLA
        Serial.println("SOLA");
      }

      if(msg[0] >=525 && msg[0] <=1023 && msg[1] >= 525 && msg[1] <= 1023)
      {
        // İLERİ VE SAĞA
        Serial.println("İLERİ VE SAĞA");
      }

      if(msg[0] >=525 && msg[0] <=1023 && msg[1] >= 0 && msg[1] <= 480)
      {
        // İLERİ VE SOLA
        Serial.println("İLERİ VE SOLA");
      }

      if(msg[0] >= 0 && msg[0] <= 480 && msg[1] >= 525 && msg[1] <= 1023)
      {
        // GERİ VE SAĞA
        Serial.println("GERİ VE SAĞA");
      }

      if(msg[0] >= 0 && msg[0] <= 480 && msg[1] >= 0 && msg[1] <= 480)
      {
        // GERİ VE SOLA
        Serial.println("GERİ VE SOLA");
      }
      
    }
  }
 

  

}
