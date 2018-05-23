// XDaggerMinerRuntimeCLI.h

#pragma once
#include "D:\Toney\Personal\Git\XDaggerMinerWin\XDaggerMinerRuntime\miner_runtime.h";

using namespace System;

namespace XDaggerMinerRuntimeCLI {

	public ref class Runtime
	{
		// TODO: Add your methods for this class here.

	public:
		int GetDevice();

	private:
		XDaggerMinerRuntime::Runtime *runtime;

	};
}
