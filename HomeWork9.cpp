
#include <iostream>

#define I int
#define SIZE 100
#define SZ 10
#define true 1 == 1
#define false 1 != 1

typedef struct {
    int pr;
    int dat;
} Node;

Node* arr[SZ];
int head;
int tail;
int items;

void init() {
    for (int i = 0; i < SZ; i++)
    {
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

void ins(int pr, int dat) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;
    int flag;

    if (items == 0)
    {
        arr[tail++] = node;
        items++;
    }
    else if (items == SZ)
    {
        std::cout << "Queue is full";
        return;
    }
    else
    {
        int i = 0;
        int idx = 0;
        Node* tmp;
        for (i = head; i < tail; i++)
        {
            idx = i % SZ;
            if (arr[idx] == NULL || arr[idx]->pr > pr)
            {
                break;
            }
            else
            {
                idx++;
            }

        }
        flag = idx % SZ;
        i++;
        while (i <= tail)
        {
            if (arr[idx] == NULL)
            {
                tmp = arr[idx];
                arr[idx] = arr[flag];
                arr[flag] = tmp;
                break;
            }
            idx = i % SZ;
            tmp = arr[idx];
            arr[idx] = arr[flag];
            arr[flag] = tmp;
            i++;
        }
        arr[flag] = node;
        items++;
        tail++;
    }
}

Node* rem() {
    if (items == 0)
    {
        return NULL;
    }
    else
    {
        int idx = 0;
        int max = 0;
        for (size_t i = 0; i < tail; i++)
        {
            if (arr[idx] == NULL)
            {
                idx++;
                break;
            }
            else if (arr[idx]->pr >= max)
            {
                max = arr[idx]->pr;
                idx++;

            }
            else {
                idx++;
            }

        }

        idx = 0;
        for (size_t i = 0; i < tail; i++)
        {
            if (arr[idx] == NULL)
            {
                idx++;
                break;
            }
            else if (arr[idx]->pr == max)
            {
                Node* tmp = arr[idx];
                arr[idx] = NULL;
                items--;
                max = 0;
                return tmp;
            }
            else {
                idx++;
            }
        }
    }
}

void printQueue() {
    std::cout << "[";
    for (size_t i = 0; i < SZ; i++)
    {
        if (arr[i] == NULL)
        {
            std::cout << "[*, *]";
        }
        else {
            std::cout << "[" << arr[i]->pr << "," << arr[i]->dat << "]";
        }
    }
    std::cout << "]";
    std::cout << std::endl;
}

typedef int boolean;

I arr2[SIZE];
int cursor = -1;
int temp = 0;

boolean push(I data) {
    if (cursor < SIZE)
    {
        while (data)
        {
            arr2[++cursor] = data % 2;
            data /= 2;
        }
        return true;
    }
    else
    {
        std::cout << "Stack overflow";
        return false;
    }

}

I pop() {
    if (cursor != -1)
    {
        return arr2[cursor--];
    }
    else
    {
        std::cout << "Stack is empty";
        return -1;
    }
}

int main()
{
    ///////exercise 1

    init();
    ins(1, 11);
    ins(2, 22);
    ins(2, 33);
    ins(4, 44);
    ins(5, 55);
    ins(2, 66);
    ins(7, 77);
    ins(6, 88);
    ins(10, 99);
    ins(9, 100);
    printQueue();
    rem();
    rem();
    rem();
    rem();
    ins(10, 99);
    ins(9, 100);
    rem();
    ins(2, 77);
    printQueue();

    ///////

    /////////exercise 2

    int n = 0;
    std::cout << "Enter a number: ";
    std::cin >> n;

    push(n);

    while (cursor != -1)
    {
        std::cout << pop();
    }
    std::cout << std::endl;

    ///////////

    system("pause");
    return 0;
}

