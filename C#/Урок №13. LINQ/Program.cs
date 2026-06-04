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

            string[] poemS = {
                "All the world`s a stage,",
                "And all the men and women merely players;",
                "They have their exists and their entrances,",
                "And one man in his time plays many parts,",
                "His acts being seven ages..."
            };

            string[] poemP =
            {
                "Я помню чудное мгновенье:",
                "Передо мной явилась ты,",
                "Как мимолётное виденье,",
                "Как гений чистой красоты",
                "В томленьях грусти безнадежной,",
                "В тревогах шумной суеты,",
                "Звучал мне долго голос нежный",
                "И снились милые черты..."
            };

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

            IEnumerable<string> qPS = from p in poemS
                                     let words = p.Split(' ', ';', ',', '.', ':')
                                     from w in words
                                     where w.Count() >= 5
                                     select w;
            IEnumerable<string> qPP = from p in poemP
                                      let words = p.Split(' ', ';', ',', '.', ':')
                                      from w in words
                                      where w.Count() > 5
                                      select w;
            Console.WriteLine("\n\nСлова с 5 и более буквами:");
            foreach (string item in qPS)
            {
                Console.WriteLine($"\t{item}");
            }
            Console.WriteLine("\n\nСлова с более 5 буквами:");
            foreach (string item in qPP)
            {
                Console.WriteLine($"\t{item}");
            }

            List<Group> groups = new List<Group>
            {
                new Group {Id = 1, Name = "П-12"},
                new Group {Id = 2, Name = "ПВ-311"},
                new Group {Id = 3, Name = "П-41"}
            };
            List<Student> students = new List<Student>
            {
                new Student { FirstName = "Артём Романович", LastName = "Бочаров", GroupId = 3},
                new Student { FirstName = "Эдуард Захарович", LastName = "Газарян", GroupId = 3},
                new Student { FirstName = "Анастасия Владимировна", LastName = "Дымочкина", GroupId = 3},
                new Student { FirstName = "Илья Сергеевич", LastName = "Лобозев", GroupId = 3},
                new Student { FirstName = "Денис Евгеньевич", LastName = "Беляев", GroupId = 2},
                new Student { FirstName = "Павел Дмитриевич", LastName = "Кордуков", GroupId = 1},
                new Student { FirstName = "Филипп Эдуардович", LastName = "Тупольский", GroupId = 1},
            };

            IEnumerable<Student> queryA = from g in groups
                                         join st in students on g.Id equals st.GroupId into result
                                         from r in result
                                         select r;
            Console.WriteLine("\n\nСтуденты в группах (вариант А):");
            foreach (Student item in queryA)
            {
                Console.WriteLine($"Фамилия: {item.LastName},\tИмя: {item.FirstName},\t" +
                    $"Группа: {groups.First(g => g.Id == item.GroupId).Name}");
            }
            Console.WriteLine("\n\nСтуденты в группах (вариант Б):");
            var queryB = from g in groups
                         join st in students on g.Id equals st.GroupId
                         select new { FirstName = st.FirstName,
                                      LastName = st.LastName,
                                      GroupName = g.Name };
            foreach (var item in queryB)
            {
                Console.WriteLine($"Фамилия: {item.LastName},\tИмя: {item.FirstName},\tГруппа: {item.GroupName}");
            }
        }
    }
}
