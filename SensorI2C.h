#ifndef OBMT_Sensor
#define OBMT_Sensor

#include "arduino.h"

class SensorI2C
{        
protected:
    int     m_id;
    byte    m_wert;
    bool    m_triggered;
    void    (*m_triggerFunction)(SensorI2C*);
       
public:
    SensorI2C(int id);

    int id() const { return m_id; }

    bool aktiv();
    bool inaktiv();

    void tick();
    void attachTrigger(void (*func)(SensorI2C*));


    byte wert();
    
    // I2C    
    void wert(byte w);
};

#endif
