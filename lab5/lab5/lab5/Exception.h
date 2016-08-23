/************************************************************************
* Class: Exception
*
* Purpose: This class represents a simple exception consisting of a 
*		single string.
*
* Manager functions:	
* 	Exception()
*		Sets exception message to "Generic Exception".
*	Exception(const string &msg)
*		Sets exception message to msg.
*	Exception(const Exception &copy)
*		Copy constructor
*	~Exception()
*		Destructor. Cleans up message.
*
* Methods:		
*	operator=(const Exception &rhs)
*		Overloaded operator= for assignment.
*	getMessage()
*		Returns the current exception message.
*	setMessage(const string &msg)
*		Sets the current exception message to msg.
*************************************************************************/
#pragma once
#include <string>
using std::string;

class Exception{
		friend std::ostream& operator<<(std::ostream& stream, const Exception &exception);

	private:
		string m_msg;

	public:
		Exception();
		Exception(const string &msg);
		Exception(const Exception &copy);
		~Exception();

		Exception& operator=(const Exception &rhs);
		string getMessage();
		void setMessage(const string &msg);

};