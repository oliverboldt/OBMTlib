#include "Sensor.h"
#include "Arduino.h"

Sensor::Sensor(int id)
: m_id(id)
, m_pin(-1)
, m_type (ACTIVE_HIGH)
, m_wert(-1)
, m_wert_test(-1)
, m_wert_test_millis(0)
, m_triggered(false)
, m_triggerFunction(NULL)
{
    
}

Sensor::Sensor(int id, int pin, Type type)
: m_id(id)
, m_pin(pin)
, m_type(type)
, m_wert(0)
, m_wert_test(-1)
, m_wert_test_millis(0)
, m_triggered(false)
, m_triggerFunction(NULL)
{
    if (pin >= 0)
        pinMode(pin,INPUT);
}

bool Sensor::aktiv()
{
    return this->wert() != 0;
}

bool Sensor::inaktiv()
{
    return ! this->aktiv();
}


byte Sensor::wert()
{
    if (m_pin >= 0)
    {
        byte            wert_aktuell = m_type == ACTIVE_HIGH ? digitalRead(m_pin) : ! digitalRead(m_pin); 
        unsigned long   wert_aktuell_millis = millis();

        if (wert_aktuell != m_wert_test)
        {
            // aktuellen Zustand merken
             m_wert_test = wert_aktuell;
             m_wert_test_millis = wert_aktuell_millis;            
        }
        else
        {
            // Selber Wert wie vor 120ms ?
            //       
            if (wert_aktuell_millis > (m_wert_test_millis+120)
            /*&&  wert_aktuell == m_wert_test*/)
            {
                m_wert = wert_aktuell;
                m_triggered = true;    
             }   
        }   
    }

    return m_wert;
}

// I2C
void Sensor::wert(byte w)
{
    m_triggered =  m_wert != w;
    m_wert = w;
}

void Sensor::tick()
{
    if (m_triggered)
    {
        if (m_triggerFunction != NULL)
            m_triggerFunction(this);
            
        m_triggered = false;
    }
}
void Sensor::attachTrigger(void (*func)(Sensor*))
{
    m_triggerFunction = func;
}
