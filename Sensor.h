#ifndef OBMT_Sensor
#define OBMT_Sensor

#include "arduino.h"

class Sensor
{
public:
    enum Type { ACTIVE_HIGH, ACTIVE_LOW};
        
protected:
    int     m_id;
    int     m_pin;
    Type    m_type;
    byte    m_wert;
    byte    m_wert_test;
    unsigned long   
            m_wert_test_millis;

    bool    m_triggered;
    void    (*m_triggerFunction)(Sensor*);
       
public:
    Sensor(int id);
    Sensor(int id, int pin, Type type);

    int id() const { return m_id; }

    bool aktiv();
    bool inaktiv();

    void tick();
    void attachTrigger(void (*func)(Sensor*));


    byte wert();
    
    // I2C    
    void wert(byte w);


};

#endif
