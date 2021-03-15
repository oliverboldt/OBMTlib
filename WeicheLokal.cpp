#include "WeicheLokal.h"
#include "Arduino.h"

WeicheLokal::WeicheLokal(int id, WeichenStellung stellung, RelaisLokal& impulsRelais, int impulsLange, int stellungPin)
: Weiche(id,stellung)
, m_ImpulsRelais(impulsRelais)
, m_StellungsRelais(0,stellungPin,RelaisLokal::ACTIVE_LOW,false)
{
     m_stellung     = stellung;
     m_ImpulsLange  = impulsLange;
     // this->stellen(stellung); zu früh !
}


void WeicheLokal::stellen(WeichenStellung stellung)
{
    if (stellung != m_stellung || m_initial)
    {
        // Weiche stellen
        //
        m_StellungsRelais.setzen(stellung == WEICHE_ABBIEGEN);
        m_ImpulsRelais.schickeImpuls(m_ImpulsLange); // geteiltesRelais !
        m_stellung = stellung;
        m_initial = false;
    }
}
