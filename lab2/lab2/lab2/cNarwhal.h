///////////////////////////////////////////////////////////
//  cNarwhal.h
//  Implementation of the Class cNarwhal
//  Created on:      01-Feb-2013 8:32:00 PM
//  Original author: andrew.sparkes
///////////////////////////////////////////////////////////

#if !defined(EA_0EE26224_012C_4519_ABC9_D651FF537B4D__INCLUDED_)
#define EA_0EE26224_012C_4519_ABC9_D651FF537B4D__INCLUDED_

#include "cAquaticAnimal.h"

class cNarwhal : public cAquaticAnimal
{

public:
	cNarwhal();
	virtual ~cNarwhal();
	void MakeNoise() const;

};
#endif // !defined(EA_0EE26224_012C_4519_ABC9_D651FF537B4D__INCLUDED_)
