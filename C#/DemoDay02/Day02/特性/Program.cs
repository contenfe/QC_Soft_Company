using System;

namespace 特性
{
    [AttributeUsage(AttributeTargets.Class|AttributeTargets.Struct)]//限定在类中使用
    public class AuthorAttribute:System.Attribute
    {
        private string name;
        public double version;

        public AuthorAttribute(string name)
        {
            this.name = name;
            version = 1.0;
        }
    }


    [Author("测试")]
    class SampleTest
    {

    }

    [Obsolete("这个类过时了，请使用。。。")]
    class CThis
    {
        public void Say()
        {
            Console.WriteLine("HELLO");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("特性!");
            SampleTest sample = new SampleTest();

            CThis cThis = new CThis();
            cThis.Say();
        }
    }
}
