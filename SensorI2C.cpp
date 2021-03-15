#include "SensorI2C.h"
#include "Arduino.h"

SensorI2C::SensorI2C(int id)
: m_id(id)
, m_wert(-1)
, m_triggered(false)
, m_triggerFunction(NULL)
{
    
}


bool SensorI2C::aktiv()
{
    return this->wert() != 0;
}

bool SensorI2C::inaktiv()
{
    return ! this->aktiv();
}


byte SensorI2C::wert()
{
    return m_wert;
}

// I2C
void SensorI2C::wert(byte w)
{
    m_triggered =  m_wert != w;
    m_wert = w;
}

void SensorI2C::tick()
{
    if (m_triggered)
    {
        if (m_triggerFunction != NULL)
            m_triggerFunction(this);
            
        m_triggered = false;
    }
}
void SensorI2C::attachTrigger(void (*func)(SensorI2C*))
{
    m_triggerFunction = func;
}
