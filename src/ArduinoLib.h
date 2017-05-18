#ifndef ARDUINOLIB_H
#define ARDUINOLIB_H

#include <Arduino.h>

class Pin{
    private:
    
    Pin(){}
    
    int pin;
    int mode;
    
    public:
    
    Pin(int pin){
        this->pin=pin;
        setMode(INPUT);
    }
    
    Pin(int pin,int mode){
        this->pin=pin;
        setMode(mode);
    }
    
    int getPin(){
        return this->pin;
    }
    
    void setMode(int mode){
        this->mode=mode;
        pinMode(this->pin,mode);
    }
    
    int getAnalog(){
        return analogRead(this->pin);
    }
    
    void setAnalog(int value){
        analogWrite(this->pin,value);
    }
    
    int getDigital(){
        return digitalRead(this->pin,value);
    }
    
    void setDigital(int value){
        digitalWrite(this->pin,value);
    }
    
    void setHigh(){
        digitalWrite(this->pin,HIGH);
    }
    
    void setLow(){
        digitalWrite(this->pin,LOW);
    }
    
    bool isHigh(){
        return digitalRead(this->pin)==HIGH;
    }
    
    bool isLow(){
        return digitalRead(this->pin)==LOW;
    }
    
    void waitTillHigh(){
        while(isLow());
    }
    
    void waitTillLow(){
        while(isHigh());
    }
};

#define MOTOR_FORWARD 0X01
#define MOTOR_BACKWARD 0X00

class Motor{
    private:
    
    Motor(){}
    
    Pin directionPin;
    Pin speedPin;
    
    public:
    
    Motor(int directionPin,int speedPin){
        this->directionPin=Pin(directionPin,OUTPUT);
        this->speedPin=Pin(speedPin,OUTPUT);
    }
    
    void setDirection(int direction){
        directionPin.setDigital(direction);
    }
    
    void setSpeed(int speed){
        speedPin.setAnalog(speed);
    }
    
    void stop(){
        setSpeed(0);
    }
};
#endif
