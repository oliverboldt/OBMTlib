#ifndef OBMT_Weiche
#define OBMT_Weiche

#include "WeichenStellung.h"

class Weiche
{
protected:
    int             m_id;
    WeichenStellung m_stellung;
    bool            m_initial;

public:
    Weiche(int id, WeichenStellung stellung)
    : m_id(id), m_stellung(stellung), m_initial(true)
    {}

    int id() const { return m_id; }
	WeichenStellung stellung() const { return m_stellung; }
    
    virtual void stellen(WeichenStellung) = 0;
};

#endif
