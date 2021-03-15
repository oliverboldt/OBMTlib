#ifndef OBMT_SensorLokal
#define OBMT_SensorLokal

#include "Pin.h"
#include "arduino.h"

class SensorLokal
{
public:
    enum Type { ACTIVE_HIGH, ACTIVE_LOW /* todo ANALOG */ };
        
protected:
    int     m_id;
 	Pin* 	m_pin;
    Type    m_type;
    byte    m_wert;
/*    unsigned long m_timeUp;
    unsigned long m_timeDown;
    unsigned long m_timeUpLength;*/

    bool    m_triggered;
    void    (*m_triggerFunction)(SensorLokal*);
       
public:
    SensorLokal(int id, int pin, Type type);
	SensorLokal(int id, Pin& pin, Type type);

    int id() const { return m_id; }

    bool aktiv();
    bool inaktiv();

    void tick();
    void attachTrigger(void (*func)(SensorLokal*));

    byte wert();
    byte wertGlatt();
};

#endif
