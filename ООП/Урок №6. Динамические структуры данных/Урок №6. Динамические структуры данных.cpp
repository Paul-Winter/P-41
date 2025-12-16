#include <iostream>
#include <string>
#include <time.h>
#include <forward_list>

using namespace std;

class Stack
{
    // нижняя и верхняя границы стека
    enum {EMPTY = -1, FULL = 100};

    // массив для хранения данных
    char st[FULL + 1];

    // указатель на вершину стека
    int top;

public:
    // конструктор
    Stack()
    {
        // изначально стек пуст
        top = EMPTY;
    }
    // добавление элемента
    void Push(char c)
    {
        if (!IsFull())
        {
            st[++top] = c;
        }
    }

    // посмотреть элемент
    char Pull()
    {
        if (!IsEmpty())
            return st[top];
        else
            return 0;
    }

    // извлечение элемента
    char Pop()
    {
        if (!IsEmpty())
            return st[top--];
        else
            return 0;
    }

    // очистка стека
    void Clear()
    {
        top = EMPTY;
    }

    // проверка существования элементов в стеке
    bool IsEmpty()
    {
        return top == EMPTY;
    }

    // проверка переполнения стека
    bool IsFull()
    {
        return top == FULL;
    }

    // количество элементов в стеке
    int GetCount()
    {
        return top + 1;
    }
};

class Queue
{
    //  Очередь
    int* Wait;

    //  Максимальный размер очереди
    int MaxQueueLength;

    //  Текущий размер очереди
    int QueueLength;

public:
    //  Конструктор
    Queue(int m)
    {
        MaxQueueLength = m;
        Wait = new int[MaxQueueLength];
        QueueLength = 0;
    }  

    //  Деструктор
    ~Queue()
    {
        delete[] Wait;
    }

    //  Добавление элемента
    void Add(int n)
    {
        if (!IsFull())
        {
            Wait[QueueLength++] = n;
        }
    }

    //  Извлечение элемента
    int Extract()
    {
        if (!IsEmpty())
        {
            int temp = Wait[0];
            for (int i = 1; i < QueueLength; i++)
            {
                Wait[i - 1] = Wait[i];
            }
            QueueLength--;
            return temp;
        }
        else
        {
            return -1;
        }
    }

    //  Очистка очереди
    void Clear()
    {
        QueueLength = 0;
    }

    //  Проверка существования элементов в очереди
    bool IsEmpty()
    {
        return QueueLength == 0;
    }

    //  Проверка на переполнение очереди
    bool IsFull()
    {
        return QueueLength == MaxQueueLength;
    }

    //  Количество элементов в очереди
    int GetCount()
    {
        return QueueLength;
    }

    //  Демонстрация очереди
    void Show()
    {
        for (int i = 0; i < QueueLength; i++)
        {
            cout << Wait[i] << " ";
        }
        cout << endl;
    }
};

class QueueRing
{
    //  Очередь
    int* Wait;

    //  Максимальный размер очереди
    int MaxQueueLength;

    //  Текущий размер очереди
    int QueueLength;

public:
    //  Конструктор
    QueueRing(int m)
    {
        MaxQueueLength = m;
        Wait = new int[MaxQueueLength];
        QueueLength = 0;
    }

    //  Деструктор
    ~QueueRing()
    {
        delete[] Wait;
    }

    //  Добавление элемента
    void Add(int n)
    {
        if (!IsFull())
        {
            Wait[QueueLength++] = n;
        }
    }

    //  Извлечение элемента
    bool Extract()
    {
        if (!IsEmpty())
        {
            int temp = Wait[0];
            for (int i = 1; i < QueueLength; i++)
            {
                Wait[i - 1] = Wait[i];
            }
            Wait[QueueLength - 1]= temp;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    //  Очистка очереди
    void Clear()
    {
        QueueLength = 0;
    }

    //  Проверка существования элементов в очереди
    bool IsEmpty()
    {
        return QueueLength == 0;
    }

    //  Проверка на переполнение очереди
    bool IsFull()
    {
        return QueueLength == MaxQueueLength;
    }

    //  Количество элементов в очереди
    int GetCount()
    {
        return QueueLength;
    }

    //  Демонстрация очереди
    void Show()
    {
        for (int i = 0; i < QueueLength; i++)
        {
            cout << Wait[i] << " ";
        }
        cout << endl;
    }    
};

class QueuePriority
{
    //  Очередь
    int* Wait;

    // Приоритет
    int* Pri;

    //  Максимальный размер очереди
    int MaxQueueLength;

    //  Текущий размер очереди
    int QueueLength;

public:
    //  Конструктор
    QueuePriority(int m)
    {
        MaxQueueLength = m;
        Wait = new int[MaxQueueLength];
        Pri = new int[MaxQueueLength];
        QueueLength = 0;
    }

    //  Деструктор
    ~QueuePriority()
    {
        delete[] Wait;
        delete[] Pri;
    }

    //  Добавление элемента
    void Add(int n, int p)
    {
        if (!IsFull())
        {
            Wait[QueueLength] = n;
            Pri[QueueLength] = p;
            QueueLength++;
        }
    }

    //  Извлечение элемента
    int Extract()
    {
        if (!IsEmpty())
        {
            int maxPri = Pri[0];
            int posMaxPri = 0;
            for (int i = 1; i < QueueLength; i++)
            {
                if (maxPri < Pri[i])
                {
                    maxPri = Pri[i];
                    posMaxPri = i;
                }
            }
            int tempEl = Wait[posMaxPri];
            int tempPri = Pri[posMaxPri];
            for (int i = posMaxPri; i < QueueLength; i++)
            {
                Wait[i] = Wait[i + 1];
                Pri[i] = Pri[i + 1];
            }
            QueueLength--;
            return tempEl;
        }
        else
        {
            return -1;
        }
    }

    //  Очистка очереди
    void Clear()
    {
        QueueLength = 0;
    }

    //  Проверка существования элементов в очереди
    bool IsEmpty()
    {
        return QueueLength == 0;
    }

    //  Проверка на переполнение очереди
    bool IsFull()
    {
        return QueueLength == MaxQueueLength;
    }

    //  Количество элементов в очереди
    int GetCount()
    {
        return QueueLength;
    }

    //  Демонстрация очереди
    void Show()
    {
        for (int i = 0; i < QueueLength; i++)
        {
            cout << Wait[i] << " - " << Pri[i] << "\t";
        }
        cout << endl;
    }
};

struct Node
{
    int value;
    Node* next;
    Node(int val) :value{ val }, next{nullptr} {}
};
struct LinkedList
{
    Node* head;
    Node* tail;
public:
    LinkedList() :head{ nullptr }, tail{ nullptr } {}
    bool IsEmpty()
    {
        if (head == nullptr)
        {
            return true;
        }
        return false;
    }
    void Print()
    {
        if (IsEmpty())
        {
            return;
        }
        Node* temp = head;
        while (temp)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void Push(int value)
    {
        Node* temp = new Node(value);
        if (IsEmpty())
        {
            head = temp;
            tail = temp;
            return;
        }
        tail->next = temp;
        tail = temp;
    }
};

int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));

    // Работа со стеком
    /*Stack stack;
    stack.Push('A');
    stack.Push('B');
    stack.Push('C');

    cout << "в стеке " << stack.GetCount() << " элементов" << endl;
    cout << "Pull 1 раз: " << stack.Pull() << endl;

    cout << "в стеке " << stack.GetCount() << " элементов" << endl;
    cout << "pop 1 раз: " << stack.Pop() << endl;

    cout << "в стеке " << stack.GetCount() << " элементов" << endl<<endl;
    cout << "Pull 2 раз: " << stack.Pull() << endl;
    cout << "Pull дубль: " << stack.Pull() << endl<<endl;

    cout << "в стеке " << stack.GetCount() << " элементов" << endl;
    cout << "pop 2 раз: " << stack.Pop() << endl;

    cout << "в стеке " << stack.GetCount() << " элементов" << endl;
    cout << "Pull 3 раз: " << stack.Pull() << endl;

    cout << "в стеке " << stack.GetCount() << " элементов" << endl;
    cout << "pop 3 раз: " << stack.Pop() << endl;

    cout << "в стеке " << stack.GetCount() << " элементов" << endl;

    stack.Push('A');
    stack.Push('B');
    stack.Push('C');
    stack.Push('D');
    stack.Push('E');
    stack.Push('F');

    cout << "в стеке " << stack.GetCount() << " элементов" << endl;
    cout << "pop 1 раз: " << stack.Pop() << endl;
    cout << "в стеке " << stack.GetCount() << " элементов" << endl;
    cout << "pop 2 раз: " << stack.Pop() << endl;
    cout << "в стеке " << stack.GetCount() << " элементов" << endl;
    cout << "pop 3 раз: " << stack.Pop() << endl;
    cout << "в стеке " << stack.GetCount() << " элементов" << endl;
    cout << "pop 4 раз: " << stack.Pop() << endl;
    cout << "в стеке " << stack.GetCount() << " элементов" << endl;
    cout << "pop 5 раз: " << stack.Pop() << endl;*/

    // Проверка скобок
    /*
    string input;
    cout << "Введите строку: " << endl;
    cin >> input;
    const char* mass = input.c_str();
    bool temp=0;
    int i = 0;
    
    while (mass[i]==';')
    {
        if (mass[i] == '(' || mass[i] == '['|| mass[i] == '{'|| mass[i] == '<')
        {
            stack.Push(mass[i++]);
        }
        else if (mass[i] == ')')
        {
            if (stack.Pop() == '(')//({x-y-z}*[x+2y]-(z+4x));
            {
                continue;
            }
            else
            {
                break;
            }
        }
        else if (mass[i] == '}')
        {
            if (stack.Pop() == '{')//({x-y-z}*[x+2y]-(z+4x));
            {
                continue;
            }
            else
            {
                break;
            }
        }
        else if (mass[i] == ']')
        {
            if (stack.Pop() == '[')//({x-y-z}*[x+2y]-(z+4x));
            {
                continue;
            }
            else
            {
                break;
            }
        }
        else if (mass[i] == '>')
        {
            if (stack.Pop() == '<')//({x-y-z}*[x+2y]-(z+4x));
            {
                continue;
            }
            else
            {
                break;
            }
        }
        else if (mass[i] == ';')
        {
            temp++;
            break;
        }
    }
    if (!temp)
    {
        cout << "Неправильная строка!" << endl;
    }
    else
    {
        cout << "Строка верна!" << endl;
    }
    */

    // Работа с очередью
    /*  Queue queuei(20);

    for (int i = 0; i < 20; i++)
    {
        queuei.Add(rand());
    }
    queuei.Show();
    queuei.Extract();
    queuei.Show();*/

    // Работа с кольцевой очередью
    /*QueueRing qr(20);
    for (int i = 0; i < 20; i++)
    {
        qr.Add(rand()%20);
    }
    qr.Show();
    qr.Extract();
    qr.Show();
    qr.Extract();
    qr.Show();
    qr.Extract();
    qr.Show();
    */

    // Работа с приоритетной очередью
    /*QueuePriority qp(25);
    for (int i = 0; i < 5; i++)
    {
        qp.Add(rand() % 100, rand() % 6);
    }
    qp.Show();
    qp.Extract();
    qp.Show();
    qp.Extract();
    qp.Show();
    qp.Extract();
    qp.Show();
    */

    // Работа со связным списком из стандартной библиотеки
   /* forward_list<int> numbers{ 1,2,3,4,5 };
    cout << numbers.front() << endl;
    for (int n : numbers)
    {
        cout << n << "\t";
    }
    auto current = numbers.begin();
    auto end = numbers.end();
    cout << "\ncurrent = " << &current << "\nend = " << &end << endl;*/

    // Работа со связным списком
    LinkedList l;
    cout << l.IsEmpty() << endl;

    l.Push(3);
    l.Push(123);
    l.Print();

    l.Push(69);
    l.Push(42);
    l.Push(37);
    l.Print();

    return 0;
}
