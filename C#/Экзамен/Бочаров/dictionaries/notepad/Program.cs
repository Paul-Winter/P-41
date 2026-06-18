using System;
using System.Collections.Generic;
using System.Text;

namespace DictionaryApplication
{
    class Program
    {
        static List<TranslationDictionary> dictionaries = new List<TranslationDictionary>();

        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            Console.InputEncoding = Encoding.UTF8;
            Console.WriteLine($"Точный путь к базе данных: {Path.GetFullPath("Dictionaries")}");
            Console.ReadKey();

            AuthManager.Initialize();
            dictionaries = StorageManager.LoadDictionaries();
            MainMenu();
        }

        static void MainMenu()
        {
            while (true)
            {
                Console.Clear();
                Console.WriteLine($"        ЦЕНТРАЛЬНОЕ МЕНЮ СИСТЕМЫ «СЛОВАРИ» | СЕССИЯ: {AuthManager.CurrentUser.Username.ToUpper()}       ");
                Console.WriteLine("1. Отобразить список доступных словарей");
                Console.WriteLine("2. Создать новый словарь");
                Console.WriteLine("3. Завершить работу приложения");
                Console.Write("\nВыберите пункт меню: ");

                string choice = Console.ReadLine();

                switch (choice)
                {
                    case "1":
                        SelectDictionaryMenu();
                        break;
                    case "2":
                        CreateDictionary();
                        break;
                    case "3":
                        StorageManager.SaveDictionaries(dictionaries);
                        return;
                    default:
                        Console.WriteLine("Ошибка: некорректный выбор. Нажмите любую клавишу для повтора...");
                        Console.ReadKey();
                        break;
                }
            }
        }

        static void CreateDictionary()
        {
            Console.Clear();
            Console.WriteLine("     СОЗДАНИЕ НОВОГО СЛОВАРЯ         ");
            Console.Write("Укажите тип словаря (например, Англо-Русский): ");
            string type = Console.ReadLine().Trim();

            if (string.IsNullOrEmpty(type))
            {
                Console.WriteLine("Ошибка: тип словаря не может быть пустым.");
                Console.ReadKey();
                return;
            }

            dictionaries.Add(new TranslationDictionary(type));
            StorageManager.SaveDictionaries(dictionaries);
            Console.WriteLine("Словарь успешно создан и сохранен в базе данных.");
            Console.ReadKey();
        }

        static void SelectDictionaryMenu()
        {
            while (true)
            {
                Console.Clear();
                Console.WriteLine("     СПИСОК ДОСТУПНЫХ СЛОВАРЕЙ       ");
                if (dictionaries.Count == 0)
                {
                    Console.WriteLine("Информационные данные отсутствуют. Словари не найдены.");
                }
                else
                {
                    for (int i = 0; i < dictionaries.Count; i++)
                    {
                        Console.WriteLine($"{i + 1}. {dictionaries[i].Type}");
                    }
                }
                Console.WriteLine("0. Вернуться в главное меню");

                Console.Write("\nВыберите номер словаря для последующей работы: ");
                string choice = Console.ReadLine();

                if (choice == "0") return;

                if (int.TryParse(choice, out int index) && index > 0 && index <= dictionaries.Count)
                {
                    DictionaryOperationsMenu(dictionaries[index - 1]);
                }
                else
                {
                    Console.WriteLine("Ошибка: введенный индекс не существует в системе.");
                    Console.ReadKey();
                }
            }
        }

        static void DictionaryOperationsMenu(TranslationDictionary dict)
        {
            while (true)
            {
                Console.Clear();
                Console.WriteLine($"        УПРАВЛЕНИЕ СЛОВАРЕМ:      {dict.Type}");
                Console.WriteLine("1. Просмотр всех зарегистрированных записей");
                Console.WriteLine("2. Добавить слово и варианты его перевода");
                Console.WriteLine("3. Корректировать слово или существующий перевод");
                Console.WriteLine("4. Удалить слово или отдельный вариант перевода");
                Console.WriteLine("5. Поиск перевода заданного слова");
                Console.WriteLine("6. Экспорт слова и вариантов перевода в файл");
                Console.WriteLine("0. Вернуться в предыдущее меню выбора");
                Console.Write("\nВыберите необходимое действие: ");

                string choice = Console.ReadLine();

                switch (choice)
                {
                    case "1": ShowAllWords(dict); break;
                    case "2": AddWordAndTranslation(dict); break;
                    case "3": ReplaceWordOrTranslation(dict); break;
                    case "4": DeleteWordOrTranslation(dict); break;
                    case "5": FindTranslation(dict); break;
                    case "6": ExportWordToFile(dict); break;
                    case "0": return;
                    default:
                        Console.WriteLine("Ошибка: выбран неустановленный пункт меню.");
                        Console.ReadKey();
                        break;
                }
            }
        }

        static void ShowAllWords(TranslationDictionary dict)
        {
            Console.Clear();
            Console.WriteLine($"        СОДЕРЖИМОЕ СЛОВАРЯ:      {dict.Type} ");
            if (dict.Words.Count == 0)
            {
                Console.WriteLine("Данный словарь не содержит информационных записей.");
            }
            else
            {
                foreach (var pair in dict.Words)
                {
                    Console.WriteLine($"{pair.Key} -> {string.Join(", ", pair.Value)}");
                }
            }
            Console.WriteLine("\nДля продолжения нажмите любую клавишу...");
            Console.ReadKey();
        }

        static void AddWordAndTranslation(TranslationDictionary dict)
        {
            Console.Clear();
            Console.WriteLine("     РЕГИСТРАЦИЯ НОВОЙ ЗАПИСИ        ");
            Console.Write("Введите исходное слово: ");
            string word = Console.ReadLine().Trim().ToLower();

            if (string.IsNullOrEmpty(word)) return;

            Console.Write("Введите вариант перевода: ");
            string translation = Console.ReadLine().Trim().ToLower();

            if (string.IsNullOrEmpty(translation)) return;

            if (dict.Words.ContainsKey(word))
            {
                if (!dict.Words[word].Contains(translation))
                {
                    dict.Words[word].Add(translation);
                    Console.WriteLine("Уведомление: Вариант перевода успешно добавлен к существующему объекту.");
                }
                else
                {
                    Console.WriteLine("Предупреждение: Данный вариант перевода уже зарегистрирован в системе.");
                }
            }
            else
            {
                dict.Words.Add(word, new List<string> { translation });
                Console.WriteLine("Уведомление: Слово и первый вариант перевода успешно зафиксированы.");
            }

            StorageManager.SaveDictionaries(dictionaries);
            Console.ReadKey();
        }

        static void ReplaceWordOrTranslation(TranslationDictionary dict)
        {
            Console.Clear();
            Console.WriteLine("         МОДИФИКАЦИЯ ДАННЫХ       ");
            Console.WriteLine("1. Изменить исходное слово");
            Console.WriteLine("2. Изменить существующий вариант перевода");
            Console.Write("Выберите режим работы: ");
            string mode = Console.ReadLine();

            if (mode == "1")
            {
                Console.Write("Введите слово, подлежащее замене: ");
                string oldWord = Console.ReadLine().Trim().ToLower();

                if (dict.Words.TryGetValue(oldWord, out List<string> translations))
                {
                    Console.Write("Введите новое значение для данного слова: ");
                    string newWord = Console.ReadLine().Trim().ToLower();

                    if (!string.IsNullOrEmpty(newWord) && !dict.Words.ContainsKey(newWord))
                    {
                        dict.Words.Remove(oldWord);
                        dict.Words.Add(newWord, translations);
                        Console.WriteLine("Уведомление: Исходное слово успешно модифицировано.");
                        StorageManager.SaveDictionaries(dictionaries);
                    }
                    else
                    {
                        Console.WriteLine("Ошибка: новое значение пусто или дублирует существующее.");
                    }
                }
                else
                {
                    Console.WriteLine("Ошибка: указанный объект не найден в текущем словаре.");
                }
            }
            else if (mode == "2")
            {
                Console.Write("Введите исходное слово: ");
                string word = Console.ReadLine().Trim().ToLower();

                if (dict.Words.TryGetValue(word, out List<string> translations))
                {
                    Console.WriteLine("Зарегистрированные варианты перевода:");
                    for (int i = 0; i < translations.Count; i++)
                    {
                        Console.WriteLine($"{i + 1}. {translations[i]}");
                    }

                    Console.Write("Выберите порядковый номер для проведения замены: ");
                    if (int.TryParse(Console.ReadLine(), out int idx) && idx > 0 && idx <= translations.Count)
                    {
                        Console.Write("Введите измененный вариант перевода: ");
                        string newTrans = Console.ReadLine().Trim().ToLower();

                        if (!string.IsNullOrEmpty(newTrans))
                        {
                            translations[idx - 1] = newTrans;
                            Console.WriteLine("Уведомление: Перевод успешно скорректирован.");
                            StorageManager.SaveDictionaries(dictionaries);
                        }
                    }
                    else
                    {
                        Console.WriteLine("Ошибка: индекс указан неверно.");
                    }
                }
                else
                {
                    Console.WriteLine("Ошибка: указанное слово не обнаружено.");
                }
            }
            Console.ReadKey();
        }

        static void DeleteWordOrTranslation(TranslationDictionary dict)
        {
            Console.Clear();
            Console.WriteLine("     УДАЛЕНИЕ ИНФОРМАЦИОННЫХ СТРУКТУР        ");
            Console.WriteLine("1. Удалить слово целиком (включая все переводы)");
            Console.WriteLine("2. Удалить конкретный вариант перевода");
            Console.Write("Выберите режим удаления: ");
            string mode = Console.ReadLine();

            Console.Write("Введите целевое слово: ");
            string word = Console.ReadLine().Trim().ToLower();

            if (!dict.Words.TryGetValue(word, out List<string> translations))
            {
                Console.WriteLine("Ошибка: объект отсутствует в базе данных.");
                Console.ReadKey();
                return;
            }

            if (mode == "1")
            {
                dict.Words.Remove(word);
                Console.WriteLine("Уведомление: Слово и все связанные с ним переводы удалены.");
                StorageManager.SaveDictionaries(dictionaries);
            }
            else if (mode == "2")
            {
                if (translations.Count <= 1)
                {
                    Console.WriteLine("Отказ в выполнении операции: невозможно удалить единственный вариант перевода.");
                }
                else
                {
                    Console.WriteLine("Доступные переводы:");
                    for (int i = 0; i < translations.Count; i++)
                    {
                        Console.WriteLine($"{i + 1}. {translations[i]}");
                    }

                    Console.Write("Выберите номер варианта для удаления: ");
                    if (int.TryParse(Console.ReadLine(), out int idx) && idx > 0 && idx <= translations.Count)
                    {
                        translations.RemoveAt(idx - 1);
                        Console.WriteLine("Уведомление: Выбранный вариант перевода успешно ликвидирован.");
                        StorageManager.SaveDictionaries(dictionaries);
                    }
                    else
                    {
                        Console.WriteLine("Ошибка: некорректный ввод индекса.");
                    }
                }
            }
            Console.ReadKey();
        }

        static void FindTranslation(TranslationDictionary dict)
        {
            Console.Clear();
            Console.WriteLine("     ИНФОРМАЦИОННЫЙ ПОИСК        ");
            Console.Write("Введите искомое слово: ");
            string word = Console.ReadLine().Trim().ToLower();

            if (dict.Words.TryGetValue(word, out List<string> translations))
            {
                Console.WriteLine($"Результат выполнения запроса: {word} -> {string.Join(", ", translations)}");
            }
            else
            {
                Console.WriteLine("Уведомление: Соответствия для данного слова не обнаружены.");
            }
            Console.ReadKey();
        }

        static void ExportWordToFile(TranslationDictionary dict)
        {
            Console.Clear();
            Console.WriteLine("     ЭКСПОРТ ДАННЫХ       ");
            Console.Write("Введите слово для осуществления экспорта: ");
            string word = Console.ReadLine().Trim().ToLower();

            if (dict.Words.TryGetValue(word, out List<string> translations))
            {
                ExportManager.ExportWord(word, translations, dict.Type);
                Console.WriteLine($"Уведомление: Операция завершена. Данные выгружены в текстовый файл.");
            }
            else
            {
                Console.WriteLine("Ошибка: Данное слово отсутствует. Экспорт отклонен.");
            }
            Console.ReadKey();
        }
    }
}