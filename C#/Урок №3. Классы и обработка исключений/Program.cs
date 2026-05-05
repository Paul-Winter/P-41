using ClassLibrary;

namespace Урок__3._Классы_и_обработка_исключений
{
    public class Program
    {        
        public Lesson les = new Lesson();
        public Classwork work;
        public StudentClass sClass = new StudentClass();
        public StudentStruct sStruct;
        public static StudentStruct stud;

        public static void Main(string[] args)
        {
            Console.WriteLine("Hello from Program!");
            Console.WriteLine(Lesson.name);
            Lesson.name = "Исключения";
            Console.WriteLine($"Название занятия изменилось на {Lesson.name}");

            Program proga = new Program();
            proga.NonStaticMain();
            Console.WriteLine("изменяем номер занятия");
            proga.ChangeNumber();
            proga.NonStaticMain();

            Console.WriteLine("_____________________________________");
            proga.ShowStudentsAge();
            proga.ChangeAgeClass();
            proga.ChangeAgeStruct(stud);
            proga.ShowStudentsAge();
            Console.WriteLine("_____________________________________");

            ClassLibrary.ClassPublic cp = new ClassLibrary.ClassPublic();
            Calculator calc = new Calculator();            
            Console.WriteLine($"Calc.Sum(1,2) = {calc.Sum(1,2)}");
            Console.WriteLine($"Calc.Sum(1,2,3) = {calc.Sum(1,2,3)}");
            Console.WriteLine($"Calc.Sum(1.1,2.2) = {calc.Sum(1.1,2.2)}");
            Console.WriteLine("_____________________________________");
            while (true)
            {
                try
                {
                    Console.Write("Введите первое число: ");
                    int first = Int32.Parse(Console.ReadLine());
                    Console.Write("Введите второе число: ");
                    int second = Int32.Parse(Console.ReadLine());
                    Console.Write("Введите знак операции (+,-,*,/): ");
                    char operation = Char.Parse(Console.ReadLine());
                    switch (operation)
                    {
                        case '+':
                            Console.WriteLine($"Sum({first},{second}) = {calc.Sum(first, second)}");
                            break;
                        case '-':
                            Console.WriteLine($"Sub({first},{second}) = {calc.Sub(first, second)}");
                            break;
                        case '*':
                            Console.WriteLine($"Mul({first},{second}) = {calc.Mul(first, second)}");
                            break;
                        case '/':
                            Console.WriteLine($"Div({first},{second}) = {calc.Div(first, second)}");
                            break;
                        default:
                            Console.WriteLine($"Вы ввели недопустимую операцию для чисел: {first},{second}");
                            break;
                    }
                }
                catch (DivideByZeroException ex)
                {
                    Console.WriteLine("Была выявлена попытка деления на ноль!");
                }
                catch (FormatException ex)
                {
                    Console.WriteLine("Ошибка! Неверный ввод!!!");
                }
                catch (Exception ex)
                {
                    Console.WriteLine("Произошла непредусмотренная программистом ошибка!");
                }
            }
        }

        public int ChangeAgeClass()
        {
            return ++sClass.age;
        }
        public int ChangeAgeStruct(StudentStruct st)
        {
            Console.WriteLine($"изменяем значение age {++st.age}");
            return ++st.age;
        }
        public void ShowStudentsAge()
        {
            Console.WriteLine($"Student class age {sClass.age}");
            Console.WriteLine($"Student struct age {sStruct.age}");
        }
        public void NonStaticMain()
        {
            //work.number = 6;
            Console.WriteLine($"Lesson number {les.number}");
            Console.WriteLine($"Classwork number {work.number}");
        }

        public void ChangeNumber()
        {
            Console.WriteLine($"номер занятия {++work.number}");
        }

        //static int Main()
        //{
        //    return 0;
        //}
    }

    public struct Classwork
    {
        public string name;
        public int number;
    }

    //class Lesson
    //{
    //    Program proga = new Program();
    //    static void Main()
    //    {
    //        Console.WriteLine("Hello from Lesson class!");
    //    }
    //}
}
