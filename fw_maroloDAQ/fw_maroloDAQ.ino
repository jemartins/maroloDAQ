/*
 * Defines
 */
#define LED_ONBOARD 13
#define FW_VERSION "projMarolo v0.1"

/*
 * Globais
 */
unsigned char FLAG_CONTROL_RX_UART_DATA = 0; 
const unsigned int SIZE_BUF_RX = 10;

/* 
 * constante para configuração do prescaler
 */
const unsigned char PS_16 = (1 << ADPS2);
const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
const unsigned char PS_64 = (1 << ADPS2) | (1 << ADPS1);
const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

/* 
 * Estruturas
 */
typedef enum States{
  NONE=10,      //10
  CALL_LED,     //11
  CALL_INFO,    //12
  CALL_VERSION, //13
  CALL_GETA0,   //14
  CALL_GETA1,   //15
  CALL_GETA2,   //16
  CALL_GETA3,   //17
  CALL_GETA4,   //18
  CALL_GETA5    //19
};

/*
 * Prototipos das funcoes
 */
void ProcToggleLed(int);
void ProcInfo();
void ProcVersion();
void ProcGetA0();
void ProcGetA1();
void ProcGetA2();
void ProcGetA3();
void ProcGetA4();
void ProcGetA5();
void ProcStatesUARTRx(char *buffRx);
void CheckUARTRx(char *buffRx);


/*
 * Funcoes
 */
void ProcInfo()
{ 
  
  /* Retorna o versao do GCC utilizado para compilar */
  Serial.write(__VERSION__);
  Serial.write('|');
  
  /* Retorna o Modelo do Arduino */
  #if defined(__AVR_ATmega168__)
    //Serial.write("DIECIMILA");
    Serial.write("maroloDAQ");
  #endif 
  #if defined(__AVR_ATmega328P__)
    //Serial.write("UNO");
    Serial.write("maroloDAQ");
  #endif
  #if defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__)
    //Serial.write("MEGA");
    Serial.write("maroloDAQ");
  #endif
  #if defined(__AVR_ATmega32U4__)
    //Serial.write("LEONARDO");
    Serial.write("maroloDAQ");
  #endif
  #if defined(__SAM3X8E__)
    //Serial.write("DUE");
    Serial.write("maroloDAQ");
  #endif
  
  Serial.flush();
}


void ProcVersion()
{
  /* Retorna a versao atual deste Firmware */
  Serial.write(FW_VERSION);  
  Serial.flush();
}


void ProcToggleLed(int)
{
  /* Pegando o status atual do Led (Pino 13) */
  volatile int led_status = digitalRead(LED_ONBOARD);
  
  /* Enviando o outro estado para o Pino */
  digitalWrite(LED_ONBOARD, !led_status);
  
  /* Enviando na serial se o Led esta aceso ou apagado */
  if(!led_status) { Serial.write("ON"); }
  else { Serial.write("OFF"); }
  
  Serial.flush();
}

void ProcGetA0()
{
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  
  /* Convertendo inteiro (int) em character (string) */
  char sensorValueChar[20];
  int len = 0;
  for(; sensorValue > 0; ++len)
  {
    sensorValueChar[len] = sensorValue%10+'0';
    sensorValue/=10;
  }
  sensorValueChar[len] = 0; //null-terminating

  //now we need to reverse res
  for(int i = 0; i < len/2; ++i)
  {
      char c = sensorValueChar[i]; sensorValueChar[i] = sensorValueChar[len-i-1]; sensorValueChar[len-i-1] = c;
  } 
  
  /* Retorna Leitura no pino A0 */
  Serial.write(sensorValueChar);
  //Serial.flush();

  // delay 10ms to let the ADC recover
  //delay(10);
}

void ProcGetA1()
{
  // read the input on analog pin 1:
  int sensorValue = analogRead(A1);
  
  /* Convertendo inteiro (int) em character (string) */
  char sensorValueChar[20];
  int len = 0;
  for(; sensorValue > 0; ++len)
  {
    sensorValueChar[len] = sensorValue%10+'0';
    sensorValue/=10;
  }
  sensorValueChar[len] = 0; //null-terminating

  //now we need to reverse res
  for(int i = 0; i < len/2; ++i)
  {
      char c = sensorValueChar[i]; sensorValueChar[i] = sensorValueChar[len-i-1]; sensorValueChar[len-i-1] = c;
  } 
  
  /* Retorna Leitura no pino A1 */
  Serial.write(sensorValueChar);
  //Serial.flush();

  // delay 10ms to let the ADC recover
  //delay(10);
}

void ProcGetA2()
{
  // read the input on analog pin 2:
  int sensorValue = analogRead(A2);
  
  /* Convertendo inteiro (int) em character (string) */
  char sensorValueChar[20];
  int len = 0;
  for(; sensorValue > 0; ++len)
  {
    sensorValueChar[len] = sensorValue%10+'0';
    sensorValue/=10;
  }
  sensorValueChar[len] = 0; //null-terminating

  //now we need to reverse res
  for(int i = 0; i < len/2; ++i)
  {
      char c = sensorValueChar[i]; sensorValueChar[i] = sensorValueChar[len-i-1]; sensorValueChar[len-i-1] = c;
  } 
  
  /* Retorna Leitura no pino A2 */
  Serial.write(sensorValueChar);
  //Serial.flush();

  // delay 10ms to let the ADC recover
  //delay(10);
}

void ProcGetA3()
{
  // read the input on analog pin 3:
  int sensorValue = analogRead(A3);
  
  /* Convertendo inteiro (int) em character (string) */
  char sensorValueChar[20];
  int len = 0;
  for(; sensorValue > 0; ++len)
  {
    sensorValueChar[len] = sensorValue%10+'0';
    sensorValue/=10;
  }
  sensorValueChar[len] = 0; //null-terminating

  //now we need to reverse res
  for(int i = 0; i < len/2; ++i)
  {
      char c = sensorValueChar[i]; sensorValueChar[i] = sensorValueChar[len-i-1]; sensorValueChar[len-i-1] = c;
  } 
  
  /* Retorna Leitura no pino A3 */
  Serial.write(sensorValueChar);
  //Serial.flush();

  // delay 10ms to let the ADC recover
  //delay(10);
}

void ProcGetA4()
{
  // read the input on analog pin 4:
  int sensorValue = analogRead(A4);
  
  /* Convertendo inteiro (int) em character (string) */
  char sensorValueChar[20];
  int len = 0;
  for(; sensorValue > 0; ++len)
  {
    sensorValueChar[len] = sensorValue%10+'0';
    sensorValue/=10;
  }
  sensorValueChar[len] = 0; //null-terminating

  //now we need to reverse res
  for(int i = 0; i < len/2; ++i)
  {
      char c = sensorValueChar[i]; sensorValueChar[i] = sensorValueChar[len-i-1]; sensorValueChar[len-i-1] = c;
  } 
  
  /* Retorna Leitura no pino A4 */
  Serial.write(sensorValueChar);
  //Serial.flush();

  // delay 10ms to let the ADC recover
  //delay(10);
}

void ProcGetA5()
{
  // read the input on analog pin 5:
  int sensorValue = analogRead(A5);
  
  /* Convertendo inteiro (int) em character (string) */
  char sensorValueChar[20];
  int len = 0;
  for(; sensorValue > 0; ++len)
  {
    sensorValueChar[len] = sensorValue%10+'0';
    sensorValue/=10;
  }
  sensorValueChar[len] = 0; //null-terminating

  //now we need to reverse res
  for(int i = 0; i < len/2; ++i)
  {
      char c = sensorValueChar[i]; sensorValueChar[i] = sensorValueChar[len-i-1]; sensorValueChar[len-i-1] = c;
  } 
  
  /* Retorna Leitura no pino A5 */
  Serial.write(sensorValueChar);
  //Serial.flush();

  // delay 10ms to let the ADC recover
  //delay(10);
}

void ProcStatesUARTRx(char *buffRx)
{
  /* Flag para sinalizar quando tem dados no Buffer RX */
    if(FLAG_CONTROL_RX_UART_DATA) {
      
      /* Ira continuar apenas se o primeiro caractere
        for 1 sendo do range do nosso States
        */
        if (buffRx[0] != '1') return;
    
    /* 
       Neste caso me interessa apenas o segundo 
       caractere do Buffer, ele seria o ID para 
       meus States
    */

    int state=int{buffRx[1]}-38;
    
    //switch(buffRx[1]) {
    switch(state) {
      case NONE:
        break;
      case CALL_LED:
        ProcToggleLed(LED_ONBOARD);
        break;
      case CALL_INFO:
        ProcInfo();
        break;
      case CALL_VERSION:
        ProcVersion();
        break;
      case CALL_GETA0:
        ProcGetA0();
        break;
      case CALL_GETA1:
        ProcGetA1();
        break;
      case CALL_GETA2:
        ProcGetA2();
        break;
      case CALL_GETA3:
        ProcGetA3();
        break;
      case CALL_GETA4:
        ProcGetA4();
        break;
      case CALL_GETA5:
        ProcGetA5();
        break;
      default:
        break;
    }
    FLAG_CONTROL_RX_UART_DATA=0;
  }  
}


void CheckUARTRx(char *buffRx)
{
  static unsigned int pos_buf_rx = 0;
  /* Caso tenha algo na serial, ira tratar e/ou guardar no buffer */
  if( Serial.available()>0 ) {
    const byte RxDataUart = Serial.read();

    switch (RxDataUart) {
      case '\n':
        /* Inseri terminador no final do buffer */
        buffRx[pos_buf_rx] = 0;
      
        /* Sinaliza que o Buffer esta pronto */
        FLAG_CONTROL_RX_UART_DATA=1;
      
        /* Reseta o valor de indice para o Buffer de Recepção */
        pos_buf_rx = 0;  
        break;
      case '\r':
        /* Ignora Carriage Return ou pode colocar junto ao /n */
        break;
      default:
        /* Inseri no buffer se ainda nao encher */
        if (pos_buf_rx < (SIZE_BUF_RX - 1))
          buffRx[pos_buf_rx++] = RxDataUart;
        break;
      }
      
      Serial.flush();
  }
}


/* Inicializando e configurando os perifericos usados */
void setup() {
    
    /* Inicialização Serial 9600 bps */
    //Serial.begin(9600,SERIAL_8N1);
    /* Inicialização Serial 19200 bps */
    //Serial.begin(19200,SERIAL_8N1);
    Serial.begin(9600);
    
    // configura o preescaler do ADC
    ADCSRA &= ~PS_128;  //limpa configuração da biblioteca do arduino
    
    // valores possiveis de prescaler só deixar a linha com prescaler desejado
    // PS_16, PS_32, PS_64 or PS_128
    //ADCSRA |= PS_128; // 64 prescaler
    ADCSRA |= PS_64; // 64 prescaler
    //  ADCSRA |= PS_32; // 32 prescaler
    // ADCSRA |= PS_16; // 16 prescaler
    
    /* Inicialização do Led OUTPUT */
    pinMode(LED_ONBOARD, OUTPUT);
}


/* Loop Principal Infinito */
void loop() {
  
  /* Buffer para recepção dos dados vindos da Serial */
  static char RxBuffer[SIZE_BUF_RX];
    
  /*
    Rotina para verificar se tem algo para receber na serial
    e como parametro envia o buffer para RX
   */
  CheckUARTRx(RxBuffer);
    
  /*
    Rotina para processar o que chegou pela serial
   */

  ProcStatesUARTRx(RxBuffer);

}
