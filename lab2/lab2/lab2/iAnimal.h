///////////////////////////////////////////////////////////
//  iAnimal.h
//  Implementation of the Interface iAnimal
//  Created on:      01-Feb-2013 8:29:49 PM
//  Original author: andrew.sparkes
///////////////////////////////////////////////////////////

#if !defined(EA_1A7E5A24_D89C_469a_94E2_09E95DDEBCEF__INCLUDED_)
#define EA_1A7E5A24_D89C_469a_94E2_09E95DDEBCEF__INCLUDED_

class iAnimal
{

public:
	iAnimal() {

	}

	virtual ~iAnimal() {

	}

	virtual void MakeNoise() const =0;

};
#endif // !defined(EA_1A7E5A24_D89C_469a_94E2_09E95DDEBCEF__INCLUDED_)
