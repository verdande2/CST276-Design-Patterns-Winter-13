///////////////////////////////////////////////////////////
//  cCageBuilder.h
//  Implementation of the Class cCageBuilder
//  Created on:      03-Feb-2013 3:12:47 PM
//  Original author: Verdande
///////////////////////////////////////////////////////////

#if !defined(EA_4E279F98_CDC2_4b02_B36D_2083765AB1B1__INCLUDED_)
#define EA_4E279F98_CDC2_4b02_B36D_2083765AB1B1__INCLUDED_

#include "cCage.h"

class cCageBuilder
{

public:
	virtual ~cCageBuilder();

	void BuildCage();
	virtual void BuildDimensions() = 0;
	virtual void BuildWalls() = 0;
	cCage & Cage();

protected:
	cCageBuilder();
	cCage * m_cage;

};
#endif // !defined(EA_4E279F98_CDC2_4b02_B36D_2083765AB1B1__INCLUDED_)
