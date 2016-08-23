///////////////////////////////////////////////////////////
//  cLandAnimalFactory.h
//  Implementation of the Class cLandAnimalFactory
//  Created on:      01-Feb-2013 8:28:29 PM
///////////////////////////////////////////////////////////

#if !defined(EA_0FE7F4E6_5AE7_43ea_8D31_06F007C3BA38__INCLUDED_)
#define EA_0FE7F4E6_5AE7_43ea_8D31_06F007C3BA38__INCLUDED_

#include "cAnimalFactory.h"

/**
 * This class implements the operations to create concrete product objects.
 */
class cLandAnimalFactory : public iAnimalFactory
{

public:
	cLandAnimalFactory();
	virtual ~cLandAnimalFactory();
	iAnimal & CreateNormalAnimal() const;
	iAnimal & CreateSpecialtyAnimal() const;
	static cLandAnimalFactory & Instance();

};
#endif // !defined(EA_0FE7F4E6_5AE7_43ea_8D31_06F007C3BA38__INCLUDED_)
