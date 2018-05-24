
#pragma once

#include <stdint.h>
#include "miner_manager.h"
#include "cl_device_utils.h"

#include "Core/Farm.h"
#include "Core/Workers/XCpuMiner.h"
#include "XDagCore/XTaskProcessor.h"
#include "XDagCore/XPool.h"
#include "Utils/CpuInfo.h"
#include "Utils/Random.h"

using namespace std;
using namespace XDag;
using namespace XDaggerMinerRuntime;

MinerManager::MinerManager()
{

}

std::vector< MinerDevice* > MinerManager::getAllMinerDevices()
{
	std::vector< MinerDevice* > resultList;

	std::vector<cl::Platform> platformList = DeviceUtils::GetPlatforms();

	if (platformList.empty())
	{
		//// XCL_LOG("No OpenCL platforms found.");
		return resultList;
	}

	bool useAllOpenCLCompatibleDevices = true;
	cl_device_type type = useAllOpenCLCompatibleDevices
		? CL_DEVICE_TYPE_ALL
		: CL_DEVICE_TYPE_GPU | CL_DEVICE_TYPE_ACCELERATOR;

	for (auto const &platform : platformList) // access by reference to avoid copying
	{
		std::vector<cl::Device> devices;

		try
		{
			platform.getDevices(type, &devices);
		}
		catch (cl::Error const& err)
		{
			// if simply no devices found return empty vector
			if (err.err() != CL_DEVICE_NOT_FOUND)
			{
				throw err;
			}
		}
		
		if (devices.empty())
		{
			continue;
		}

		for (auto const &device : devices)
		{
			std::string deviceName = device.getInfo<CL_DEVICE_NAME>();

			MinerDevice * deviceObject = new MinerDevice(deviceName, 1);
			resultList.push_back(deviceObject);
			
		}
	}

	return resultList;
}

