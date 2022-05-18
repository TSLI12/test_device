
//               'get id': '@0001AA\r\n',
//               'get temperature': '@0001BB\r\n',
//               'get random number': '@0001CC\r\n',
//               'start sequence': '@0001DD\r\n'}
    

char incomingChar[9];
char formattedString[8];
char prefix[5]={'@','0','0','0','1'};

void setup() {
  // start serial port at 115200 bps and wait for port to open:
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  if (Serial.available() > 0) {
    delay(500); // reading time
    for(int i=0; i<9;incomingChar[i++]=Serial.read()){} // get incoming char:

    if (compareTab(incomingChar,prefix)){
      if (incomingChar[5]=='A' && incomingChar[6]=='A'){
        //Serial.println("get id");
        sprintf(formattedString, "@0001%08X",random());
        Serial.println(formattedString);
        }
      else if (incomingChar[5]=='B' && incomingChar[6]=='B'){
        //Serial.println("get temperature");
        sprintf(formattedString, "@0001%d",random(50));
        Serial.println(formattedString);
        }
      else if (incomingChar[5]=='C' && incomingChar[6]=='C'){
        //Serial.println("get random number");
        sprintf(formattedString, "@0001%04d",random());
        Serial.println(formattedString);
        }
      else if (incomingChar[5]=='D' && incomingChar[6]=='D'){
        //Serial.println("start sequence");
        Serial.println("OK");
        sequence(100);
        }
      }
    else{
    Serial.println("Error");
    }
  }
}
  
bool compareTab(char *tab1, char *tab2){
  for(int i = 0; i<sizeof(tab2);i++){
    if (tab1[i]!=tab2[i]){
      return false;
      }
    }
  return true;
  }

void sequence(int timer){
  for(int i = 0; i<20;i++){
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(timer);                       // wait for a second
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      delay(timer);                       // wait for a second
      }
  }
