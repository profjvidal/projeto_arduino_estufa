// C++ code
// Projeto - Simulando um sistema básico para estufa


// Pinos de conexão
const int sensorTemperaturaPin = 0;   // Pino analógico para o sensor de temperatura
const int motorVentiladorPin = 3;     // Pino de controle do motor do ventilador
const int ledVermelhoPin = 5;         // Pino de controle do LED vermelho
const int buzinaPin = 7;              // Pino de controle da buzina

// Limiares de temperatura
const int temperaturaLimiteVentilador = 30;
const int temperaturaLimiteEmergencia = 50;

void setup() {
  // Inicializa os pinos como saídas ou entradas
  pinMode(motorVentiladorPin, OUTPUT);
  pinMode(ledVermelhoPin, OUTPUT);
  pinMode(buzinaPin, OUTPUT);

  // Inicializa a comunicação serial para monitoramento (opcional)
  Serial.begin(9600);
}

void loop() {
  // Faz a leitura da temperatura em graus Celsius
  float temperatura = lerTemperatura();

  // Exibe a temperatura no monitor serial (opcional)
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" Grau Celsius");

  // Verifica as condições de temperatura e toma as ações necessárias
  if (temperatura >= temperaturaLimiteVentilador) {
	// Liga o motor do ventilador
    digitalWrite(motorVentiladorPin, HIGH);
  } else {
	// Desliga o motor do ventilador
    digitalWrite(motorVentiladorPin, LOW);
  }

  if (temperatura >= temperaturaLimiteEmergencia) {
	// Liga o LED vermelho e a buzina
    digitalWrite(ledVermelhoPin, HIGH);
	digitalWrite(buzinaPin, HIGH);
  } else {
	// Desliga o LED vermelho e a buzina
    digitalWrite(ledVermelhoPin, LOW);
    digitalWrite(buzinaPin, LOW);
  }
}

float lerTemperatura() {
  // Lê a tensão do sensor de temperatura e converte para Celsius
  int leitura = analogRead(sensorTemperaturaPin);
  float tensao = leitura * 5.0 / 1023.0;
  float temperaturaCelsius = (tensao - 0.5) * 100.0;
  
  return temperaturaCelsius;
}