using System;
using System.Reflection;
namespace test2
{
    public class Class1
    {

       public void GetRefe()
        {
            Assembly assembly = Assembly.Load("BIMBaseNet");
            Type[] types = assembly.GetTypes();
            foreach (var type in types)
            {
                Console.WriteLine(type.FullName);
            }
        }

        
    }
}
