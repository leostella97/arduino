// Inclui as bibliotecas necessárias
#include <IRremote.h>

// Define os pinos usados
const int ledPin = 13;
const int irReceiverPin = 11;

// Cria o objeto receptor de IR
IRrecv irrecv(irReceiverPin);

// Cria o objeto para armazenar a mensagem recebida
decode_results results;

void setup()
{
  // Configura o pino do LED como saída
  pinMode(ledPin, OUTPUT);

  // Inicia o receptor de IR
  irrecv.enableIRIn();
}

void loop()
{
  // Verifica se há uma mensagem IR recebida
  if (irrecv.decode(&results))
  {
    // Verifica qual botão do controle remoto foi pressionado
    switch (results.value)
    {
      case 0xFFA25D: // Botão esquerdo pressionado
        // Para de piscar
        digitalWrite(ledPin, LOW);
        break;

      case 0xFF629D: // Botão direito pressionado
        // Começa a piscar
        digitalWrite(ledPin, HIGH);
        break;
    }

    // Limpa a mensagem recebida
    irrecv.resume();
  }
}
