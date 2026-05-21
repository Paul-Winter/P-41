namespace Урок__9._Делегаты_и_события
{
    public delegate int IntDelegate(double d);
    public delegate double AnonymousDelegateDouble(double a, double b);
    public delegate void AnonymousDelegateInt(int i);
    public delegate void AnonymousDelegateVoid();
    public class Program
    {
        //class MyDelegate : MulticastDelegate
        //{

        //}

        // модификатор_доступа delegate тип_данных ИмяДелегата(параметры);

        // модификатор_доступа event ИмяДелегата ИмяСобытия;

        // модификатор_доступа delegate(параметры) { выполняемый код; }

        delegate void VoidDelegate(int i);

        static void Main(string[] args)
        {
            // anonymous methods
            Dispatcher dispatcher = new Dispatcher();
            dispatcher.eventDouble += delegate (double a, double b)
            {
                if (b != 0)
                {
                    return a / b;
                }
                throw new DivideByZeroException();
            };
            double x = 5.7, y = 3.2;
            int n = 5;
            Console.WriteLine($"{x} / {y} = {dispatcher.OnEventDouble(x, y)}");
            dispatcher.eventInt += delegate (int i)
            {
                Console.WriteLine($"{n} + {i} = {n + i}");
            };
            dispatcher.OnEventInt(7);

            // event
            Student[] group = new Student[]
            {
                new Student
                {
                    FirstName = "Артём Романович",
                    LastName = "Бочаров",
                    BirthDate = new DateTime(2009, 12, 11)
                },
                new Student
                {
                    FirstName = "Эдуард Захарович",
                    LastName = "Газарян",
                    BirthDate = new DateTime(2009, 05, 06)
                },
                new Student
                {
                    FirstName = "Анастасия Владимировна",
                    LastName = "Дымочкина",
                    BirthDate = new DateTime(2008, 07, 21)
                },
                new Student
                {
                    FirstName = "Илья Сергеевич",
                    LastName = "Лобозев",
                    BirthDate = new DateTime(2009, 07, 30)
                }
            };
            Teacher teacher = new Teacher();
            foreach (Student student in group)
            {
                teacher.examEvent += student.Exam;
            }
            teacher.Exam("экзаменационный билет");

            // multicast delegate
            Calculator calc = new Calculator();
            CalcDelegate delAll = null;
            CalcDelegate delDiv = calc.Div;
            delAll += calc.Sum;
            delAll += delDiv;
            delAll += calc.Mul;
            delAll += calc.Sub;
            foreach (CalcDelegate item in delAll.GetInvocationList())
            {
                try
                {
                    Console.WriteLine($"Результат: {item(5.7, 3.2)}");
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Ошибка: {ex.Message}");
                }
            }

            // delegate
            while (true)
            {
                Calculator calculator = new Calculator();
                Console.Write("Введите выражение (например: X+Y): ");
                string expression = Console.ReadLine();
                char operation = ' ';
                if (String.IsNullOrEmpty(expression))
                {
                    return;
                }
                foreach (char item in expression)
                {
                    if (item == '+' || item == '-' || item == '*' || item == '/')
                    {
                        operation = item;
                        break;
                    }
                }
                //Console.WriteLine($"Вы ввели {operation} операцию");
                try
                {
                    string[] numbers = expression.Split(operation);
                    double a = Double.Parse(numbers[0]);
                    double b = Double.Parse(numbers[1]);
                    CalcDelegate calcDel = null;
                    switch (operation)
                    {
                        case '+': calcDel = new CalcDelegate(calculator.Sum); break;
                        case '-': calcDel = new CalcDelegate(calculator.Sub); break;
                        case '*': calcDel = new CalcDelegate(calculator.Mul); break;
                        case '/': calcDel = new CalcDelegate(calculator.Div); break;
                        default: throw new InvalidOperationException();
                    }
                    Console.WriteLine($"Результат: {calcDel(a, b)}");
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Ошибка: {ex.Message}");
                }
            }
        }
    }
}
