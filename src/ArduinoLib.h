#ifndef ARDUINOLIB_H
#define ARDUINOLIB_H

#define AL_HIGH 32767
#define AL_LOW -32768


#define AL_ANALOG_MIN 0
#define AL_ANALOG_MAX 255

class Pin{
    private:
    
    Pin(){}
    
    int pin;
    
    public:
    
    Pin(int pin){
        this->pin=pin;
    }
    
    int read(){
        
    }
    
    void write(int value){
        if(value==AL_HIGH)
            digitalWrite(this->pin,HIGH);
        else if(value==AL_LOW)
            digitalWrite(this->pin,LOW);
        else
            analogWrite(this->pin,value);
    }
}
#endif
