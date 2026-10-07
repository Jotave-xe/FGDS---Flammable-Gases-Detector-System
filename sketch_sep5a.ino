#define LED_BRANCO 15
#define LED_VERDE 2
#define LED_VERMELHO 4

#define  BOTAO_RESET 17
#define BUZZER 5

#define MQ2 34
#define MQ6 35

void IRAM_ATTR interrupcao() {
  digitalWrite(LED_BRANCO, HIGH);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_VERMELHO, LOW);

  Serial.println("CALIBRANDO OS SENSORES, ESPERE UM POUCO...");

  delay(10000);

  digitalWrite(LED_BRANCO, LOW);
  Serial.println("SENSORES CALIBRADOS :)");
}

void LEITURA_NORMAL(){ //função para quando as leituras serem normais
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(BUZZER, LOW);

  Serial.println("TUDO TRANQUILO, METRICAS NORMAIS :)");
}

void LEITURA_ANORMAL(){ //função para quando as leituras derem altas
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_VERMELHO, HIGH);
  digitalWrite(BUZZER, HIGH);

  Serial.println("CUIDADO !!! PERIGO EXTREMO");
}



void setup() {

  //setup dos LEDS
  pinMode(BOTAO_BRANCO, OUTPUT);
  pinMode(BOTAO_VERDE, OUTPUT);
  pinMode(BOTAO_AMARELO, OUTPUT);
  pinMode(BOTAO_VERMELHO, OUTPUT);

  digitalWrite(LED_BRANCO, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERMELHO, LOW);


  //setup do botão
  pinMode(BOTAO_RESET, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BOTAO_RESET), interrupcao, FALLING);

  Serial.begin(115200);
  
  pinMode(MQ2, INPUT);
  pinMode(MQ6, INPUT);

}

void loop() {

  int valorMQ2 = analogRead(MQ2);
  int valorMQ6 = analogRead(MQ6);

  Serial.print("MQ-2: ");
  Serial.print(valorMQ2);

  Serial.print(" | MQ-6: ");
  Serial.println(valorMQ6);

  delay(500);
}
