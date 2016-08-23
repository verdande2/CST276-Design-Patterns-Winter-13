///////////////////////////////////////////////////////////
//  cLandCageBuilder.h
//  Implementation of the Class cLandCageBuilder
//  Created on:      03-Feb-2013 3:12:43 PM
//  Original author: Verdande
///////////////////////////////////////////////////////////

#if !defined(EA_4023A986_C113_4000_95C9_C1EB91C7B7DB__INCLUDED_)
#define EA_4023A986_C113_4000_95C9_C1EB91C7B7DB__INCLUDED_

#include "cCageBuilder.h"

class cLandCageBuilder : public cCageBuilder
{

public:
	cLandCageBuilder();
	virtual ~cLandCageBuilder();

	virtual void BuildDimensions();
	virtual void BuildWalls();

};
#endif // !defined(EA_4023A986_C113_4000_95C9_C1EB91C7B7DB__INCLUDED_)
