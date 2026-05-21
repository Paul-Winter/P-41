namespace Урок__9._Делегаты_и_события
{
    public delegate int IntDelegate(double d);
    public class Program
    {
        //class MyDelegate : MulticastDelegate
        //{

        //}

        // модификатор_доступа delegate тип_данных ИмяДелегата(параметры);

        delegate void VoidDelegate(int i);

        static void Main(string[] args)
        {
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
