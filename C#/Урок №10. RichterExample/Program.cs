using System.Collections;
using System.Diagnostics;

namespace Урок__10._RichterExample
{
    internal class Program
    {
        static void Main(string[] args)
        {
            const int COUNT = 10000000;
            using (new OperationTimer("Необобщённая коллекция List"))
            {
                List<int> list = new List<int>(COUNT);
                for (int i = 0; i < COUNT; i++)
                {
                    list.Add(i);
                    int x = list[i];
                }
                list = null;
            }
            using (new OperationTimer("Обобщённая коллекция ArrayList"))
            {
                ArrayList arrList = new ArrayList();
                for (int i = 0; i < COUNT; i++)
                {
                    arrList.Add(i);
                    int x = (int)arrList[i];
                }
                arrList = null;
            }
        }
    }

    internal sealed class OperationTimer : IDisposable
    {
        long startTime;
        string text;
        int collectionCount;

        public OperationTimer(string text)
        {
            PrepareForOperation();
            this.text = text;
            this.collectionCount = GC.CollectionCount(0);
            this.startTime = Stopwatch.GetTimestamp();
        }
        private static void PrepareForOperation()
        {
            GC.Collect();
            GC.WaitForPendingFinalizers();
            GC.Collect();
        }
        public void Dispose()
        {
            Console.WriteLine($"{text}\n{(Stopwatch.GetTimestamp() - startTime)/(double)Stopwatch.Frequency:0.00} секунды, " +
                $"сборок мусора {GC.CollectionCount(0) - collectionCount}");
        }
    }
}
