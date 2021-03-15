#include "SensorLokal.h"
#include "Arduino.h"


SensorLokal::SensorLokal(int id, int pin, Type type)
: m_id(id)
, m_pin(new Pin(pin,INPUT))
, m_type(type)
, m_wert(0)
/*, m_timeUp(0)
, m_timeDown(0)
, m_timeUpLength(0)*/
, m_triggered(false)
, m_triggerFunction(NULL)
{
    if (pin >= 0)
        pinMode(pin,INPUT);

    m_wert = this->wert();
	
}

SensorLokal::SensorLokal(int id, Pin& pin, Type type)
: m_id(id)
, m_pin(&pin)
, m_type(type)
, m_wert(0)
/*, m_timeUp(0)
, m_timeDown(0)
, m_timeUpLength(0)*/
, m_triggered(false)
, m_triggerFunction(NULL)
{
    m_wert = this->wert();
	
}


bool SensorLokal::aktiv()
{
    return this->wert() != 0;
}

bool SensorLokal::inaktiv()
{
    return ! this->aktiv();
}


byte SensorLokal::wert()
{
    byte neu = (m_type == ACTIVE_HIGH) ? m_pin->digitalRead() : ! m_pin->digitalRead();

    m_triggered = neu != m_wert;
    m_wert = neu;
    return m_wert;
}

byte SensorLokal::wertGlatt()
{
    return m_wert;
}

void SensorLokal::tick()
{
    this->wert(); // !!

	if (m_triggered)
    {
        if (m_triggerFunction != NULL)
            m_triggerFunction(this);
            
        m_triggered = false;
    }
}

/*
void SensorLokal::tick()
{
    byte neu = (m_type == ACTIVE_HIGH) ? m_pin->digitalRead() : ! m_pin->digitalRead();

    // 0 -> 1 Transition
    //
    if (m_wert == 0 && neu == 1)
    {
        if (m_timeUp == 0)
        {
            m_wert = neu;
            m_triggered = true;
            m_timeUp = millis();
        }
    }
    // 1 -> 0 Transition
    //
    else if (m_wert == 1 && neu == 0)
    {
        if (m_timeUp > 0)
        {
            unsigned long length = millis() - m_timeUp;
    
            if (length > m_timeUpLength)
                m_timeUpLength = min(500,length);
    
            m_timeDown = millis();
        }
        else
        {
            // Sollte nicht passieren...
            //
            m_wert = neu; // 0
            m_triggered = true;          
        }
    }
    // 0 -> 0 
    //
    else if (m_wert == 0 && neu == 0)
    {
        if ((m_timeDown + m_timeUpLength) > millis())
        {
            m_wert = neu; // 0
            m_triggered = true;
            m_timeUp = 0; // reset
        }
    }
    
    
    if (m_triggered)
    {
        if (m_triggerFunction != NULL)
            m_triggerFunction(this);
            
        m_triggered = false;
    }
}
*/

void SensorLokal::attachTrigger(void (*func)(SensorLokal*))
{
    m_triggerFunction = func;
}
