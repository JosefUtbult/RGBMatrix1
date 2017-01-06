#include <Arduino.h>

#include "LedWriter.h"
#include "Const.h"

int matrix[MATRIXSIZE * MATRIXSIZE] = {
  0, 10, 0,
  0, 50, 0,
  0, 100, 0
};

void writeLed(int* matrix);

void setup() {

  for(int i = 0; i < OUTPUTLENGTH; i ++){
    pinMode(OUTPUTPIN[i], OUTPUT);
    pinMode(INPUTPIN[i], OUTPUT);
  }

  for(int i = 0; i < INPUTLENGTH; i ++){
    digitalWrite(INPUTPIN[i], HIGH);
  }

}

void loop() {
  /*for(int e = 0; e < INPUTLENGTH; e ++){
    digitalWrite(INPUTPIN[e], LOW);
    for(int i = 0; i < OUTPUTLENGTH; i ++){
      digitalWrite(OUTPUTPIN[i], HIGH);
      delay(1000);
      digitalWrite(OUTPUTPIN[i], LOW);
    }
    digitalWrite(INPUTPIN[e], HIGH);
  } */

  writeLed(matrix);

}

void writeLed(int* currentMatrix){
  //Writing to all led rows
  for(int posY = 0; posY < OUTPUTLENGTH; posY ++){
    digitalWrite(OUTPUTPIN[posY], HIGH);

    //SETUP - Turning on all leds for this row. (letting the light through)
    for(int i = 0; i < INPUTLENGTH; i ++){
      if(currentMatrix[posY * MATRIXSIZE + i] > 0){
        digitalWrite(INPUTPIN[i], LOW);
      }
    }

    //Writing to all leds in a column
    for(int i = 0; i <= 100; i ++){
      for(int posX = 0; posX < MATRIXSIZE; posX ++){

        //If the time stated in the matrix is exceeded by value i, then turn off that led.
        if(i > currentMatrix[posY * MATRIXSIZE + posX]){
          digitalWrite(INPUTPIN[posX], HIGH);
        }

      }

      delayMicroseconds(1);
    }

    for(int e = 0; e < INPUTLENGTH; e ++){
      digitalWrite(INPUTPIN[e], HIGH);
    }

    digitalWrite(OUTPUTPIN[posY], LOW);
  }
}
