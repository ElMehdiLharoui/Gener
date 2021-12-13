#include "pch.h"
#include"MathClasses.h" 
#include<iostream>
#include"assert.h"
using namespace std;
using namespace Math;

Matrix::Matrix(unsigned int numC, unsigned int numL)
{
	assert(numC != 0 && numL != 0);
	this->numC = numC;
	this->numL = numL;
	this->Matx = new float* [numL];
	for (int i = 0; i < numL; i++) 
	{ 
		this->Matx[i] = new float[numC]();
	}
}








