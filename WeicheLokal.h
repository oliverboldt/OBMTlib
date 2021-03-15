#ifndef OBMT_WeicheLokal
#define OBMT_WeicheLokal

#include "Weiche.h"
#include "RelaisLokal.h"

class WeicheLokal : public Weiche
{

    RelaisLokal&      m_ImpulsRelais;
    RelaisLokal       m_StellungsRelais;
    int               m_ImpulsLange;
    
public:
    WeicheLokal(int id, WeichenStellung stellung, RelaisLokal& impulsRelais, int impulsLange, int stellungPin);

    virtual void stellen(WeichenStellung);

    WeichenStellung stellung() { return m_stellung; }
};

#endif
