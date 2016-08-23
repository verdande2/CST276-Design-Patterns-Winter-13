///////////////////////////////////////////////////////////
//  cAnimalFactory.h
//  Implementation of the Class cAnimalFactory
//  Created on:      01-Feb-2013 8:28:29 PM
///////////////////////////////////////////////////////////

#if !defined(EA_3360185B_98E7_49d0_85D5_96C0404FFA52__INCLUDED_)
#define EA_3360185B_98E7_49d0_85D5_96C0404FFA52__INCLUDED_

#include "iAnimalFactory.h"
#include "iAnimal.h"

/**
 * This class declares an interface for operations that create abstract product
 * objects.
 */
class cAnimalFactory : public iAnimalFactory
{

public:
	virtual ~cAnimalFactory();
	virtual iAnimal & CreateNormalAnimal() const = 0;
	virtual iAnimal & CreateSpecialtyAnimal() const = 0;
	static cAnimalFactory const& Instance();
	

protected:
	cAnimalFactory();

};
#endif // !defined(EA_3360185B_98E7_49d0_85D5_96C0404FFA52__INCLUDED_)
