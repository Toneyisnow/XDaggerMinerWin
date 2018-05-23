// This is the main DLL file.

#include "stdafx.h"

#include "XDaggerMinerRuntimeCLI.h"

int XDaggerMinerRuntimeCLI::Runtime::GetDevice()
{
	return this->runtime->getDevices();
}