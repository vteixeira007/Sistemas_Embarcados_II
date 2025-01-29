// Sensor de Temperatura TMP36
int Pino_temperatura = A0;  // Pino ao qual o sensor de temperatura TMP36 está conectado
int TemperaturaTensao;      // Variável para armazenar o valor lido do sensor em termos de tensão
float Tensao;               // Variável para armazenar a tensão convertida a partir do valor lido do sensor
float TemperaturaC;         // Variável para armazenar a temperatura em graus Celsius
float TemperaturaF;         // Variável para armazenar a temperatura em graus Fahrenheit
float TemperaturaK;         // Variável para armazenar a temperatura em Kelvin

void setup() {
  pinMode(Pino_temperatura, INPUT);  // Configura o pino do sensor como entrada
  Serial.begin(9600);               // Inicia a comunicação serial com uma taxa de 9600 bps
}

void loop() {
  // Faz a leitura da tensão no Sensor de Temperatura
  TemperaturaTensao = analogRead(Pino_temperatura);
  Tensao = TemperaturaTensao * 5;
  Tensao = Tensao / 1024;

  // Converte a tensão lida em Graus Celsius
  TemperaturaC = (Tensao - 0.5) * 100;

  // Converte a temperatura de graus Celsius em Fahrenheit
  TemperaturaF = (TemperaturaC * 9 / 5) + 32;

  // Converte a temperatura de graus Celsius para Kelvin
  TemperaturaK = TemperaturaC + 273.15;

  // Imprime as informações no monitor serial
  Serial.print("Temperatura: ");
  Serial.print(TemperaturaC);
  Serial.print(" C | ");
  Serial.print(TemperaturaF);
  Serial.print(" F | ");
  Serial.print(TemperaturaK);
  Serial.println(" K");

  delay(500);  // Adiciona um atraso de 500 milissegundos para evitar leituras muito frequentes
}
