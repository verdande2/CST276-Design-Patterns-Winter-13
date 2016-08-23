///////////////////////////////////////////////////////////
//  cZoo.h
//  Implementation of the Class cZoo
//  Created on:      01-Feb-2013 8:32:01 PM
//  Original author: andrew.sparkes
///////////////////////////////////////////////////////////

#if !defined(EA_2D694DCE_8B0A_4f80_9280_E826CECFBC3B__INCLUDED_)
#define EA_2D694DCE_8B0A_4f80_9280_E826CECFBC3B__INCLUDED_

#include "cCage.h"
#include <vector>
using std::vector;
#include "iAnimalFactory.h"

class cZoo
{

public:
	cZoo();
	cZoo(iAnimalFactory &animalFactory);
	virtual ~cZoo();
	cZoo& operator=(const cZoo &rhs);
	cZoo(const cZoo &copy);

	void MakeAllAnimalsMakeNoise() const;
	void Populate();

	void AddAnimal(iAnimal &animal);

private:
	vector<cCage> m_cages;
	iAnimalFactory * m_animalFactory;

};
#endif // !defined(EA_2D694DCE_8B0A_4f80_9280_E826CECFBC3B__INCLUDED_)
