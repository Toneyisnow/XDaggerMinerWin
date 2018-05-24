#pragma once

#include <vector>
#include "../Stdafx.h"

#include "MinerDevice.h"
#include "..\..\XDaggerMinerRuntime\miner_runtime.h";


using namespace System;
using namespace System::Collections::Generic;

namespace XDaggerMinerRuntimeCLI {

	public ref class MinerManager
	{
	public:
		MinerManager();

		List<MinerDevice^>^ GetAllMinerDevices();

	private:
		// List<String^>^ dinosaurs = gcnew List<String^>();

		XDaggerMinerRuntime::MinerManager * _impl;

	};






}
