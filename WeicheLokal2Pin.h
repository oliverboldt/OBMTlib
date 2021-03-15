#ifndef OBMT_WeicheLokal2Pin
#define OBMT_WeicheLokal2Pin

#include "Weiche.h"

class WeicheLokal2Pin : public Weiche
{
    int     m_geradePin;
    int     m_abbiegenPin;
    int     m_ImpulsLange;
	bool    m_async;
    bool    m_dirty;
    
public:
    WeicheLokal2Pin(int id, WeichenStellung stellung, int geradePin, int abbiegenPin, int impulsLange, bool async=false);

    virtual void stellen(WeichenStellung);

    WeichenStellung stellung() { return m_stellung; }
	
	void tick();
};

#endif
