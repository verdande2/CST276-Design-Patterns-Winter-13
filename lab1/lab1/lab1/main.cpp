/***********************************************************
* Author:					Andrew Sparkes
* Date Created:				1/17/13
* Last Modification Date:	1/17/13
* Lab Number:				CST 276 Lab 1
* Filename:					main.cpp
*
* Overview:
*	This program demos some code generated from EA and provides 
*	a short test of all code.
*
* Input:
*	None.
*
* Output:
*	This program creates two objects and then dumps a short 
*	analysis of each method called.
************************************************************/

#include <iostream>
using std::cout;
using std::endl;

#include "cTestClass.h"
#include "cChildClass.h"

int main()
{
	cout << "Current cTestClass Instance Count: " << cTestClass::GetInstanceCount() << endl;
	cout << endl;

	cout << "Creating TestClass..." << endl;
	cTestClass TestClass;
	TestClass.SetPrivateBool(true);
	TestClass.SetPrivateChar('a');
	TestClass.SetPrivateInt(123);
	
	cout << "Dumping TestClass:" << endl;
	cout << "PrivateBool: " << TestClass.GetPrivateBool() << endl;
	cout << "PrivateChar: " << TestClass.GetPrivateChar() << endl;
	cout << "Pri6vateInt: " << TestClass.GetPrivateInt() << endl;
	cout << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << endl;
	
	cout << "Current cTestClass Instance Count: " << cTestClass::GetInstanceCount() << endl;
	cout << endl;




	cout << "Creating ChildClass..." << endl;
	cChildClass ChildClass;
	ChildClass.SetPrivateBool(false);
	ChildClass.SetPrivateChar('b');
	ChildClass.SetPrivateInt(999);
	ChildClass.SetNumber(123456789);

	cout << "Dumping ChildClass:" << endl;
	cout << "PrivateBool: " << ChildClass.GetPrivateBool() << endl;
	cout << "PrivateChar: " << ChildClass.GetPrivateChar() << endl;
	cout << "PrivateInt: " << ChildClass.GetPrivateInt() << endl;
	cout << "Number: " << ChildClass.GetNumber() << endl;
	cout << "Testing Meow() method..." << endl;
	ChildClass.Meow();
	cout << "Testing DoublePrivateInt() method: " << ChildClass.DoublePrivateInt() << endl;
	cout << endl;

	cout << "Current cTestClass Instance Count: " << cTestClass::GetInstanceCount() << endl;
	cout << endl;

	cout << endl << endl;

	system("pause");
	return 0;
}