#include "forwardlist.h"
#include <iostream>
#include<stdlib.h>
using namespace std;

QGForwardList::QGForwardList()//初始化链表
{
    head = new Node;
    head->data = 0;
    head->next = NULL;
    length = 0;
}
QGForwardList:: ~QGForwardList()//销毁链表
{
    Node* p1 = head->next;
    while (p1->next != NULL)
    {
        Node* p2 = p1->next;
        delete p1;
        p1 = NULL;
        p1 = p2;
    }
    delete head;
    head = NULL;
}
bool QGForwardList::clear()//清空链表
{
    Node* p1 = head->next;
    if (p1 == NULL)
    {
        return false;
    }
    while (p1->next != NULL)
    {
        Node* p2 = p1->next;
        delete p1;
        p1 = p2;
    }
    return true;
}

bool QGForwardList::push_front(ElemType& e)//在链表第一个元素前添加元素e
{
    Node* p1 = head->next;
    Node* p2 = new Node;
    if (p2 == NULL)
    {
        return false;
    }
    p2->data = e;
    head->next = p2;
    p2->next = p1;
    length++;
    return true;
}
bool QGForwardList::pop_front()//删除链表第一个元素
{
    Node* p1 = head->next;
    if (p1 == NULL)
    {
        return false;
    }
    head->next = p1->next;
    length--;
    return true;
}
bool QGForwardList::push_back(ElemType& e)//在链表最后一个元素后添加元素e
{
    Node* p1 = head;
    for (; p1->next != NULL; p1 = p1->next);
    Node* p2 = new Node;
    if (p2 == NULL)
    {
        return false;
    }
    p2->data = e;
    p1->next = p2;
    p2->next = NULL;
    length++;
    return true;
}
bool QGForwardList::pop_back()//删除链表最后一个元素
{
    Node* p = head;
    if (p->next == NULL)
    {
        return false;
    }
    Node* pb = NULL;
    while (p->next != NULL)
    {
        pb = p;
        p = p->next;
    }
    pb->next = NULL;
    length--;
    return true;
}
bool QGForwardList::insert(unsigned int index, ElemType& e)//在链表的第index + 1个元素前插入元素e
{
    if (index<0 || index>length)
    {
        return false;
    }
    Node* p1 = head;
    for (unsigned int k = 0; k < index; k++)
    {
        p1 = p1->next;
    }
    Node* p2 = new Node;
    if (p2 == NULL)
    {
        return false;
    }
    p2->data = e;
    p2->next = p1->next;
    p1->next = p2;
    length++;
    return true;
}
bool QGForwardList::erase(unsigned int index)//删除任意位置元素
{
    if (index < 0 || index >= length)
    {
        return false;
    }
    Node* p1 = head;
    Node* p2 = NULL;
    for (unsigned int k = 0; k <= index; k++)
    {
        p2 = p1;
        p1 = p1->next;
    }
    p2->next = p1->next;
    delete p1;
    p1 = NULL;
    length--;
    return true;
}
bool QGForwardList::contain(ElemType& e)//查找元素是否存在
{
    Node* p1 = head;
    for (unsigned int k = 0; k < length; k++)
    {
        if (p1->data == e)
        {
            return true;
        }
        p1 = p1->next;
    }
    return false;
}
unsigned int QGForwardList::size()//返回链表中元素的数量
{
    return length;
}
QGForwardList::ElemType& QGForwardList::front()//返回链表中第一个元素的引用
{
    Node* p = head;
    if (p->next == NULL)
    {
        cout << "这是头结点";
        return p->data;
    }
    p = p->next;
    return p->data;
}
QGForwardList::ElemType& QGForwardList::back()//返回链表中最后一个元素的引用
{
    Node* p = head;
    if (p->next == NULL)
    {
        cout << "这是尾结点";
        return p->data;
    }
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p->data;
}
void QGForwardList::Traverse()//输出当前链表的数据
{
    Node* p1 = head;
    if (p1->next == NULL)
    {
        cout << "链表中无数据" << endl;
    }
    while (p1->next != NULL)
    {
        p1 = p1->next;
        cout << p1->data << endl;
    }
}
int main()
{
    cout << "1.查询首结点数据   " << "2.查询尾结点数据 " << "3.查询链表长度          丨" << endl;
    cout << "                                                            丨" << endl;
    cout << "4.插入结点数据     " << "5.删除结点数据   " << "6.清空链表              丨" << endl;
    cout << "                                                            丨" << endl;
    cout << "7.首元素前插入     " << "8.尾结点后处插入 " << "9.查找数据是否存在      丨" << endl;
    cout << "                                                            丨" << endl;
    cout << "10.删除首结点数据  " << "11.删除尾结点数据" << "12.查看链表当前数据     丨" << endl;
    cout << "                                                            丨" << endl;
    cout << "13.退出操作        " << "14.      (空)    " << "15.      （空）         丨" << endl;
    cout << "============================================================丨" << endl;

    QGForwardList* p = new QGForwardList();
    int i, n;
    cout << "请选择你的操作：";
    cin >> i;
    while (i != 13)
    {
        if (i == 1)
        {
            cout << "当前首结点数据为：" << endl;
            cout << p->front() << endl;
        }
        if (i == 2)
        {
            cout << "当前尾结点数据为：" << endl;
            cout << p->back() << endl;
        }
        if (i == 3)
        {
            cout << "当前链表长度：" << p->size() << endl;
        }
        if (i == 4)
        {
            int j;
            cout << "请输入插入位置：";
            cin >> j;
            cout << "请输入插入数字：";
            cin >> n;
            p->insert(j - 1, n);
        }
        if (i == 5)
        {
            int d;
            cout << "请输入删除位置：";
            cin >> d;
            p->erase(d - 1);
        }
        if (i == 6)
        {
            if (p->clear())
            {
                cout << "已清空链表" << endl;
            }
            else
            {
                cout << "操作失败" << endl;
            }
            p->Traverse();
        }
        if (i == 7)
        {
            cout << "请输入插入数字：";
            cin >> n;
            p->push_front(n);
        }
        if (i == 8)
        {
            cout << "请输入插入数字：";
            cin >> n;
            p->push_back(n);
        }
        if (i == 9)
        {
            cout << "请输入想要查找数据：";
            int k;
            cin >> k;
            if (p->contain(k))
            {
                cout << "有此数据" << endl;
            }
            else
            {
                cout << "此数据不存在" << endl;
            }
        }
        if (i == 10)
        {
            p->pop_front();
        }
        if (i == 11)
        {
            p->pop_back();
        }
        if (i == 12)
        {
            cout << "链表当前数据：" << endl;
            p->Traverse();
        }
        cout << "请选择你的操作：";
        cin >> i;
    }


    return 0;
}