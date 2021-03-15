#include "WeicheI2C.h"
#include "Arduino.h"
#include "Wire.h"

WeicheI2C::WeicheI2C(int clientId, int id, WeichenStellung stellung)
: Weiche(id,stellung)
, m_clientId(clientId)
{
    m_id        = id;
    m_stellung  = stellung;

     // this->stellen(stellung); zu früh !
}


void WeicheI2C::stellen(WeichenStellung stellung)
{
    if (stellung != m_stellung || m_initial)
    {
        Wire.beginTransmission(m_clientId);
        Wire.write('W');
        Wire.write((byte)m_id);
        Wire.write((byte)stellung);
        Wire.endTransmission();
    
        m_initial = false;  
        m_stellung = stellung;
    }
}
