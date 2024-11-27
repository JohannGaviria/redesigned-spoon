// Definir los pines del sensor y los LEDs
const int sensorIRPin = A0;
const int ledVerdePin = 9;
const int ledRojoPin = 10;

void setup() {
  // Configurar los pines como salidas
  pinMode(ledVerdePin, OUTPUT);
  pinMode(ledRojoPin, OUTPUT);
  Serial.begin(9600);  // Inicializar la comunicación serie para monitorear el valor del sensor
}

void loop() {
  // Leer el valor del sensor IR (0-1023)
  int sensorValue = analogRead(sensorIRPin);

  // Mapear el valor del sensor a un rango de PWM (0-255)
  int pwmValue = map(sensorValue, 0, 1023, 0, 255);

  // Ajustar la intensidad de los LEDs
  analogWrite(ledVerdePin, 255 - pwmValue);  // LED verde es inversamente proporcional a la distancia
  analogWrite(ledRojoPin, pwmValue);         // LED rojo es proporcional a la distancia

  // Mostrar el valor del sensor y el valor PWM en el monitor serie
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print("  PWM Value: ");
  Serial.println(pwmValue);

  delay(100);  // Pequeño retraso para estabilizar la lectura del sensor
}
