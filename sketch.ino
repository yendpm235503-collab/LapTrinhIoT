const int kPinPIR = 2;    // Chân số 2 đọc tín hiệu từ cảm biến PIR
const int kPinOut = 9;    // Chân số 9 cấp điện cho cả LED và Còi Buzzer

void setup() {
  pinMode(kPinPIR, INPUT);      // Thiết lập chân cảm biến là ngõ vào (INPUT)
  pinMode(kPinOut, OUTPUT);     // Thiết lập chân số 9 là ngõ ra (OUTPUT)
  Serial.begin(9600);           // Bật màn hình Serial để xem thông báo chữ
}

void loop() {
  // Đọc tín hiệu từ cảm biến PIR
  int trangThai = digitalRead(kPinPIR);

  if (trangThai == HIGH) {        // Khi phát hiện có người chuyển động
    digitalWrite(kPinOut, HIGH);  // Cấp điện 5V ra chân số 9 -> Đèn sáng!
    tone(kPinOut, 1000);          // Phát xung âm thanh 1000Hz -> Còi kêu!
    Serial.println("CẢNH BÁO: Phát hiện có chuyển động!");
    delay(500);
  } else {                        // Khi không có chuyển động
    noTone(kPinOut);              // Tắt tiếng còi
    digitalWrite(kPinOut, LOW);   // Ngắt điện chân số 9 -> Đèn tắt!
    Serial.println("Hệ thống an toàn.");
    delay(200);
  }
}