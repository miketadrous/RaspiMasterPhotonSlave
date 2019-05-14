#include <Wire.h>

#define SLAVE_ADDRESS 0x05
int number = 0;
int myData [8];

int Slot1State=0;
int Slot2State=0;
int Slot3State=0;
int Slot4State=0;
int Slot5State=0;
int ParkedCars=0;
int Slots=5;
int Available=Slots-ParkedCars;

void setup() {
// initialize i2c as slave
Wire.begin(SLAVE_ADDRESS);

// define callbacks for i2c communication
Wire.onReceive(receiveData);
Wire.onRequest(sendData);

}

void loop() {
  delay(100);
    convertData();
    delay(100);
    PublishData1();
    delay(10000);

}

// callback for received data
void receiveData(int byteCount){

    while(Wire.available()) {
        for(int i=0;i<byteCount;i++){          
          number = Wire.read();
          myData[i] = int(number);
             
        }
    }

}

// callback for sending data
void sendData(){
  Wire.write(myData[0]);
}

void convertData(){
    Slot1State=myData[1];
    Slot2State=myData[2];
    Slot3State=myData[3];
    Slot4State=myData[4];
    Slot5State=myData[5];
    ParkedCars=myData[1]+myData[2]+myData[3]+myData[4]+myData[5];
    Slots=5;
    Available=Slots-ParkedCars;
        }
        
        
void PublishData1(){  
        Particle.publish("Slot1State", String(Slot1State), PRIVATE);
        delay(1000);
        Particle.publish("Slot2State", String(Slot2State), PRIVATE);
        delay(1000);
        Particle.publish("Slot3State", String(Slot3State), PRIVATE);
        delay(1000);
        Particle.publish("Slot4State", String(Slot4State), PRIVATE);
        delay(1000);
        Particle.publish("Slot5State", String(Slot5State), PRIVATE);
        delay(1000);
        Particle.publish("ParkedCars", String(ParkedCars), PRIVATE);
        delay(1000);
        Particle.publish("Slots", String(Slots), PRIVATE);
        delay(1000);
        Particle.publish("Available", String(Available), PRIVATE);
        delay(1000);

}
