#include "forwardlist.h"
#include <iostream>
#include<stdlib.h>
using namespace std;

QGForwardList::QGForwardList()//��ʼ������
{
    head = new Node;
    head->data = 0;
    head->next = NULL;
    length = 0;
}
QGForwardList:: ~QGForwardList()//��������
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
bool QGForwardList::clear()//�������
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

bool QGForwardList::push_front(ElemType& e)//�������һ��Ԫ��ǰ���Ԫ��e
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
bool QGForwardList::pop_front()//ɾ�������һ��Ԫ��
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
bool QGForwardList::push_back(ElemType& e)//���������һ��Ԫ�غ����Ԫ��e
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
bool QGForwardList::pop_back()//ɾ���������һ��Ԫ��
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
bool QGForwardList::insert(unsigned int index, ElemType& e)//������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
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
bool QGForwardList::erase(unsigned int index)//ɾ������λ��Ԫ��
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
bool QGForwardList::contain(ElemType& e)//����Ԫ���Ƿ����
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
unsigned int QGForwardList::size()//����������Ԫ�ص�����
{
    return length;
}
QGForwardList::ElemType& QGForwardList::front()//���������е�һ��Ԫ�ص�����
{
    Node* p = head;
    if (p->next == NULL)
    {
        cout << "����ͷ���";
        return p->data;
    }
    p = p->next;
    return p->data;
}
QGForwardList::ElemType& QGForwardList::back()//�������������һ��Ԫ�ص�����
{
    Node* p = head;
    if (p->next == NULL)
    {
        cout << "����β���";
        return p->data;
    }
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p->data;
}
void QGForwardList::Traverse()//�����ǰ���������
{
    Node* p1 = head;
    if (p1->next == NULL)
    {
        cout << "������������" << endl;
    }
    while (p1->next != NULL)
    {
        p1 = p1->next;
        cout << p1->data << endl;
    }
}
int main()
{
    cout << "1.��ѯ�׽������   " << "2.��ѯβ������� " << "3.��ѯ������          ح" << endl;
    cout << "                                                            ح" << endl;
    cout << "4.����������     " << "5.ɾ���������   " << "6.�������              ح" << endl;
    cout << "                                                            ح" << endl;
    cout << "7.��Ԫ��ǰ����     " << "8.β���󴦲��� " << "9.���������Ƿ����      ح" << endl;
    cout << "                                                            ح" << endl;
    cout << "10.ɾ���׽������  " << "11.ɾ��β�������" << "12.�鿴����ǰ����     ح" << endl;
    cout << "                                                            ح" << endl;
    cout << "13.�˳�����        " << "14.      (��)    " << "15.      ���գ�         ح" << endl;
    cout << "============================================================ح" << endl;

    QGForwardList* p = new QGForwardList();
    int i, n;
    cout << "��ѡ����Ĳ�����";
    cin >> i;
    while (i != 13)
    {
        if (i == 1)
        {
            cout << "��ǰ�׽������Ϊ��" << endl;
            cout << p->front() << endl;
        }
        if (i == 2)
        {
            cout << "��ǰβ�������Ϊ��" << endl;
            cout << p->back() << endl;
        }
        if (i == 3)
        {
            cout << "��ǰ�����ȣ�" << p->size() << endl;
        }
        if (i == 4)
        {
            int j;
            cout << "���������λ�ã�";
            cin >> j;
            cout << "������������֣�";
            cin >> n;
            p->insert(j - 1, n);
        }
        if (i == 5)
        {
            int d;
            cout << "������ɾ��λ�ã�";
            cin >> d;
            p->erase(d - 1);
        }
        if (i == 6)
        {
            if (p->clear())
            {
                cout << "���������" << endl;
            }
            else
            {
                cout << "����ʧ��" << endl;
            }
            p->Traverse();
        }
        if (i == 7)
        {
            cout << "������������֣�";
            cin >> n;
            p->push_front(n);
        }
        if (i == 8)
        {
            cout << "������������֣�";
            cin >> n;
            p->push_back(n);
        }
        if (i == 9)
        {
            cout << "��������Ҫ�������ݣ�";
            int k;
            cin >> k;
            if (p->contain(k))
            {
                cout << "�д�����" << endl;
            }
            else
            {
                cout << "�����ݲ�����" << endl;
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
            cout << "����ǰ���ݣ�" << endl;
            p->Traverse();
        }
        cout << "��ѡ����Ĳ�����";
        cin >> i;
    }


    return 0;
}