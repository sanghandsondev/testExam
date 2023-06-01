#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

typedef struct Node *node;

node makeNode(int x)
{
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

bool empty(node a)
{
    return a == NULL;
}

int Size(node a)
{
    int cnt = 0;
    while (a != NULL)
    {
        cnt++;
        a = a->next;
    }
    return cnt;
}

void insertFirst(node &a, int x)
{
    node tmp = makeNode(x);
    if (a == NULL)
    {
        a = tmp;
    }
    else
    {
        tmp->next = a;
        a = tmp;
    }
}

void insertLast(node &a, int x)
{
    node tmp = makeNode(x);
    if (a == NULL)
    {
        a = tmp;
    }
    else
    {
        node p = a;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = tmp;
    }
}

void insertMiddle(node &a, int x, int pos)
{
    int n = Size(a);
    if (pos <= 0 || pos > n + 1)
        return;
    if (pos == 1)
    {
        insertFirst(a, x);
        return;
    }
    else if (pos == n + 1)
    {
        insertLast(a, x);
        return;
    }
    node p = a;
    for (int i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }
    node tmp = makeNode(x);
    tmp->next = p->next;
    p->next = tmp;
}

void deleteFirst(node &a)
{
    if (a == NULL)
        return;
    a = a->next;
}

void deleteLast(node &a)
{
    if (a == NULL)
        return;
    node truoc = NULL, sau = a;
    while (sau->next != NULL)
    {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == NULL)
    {
        a = NULL;
    }
    else
    {
        truoc->next = NULL;
    }
}

void deleteMiddle(node &a, int pos)
{
    if (pos <= 0 || pos > Size(a))
        return;
    node truoc = NULL, sau = a;
    for (int i = 1; i < pos; i++)
    {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == NULL)
    {
        a = a->next;
    }
    else
    {
        truoc->next = sau->next;
    }
}

void show(node a)
{
    while (a != NULL)
    {
        cout << a->data << " ";
        a = a->next;
    }
    cout << endl;
}

// Solution
node solve1(node a, int k)
{
    bool check = true;
    while (check)
    {
        check = false;
        int index = 0;
        int length = Size(a);
        for (node p = a; p != NULL; p = p->next)
        {
            index++;
            if (p->data == k)
            {
                if (index == 1)
                {
                    deleteFirst(a);
                }
                else if (index == length)
                {
                    deleteLast(a);
                }
                else
                {
                    deleteMiddle(a, index);
                }
                check = true;
                break;
            }
        }
    }
    return a;
}

node solve2(node a, node b)
{
    node result = NULL;
    while (a != NULL || b != NULL)
    {
        if (a == NULL)
        {
            insertLast(result, b->data);
            deleteFirst(b);
            continue;
        }
        if (b == NULL)
        {
            insertLast(result, a->data);
            deleteFirst(a);
            continue;
        }
        if (a->data < b->data)
        {
            insertLast(result, a->data);
            deleteFirst(a);
        }
        else
        {
            insertLast(result, b->data);
            deleteFirst(b);
        }
    }
    return result;
}

int main()
{
    int n;
    int ptu;
    cout << "------------------- Bai Test so 1 -----------------------\n";
    node head = NULL; // Khoi tao node dau` tien
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    cout << "Nhap " << n << " phan tu cua danh sach: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ptu; // Nhap cac phan tu vao danh sach
        insertLast(head, ptu);
    }
    show(head); // Bieu dien danh sach lien ket
    int k;
    cout << "Nhap gia tri cua cac phan tu muon xoa: ";
    cin >> k;
    node res1 = solve1(head, k);
    cout << "Ket qua: ";
    show(res1);

    cout << "------------------- Bai Test so 2 ----------------------\n";
    node head2 = NULL, head3 = NULL;
    cout << "Nhap so luong phan tu ds1: ";
    cin >> n;
    cout << "Nhap " << n << " phan tu cua danh sach ds1: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ptu; // Nhap cac phan tu vao danh sach
        insertLast(head2, ptu);
    }
    show(head2);
    //---
    cout << "Nhap so luong phan tu ds2: ";
    cin >> n;
    cout << "Nhap " << n << " phan tu cua danh sach ds2: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ptu; // Nhap cac phan tu vao danh sach
        insertLast(head3, ptu);
    }
    show(head3); // Bieu dien danh sach lien ket
    //---
    node res2 = solve2(head2, head3);
    cout << "Ket qua: ";
    show(res2);

    cout << "------------------- Bai Test so 3 ----------------------\n";
    cout << "Gia su chi co 10 danh sach thay vi 32 ~~" << endl;
    int sods = 10;
    node ds[sods] = {NULL};
    cout << "gia su moi danh sach co 4 phan tu (Luu y theo thu tu tang dan)\n";
    for (int i = 0; i < sods; i++)
    {
        cout << "Nhap danh sach thu " << i + 1 << " : ";
        for (int j = 0; j < 4; j++)
        {
            cin >> ptu;
            insertLast(ds[i], ptu);
        }
    }
    for (int i = 0; i < sods; i++)
    {
        show(ds[i]);
    }
    //---
    node res3 = NULL;
    map<int, int> mp;
    for (int i = 0; i < sods; i++)
    {
        for (node p = ds[i]; p != NULL; p = p->next)
        {
            mp[p->data]++;
        }
    }
    for (auto x : mp)
    {
        for (int i = 0; i < x.second; i++)
        {
            insertLast(res3, x.first);
        }
    }
    cout << "Ket qua:";
    show(res3);

    return 0;
}