#ifndef OBMT_WeicheI2C
#define OBMT_WeicheI2C

#include "Weiche.h"
#include "Arduino.h"

class WeicheI2C : public Weiche
{
    int     m_clientId;
    
public:
    WeicheI2C(int clientId, int id, WeichenStellung stellung);

    virtual void stellen(WeichenStellung);

    WeichenStellung stellung() { return m_stellung; }
};

#endif
