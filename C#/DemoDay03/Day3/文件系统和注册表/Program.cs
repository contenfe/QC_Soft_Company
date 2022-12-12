using System;
using System.Collections.Generic;
using System.IO;
namespace 文件系统和注册表
{
    class CDrivInfo
    {
        /// <summary>
        /// 获取所有盘符
        /// </summary>
        public static void GetAllDrivInfo()
        {

            try
            {
                // 
                DriveInfo[] drives = DriveInfo.GetDrives();
                foreach (var d in drives)
                {
                    if(!d.IsReady)
                    {
                        
                    }
                    Console.WriteLine($"d.Name:\t{d.Name}\n" +
                        $"d.DriveType:\t{d.DriveType}\n" +
                        $"d.IsReady:\t{d.IsReady}\n" +
                        $"d.VolumeLabel:\t{d.VolumeLabel}\n" +
                        $"d.RootDirectory:\t{d.RootDirectory}\n" +
                        $"d.DriveFormat:\t{d.DriveFormat}\n" +
                        $"d.AvailableFreeSpace:\t{d.AvailableFreeSpace} \n" +
                        $"d.TotalFreeSpace:\t{d.TotalFreeSpace}\n " +
                        $"d.TotalSize:\t{d.TotalSize}\n" +
                        $"d.TotalFreeSpace:\t{d.TotalFreeSpace}\n");
                    

                }
            }
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }

        /// <summary>
        /// 获取指定盘符
        /// </summary>
        /// <param name="flag"></param>
        public static void GetDrivInfo(string flag)
        {
            DriveInfo info  = new DriveInfo(flag);

            Console.WriteLine($"info:\t{info.VolumeLabel}");

        }


        /// <summary>
        /// 获取目录
        /// </summary>
        /// <param name="args"></param>
        public static void GetAllDirectory()
        {
            string curdir = Directory.GetCurrentDirectory();        // 获取当前目录,(bin/debug/)
            Console.WriteLine(curdir);
            
            try
            {
                Directory.CreateDirectory("res");
                Directory.CreateDirectory("obj/res/t/");

                if(Directory.Exists("obj/res32"))
                {
                    Console.WriteLine("asd");
                }

                // 创建快捷
                //Directory.CreateSymbolicLink("C:/Windows/", Directory.GetCurrentDirectory());

                // 删除文件夹
                Directory.Delete("obj/res/t");

                // 返回指定路径中的目录完整名称的可枚举集合。
                List<string> listdir =  new List<string>(Directory.EnumerateDirectories("E:\\qindao"));
                Console.WriteLine("****************List Directory.EnumerateDirectories******************");
                foreach(var str in listdir)
                {
                    Console.WriteLine(str);
                }
                Console.WriteLine("****************end Directory.EnumerateDirectories******************");

                // 返回满足指定条件的完整文件名的可枚举集合
                // E:\qindao\C++\C++爬虫\src\项目
                List<string> listfile = new List<string>(Directory.EnumerateFiles(@"E:\qindao", "*.cpp",SearchOption.AllDirectories));
                Console.WriteLine("****************List Directory.EnumerateFiles******************");
                foreach (var str in listfile)
                {
                    Console.WriteLine(str);
                }
                Console.WriteLine("****************end Directory.EnumerateFiles******************");

                // 返回满足指定条件的文件系统项的可枚举集合。
                // 有问题
                List<string> listfilesystem = new List<string>(Directory.EnumerateFileSystemEntries(@"E:\qindao\C++\C++爬虫\src\项目", ".h"));
                Console.WriteLine("****************List Directory.EnumerateFileSystemEntries******************");
                foreach (var str in listfilesystem)
                {
                    Console.WriteLine(str);
                }
                Console.WriteLine("****************end Directory.EnumerateFileSystemEntries******************");

                // 获取目录
                List<string> listAllDirectory = new List<string>(Directory.GetDirectories(@"E:\qindao"));
                Console.WriteLine("****************List Directory.GetDirectories******************");
                foreach (var str in listAllDirectory)
                {
                    Console.WriteLine(str);
                }
                Console.WriteLine("****************end Directory.GetDirectories******************");



            }
            catch (DirectoryNotFoundException e)
            {
                Console.WriteLine(e.Message);
            }
                    

        }


        /// <summary>
        /// 创建文件
        /// </summary>
        /// <param name="args"></param>
        public static void GetText()
        {
            using (StreamWriter sw = File.CreateText($"{Directory.GetCurrentDirectory()}/it.txt"))
            {
                sw.WriteLine("asdfasd");
                sw.WriteLine("八大搭嘎大量达克赛德");
            }



            using StreamWriter sw1 = File.AppendText($"{Directory.GetCurrentDirectory()}/it.txt");
            
                sw1.WriteLine("太空人hello world");
                sw1.WriteLine("阿斯顿发发宇航员");
            sw1.WriteLine("终结技能");




            //FileStream file = File.OpenWrite($"{Directory.GetCurrentDirectory()}/it.txt");
            //file.Write("下发送到发送到");

        }


        /// <summary>
        /// 注册表
        /// </summary>
        /// <param name="args"></param>
        public static void SetRegedit()
        {
            //Microsoft.Win32.
        }



        static void Main(string[] args)
        {

            GetText();
            Console.WriteLine("\n****************************\n文件夹：\n***********************");
            GetAllDirectory();
            Console.WriteLine("\n****************************\n驱动器：\n***********************");
            GetAllDrivInfo();
            GetDrivInfo("E");
        }
    }
}
