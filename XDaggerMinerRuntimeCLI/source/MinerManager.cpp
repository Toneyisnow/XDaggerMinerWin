#pragma once

#include "../Stdafx.h"
#include <msclr\marshal_cppstd.h>
#include "MinerManager.h"

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace XDaggerMinerRuntimeCLI;


MinerManager::MinerManager()
{
	this->_impl = new XDaggerMinerRuntime::MinerManager();
	
	// Set Logger Callback
	LoggerCallback^ writLogFunc = gcnew LoggerCallback(this, &MinerManager::WriteLog);
	GCHandle gc = GCHandle::Alloc(writLogFunc);	IntPtr func = Marshal::GetFunctionPointerForDelegate(writLogFunc);
	LoggerCallbackFunc necb = static_cast<LoggerCallbackFunc>(func.ToPointer());
	this->_impl->setLogCallback(necb);

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

void MinerManager::DoMining()
{
	std::string test = "asdf";
	this->_impl->doMining(test, 0);
}

void MinerManager::SetLogger(LoggerBase ^ logger)
{
	this->_logger = logger;
}

void MinerManager::WriteLog(int level, int eventId, std::string message)
{
	if (this->_logger != nullptr)
	{
		this->_logger->WriteLog(level, eventId, msclr::interop::marshal_as<System::String^>(message));
	}
}
