///////////////////////////////////////////////////////////
//  cAnimal.h
//  Implementation of the Class cAnimal
//  Created on:      01-Feb-2013 8:28:30 PM
///////////////////////////////////////////////////////////

#if !defined(EA_C1A6185D_72EB_4ce0_9608_A1DFD600D90C__INCLUDED_)
#define EA_C1A6185D_72EB_4ce0_9608_A1DFD600D90C__INCLUDED_

#include "iAnimal.h"
#include <string>
using std::string;

/**
 * This class declares an interface for a type of product object.
 */
class cAnimal : public iAnimal
{

public:
	virtual ~cAnimal();
	string GetName();
	void MakeNoise() const;
	void SetName(string name);

protected:
	cAnimal();

private:
	string m_name;

};
#endif // !defined(EA_C1A6185D_72EB_4ce0_9608_A1DFD600D90C__INCLUDED_)
