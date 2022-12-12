using System;

/**
 * 
 * 
 * 测试Interal
 * 
 * 
 */
namespace testInternal
{
    public class CTestInternal
    {
        public void say()
        {
            Console.WriteLine("hello say Test Internal");
        }
    }

    public interface ISampleInterface
    {
        public void sayLitte();
    }


    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }
    }


    public abstract class AbtrTest
    {
        public void say()
        {
            Console.WriteLine("AbtrTest");
            
        }

        public abstract void Sum(float a,float b);
    }
}
