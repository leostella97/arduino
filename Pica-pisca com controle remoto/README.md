# Pica-pisca com controle remoto

Este código em C permite controlar o estado de um LED através de um controle remoto infravermelho (IR) conectado a um Arduino.

Bibliotecas utilizadas
O código faz uso da biblioteca IRremote.h para decodificar os sinais infravermelhos recebidos do controle remoto.

  #include <IRremote.h>

Configuração dos pinos
Os pinos que serão utilizados no código são definidos como constantes para facilitar a sua identificação e manutenção do código. Neste caso, estamos utilizando o pino digital 13 para controlar o LED e o pino digital 11 para receber os sinais do controle remoto.

  const int ledPin = 13;
  const int irReceiverPin = 11;

Inicialização do receptor IR
Antes de utilizar o controle remoto, é preciso inicializar o receptor IR do Arduino. Isso é feito na função setup() através do método enableIRIn().

  IRrecv irrecv(irReceiverPin);

  void setup()
  {
  pinMode(ledPin, OUTPUT);
  irrecv.enableIRIn();
  }

Controle do LED
O controle do LED é feito no loop principal do código, na função loop(). Quando um sinal infravermelho é recebido, o método decode() é chamado para decodificar a mensagem e armazená-la na variável results.

  decode_results results;

  void loop()
  {
  if (irrecv.decode(&results))
  {
    // Código para controle do LED
    // ...
  }
  }
Dentro do bloco if, utilizamos um switch para verificar qual botão do controle remoto foi pressionado. Neste exemplo, estamos usando os códigos dos botões "esquerda" e "direita" do controle remoto para ligar e desligar o LED, respectivamente.

  switch (results.value)
  {
  case 0xFFA25D: // Botão esquerdo pressionado
    digitalWrite(ledPin, LOW);
    break;

  case 0xFF629D: // Botão direito pressionado
    digitalWrite(ledPin, HIGH);
    break;
}
Quando um botão é pressionado, o LED é ligado ou desligado através da função digitalWrite(), que define o estado do pino de saída do LED.

  digitalWrite(ledPin, LOW); // Desliga o LED
  digitalWrite(ledPin, HIGH); // Liga o LED

A mensagem recebida é limpa utilizando o método resume() para que possa ser recebida uma nova mensagem na próxima iteração do loop.

  irrecv.resume();

Com este código, você pode controlar o estado de um LED utilizando um controle remoto IR conectado a um Arduino.