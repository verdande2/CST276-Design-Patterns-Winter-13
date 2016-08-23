///////////////////////////////////////////////////////////
//  cTestClass.cpp
//  Implementation of the Class cTestClass
//  Created on:      17-Jan-2013 3:08:26 PM
//  Original author: andrew.sparkes
///////////////////////////////////////////////////////////

#include "cTestClass.h"

unsigned int cTestClass::m_instanceCount = 0;

cTestClass::cTestClass()
{
	cTestClass::m_instanceCount++;
}


cTestClass::~cTestClass()
{
	cTestClass::m_instanceCount--;
}


char cTestClass::GetPrivateChar() const
{
	return m_privateChar;
}


int cTestClass::GetPrivateInt() const
{
	return m_privateInt;
}


bool cTestClass::GetPrivateBool() const
{
	return m_privateBool;
}


void cTestClass::SetPrivateBool(bool newVal)
{
	m_privateBool = newVal;
}


void cTestClass::SetPrivateChar(char newVal)
{
	m_privateChar = newVal;
}


void cTestClass::SetPrivateInt(int newVal)
{
	m_privateInt = newVal;
}


unsigned int cTestClass::GetInstanceCount()
{
	return cTestClass::m_instanceCount;
}