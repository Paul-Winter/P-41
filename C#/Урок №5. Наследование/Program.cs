namespace Урок__5._Наследование
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int a = 12;
            Console.WriteLine($@"
============================================================================================
class Имя_класса_наследника : Имя_базового_класса, Имя_интерфейса1, Имя_интерфейса2...
============================================================================================
                           Hello\
                           ///{a}\\\                                
                                    \n\t
                                       \b\a\\
                                             \World!
============================================================================================");

            Child child = new Child(a);
            child.ShowChild();
            PublicParent pb = new PublicParent();
            InternalParent ip = new InternalParent();
            //Parent parent = new Parent();
        }
    }
}
