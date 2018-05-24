using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

using XDaggerMinerRuntimeCLI;

namespace XDaggerMinerDaemon
{
    class Program
    {

        static void Main(string[] args)
        {

            ///  MinerManager
            MinerManager manager = new MinerManager();
            List<MinerDevice> devices = manager.GetAllMinerDevices();

            foreach (MinerDevice device in devices)
            {
                Console.WriteLine(device.GetDisplayName());
            }

            Console.ReadKey();
            /// HelloWorld();
        }
    }


    

}
