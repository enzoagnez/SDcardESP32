#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

const int chipSelect = 5; // Ajuste conforme o pino CS usado

void setup() {
  Serial.begin(115200);


  Serial.println("Inicializando o cartão SD...");
  if (!SD.begin(chipSelect)) {
    Serial.println("Erro ao inicializar o cartão SD.");
    while (1); // Para o programa aqui se o cartão não puder ser inicializado
  }
  Serial.println("Cartão SD inicializado com sucesso.");

  // Cria um arquivo e escreve dados
  File file = SD.open("/exemplo.txt", FILE_WRITE);
  if (file) {
    file.println("Olá, microSD!");
    file.close();
    Serial.println("Dados escritos com sucesso.");
  } else {
    Serial.println("Erro ao abrir o arquivo para escrita.");
  }

  // Lê o arquivo
  file = SD.open("/exemplo.txt");
  if (file) {
    Serial.println("Conteúdo do arquivo:");
    while (file.available()) {
      Serial.write(file.read());
    }
    file.close();
  } else {
    Serial.println("Erro ao abrir o arquivo para leitura.");
  }
}

void loop() {
  // O loop fica vazio para este exemplo
}