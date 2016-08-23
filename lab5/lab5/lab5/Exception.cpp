#include "Exception.h"
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

/**********************************************************************	
* ostream& operator<<(ostream& stream, const Exception &exception)
* Purpose: This function allows exceptions to be used with cout.
*
* Entry: 
*	Params:
*		stream: The ostream object to output the exception message to.
*		exception: The Exception to output.
*
* Exit: The exception's message is output to the stream, and the modified 
*		stream is returned for chaining.
************************************************************************/
std::ostream& operator<<(std::ostream& stream, const Exception &except)
{
	return stream << except.m_msg;
}

/**********************************************************************	
* Exception()
* Purpose: This function is the default constructor for the Exception class.
*
* Entry:
*		None.
*
* Exit: Constructs an Exception with a message of "Generic Exception".
************************************************************************/
Exception::Exception() :
	m_msg("Generic Exception")
{

}

/**********************************************************************	
* Exception(const string &msg)
* Purpose: This function is the 1-arg constructor for the Exception class.
*
* Entry:
*	Params:
*		msg: (string) The exception message.
*
* Exit: Constructs an Exception with the given message.
************************************************************************/
Exception::Exception(const string &msg) :
	m_msg(msg)
{

}

/**********************************************************************	
* Exception(const Exception &copy)
* Purpose: This function is the copy constructor for the Exception class.
*
* Entry:
*	Params:
*		copy: (Exception) The Exception to copy from.
*
* Exit: Constructs an Exception that is a deep copy of the passed in Exception.
************************************************************************/
Exception::Exception(const Exception &copy) :
	m_msg(copy.m_msg)
{

}

/**********************************************************************	
* ~Exception()
* Purpose: This function is the destructor for the Exception class. It 
*		frees the memory allocated for the message.
*
* Entry:
*		None.
*
* Exit: Resets the exception to default and frees up allocated memory.
************************************************************************/
Exception::~Exception()
{
	
}

/**********************************************************************	
* Exception& operator=(Exception const& rhs)
* Purpose: This function is the assignment operator for the Exception class.
*
* Entry:
*	Params:
*		rhs: (Exception) The right hand side of the assignment.
*
* Exit: The left hand Exception is assigned the values of the right hand 
*		Exception and the left hand Exception is returned by reference.
************************************************************************/
Exception& Exception::operator=(Exception const& rhs)
{
	// check for self assignment
	if(this != &rhs){
		setMessage(rhs.m_msg);
	}
	return *this;
}

/**********************************************************************	
* string getMessage()
* Purpose: This function returns the message for the exception.
*
* Entry:
*		None.
*
* Exit: Returns the exception message (const char*).
************************************************************************/
string Exception::getMessage()
{
	return m_msg;
}

/**********************************************************************	
* setMessage(string msg)
* Purpose: This function sets the exception message.
*
* Entry:
*	Params:
*		msg: (string) The exception message.
*
* Exit: The exception's message is set to the passed in message.
************************************************************************/
void Exception::setMessage(const string &msg)
{
	m_msg = msg;
}