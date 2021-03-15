#include "RelaisLokal.h"
#include "Arduino.h"

RelaisLokal::RelaisLokal(int id, int pin, Active active, bool geteilt)
: Relais(id)
, m_pin(pin)
, m_active(active)
, m_geteilt(geteilt)
{
    m_ImpulsBeiTick = false;
    m_ImpulsLange = 250;
    
    pinMode(m_pin, OUTPUT);
}

void RelaisLokal::tick()
{
    if (m_ImpulsBeiTick)
    {
        this->setzen(true);
        delay(m_ImpulsLange);
        this->setzen(false);
        delay(m_ImpulsLange); // Test wegen Weichenproblemen
        m_ImpulsBeiTick = false;
    }
}

void RelaisLokal::setzen(bool an)
{
	m_on = an;

    if (m_active == ACTIVE_HIGH)
        digitalWrite(m_pin, an ? HIGH : LOW);
    else
        digitalWrite(m_pin, an ? LOW : HIGH);
	
}

void RelaisLokal::schickeImpuls(int millisec)
{
    if (m_geteilt)
    {
        m_ImpulsBeiTick = true;
        m_ImpulsLange = millisec;
    }
    else
    {
        this->setzen(true);
        delay(millisec);
        this->setzen(false);
    }
}
