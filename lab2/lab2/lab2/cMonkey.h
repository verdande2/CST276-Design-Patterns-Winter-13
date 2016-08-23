///////////////////////////////////////////////////////////
//  cMonkey.h
//  Implementation of the Class cMonkey
//  Created on:      01-Feb-2013 8:32:00 PM
//  Original author: andrew.sparkes
///////////////////////////////////////////////////////////

#if !defined(EA_3C06E2E5_098F_4168_81CD_A9CB9356818F__INCLUDED_)
#define EA_3C06E2E5_098F_4168_81CD_A9CB9356818F__INCLUDED_

#include "cLandAnimal.h"

class cMonkey : public cLandAnimal
{

public:
	cMonkey();
	virtual ~cMonkey();
	void MakeNoise() const;

};
#endif // !defined(EA_3C06E2E5_098F_4168_81CD_A9CB9356818F__INCLUDED_)
