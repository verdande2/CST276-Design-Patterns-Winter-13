///////////////////////////////////////////////////////////
//  cLandCage.h
//  Implementation of the Class cLandCage
//  Created on:      01-Feb-2013 8:31:59 PM
///////////////////////////////////////////////////////////

#if !defined(EA_A3E31B46_C56B_42b8_94C9_A8F1737614C8__INCLUDED_)
#define EA_A3E31B46_C56B_42b8_94C9_A8F1737614C8__INCLUDED_

#include "cCage.h"

/**
 * This class (a) defines a product object to be created by the corresponding
 * concrete factory, and (b) implements the AbstractProduct interface.
 */
class cLandCage : public cCage
{

public:
	cLandCage();
	virtual ~cLandCage();

};
#endif // !defined(EA_A3E31B46_C56B_42b8_94C9_A8F1737614C8__INCLUDED_)
