// Definir os pinos utilizados
const int pinoSensorLuz = A0;
const int pinoLED = 13;

void setup() {
  pinMode(pinoSensorLuz, INPUT);
  pinMode(pinoLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Ler o valor do sensor de luz
  int valorSensorLuz = analogRead(pinoSensorLuz);

  // Converter o valor para uma porcentagem
  float porcentagemLuz = (valorSensorLuz / 1023.0) * 100;

  // Exibir o valor no monitor serial
  Serial.print("Porcentagem de luz: ");
  Serial.println(porcentagemLuz);

  // Verificar se a porcentagem de luz é menor que 40%
  if (porcentagemLuz <= 40) {
    // Acender o LED
    digitalWrite(pinoLED, HIGH);
  } else {
    // Apagar o LED
    digitalWrite(pinoLED, LOW);
  }

  // Aguardar um curto período de tempo antes de repetir o loop
  delay(1000);
}