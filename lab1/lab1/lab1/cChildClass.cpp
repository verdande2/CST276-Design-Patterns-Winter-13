///////////////////////////////////////////////////////////
//  cChildClass.cpp
//  Implementation of the Class cChildClass
//  Created on:      17-Jan-2013 3:08:17 PM
//  Original author: andrew.sparkes
///////////////////////////////////////////////////////////

#include "cChildClass.h"
#include <iostream>
using std::cout;
using std::endl;


cChildClass::cChildClass(){

}


cChildClass::~cChildClass(){

}


void cChildClass::Meow() const
{
	cout << "Meow!" << endl;
}


int cChildClass::DoublePrivateInt() const
{
	return 2*GetPrivateInt();
}


int cChildClass::GetNumber() const
{
	return m_number;
}


void cChildClass::SetNumber(int newVal)
{
	m_number = newVal;
}