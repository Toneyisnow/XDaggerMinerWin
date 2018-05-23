#include "stdafx.h"  
#include "MathLibrary.h"  

namespace MathLibrary
{
	double CoreLibrary::Add(double a, double b)
	{
		return a + b;
	}

	double CoreLibrary::Multiply(double a, double b)
	{
		return a * b;
	}

	double CoreLibrary::AddMultiply(double a, double b)
	{
		return a + (a * b);
	}
}
