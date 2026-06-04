namespace Урок__13._LINQ
//  LINQ - Language INtegrated Query - язык интегрированных запросов
//
//  LINQ to DataSet         -   работает с данными из DataSet
//  LINQ to XML             -   работает с данными из файлов XML
//  LINQ to Sql             -   работает с данными из MS SQL Server
//  LINQ to Entities        -   работает с технологией Entity Framework
//  Parallel LINQ (PLINQ)   -   для выполнения параллельных запросов
//  LINQ to Object          -   работает с данными из различных коллекций

//  запрос:
//  результат = from имя_переменной
//              in источник_данных
//              where условие
//              orderby имя_переменной вид_сортировки (ascending/descending)
//              select имя_переменной;
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] arr1 = { 5, 34, 67, 12, 98, 48, 94, 42, 88, 75,
                           6, 43, 76, 21, 89, 84, 49, 24, 44, 57 };
            IEnumerable<int> query1 = from i
                                      in arr1
                                      select i;
            IEnumerable<int> query2 = from i
                                      in arr1
                                      where i % 2 == 0
                                      select i;
            IEnumerable<int> query3 = from i
                                      in arr1
                                      where i % 2 == 0
                                      orderby i ascending
                                      select i;
            IEnumerable<IGrouping<int, int>> query4 = from i
                                                      in arr1
                                                      group i by i % 10;
            IEnumerable<IGrouping<int, int>> query5 = from i
                                                      in arr1
                                                      group i by i % 10 into result
                                                      where result.Count() > 2
                                                      select result;

            Console.WriteLine("\nМассив до изменения:");
            foreach (int item in query1)
            {
                Console.Write($"{item} ");
            }
            arr1[0] = 25;
            Console.WriteLine("\nМассив после изменения:");
            foreach (int item in query1)
            {
                Console.Write($"{item} ");
            }
            Console.WriteLine("\nРезультат запроса с фильтрацией:");
            foreach (int item in query2)
            {
                Console.Write($"{item} ");
            }
            Console.WriteLine("\nРезультат запроса с фильтром и сортировкой:");
            foreach (int item in query3)
            {
                Console.Write($"{item} ");
            }
            Console.WriteLine("\nРезультат запроса группировки:");
            foreach (IGrouping<int, int> item in query4)
            {
                Console.Write($"Key: {item.Key}\tValue: ");
                {
                    foreach (int i in item)
                    {
                        Console.Write($"{i}\t");
                    }
                    Console.WriteLine();
                }
            }
            Console.WriteLine("\nРезультат запроса группировки с промежуточным сохранением результатов:");
            foreach (IGrouping<int, int> item in query5)
            {
                Console.Write($"Key: {item.Key}\tValue: ");
                {
                    foreach (int i in item)
                    {
                        Console.Write($"{i}\t");
                    }
                    Console.WriteLine();
                }
            }
        }
    }
}
