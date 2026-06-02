using System.IO;
using System.Text;

namespace Урок__12._Файловая_система
{
    internal class Program
    {
        static void Main(string[] args)
        {
            ////  FileStream
            //string filePath = "C:\\Users\\Student\\P-41\\C#\\Урок №12. Файловая система\\bin\\Debug\\net10.0";
            //string filePath = "test.bin";
            //WriteFile(filePath);
            //Console.WriteLine($"Информация из файла: {ReadFile(filePath)}");

            //// StreamWriter & StreamReader
            //string filePath = "test.txt";
            //WriteText(filePath);
            //Console.WriteLine($"Информация из файла: {ReadText(filePath)}");

            //// BinaryWriter & BinaryReader
            //string filePath = "test.dat";
            //BinaryWrite(filePath);
            //BinaryRead(filePath);

            DirectoryInfo dir = new DirectoryInfo("."); //текущая директория
            Console.WriteLine($"Полный путь к папке: {dir.FullName}");
            Console.WriteLine($"Время создания: {dir.CreationTime}");
            Console.WriteLine($"Содержит:");
            DirectoryInfo[] dirs = dir.GetDirectories();
            foreach (DirectoryInfo d in dirs)
            {
                Console.WriteLine($"DIR\t{d.Name}");
            }
            FileInfo[] files = dir.GetFiles();
            foreach (FileInfo f in files)
            {
                Console.WriteLine($"FILE\t{f.Name}");
            }

            if (!dir.Exists) //если каталог не существует
            {
                dir.Create();
            }

            //DirectoryInfo dir2 = dir.CreateSubdirectory("Subdir2");
            //Console.WriteLine("Создана подпапка Subdir2");
            //Console.WriteLine($"Полный путь к подпапке: {dir2.FullName}");
            //Console.WriteLine($"Время создания: {dir2.CreationTime}");

            string filePath = "test2.txt";
            TextWrite(filePath);
            TestRead(filePath);
        }

        #region File - работа с файлами
        static void TextWrite(string filePath)
        {
            using (StreamWriter sw = File.CreateText(filePath))
            {
                Console.WriteLine("Введите данные для записи в файл:");
                string writeText = Console.ReadLine();
                sw.WriteLine(writeText);
                Console.WriteLine("Запись проведена успешно!");
            }
        }
        static void TestRead(string filePath)
        {
            using (StreamReader sr = File.OpenText(filePath))
            {
                Console.WriteLine($"Информация из файла: {sr.ReadToEnd()}");
            }
        }
        #endregion

        #region FileStream - работа с файловыми потоками
        static void WriteFile(string filePath)
        {
            using (FileStream fs = new FileStream(filePath, FileMode.Append, FileAccess.Write, FileShare.None))
            {
                Console.WriteLine("Введите данные для записи в файл:");
                string writeText = Console.ReadLine();
                byte[] writeBytes = Encoding.Default.GetBytes(writeText);
                fs.Write(writeBytes, 0, writeBytes.Length);
                Console.WriteLine("Запись проведена успешно!");
            }
        }
        static string ReadFile(string filePath)
        {
            using (FileStream fs = new FileStream(filePath, FileMode.Open, FileAccess.Read, FileShare.Read))
            {
                byte[] readBytes = new byte[(int)fs.Length];
                fs.Read(readBytes, 0, readBytes.Length);
                return Encoding.Default.GetString(readBytes);
            }
        }
        #endregion

        #region StreamWriter StreamReader - работа с потоками записи/чтения
        static void WriteText(string filePath)
        {
            using (FileStream fs = new FileStream(filePath, FileMode.Append))
            {
                using (StreamWriter sw = new StreamWriter(fs, Encoding.Unicode))
                {
                    Console.WriteLine("Введите данные для записи в файл:");
                    string writeText = Console.ReadLine();
                    sw.WriteLine(writeText);
                    Console.WriteLine("Запись проведена успешно!");
                }
            }
        }
        static string ReadText(string filePath)
        {
            using (FileStream fs = new FileStream(filePath, FileMode.Open))
            {
                using (StreamReader sw = new StreamReader(fs, Encoding.Unicode))
                {
                    return sw.ReadToEnd();
                }
            }
        }
        #endregion

        #region BinaryWriter BinaryReader - работа с бинарными потоками
        static void BinaryWrite(string filePath)
        {
            using (FileStream fs = new FileStream(filePath, FileMode.OpenOrCreate))
            {
                using (BinaryWriter bw = new BinaryWriter(fs, Encoding.Unicode))
                {
                    Console.WriteLine("Введите данные для записи в файл:");
                    string writeText = Console.ReadLine();
                    double pi = 3.1415926d;
                    int num = 123456789;
                    bw.Write(writeText);
                    bw.Write(pi);
                    bw.Write(num);
                    Console.WriteLine("Запись проведена успешно!");
                }
            }
        }
        static void BinaryRead(string filePath)
        {
            using (FileStream fs = new FileStream(filePath, FileMode.OpenOrCreate))
            {
                using (BinaryReader br = new BinaryReader(fs, Encoding.Unicode))
                {
                    Console.WriteLine("Информация из файла:");
                    Console.WriteLine(br.ReadString());
                    Console.WriteLine(br.ReadDouble());
                    Console.WriteLine(br.ReadInt32());
                }
            }
        }
        #endregion
    }
}
