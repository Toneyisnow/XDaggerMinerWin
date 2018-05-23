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
            Runtime run = new Runtime();
            Console.WriteLine(run.GetDevice());
            
            Console.ReadKey();

            

            /// HelloWorld();
        }
    }


    

}
