#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std;

void ShowLists(list<int>& l1, list<int>& l2)
{
    // создаём итератор
    list<int>::iterator iter;

    cout << "list1: ";
    for (iter = l1.begin(); iter != l1.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << "\n____________________________________________________________" << endl;
    cout << "list2: ";
    for (iter = l2.begin(); iter != l2.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << "\n____________________________________________________________" << endl;
}

void Show(map<string, int> con)
{
    for (map<string, int>::const_iterator i = con.begin(); i != con.end(); ++i)
    {
        cout << i->first << '\t' << i->second << endl;
    }
}
void Show(multimap<string, int> con)
{
    for (multimap<string, int>::const_iterator i = con.begin(); i != con.end(); ++i)
    {
        cout << i->first << '\t' << i->second << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "");

#pragma region vector

    cout << "==============================vector==============================" << endl;
    // создаём объект динамического массива
    vector<int> vec;

    cout << "Ёмкость вектора: " << vec.capacity() << endl;
    cout << "____________________________________________________________" << endl;
    cout << "Количество элементов вектора: " << vec.size() << endl;
    cout << "____________________________________________________________" << endl;
    cout << "Изменяем размер вектора..." << endl;
    vec.resize(4, 0);
    cout << "____________________________________________________________" << endl;
    cout << "Количество элементов вектора: " << vec.size() << endl;
    cout << "____________________________________________________________" << endl;
    cout << "Элементы вектора: " << endl;
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << i+1 << "-й элемент вектора = " << vec[i] << endl;
    }
    cout << "____________________________________________________________" << endl;
    cout << "Максимальный размер вектора: " << vec.max_size() << " Байт" << endl;
    cout << "____________________________________________________________" << endl;
    cout << "Максимальный размер вектора: " << vec.max_size()/4 << endl;
    cout << "____________________________________________________________" << endl;
    cout << "Вставляем элемент в конец вектора..." << endl;
    vec.push_back(1);
    cout << "____________________________________________________________" << endl;
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << i + 1 << "-й элемент вектора = " << vec[i] << endl;
    }
    cout << "____________________________________________________________" << endl;
    cout << "Создаём обычный итератор и выставляем его в начало вектора..." << endl;
    vector<int>::iterator i_iter;
    cout << "Выводим содержимое вектора с помощью итератора:" << endl;
    for (i_iter = vec.begin(); i_iter != vec.end(); i_iter++)
    {
        cout << *(i_iter) << endl;
    }
    cout << "____________________________________________________________" << endl;
    cout << "Создаём реверсный итератор и выставляем его в конец вектора..." << endl;
    vector<int>::reverse_iterator r_iter;
    cout << "Выводим содержимое вектора с помощью итератора:" << endl;
    for (r_iter = vec.rbegin(); r_iter != vec.rend(); r_iter++)
    {
        cout << *(r_iter) << endl;
    }
    cout << "____________________________________________________________" << endl;
    cout << "Добавляем два элемента перед последним элементом вектора..." << endl;
    vec.insert(i_iter - 1, 2, 3);
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << i + 1 << "-й элемент вектора = " << vec[i] << endl;
    }
#pragma endregion

#pragma region list

    cout << endl << endl;
    cout << "==============================list==============================" << endl;
    // создаём объекты двунаправленного связного списка
    list<int> list1;
    list<int> list2;

    cout << "Заполняем списки значениями..." << endl;
    for (int i = 0; i < 6; i++)
    {
        list1.push_back(i);
        list2.push_front(i);
    }
    cout << "____________________________________________________________" << endl;
    cout << "Выводим списки:" << endl;
    ShowLists(list1, list2);
    cout << "В первом списке перемещаем первый элемент в конец..." << endl;
    list1.splice(list1.end(),   // позиция в приёмнике
                 list1,         // источник
                 list1.begin());// позиция в источнике
    ShowLists(list1, list2);
    cout << "Во втором списке перемещаем первый элемент в конец..." << endl;
    list2.splice(list2.end(),   // позиция в приёмнике
                 list2,         // источник
                 list2.begin());// позиция в источнике
    ShowLists(list1, list2);
    cout << "Разворачиваем первый список..." << endl;
    list1.reverse();
    cout << "____________________________________________________________" << endl;
    ShowLists(list1, list2);
    cout << "Сортируем оба списка..." << endl;
    list1.sort();
    list2.sort();
    cout << "____________________________________________________________" << endl;
    ShowLists(list1, list2);
    cout << "Сливаем два списка в первый..." << endl;
    list1.merge(list2);
    cout << "____________________________________________________________" << endl;
    ShowLists(list1, list2);
    cout << "Удаляем дубликаты из первого списка..." << endl;
    list1.unique();
    cout << "____________________________________________________________" << endl;
    ShowLists(list1, list2);

#pragma endregion

#pragma region map

    cout << endl << endl;
    cout << "==============================map==============================" << endl;

    map<int, int> my_map;
    vector<int> my_vect;

    cout << "\nМаксимальный размер vector:\t" << my_vect.max_size() / sizeof(int) << endl;
    cout << "Максимальный размер map:\t" << my_map.max_size() / sizeof(int) << endl;
    cout << "____________________________________________________________" << endl;

    int key, key2;
    int value, value2;

    cout << "\nВведите значение: ";
    cin >> value;
    cout << "Введите ключ: ";
    cin >> key;

    pair<int, int> elem(key, value);
    my_map.insert(elem);
    cout << "Количество элементов в словаре: " << my_map.size() << endl;
    cout << "____________________________________________________________" << endl;

    //pair<int, int> second(1, 123456);
    cout << "\nВведите значение: ";
    cin >> value2;
    cout << "Введите ключ: ";
    cin >> key2;

    pair<map<int, int>::iterator, bool> error = my_map.insert(make_pair(key2, value2));
    if (!error.second)
    {
        cout << "Ошибка!!! Ключ уже существует!" << endl;
    }

    cout << "Количество элементов в словаре: " << my_map.size() << endl;
    cout << "____________________________________________________________" << endl;
    //map<string, map<string, bool>>

#pragma endregion

#pragma region multimap

    cout << endl << endl;
    cout << "==============================multimap==============================" << endl;
    
    map<string, int> cont1;
    multimap<string, int> cont2;

    cont1.insert(pair<string, int>("Иванов", 10));
    cont1.insert(pair<string, int>("Петров", 20));
    cont1["Сидоров"] = 30;

    cout << "Содержимое отображения:" << endl;
    Show(cont1);
    cout << "____________________________________________________________" << endl;

    cout << "Изменяем значение по ключу (Иванову - 50)..." << endl;
    cont1["Иванов"] = 50;
    Show(cont1);
    cout << "____________________________________________________________" << endl;

    cout << "Добавляем значение по существующему ключу (Иванову - 100)..." << endl;
    cont1.insert(pair<string, int>("Иванов", 100));
    Show(cont1);
    cout << "____________________________________________________________" << endl;

    cont2.insert(pair<string, int>("Иванов", 10));
    cont2.insert(pair<string, int>("Петров", 20));
    cont2.insert(pair<string, int>("Сидоров", 30));

    cout << "Содержимое мультиотображения:" << endl;
    Show(cont2);
    cout << "____________________________________________________________" << endl;
    
    //cont2["Иванов"] = 20;

    cout << "Ищем первое вхождение элемента с ключом \"Петров\"..." << endl;
    multimap<string, int>::iterator iter = cont2.find("Петров");
    cout << iter->first << '\t' << iter->second << endl;
    cout << "____________________________________________________________" << endl;

    cout << "Добавляем значение по существующему ключу (Иванову - 100)..." << endl;
    cont2.insert(pair<string, int>("Иванов", 100));
    Show(cont2);
    cout << "____________________________________________________________" << endl;

    cout << "Добавляем новое значение..." << endl;
    cont2.insert(pair<string, int>("Макаров", 40));
    Show(cont2);
    cout << "____________________________________________________________" << endl;

    cout << "Добавляем значение по существующему ключу (Иванову - 80)..." << endl;
    cont2.insert(pair<string, int>("Иванов", 80));
    Show(cont2);
    cout << "____________________________________________________________" << endl;

    cout << "Добавляем значение по существующему ключу (Иванову - 30)..." << endl;
    cont2.insert(pair<string, int>("Иванов", 30));
    Show(cont2);
    cout << "____________________________________________________________" << endl;

    cout << "Добавляем значение по существующему ключу (Иванову - 50)..." << endl;
    cont2.insert(pair<string, int>("Иванов", 50));
    Show(cont2);
    cout << "____________________________________________________________" << endl;

    cout << "Количество значений по ключу \"Иванов\": " << cont2.count("Иванов") << endl;
    cout << "____________________________________________________________" << endl;

    iter = cont2.lower_bound("Иванов");

    for (; iter != cont2.upper_bound("Иванов"); iter++)
    {
        cout << iter->first << '\t' << iter->second << endl;
    }
    cout << "____________________________________________________________" << endl;

#pragma endregion

    return 0;
}
