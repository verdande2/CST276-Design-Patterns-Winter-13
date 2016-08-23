///////////////////////////////////////////////////////////
//  cTestClass.h
//  Implementation of the Class cTestClass
//  Created on:      17-Jan-2013 3:08:26 PM
//  Original author: andrew.sparkes
///////////////////////////////////////////////////////////

#if !defined(EA_BED910A0_3E61_4f8b_85E7_CE933363D382__INCLUDED_)
#define EA_BED910A0_3E61_4f8b_85E7_CE933363D382__INCLUDED_

/**
 * These are comments for cTestClass blah blah blah
 */
class cTestClass
{
private:
	/**
	 * Private bool to play with
	 */
	bool m_privateBool;
	/**
	 * Private char to test with
	 */
	char m_privateChar;
	/**
	 * A private integer to test code generation
	 */
	int m_privateInt;

	static unsigned int m_instanceCount;


public:
	// canonical
	cTestClass();
	virtual ~cTestClass();

	// getters
	char GetPrivateChar() const;
	int GetPrivateInt() const;
	bool GetPrivateBool() const;

	// setters
	void SetPrivateChar(char newVal);
	void SetPrivateInt(int newVal);
	void SetPrivateBool(bool newVal);

	// misc
	static unsigned int GetInstanceCount();
};
#endif // !defined(EA_BED910A0_3E61_4f8b_85E7_CE933363D382__INCLUDED_)
