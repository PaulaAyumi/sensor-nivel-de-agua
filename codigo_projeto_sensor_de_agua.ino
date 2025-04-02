#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Configuração da rede WiFi
const char* ssid = "DECO-M5-1";     // Nome da rede WiFi
const char* password = "L2u0I2z3A"; // Senha da rede WiFi

// Configuração do MQTT
const char* mqttServer = "broker.mqtt-dashboard.com"; 
const int mqttPort = 1883;
const char* mqttTopic = "sensor/nivel-agua";

WiFiClient espClient;
PubSubClient client(espClient);

// Definição dos pinos
#define SENSOR_AGUA A0
#define LED_VERMELHO D1 
#define LED_AMARELO D2   
#define LED_VERDE D3     
#define BUZZER D4       

void setup() {
  Serial.begin(74880); // 
  
  // Configuração dos pinos
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(SENSOR_AGUA, INPUT);

  // Conectar ao WiFi
  conectarWiFi();

  // Configuração do MQTT
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback); 
}

void callback(char* topic, byte* payload, unsigned int length) {
    Serial.print("Mensagem recebida no tópico: ");
    Serial.println(topic);

    String msg = "";
    for (int i = 0; i < length; i++) {
        msg += (char)payload[i];
    }
    Serial.println("Conteúdo: " + msg);
}

void loop() {
  if (!client.connected()) {
    reconectarMQTT();
  }
  client.loop();

  // Leitura do sensor de água (0 - 1023)
  int nivelAgua = analogRead(SENSOR_AGUA);
  Serial.print("Nível da água: ");
  Serial.println(nivelAgua);

  // Lógica para acionamento dos LEDs e buzzer
  if (nivelAgua < 400) {
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(BUZZER, LOW);
    client.publish(mqttTopic, "Nivel Baixo");
  } 
  else if (nivelAgua >= 400 && nivelAgua < 640) {
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(BUZZER, LOW);
    client.publish(mqttTopic, "Nivel Medio");
  } 
  else {
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(BUZZER, HIGH);
    client.publish(mqttTopic, "Nivel Alto");
    delay(500);
    digitalWrite(BUZZER, LOW);
  }

  delay(2000);
}

// Função para conectar ao WiFi
void conectarWiFi() {
  Serial.print("Conectando ao WiFi...");
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("Conectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

// Função para reconectar ao MQTT caso desconecte
void reconectarMQTT() {
  while (!client.connected()) {
    Serial.print("Tentando conexão MQTT...");
    
    String clientId = "NodeMCUClient-";
    clientId += String(random(0xffff), HEX); 

    if (client.connect(clientId.c_str())) {
      Serial.println("Conectado ao MQTT!");
      client.subscribe("sensor/nivel-agua"); 
    } else {
      Serial.print("Falha, erro: ");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5s...");
      delay(5000);
    }
  }
}

