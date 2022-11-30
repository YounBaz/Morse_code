#ifndef Morsecode_h
#define Morsecode_h
class morsecode
{
private:
    unsigned long currenttime;
    int _pin;

    
public:
    morsecode(int pin);
    morsecode();
    ~morsecode();
    void dot();
    void dash();
    void space();    // it's the space between two letter
    void bigspace(); // it's the space between two words
};


#endif