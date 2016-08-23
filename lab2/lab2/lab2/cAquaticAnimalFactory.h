///////////////////////////////////////////////////////////
//  cAquaticAnimalFactory.h
//  Implementation of the Class cAquaticAnimalFactory
//  Created on:      01-Feb-2013 8:28:30 PM
///////////////////////////////////////////////////////////

#if !defined(EA_22616186_225A_4acc_A4C7_5004A4CCEE68__INCLUDED_)
#define EA_22616186_225A_4acc_A4C7_5004A4CCEE68__INCLUDED_

#include "cAnimalFactory.h"

/**
 * This class implements the operations to create concrete product objects.
 */
class cAquaticAnimalFactory : public cAnimalFactory
{

public:
	cAquaticAnimalFactory();
	virtual ~cAquaticAnimalFactory();
	iAnimal & CreateNormalAnimal() const;
	iAnimal & CreateSpecialtyAnimal() const;
	static cAquaticAnimalFactory & Instance();

};
#endif // !defined(EA_22616186_225A_4acc_A4C7_5004A4CCEE68__INCLUDED_)
