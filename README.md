# XDaggerMinerWin


## Structure

Runtime: This is VC++ library that uses OpenCL to run the miner work.

Service: This is a Windows Service that wraps the Runtime, it reads/writes config, starts/stops as windows service, and write logs into EventLog.

Daemon: This is an exe file that helps install pre-requirsites, and install/update the miner. It's called by Deployment button from Manager.


## Build Instruction
