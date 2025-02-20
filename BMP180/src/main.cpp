#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BusIO_Register.h>
#include <Adafruit_BMP085_U.h>
#include <Arduino.h>
#include <SPI.h>
#include <WiFi.h>
#include <ThingSpeak.h>

WiFiClient client;
// Khai báo đối tượng BMP180
Adafruit_BMP085_Unified bmp;

const char *ssid = "Long&Le";
const char *password = "03062002";

unsigned myChannelNumber = 2;
const char* myWriteAPIKey= "108ZJH0CAAHJJG3R";

void setup() {
  // Mở kết nối Serial
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  // Khởi tạo I2C
  Serial.println("BMP180 test");

  // Kiểm tra xem BMP180 có được kết nối đúng không
  if (!bmp.begin()) {
    Serial.print("Không thể tìm thấy cảm biến BMP180!");
    while (1);
  }
  ThingSpeak.begin(client);
}

void loop() {
  // Đọc các giá trị từ cảm biến
  float temperature;
  float pressure;
  
  // Đọc nhiệt độ
  bmp.getTemperature(&temperature);
  int x = ThingSpeak.writeField(myChannelNumber, 1, temperature, myWriteAPIKey);
  
  // Đọc áp suất
  bmp.getPressure(&pressure);
  int y = ThingSpeak.writeField(myChannelNumber, 2, pressure, myWriteAPIKey);
  // In kết quả lên Serial Monitor
  Serial.print("Nhiệt độ: ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Áp suất: ");
  Serial.print(pressure);
  Serial.println(" Pa");

  // Đợi một chút trước khi tiếp tục
  delay(2000);
}
