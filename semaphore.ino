 byte seven_seg_digits[18][7] = { { 1,1,1,1,1,1,0 }, // = 0
 { 0,1,1,0,0,0,0 }, // = 1
 { 1,1,0,1,1,0,1 }, // = 2
 { 1,1,1,1,0,0,1 }, // = 3
 { 0,1,1,0,0,1,1 }, // = 4
 { 1,0,1,1,0,1,1}, // = 5
 { 1,0,1,1,1,1,1 }, // = 6
 { 1,1,1,0,0,0,0 }, // = 7
 { 1,1,1,1,1,1,1 }, // = 8
 { 1,1,1,0,0,1,1 }, // = 9 
 { 1,1,1,0,1,1,1 }, // = A
 { 0,0,1,1,1,1,1 }, // = b
 { 1,0,0,1,1,1,0 }, // = C
 { 0,1,1,1,1,0,1 }, // = D
 { 1,0,0,1,1,1,1 }, // = E
 { 1,0,0,0,1,1,1 }, // = F
 { 1,0,1,1,1,1,1 }, // = G
 { 0,1,1,0,1,1,1 } // = H
 };
 // ligação dos pinos digitais de saída

 int estado = 1;
 void setup() {
 pinMode(2, OUTPUT); //Pino 2 do Arduino ligado ao segmento A
 pinMode(3, OUTPUT); //Pino 3 do Arduino ligado ao segmento B
 pinMode(4, OUTPUT); //Pino 4 do Arduino ligado ao segmento C
 pinMode(5, OUTPUT); //Pino 5 do Arduino ligado ao segmento D
 pinMode(6, OUTPUT); //Pino 6 do Arduino ligado ao segmento E
 pinMode(7, OUTPUT); //Pino 7 do Arduino ligado ao segmento F
 pinMode(8, OUTPUT); //Pino 8 do Arduino ligado ao segmento G
 pinMode(9, OUTPUT); //Pino 9 do Arduino ligado ao segmento PONTO
 //writeDot(0); // Inicia com o "ponto" (o signal de casas decimais led) desligado

pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);

 attachInterrupt(digitalPinToInterrupt(21), countDown, RISING   );
 }

 //void writeDot(byte dot) {
 //digitalWrite(10, OUTPUT);
 //pinMode(11, INPUT_PULLUP); 
 //}

 void sevenSegWrite(byte digit) {
 byte pin = 2;
 for (byte segCount = 0; segCount < 7; ++segCount) {
 digitalWrite(pin, seven_seg_digits[digit][segCount]);
 ++pin;
 }
 }

 void countDown () {
  estado = 2;
 }

 void pedestre () {
  for (byte digit = 10; digit > 0; digit-- ) {
    sevenSegWrite(digit-1);
    delay(1000);
 }
 }

 void semaforoA (){
  digitalWrite(10, HIGH);
  delay(1000);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(1000);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(12, LOW);
 }



void loop() {

  switch (estado) {
    case 1: semaforoA(); estado++;
    case 2: pedestre (); estado = 1;
  }

} 
