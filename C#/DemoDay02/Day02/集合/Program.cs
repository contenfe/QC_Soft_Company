using System;
using System.Collections.Generic;

namespace 集合
{



    class CTest
    {

       public Dictionary<string, int> Older;
        Dictionary<float, string> Qwork;

        List<string> m_list;


        #region List
        public void CreateList()
        {
            m_list = new List<string>();
            m_list.Add("choco");
            m_list.Add("merco");
            m_list.Add("tree");
            m_list.Add("pinck");
            m_list.Add("sky");
            m_list.Add("cool");
        }

        public void ShowList()
        {
            foreach(var a in m_list)
            {
                Console.WriteLine($"{a}");
            }
        }


        public void DeleteListElentment()
        {
            Console.WriteLine("************************************");
            m_list.RemoveAt(3);

            m_list.Remove("tree");
            m_list.Remove("spb");
            //m_list.
            Console.WriteLine("************************************");

        }

        #endregion

        #region Dictionary

        public void CreateDictionary()
        {
            Older = new Dictionary<string, int>();
            Qwork = new Dictionary<float, string>();
        }

        public void AddDictionaryOlder(string name,int age)
        {
            try
            {
                Older.Add(name, age);

            }
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
            }

        }
        public void AddDictionaryQwork(float price ,string workname)
        {
            for (int i = 0; i < 20; i++)
            {
                string strname = workname + i;
                float pric = price + i;
                Qwork.Add(pric, strname);
            }
        }

        public void ShowDictionaryOlder(string name)
        {
            Console.WriteLine("**********************************************");

            foreach (var kvp in Older)
            {
                Console.WriteLine("key={0}  value={1}", kvp.Key, kvp.Value);
            }



            Console.WriteLine("**********************************************");
        }


        public void DeleteDictElenmentOlder()
        {
            int val;
            Older.Remove("ad8");
            Older.Remove("ad3", out val);
            Console.WriteLine(val);
        }

        #endregion

        #region Queue
       public Queue<int> argve;
        public void CreateQueue()
        {
            argve = new Queue<int>();
            
        }

        public void AddQueueElenment(int num)
        {
            argve.Enqueue(num);
        }

        public void ShowQueue()
        {
            Console.WriteLine("**********************************************");

            foreach (int s in argve)
            {
                Console.WriteLine(s);
            }

            Console.WriteLine("argve.Dequeue: {0}",argve.Dequeue());
            Console.WriteLine("argve.peek:{0}", argve.Peek());

            Console.WriteLine("**********************************************");

        }




        #endregion

        #region Stack
        public Stack<double> _money;
        public void CrateStack()
        {
            _money = new Stack<double>();


        }


        public void AddStackElenemt(double val)
        {
            _money.Push(val);
        }

        public void DeleteElenemtStack()
        {
            _money.Pop();
        }

        public void ShowStack()
        {
            Console.WriteLine("**********************************************");

            foreach (var kvp in _money)
            {
                Console.WriteLine(kvp);
            }

            Console.WriteLine("()()()()()()()()()()()");
            Console.WriteLine(_money.Count+"---------------");
            int leng = _money.Count;
            for (int i=0;i<leng;i++)
            {
                Console.WriteLine(_money.Pop());
                
            }


            Console.WriteLine("**********************************************");
        }


        #endregion

        #region Set
       public HashSet<int> _setage;
        public void CreateSet()
        {
            _setage = new HashSet<int>();
        }

        public void AddSetElenemt(int value)
        {
            _setage.Add(value);
        }

        public void ShowSet()
        {
            Console.WriteLine("**********************************************");
            int leng = _setage.Count;
            foreach(var s in _setage)
            {
                Console.WriteLine(s);
            }



            Console.WriteLine("**********************************************");
        }


        #endregion

        #region 使用LINQ访问集合

        //public void show()
        //{
        //    var subset = from list in m_list
        //                 where list

        //}


        #endregion

    }

    class Program
    {
        static void Main(string[] args)
        {
            CTest test = new CTest();
            //test.CreateList();
            //test.ShowList();
            //test.DeleteListElentment();
            //test.ShowList();


            //// dict
            //test.CreateDictionary();

            //for(int i=0;i<20;i++)
            //{
            //    test.AddDictionaryOlder("ad"+i, 89+i);

            //}


            //test.Older["ad3"] = 100;

            //test.ShowDictionaryOlder("ad");
            //test.DeleteDictElenmentOlder();
            //test.ShowDictionaryOlder("ad");


            //test.CreateQueue();
            //for(int i=0;i<10;i++)
            //{
            //    test.AddQueueElenment(i * 2);
            //}

            //test.ShowQueue();
            //test.ShowQueue();



            //test.CrateStack();
            //for (int i = 0; i < 20; i++)
            //{
            //    test.AddStackElenemt(i);
            //}

            //test.ShowStack();

            test.CreateSet();
            for(int i=0;i<20;i++)
            {
                test.AddSetElenemt(i);
            }

            test.AddSetElenemt(10);
            test.AddSetElenemt(10);

            test.AddSetElenemt(10);
            test.ShowSet();
            test._setage.Remove(10);
            test.ShowSet();

        }
    }
}
