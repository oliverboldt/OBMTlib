#include "WeicheLokal2Pin.h"
#include "Arduino.h"

WeicheLokal2Pin::WeicheLokal2Pin(int id, WeichenStellung stellung, int geradePin, int abbiegenPin, int impulsLange, bool async)
: Weiche(id,stellung)
{
     m_geradePin = geradePin;
     m_abbiegenPin = abbiegenPin;
     m_ImpulsLange  = impulsLange;
     m_async = async;
     m_dirty = false;

     pinMode(m_geradePin,OUTPUT);
     pinMode(m_abbiegenPin,OUTPUT);
     // this->stellen(stellung); zu früh !
}


void WeicheLokal2Pin::stellen(WeichenStellung stellung)
{
    if (stellung != m_stellung || m_initial)
    {
        int pin = stellung == WEICHE_GERADE ? m_geradePin : m_abbiegenPin;

        if (m_async)
        {
            m_dirty = true;
        }
        else
        {
            digitalWrite(pin, HIGH);
            delay(m_ImpulsLange);
            digitalWrite(pin, LOW);
        }
        
        m_stellung = stellung;
        m_initial = false;
    }
}

void WeicheLokal2Pin::tick()
{
    if (m_dirty)
    {
        int pin = m_stellung == WEICHE_GERADE ? m_geradePin : m_abbiegenPin;
        
        digitalWrite(pin, HIGH);
        delay(m_ImpulsLange);
        digitalWrite(pin, LOW);    

        m_dirty = false;
    }
}
