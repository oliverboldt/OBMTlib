#ifndef OBMT_Relais
#define OBMT_Relais

class Relais
{
protected:
    int     m_id;
	bool    m_on;
       
public:
    Relais(int id);

    virtual void    setzen(bool an) = 0;

    int id() const { return m_id; }
	bool on() const { return m_on; }
};

#endif
