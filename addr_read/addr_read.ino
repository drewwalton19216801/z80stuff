#define A0 53
#define A1 51
#define A2 49
#define A3 47
#define A4 45
#define A5 43
#define A6 41
#define A7 39
#define A8 37
#define A9 35
#define A10 33

#define SIG 31

struct AddressBus {
  String a0;
  String a1;
  String a2;
  String a3;
  String a4;
  String a5;
  String a6;
  String a7;
  String a8;
  String a9;
  String a10;
};

int sign = 1;

struct AddressBus bus;
String prevAddr;
String Addr;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
  pinMode(A8, INPUT);
  pinMode(A9, INPUT);
  pinMode(A10, INPUT);
  pinMode(SIG, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sign = digitalRead(SIG);
  if (sign == 0) {
    bus.a0 = String(digitalRead(A0));
    bus.a1 = String(digitalRead(A1));
    bus.a2 = String(digitalRead(A2));
    bus.a3 = String(digitalRead(A3));
    bus.a4 = String(digitalRead(A4));
    bus.a5 = String(digitalRead(A5));
    bus.a6 = String(digitalRead(A6));
    bus.a7 = String(digitalRead(A7));
    bus.a8 = String(digitalRead(A8));
    bus.a9 = String(digitalRead(A9));
    bus.a10 = String(digitalRead(A10));
    Addr = String(bus.a10 + bus.a9 + bus.a8 + bus.a7 + bus.a6 + bus.a5 + bus.a4 + bus.a3 + bus.a2 + bus.a1 + bus.a0);
    if (Addr.equals(prevAddr) == false) {
      prevAddr = Addr;
      Serial.print(Addr);
      Serial.println("");
      delay(300);
    }
  }
}
