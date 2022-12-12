using System;
using System.Reflection;

namespace 反射
{
    // 程序运行时获取信息
    class Program
    {
        public int age=12;
        public string addr;
        public string space;
        string name = "helo apple";
        static void Main(string[] args)
        {
            Type type2 = Type.GetType("System.String", false, true);
            Console.WriteLine(type2.FullName);
            string s = "world";
            Type type1 = s.GetType();
            Console.WriteLine(type1.FullName);
            Program program = new Program();
            Type type = program.GetType();
            Console.WriteLine($"{type.Name}  {type.FullName}  \n\n");

            

            MemberInfo[] info = type.GetMembers();
            MethodInfo[] minfo = type.GetMethods();
            foreach(var sinfo in info)
            {
                Console.WriteLine(sinfo.Name);
            }
            Console.WriteLine("\n\n");
            foreach(var sinfo in minfo)
            {
                Console.WriteLine(sinfo.Name);
            }
        }
    }
}
