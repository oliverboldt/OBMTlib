#ifndef OBMT_RelaisLokal
#define OBMT_RelaisLokal

#include "Relais.h"

class RelaisLokal : public Relais
{
public:
    enum Active { ACTIVE_LOW, ACTIVE_HIGH };

private:
    int     m_pin;
    Active  m_active;
    bool    m_geteilt;   
    bool    m_ImpulsBeiTick;
    int     m_ImpulsLange;
    
public:
    RelaisLokal(int id, int pin, Active active, bool geteilt=false);

    void    tick();
    void    schickeImpuls(int millisec);

    virtual void setzen(bool an);
};

#endif
