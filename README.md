# XDaggerMinerWin


## Structure

Daemon.exe -->  RuntimeCLI.dll   <--  Service.exe
                    |                
                    V
                  Runtime
                    |
                    V
                  OpenCL
    
Runtime:
    This is the core library that manages Works and communicates with pool.
    
Runtime CLI:
    This is a C++/CLR project, that expose the necessary functions to dotNET framework to call.
    
Daemon:
    This is a utility project that helps communicates with XDaggerMinerManager for the management work:
    1) Provide API to install/deploy/start/stop the Miner Service;
    2) Provide API to write/read config.json file;
    3) Provide API to retrieve Machine Information (e.g. GPU info);
    4) Provide API to report statistics;
    5) Provide API to upgrade the Miner Service;
            
Service:
    This is a Windows Service project, that could:
    1) Read the config.json file for the miner configurations;
    2) Load the RuntimeCLI to start the miner work;
    3) Write information/error to EventLog;
    
    

## Build Instruction
