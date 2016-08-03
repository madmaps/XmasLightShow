// Christmas Shift Register Sketch
// Matt Applin

const byte MODID = 0x12;
//Connect pin 5(Ard) to pin 12(74HC595 - STCP) 
const byte ST_REG_PIN_CLK = 5;

//Connect pin 6(Ard) to pin 11(74HC959 - SHCP)
const byte SHFT_REG_CLK_INP = 6;

//Connect pin 7(Ard) to pin 14(74HC959 - DS)
const byte SRL_DTA_INP = 7;

char data[256];
int incomingByte=0;
int i=0;
int j=0;
int numberOfMods=0;
int byteCounter=0;



void setup()
{
  Serial.begin(9600);
   pinMode(ST_REG_PIN_CLK, OUTPUT);
   pinMode(SHFT_REG_CLK_INP, OUTPUT);
   pinMode(SRL_DTA_INP, OUTPUT); 
}

void loop()
{
  
  if(Serial.available() >0)
  {
    byteCounter=0;
    i=0;
    while(Serial.available())
    {
      data[i]=Serial.read();
      delay(2);
      i++;
    }
    numberOfMods = (int)data[0];
    byteCounter++;
    j=0;
    while(j<numberOfMods)
    {
      incomingByte = (int)data[byteCounter+1];
      if(MODID==data[byteCounter])
      {
        digitalWrite(ST_REG_PIN_CLK,LOW);
        i=0;
        while(i<incomingByte)
        {
          shiftOut(SRL_DTA_INP,SHFT_REG_CLK_INP,0,data[byteCounter+2]);
          byteCounter++;
          i++;
        }
        digitalWrite(ST_REG_PIN_CLK,HIGH);
      }
      else
      {
        byteCounter+=incomingByte+2;
      }
      j++;
    }
  }
}




