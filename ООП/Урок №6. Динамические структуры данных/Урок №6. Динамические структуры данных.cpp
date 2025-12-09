#include <iostream>
#include <string>

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

int main()
{
    setlocale(LC_ALL, "");

    Stack stack;
    //stack.Push('A');
    //stack.Push('B');
    //stack.Push('C');

    /*cout << "в стеке " << stack.GetCount() << " элементов" << endl;
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
    return 0;
}
