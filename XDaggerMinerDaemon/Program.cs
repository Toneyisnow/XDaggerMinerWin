using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

using XDaggerMinerRuntimeCLI;

namespace XDaggerMinerDaemon
{
    public class RealLogger : LoggerBase
    {
        public RealLogger()
        {

        }
        
        public override void WriteLog(int level, int eventId, String message)
        {
            Console.WriteLine(string.Format("RealLogger: [{0}][{1}][{2}]", level, eventId, message));
        }
        

    };

    public class Program
    {

       

        static void Main(string[] args)
        {

            ///  MinerManager
            MinerManager manager = new MinerManager();

            // Callback Test
            RealLogger logger = new RealLogger();
            manager.SetLogger(logger);
            manager.DoMining();


            // List Devices
            List<MinerDevice> devices = manager.GetAllMinerDevices();

            foreach (MinerDevice device in devices)
            {
                Console.WriteLine(device.GetDisplayName());
            }

            Console.ReadKey();
            /// HelloWorld();
        }
    };


    

}
