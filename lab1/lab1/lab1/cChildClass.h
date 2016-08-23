///////////////////////////////////////////////////////////
//  cChildClass.h
//  Implementation of the Class cChildClass
//  Created on:      17-Jan-2013 3:08:17 PM
//  Original author: andrew.sparkes
///////////////////////////////////////////////////////////

#if !defined(EA_C69F142E_4396_4b5e_9931_265C1601A166__INCLUDED_)
#define EA_C69F142E_4396_4b5e_9931_265C1601A166__INCLUDED_

#include "cTestClass.h"

/**
 * Child class notes here
 */
class cChildClass : public cTestClass
{
private:
	int m_number;

public:
	cChildClass();
	virtual ~cChildClass();

	// public methods
	void Meow() const;
	int DoublePrivateInt() const;

	// getters
	int GetNumber() const;

	// setters
	void SetNumber(int newVal);
};
#endif // !defined(EA_C69F142E_4396_4b5e_9931_265C1601A166__INCLUDED_)
