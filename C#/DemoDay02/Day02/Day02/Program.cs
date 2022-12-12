using System;
using testInternal;


namespace Day02
{
    #region 委托
    public delegate void Actiondelegate();


    /// <summary>
    /// 委托类，实验委托
    /// </summary>
    class CDetegle
    {
        public void sayHello()
        {
            Console.WriteLine("sayHello");
        }

        public void goodbye()
        {
            Console.WriteLine("goodbye");
        }

    }
    #endregion

    #region 继承
    /// <summary>
    /// 类,只允许单一继承，接口多继承
    /// </summary>
    class TestClass
    {
        int Age { get; set; }
        string Name { get; set; }
        public TestClass(string name, int a)
        {
            Age = a;
            Name = name;
        }

        public string GetNames()
        {

            return Name;
        }

        public int GetAge()
        {
            return Age;
        }

    }
    #endregion

    #region 接口
    /// <summary>
    /// 接口
    /// </summary>
    class SampleImpl : ISampleInterface
    {
        public void sayLitte()
        {
            Console.WriteLine("实现ISampleInterface 中的sayLitte接口");
        }
    }
    #endregion

    #region 抽象类
    /// <summary>
    /// 抽象类
    /// </summary>
    class AbstrImpl : AbtrTest
    {
        public override void Sum(float a, float b)
        {
            Console.WriteLine(a + b);
        }
    }
    #endregion

    #region readonly只读
    /// <summary>
    /// readyonly
    /// </summary>
    class CReadOnly
    {
        private int age;
        public int Age
        {
            get
            {
                return age;
            }
            set
            {
                age = value;
            }
        }

        private readonly string m_strName;
        public string StrName
        {
            get
            {
                return m_strName;
            }

            set
            {
                //m_strName = value; // error
            }
        }

        public CReadOnly(int a, string n)
        {
            Age = a;
            m_strName = n;
        }
    }
    #endregion

    #region sealed密封类与方法
    /// <summary>
    /// sealed 密封类，防止其他类继承该类
    /// </summary>
    sealed class SampleSealed : ISampleInterface
    {
        public void sayLitte()
        {
            Console.WriteLine("实现ISampleInterface 中的sayLitte接口");
        }
    }
    // 错误，无法继承sealed修饰的类
    //class B: SampleSealed
    //{

    //}

    /// <summary>
    /// 密封方法
    /// </summary>
    class X
    {
        protected virtual void F() { Console.WriteLine("X.F"); }
        protected virtual void F2() { Console.WriteLine("X.F2"); }
    }

    class Y : X
    {
        sealed protected override void F() { Console.WriteLine("Y.F"); }
        protected override void F2() { Console.WriteLine("Y.F2"); }
    }

    class Z : Y
    {
        //protected override void F() { Console.WriteLine("X.F"); } // 写入失败

        protected override void F2()
        {
            Console.WriteLine("Z.F2");
        }
    }
    #endregion

    #region static静态方法
    /// <summary>
    /// 静态方法、属性、字段只能通过类名去访问
    /// 
    /// 静态类只能包含静态的方法和字段、属性等被static修饰的
    /// </summary>
    class CStatic
    {
        private static int age;

        public static void SayStatic()
        {
            Console.WriteLine("我是静态方法");
        }


        public static string Name;

    }


    #endregion


    #region virtual 
    /// <summary>
    /// virtual 关键字用于修改方法、属性、索引器或事件声明，并使它们可以在派生类中被重写。
    /// </summary>
    class CVirtualBase
    {
        public virtual void ToSay()
        {
            Console.WriteLine("BASE suma(a,b)");
        }
    }

    class CVirChild : CVirtualBase
    {
        public override void ToSay()
        {
            Console.WriteLine("CHILD suma(a,b)");
        }
    }


    #endregion





    class Program
    {

        /// <summary>
        /// 元组
        /// </summary>
        void printf()
        {
            (double, int) t = (4.3, 5);
            Console.WriteLine($"{t.Item1}:{t.Item2}");
        }



        static void Main(string[] args)
        {
            ////委托
            //CDetegle cDetegle = new CDetegle();
            //Actiondelegate = CDetegle.sayHello;            

            ////类
            //TestClass testClass = new TestClass("张三",18);
            //Console.WriteLine($"{testClass.GetNames()}年龄{testClass.GetAge()}");

            //// 访问其他程序集
            //CTestInternal cTestInternal = new testInternal.CTestInternal();
            //cTestInternal.say();

            //// 接口
            //SampleImpl sample = new SampleImpl();
            //sample.sayLitte();

            //// 抽象类
            //AbstrImpl abstr = new AbstrImpl();
            //abstr.say();
            //abstr.Sum(12f, 20.9f);


            //// readyonly 
            //CReadOnly cRead = new CReadOnly(29,"战神");
            ////cRead.m_strName = "123"; // error 
            //Console.WriteLine($"战神名字：{cRead.StrName}");

            //// 密封类，无法展示
            ///


            //// 静态
            //CStatic cStatic = new CStatic();
            //CStatic.SayStatic();
            //CStatic.Name = "fasd";


            //// virtual 
            //CVirtualBase cVirtualBase = new CVirtualBase();
            //cVirtualBase.ToSay();
            //CVirChild cVirChild = new CVirChild();
            //cVirChild.ToSay();
            //CVirtualBase cVirtual = new CVirChild();
            //cVirtual.ToSay();



        }
    }
}
