Console.Write("Привет! Как тебя зовут? ");
string name = Console.ReadLine();
const string abc = "dlskfjsdfjasdklfjs";
int def = 14;
Console.Clear();
Console.Write($"Hello {name}. Укажите свой год рождения: ");
int birthyear = Int32.Parse(Console.ReadLine());
Console.Clear();
Console.WriteLine($"Йоу, {name}! Тебе уже {2026 - birthyear} лет");
