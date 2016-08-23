///////////////////////////////////////////////////////////
//  cMonkey.cpp
//  Implementation of the Class cMonkey
//  Created on:      01-Feb-2013 8:32:00 PM
//  Original author: andrew.sparkes
///////////////////////////////////////////////////////////

#include "cMonkey.h"
#include <iostream>
using std::cout;
using std::endl;




cMonkey::cMonkey(){

}


cMonkey::~cMonkey(){

}


void cMonkey::MakeNoise() const
{
	cout << "[Monkey Noise Here]" << endl;
}