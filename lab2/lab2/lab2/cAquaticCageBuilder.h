///////////////////////////////////////////////////////////
//  cAquaticCageBuilder.h
//  Implementation of the Class cAquaticCageBuilder
//  Created on:      03-Feb-2013 3:12:46 PM
//  Original author: Verdande
///////////////////////////////////////////////////////////

#if !defined(EA_CF42684F_24C8_43d3_B2F7_9CAF143B93BA__INCLUDED_)
#define EA_CF42684F_24C8_43d3_B2F7_9CAF143B93BA__INCLUDED_

#include "cCageBuilder.h"

class cAquaticCageBuilder : public cCageBuilder
{

public:
	cAquaticCageBuilder();
	virtual ~cAquaticCageBuilder();

	virtual void BuildDimensions();
	virtual void BuildWalls();

};
#endif // !defined(EA_CF42684F_24C8_43d3_B2F7_9CAF143B93BA__INCLUDED_)
