#pragma once

#include "../Stdafx.h"
#include <msclr\marshal_cppstd.h>
#include "MinerManager.h"

using namespace XDaggerMinerRuntimeCLI;


MinerManager::MinerManager()
{
	this->_impl = new XDaggerMinerRuntime::MinerManager();
}

List<MinerDevice^>^ MinerManager::GetAllMinerDevices()
{
	List<MinerDevice^>^ resultList = gcnew List<MinerDevice^>();

	std::vector<XDaggerMinerRuntime::MinerDevice*> rawDevices = this->_impl->getAllMinerDevices();

	for (auto const &rawDevice : rawDevices)
	{
		String ^ displayName = msclr::interop::marshal_as<System::String^>(rawDevice->getDisplayName());
		MinerDevice^ device = gcnew MinerDevice(rawDevice->getDeviceId(), displayName);
		resultList->Add(device);
	}

	return resultList;
}
