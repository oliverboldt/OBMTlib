#include "RelaisI2C.h"
#include "Arduino.h"
#include "Wire.h"

RelaisI2C::RelaisI2C(int clientId, int id)
: Relais(id)
, m_clientId(clientId)
{
}


void RelaisI2C::setzen(bool an)
{
    Wire.beginTransmission(m_clientId);
    Wire.write('R');
    Wire.write((byte)m_id);
    Wire.write((byte)an);
    Wire.endTransmission();
	
	m_on = an;
}
