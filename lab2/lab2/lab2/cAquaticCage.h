///////////////////////////////////////////////////////////
//  cAquaticCage.h
//  Implementation of the Class cAquaticCage
//  Created on:      01-Feb-2013 8:31:59 PM
///////////////////////////////////////////////////////////

#if !defined(EA_7EA58098_F1EF_4753_8EAF_8730F5D58752__INCLUDED_)
#define EA_7EA58098_F1EF_4753_8EAF_8730F5D58752__INCLUDED_

#include "cCage.h"

/**
 * This class (a) defines a product object to be created by the corresponding
 * concrete factory, and (b) implements the AbstractProduct interface.
 */
class cAquaticCage : public cCage
{

public:
	cAquaticCage();
	virtual ~cAquaticCage();

};
#endif // !defined(EA_7EA58098_F1EF_4753_8EAF_8730F5D58752__INCLUDED_)
