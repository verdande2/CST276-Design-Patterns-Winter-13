///////////////////////////////////////////////////////////
//  cVelociraptor.h
//  Implementation of the Class cVelociraptor
//  Created on:      01-Feb-2013 8:29:46 PM
//  Original author: andrew.sparkes
///////////////////////////////////////////////////////////

#if !defined(EA_D03ABA08_CA68_4c74_AFD8_FF0312C66B89__INCLUDED_)
#define EA_D03ABA08_CA68_4c74_AFD8_FF0312C66B89__INCLUDED_

#include "cLandAnimal.h"

class cVelociraptor : public cLandAnimal
{

public:
	cVelociraptor();
	virtual ~cVelociraptor();
	void MakeNoise() const;

};
#endif // !defined(EA_D03ABA08_CA68_4c74_AFD8_FF0312C66B89__INCLUDED_)
