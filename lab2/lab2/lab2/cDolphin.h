///////////////////////////////////////////////////////////
//  cDolphin.h
//  Implementation of the Class cDolphin
//  Created on:      01-Feb-2013 8:28:36 PM
//  Original author: andrew.sparkes
///////////////////////////////////////////////////////////

#if !defined(EA_E0E6329F_26F1_46d9_BEF1_744836723B9F__INCLUDED_)
#define EA_E0E6329F_26F1_46d9_BEF1_744836723B9F__INCLUDED_

#include "cAquaticAnimal.h"

class cDolphin : public cAquaticAnimal
{

public:
	cDolphin();
	virtual ~cDolphin();
	void MakeNoise() const;

};
#endif // !defined(EA_E0E6329F_26F1_46d9_BEF1_744836723B9F__INCLUDED_)
