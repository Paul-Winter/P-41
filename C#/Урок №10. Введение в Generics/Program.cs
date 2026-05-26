using System.Collections;

namespace Урок__10._Введение_в_Generics
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("_______________________Массив_______________________");
            char[] hello = new char[] { 'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!' };
            //string hello = "Hello, World!";
            Console.WriteLine(hello);
            for (int i = 0; i < hello.Length; i++)
            {
                Console.WriteLine(hello[i]);
            }

            Console.WriteLine("=======================Необобщённые_коллекции:=======================");

            Console.WriteLine("_______________________Динамический_массив_______________________");
            ArrayList arrList1 = new ArrayList();
            ArrayList arrList2 = new ArrayList(5);
            ArrayList arrList3 = new ArrayList(new int[] { 1, 4, 28, 7, 5 });
            Console.WriteLine($"Вместимость по умолчанию arrList1: {arrList1.Capacity}");
            arrList1.Add("one");
            Console.WriteLine($"Вместимость после добавления элемента в arrList1: {arrList1.Capacity}");
            arrList1.AddRange(new int[] { 2, 8, 1, 4 });
            Console.WriteLine($"Вместимость после добавления коллекции в arrList1: {arrList1.Capacity}");
            arrList1.Capacity = 10;
            Console.WriteLine($"Вместимость установлена в arrList1: {arrList1.Capacity}");
            Console.WriteLine($"Фактическое количество элементов в arrList1: {arrList1.Count}");
            arrList1.TrimToSize();
            Console.WriteLine($"Вместимость в arrList1 уменьшена до количества элементов: {arrList1.Capacity}");
            Console.WriteLine($"__________Все элементы коллекции:");
            foreach (object item in arrList1)
            {
                Console.WriteLine($"\t{item}");
            }
            Console.WriteLine($"__________Вставка нового элемента:");
            arrList1.Insert(2, "hello");
            foreach (object item in arrList1)
            {
                Console.WriteLine($"\t{item}");
            }
            Console.WriteLine($"__________Индекс элемента: {arrList1.IndexOf("hello")}");
            Console.WriteLine($"__________Удаление элемента:");
            arrList1.RemoveAt(2);
            foreach (object item in arrList1)
            {
                Console.WriteLine($"\t{item}");
            }

            ArrayList days = new ArrayList(new string[] {
                "понедельник", "вторник", "среда", "четверг", "пятница", "суббота", "воскресенье"});
            Console.WriteLine("__________Неделя:");
            foreach (object day in days)
            {
                Console.WriteLine($"День недели {day}");
            }
            ArrayList workWeek = new ArrayList(days.GetRange(0, 5));
            Console.WriteLine("__________Рабочая неделя:");
            foreach (object day in workWeek)
            {
                Console.WriteLine($"Рабочий день {day}");
            }
            ArrayList weekEnd = new ArrayList(days.GetRange(5, 2));
            Console.WriteLine("__________Выходные:");
            foreach (object day in weekEnd)
            {
                Console.WriteLine($"Выходной день {day}");
            }
            Console.WriteLine("_______________________Стек_______________________");
            Stack stack1 = new Stack();
            Stack stack2 = new Stack(7);
            Stack stack3 = new Stack(new ArrayList { 3, 8, 5 });
            Console.WriteLine("__________Push:");
            stack1.Push("one");
            stack1.Push("two");
            stack1.Push("three");
            foreach (object item in stack1)
            {
                Console.WriteLine($"{item}");
            }
            Console.WriteLine($"__________Pop: {stack1.Pop()}");
            foreach (object item in stack1)
            {
                Console.WriteLine($"{item}");
            }
            Console.WriteLine($"__________Peek: {stack1.Peek()}");
            foreach (object item in stack1)
            {
                Console.WriteLine($"{item}");
            }
            Console.WriteLine("_______________________Очередь_______________________");
            Queue q1 = new Queue();
            Queue q2 = new Queue(5);
            Queue q3 = new Queue(new ArrayList { "one", 4, 8.3 });
            Queue q4 = new Queue(7, 3.0f);
            foreach (object item in q3)
            {
                Console.WriteLine($"{item}");
            }
            Console.WriteLine($"__________Enqueue:");
            q3.Enqueue("two");
            foreach (object item in q3)
            {
                Console.WriteLine($"{item}");
            }
            Console.WriteLine($"__________Dequeue: {q3.Dequeue()}");
            Console.WriteLine($"__________Dequeue: {q3.Dequeue()}");
            foreach (object item in q3)
            {
                Console.WriteLine($"{item}");
            }

            Console.WriteLine("_______________________Хеш-таблица_______________________");
            Hashtable hash = new Hashtable();
            hash.Add(1, "John");
            hash.Add("two", 22222);
            foreach (object item in hash.Keys)
            {
                Console.WriteLine($"Ключ {item} : Значение {hash[item]}");
            }
            foreach (object item in hash.Values)
            {
                Console.WriteLine($"значение {item}");
            }
            Console.WriteLine("_______________________Сортированный_список_______________________");
            SortedList sL = new SortedList();
            sL.Add(3, 6.7);
            sL.Add(2, "two");
            sL.Add(1, "one");
            foreach (object item in sL.Keys)
            {
                Console.WriteLine($"Ключ {item} - значение {sL[item]}");
            }
            Console.WriteLine("\n\n");
            Console.WriteLine("=======================Обобщённые_коллекции:=======================");
            Console.WriteLine("_______________________Динамический_массив_______________________");
            List<int> list1 = new List<int>();
            List<double> list2 = new List<double>(5);
            List<int> list3 = new List<int>(new int[] { 1, 4, 28, 7, 5 });
            Console.WriteLine($"Вместимость по умолчанию list1: {list1.Capacity}");
            list1.Add(1);
            Console.WriteLine($"Вместимость после добавления элемента в list1: {list1.Capacity}");
            list1.AddRange(new int[] { 2, 8, 1, 4 });
            Console.WriteLine($"Вместимость после добавления коллекции в list1: {list1.Capacity}");
            list1.Capacity = 10;
            Console.WriteLine($"Вместимость установлена в list1: {list1.Capacity}");
            Console.WriteLine($"Фактическое количество элементов в list1: {list1.Count}");
            //list1.TrimToSize();
            //Console.WriteLine($"Вместимость в list1 уменьшена до количества элементов: {list1.Capacity}");
            Console.WriteLine($"__________Все элементы коллекции:");
            foreach (object item in list1)
            {
                Console.WriteLine($"\t{item}");
            }
            Console.WriteLine($"__________Вставка нового элемента:");
            list1.Insert(2, 123);
            foreach (object item in list1)
            {
                Console.WriteLine($"\t{item}");
            }
            Console.WriteLine($"__________Индекс элемента: {list1.IndexOf(123)}");
            Console.WriteLine($"__________Удаление элемента:");
            list1.RemoveAt(2);
            foreach (object item in list1)
            {
                Console.WriteLine($"\t{item}");
            }

            List<string> week = new List<string>(new string[] {
                "понедельник", "вторник", "среда", "четверг", "пятница", "суббота", "воскресенье"});
            Console.WriteLine("__________Неделя:");
            foreach (object day in days)
            {
                Console.WriteLine($"День недели {day}");
            }
            List<string> workWeek2 = new List<string>(week.GetRange(0, 5));
            Console.WriteLine("__________Рабочая неделя:");
            foreach (object day in workWeek)
            {
                Console.WriteLine($"Рабочий день {day}");
            }
            List<string> weekEnd2 = new List<string>(week.GetRange(5, 2));
            Console.WriteLine("__________Выходные:");
            foreach (object day in weekEnd)
            {
                Console.WriteLine($"Выходной день {day}");
            }
            Console.WriteLine("_______________________Словарь_______________________");
            Dictionary<string, int> dict = new Dictionary<string, int>();
            dict["D1"] = 12;
            dict.Add("D2", 10);
            dict.Add("D3", 10);
            dict.Add("D4", 6);
            foreach (KeyValuePair<string, int> item in dict)
            {
                Console.WriteLine($"Ключ {item.Key} : Значение {item.Value}");
            }
            Console.WriteLine("Изменяем значение по ключу:");
            dict["D3"] = 14;
            foreach (KeyValuePair<string, int> item in dict)
            {
                Console.WriteLine($"Ключ {item.Key} : Значение {item.Value}");
            }
            Console.WriteLine("Удаляем значение по ключу:");
            dict.Remove("D3");
            foreach (KeyValuePair<string, int> item in dict)
            {
                Console.WriteLine($"Ключ {item.Key} : Значение {item.Value}");
            }
            Console.WriteLine("=======================Создание_generics:=======================");
            Point2D<int> p1 = new Point2D<int>(1, 3);
            Point2D<double> p2 = new Point2D<double>(1.1d, 4.6d);
            Console.WriteLine($"p1 {p1}");
            Console.WriteLine($"p2 {p2}");
        }
    }

    public class Point2D<T>
    {
        public T X { get; set; }
        public T Y { get; set; }
        public Point2D(T x, T y)
        {
            X = x;
            Y = y;
        }
        public override string ToString()
        {
            return $"point {this.GetType()} {X.ToString()}:{Y.ToString()}";
        }
    }
}
