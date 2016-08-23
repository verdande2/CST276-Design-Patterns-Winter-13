///////////////////////////////////////////////////////////
//  cCage.h
//  Implementation of the Class cCage
//  Created on:      01-Feb-2013 8:31:59 PM
///////////////////////////////////////////////////////////

#if !defined(EA_EE490AFA_E61B_4140_9408_815ED14B942A__INCLUDED_)
#define EA_EE490AFA_E61B_4140_9408_815ED14B942A__INCLUDED_

#include "iAnimal.h"
#include <string>
using std::string;

/**
 * This class declares an interface for a type of product object.
 */
class cCage
{

public:
	cCage();
	cCage(const string &wallType, int width, int length, iAnimal &animal);
	virtual ~cCage();

	const iAnimal & GetAnimal() const;
	int GetLength() const;
	const string & GetWallType() const;
	int GetWidth() const;

	void SetAnimal(iAnimal &animal);
	void SetLength(int length);
	void SetWidth(int width);
	void SetWallType(const string & wallType);

private:
	iAnimal* m_animal;

	int m_length;
	string m_wallType;
	int m_width;

};
#endif // !defined(EA_EE490AFA_E61B_4140_9408_815ED14B942A__INCLUDED_)
