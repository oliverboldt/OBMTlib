#ifndef OBMT_RelaisI2C
#define OBMT_RelaisI2C

#include "Relais.h"
#include "Arduino.h"

class RelaisI2C : public Relais
{
    int     m_clientId;
    
public:
    RelaisI2C(int clientId, int id);

    virtual void setzen(bool an);
};

#endif
