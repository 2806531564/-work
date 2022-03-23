#ifndef myList
#define myList

#include <iostream>        //包含头文件iostream
using namespace std;

template <class T>
class LinkedList    
{
public:
    struct Node {    
        T data;
        Node* next;
        Node(int a = 0, Node* b = nullptr) : next(b), mat(nullptr) {}
    };

private:
    Node* head;
    int size;

public:
    //构造函数
    LinkedList()
    {
        head = new Node;
        size = 0;
    }
    LinkedList(const LinkedList& rhs)
    {
        head = new Node;
        size = 0;
        Node* p1 = nullptr, * p2 = nullptr;
        p2 = rhs.head->next;
        p1 = head;
        for (; p2 != nullptr;)
        {
            p1->next = new Node;
            p1->next->data = p2->data;
            p1 = p1->next;
            p2 = p2->next;
            size++;
        }
    }
    LinkedList(T const a[], int n)
    {
        head = new Node;
        size = 0;
        Node* p1 = nullptr;

        p1 = head;
        for (int i = 0; i < n; i++)
        {
            p1->next = new Node;
            p1->next->data = a[i];
            p1 = p1->next;

            size++;
        }
    }
    LinkedList(int n, T value)
    {
        head = new Node;
        size = 0;
        Node* p1 = nullptr;

        p1 = head;
        for (int i = 0; i < n; i++)
        {
            p1->next = new Node;
            p1->next->data = value;
            p1 = p1->next;

            size++;
        }
    }
    ~LinkedList()
    {

        Node* p1 = nullptr, * p2 = nullptr;
        p1 = head;
        for (; p1 != nullptr;)
        {
            p2 = p1->next;
            delete p1;
            p1 = p2;

        }

    }

  
    int getSize()const { return size; }


    void insert(int pos, T value)
    {
        Node* p1 = nullptr, * p2 = nullptr;
        p1 = advance(pos - 1);
        if (p1->next == nullptr)
        {
            p1->next = new Node;
        }
        else
        {
            p2 = p1->next;

            p1->next = new Node;
            p1->next->next = p2;

            p1->next->data = value;
        }

        size++;
    }

  
    void remove(int pos)
    {
        Node* p1 = nullptr, * p2 = nullptr;
        p1 = advance(pos - 1);
        if (p1->next->next == nullptr)
        {
            delete p1->next;
        }
        else
        {
            p2 = p1->next->next;

            delete p1->next;

            p1->next = p2;
        }

        size--;
    }


    
    T at(int pos)const
    {
        Node* p1 = nullptr;
        p1 = advance(pos);

        return p1->data;
    }



    void modify(int pos, T newValue)
    {
        Node* p1 = nullptr;
        p1 = advance(pos);

        p1->data = newValue;
    }

   
    void disp()const
    {
        Node* p1 = nullptr;
        p1 = head->next;
        for (; p1 != nullptr;)
        {
            cout << p1->data << " ";
            p1 = p1->next;
        }
        cout << endl;
    }

private:
   

    Node* advance(int pos)const
    {
        Node* p1 = nullptr;
        p1 = head;
        for (int i = -1;; i++)
        {
            if (i == pos)
            {
                return p1;
            }
            p1 = p1->next;
        }
    }

public:
    //运算符重载
    LinkedList<T>& operator = (const LinkedList<T>& rhs);
    LinkedList<T>& operator += (const LinkedList<T>& rhs);

};

template <class T>
LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T>& rhs)
{
    this->~LinkedList<T>();
    head = new Node;
    size = 0;
    Node* p1 = nullptr, * p2 = nullptr;
    p2 = rhs.head->next;
    p1 = head;
    while(p2 != nullptr)
    {
        p1->next = new Node;
        p1->next->data = p2->data;
        p1 = p1->next;
        p2 = p2->next;
        size++;
    }
    return *this;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator += (const LinkedList<T>& rhs)
{

    Node* p1 = nullptr, * p2 = nullptr;
    p2 = rhs.head->next;
    p1 = head;
    while(true)
    {
        if (p1->next == nullptr)
        {
            break;
        }
        p1 = p1->next;
    }
    while(p2 != nullptr)
    {
        p1->next = new Node;
        p1->next->data = p2->data;
        p1 = p1->next;
        p2 = p2->next;
        size++;
    }
    return *this;
}

template <class f>
const LinkedList<f> operator + (const LinkedList<f>& lhs, const LinkedList<f>& rhs)
{
    LinkedList<f> t;
    t = lhs;
    t += rhs;
    return t;
}

template <class f>
bool operator == (const LinkedList<f>& lhs, const LinkedList<f>& rhs)
{
    if (lhs.getSize() == rhs.getSize())
    {
        int m;
        m = lhs.getSize();
        for (int i = 0; i < m; i++)
        {
            if (lhs.at(i) != rhs.at(i))
            {
                return 0;
            }
        }
        return 1;
    }
    else
        return 0;
}

template <class f>
bool operator != (const LinkedList<f>& lhs, const LinkedList<f>& rhs)
{
    if (lhs == rhs)
    {
        return 0;
    }
    else
        return 1;
}

template <class f>
bool operator < (const LinkedList<f>& lhs, const LinkedList<f>& rhs)
{
    int m;
    if (lhs.getSize() == rhs.getSize())
    {
        m = lhs.getSize();
        for (int i = 0; i < m; i++)
        {
            if (lhs.at(i) < rhs.at(i))
            {
                return 1;
            }
        }
        return 0;
    }
    else
    {
        if (lhs.getSize() < rhs.getSize())
        {
            m = lhs.getSize();
        }
        else
        {
            m = rhs.getSize();
        }
        for (int i = 0; i < m; i++)
        {
            if (lhs.at(i) > rhs.at(i))
            {
                return 0;
            }
        }
        if (lhs.getSize() < rhs.getSize())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

template <class f>
bool operator <= (const LinkedList<f>& lhs, const LinkedList<f>& rhs)
{
    return (lhs < rhs || lhs == rhs);
}

template <class f>
bool operator > (const LinkedList<f>& lhs, const LinkedList<f>& rhs)
{
    return !(lhs <= rhs);
}

template <class f>
bool operator >= (const LinkedList<f>& lhs, const LinkedList<f>& rhs)
{
    return !(lhs < rhs);
}

template <class f>
int zeroNum(LinkedList<f>& lhs)
{
    int n = 0;
    f x;
    for (int i = 1; i <= lhs.size; i++)
    {
        if (lhs[i].data == x)
        {
            n++;
        }
    }
    return n;
}

template <class f>
ostream& operator << (ostream& os, const LinkedList<f>& rhs)
{
    rhs.disp();
    return os;
}


#endif
