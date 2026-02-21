int buttonPin = 7; //variável da porta do botao
int ledPins[] = {8,9,10,11}; // variável da porta dos led
int totalLeds = 4; // variável quantidade de leds
int estadoButton = 0; // variável do estado do botao 0 e 1
int ultimoEstado = 0; // armazena o último estado do botão
int ledAtual = 0; // posição do led atual
void setup() {
  pinMode(buttonPin,INPUT); // setando botao como entrada
  for(int pos;pos<totalLeds;pos++){
    pinMode(ledPins[pos],OUTPUT); // led é uma saída de energia
    digitalWrite(ledPins[pos],LOW);
  }
}
void loop() {
  estadoButton = digitalRead(buttonPin);

  if(estadoButton == HIGH && ultimoEstado == LOW){
    for(int pos=0;pos<totalLeds;pos++){
      digitalWrite(ledPins[pos],LOW);
    }
    digitalWrite(ledPins[ledAtual],HIGH);
    ledAtual= ledAtual+1;
    if(ledAtual>=totalLeds){
      ledAtual = 0;
    }
    delay(400);
  }
  ultimoEstado = estadoButton;
}
