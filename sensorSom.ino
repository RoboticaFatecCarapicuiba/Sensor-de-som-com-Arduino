int valorSom = 0; // variável valorSom, que contém o valor detectado na porta A0 (o sinal de saída do microfone)
int i = 0;        // índice usado para as rotinas de controle dos LEDs
int base = 360;   // valor base, usado para definir o limite mínimo de acionamento dos LEDs

void setup()
{
  for (i = 7; i <= 12; i++) // laço for para definir as portas de 7 a 12 como portas de saída
    pinMode(i, OUTPUT);

  Serial.begin(9600); // inicializa o monitor serial, para exibir rastreamento de depuração
}

void loop()
{
  valorSom = analogRead(A0); // detecta o valor (volume) do som
  Serial.println(valorSom);  // rastreamento de depuração

  for (i = 7; i <= 12; i++)
    digitalWrite(i, LOW); // desliga todos os LEDs previamente

  if (valorSom >= base) // Se o som excede o valor base
    digitalWrite(12, HIGH); // acende o primeiro LED da esquerda

  if (valorSom >= base + 16) // Se o som excede o valor base + 15
    digitalWrite(11, HIGH);  // acende o segundo LED da esquerda

  if (valorSom >= base + 31) // Se o som excede o valor base + 30
    digitalWrite(10, HIGH);  // acende o terceiro LED da esquerda

  if (valorSom >= base + 46) // Se o som excede o valor base + 45
    digitalWrite(9, HIGH);   // acende o quarto LED da esquerda

  if (valorSom >= base + 61) // Se o som excede o valor base + 60
    digitalWrite(8, HIGH);   // acende o quinto LED da esquerda

  if (valorSom >= base + 76) // Se o som excede o valor base + 75
    digitalWrite(7, HIGH);   // acende o sexto LED da esquerda
}
