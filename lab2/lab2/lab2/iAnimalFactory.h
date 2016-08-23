///////////////////////////////////////////////////////////
//  iAnimalFactory.h
//  Implementation of the Interface iAnimalFactory
//  Created on:      01-Feb-2013 8:29:49 PM
//  Original author: Verdande
///////////////////////////////////////////////////////////

#if !defined(EA_4639DC45_7A2D_4bd3_AE80_135F3C9C2EDB__INCLUDED_)
#define EA_4639DC45_7A2D_4bd3_AE80_135F3C9C2EDB__INCLUDED_
#include "iAnimal.h"

class iAnimalFactory
{

public:
	iAnimalFactory() {};
	virtual ~iAnimalFactory() {};
	virtual iAnimal & CreateNormalAnimal() const = 0;
	virtual iAnimal & CreateSpecialtyAnimal() const = 0;
};
#endif // !defined(EA_4639DC45_7A2D_4bd3_AE80_135F3C9C2EDB__INCLUDED_)
