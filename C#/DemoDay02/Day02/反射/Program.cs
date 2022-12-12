using System;
using System.Reflection;

/**
 * 
 * 反射在以下情况下很有用：
 * 需要访问程序元数据中的特性时。 
 * 检查和实例化程序集中的类型。
 * 在运行时构建新类型。 使用 System.Reflection.Emit 中的类。
 * 执行后期绑定，访问在运行时创建的类型上的方法。 请参阅主题 “动态加载和使用类型”。
 * 
 */

namespace 反射
{

    class CReflect
    {
        public void MSDN()
        {
            Type t = typeof(System.IO.BufferedStream);
            Console.WriteLine("Listing all the members (public and non public) of the {0} type", t);

            // Lists static fields first.
            FieldInfo[] fi = t.GetFields(BindingFlags.Static |
                BindingFlags.NonPublic | BindingFlags.Public);
            Console.WriteLine("// Static Fields");
            

        }


        public void GetRefe()
        {
            Assembly assembly = Assembly.LoadFile(@"D:\Program Files (x86)\BIMBase建模软件 2023\PLATFORM\BIMBaseNet.Geometries.dll");
            Type[] types = assembly.GetTypes();
            foreach (var type in types)
            {
                Console.WriteLine(type.Name);
            }
        }

    }


    class Program
    {
        static void Main(string[] args)
        {
            int i = 20;
            Type type = i.GetType();
            //Console.WriteLine(type);


            //Assembly info = typeof(int).Assembly;
            //Console.WriteLine(info);


            CReflect reflect = new CReflect();
            reflect.GetRefe();

        }
    }
}
