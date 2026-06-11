using System.Reflection;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Xml.Serialization;

namespace Урок__14._Сериализация
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Console.WriteLine("Атрибуты класса Employee:");
            //foreach (var attr in typeof(Employee).GetCustomAttributes(true))
            //{
            //    Console.WriteLine(attr);
            //}
            //Console.WriteLine("\n\nАтрибуты членов класса Employee:");
            //foreach (MemberInfo info in typeof(Employee).GetMembers())
            //{
            //    foreach (var attr in info.GetCustomAttributes(true))
            //    {
            //        Console.WriteLine(attr);
            //    }
            //}

            Person person = new Person(3456987) { Name = "John Doe", Age = 34 };
            //BinaryFormatter binForm = new BinaryFormatter();
            XmlSerializer xmlForm = new XmlSerializer(typeof(Person));
            try
            {
                using (Stream fStream = File.Create("test.xml"))
                {
                    xmlForm.Serialize(fStream, person);
                }
                Console.WriteLine("Сериализация прошла успешно!");

                Person p = null;

                using (Stream fStream = File.OpenRead("test.xml"))
                {
                    p = (Person)xmlForm.Deserialize(fStream);
                }
                Console.WriteLine(p);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex);
            }
        }

        [Obsolete]
        static void SomeMethod()
        {
            Console.WriteLine("sdlkfjsad;lfja");
        }
    }
}
