#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory deallocated " << value << endl;
    }

    void insertohead(Node *&head, int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
    void show(Node *&head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
void inserttotail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void inseratpst(Node *head, Node *tail, int pst, int data)
{
    Node *temp = head;
    int count = 1;
    while (count < pst - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        inserttotail(tail, data);
    }
    Node *toadd = new Node(data);
    toadd->next = temp->next;
    temp->next = toadd;
}
void Deletenode(Node *&head, int value)
{
    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    Node *current = head;
    Node *prev = NULL;
    while (prev != current)
    {
        if (current->data == value && current->next == NULL)
        {
            prev->next = NULL;
            delete current;
            cout << "prev data: " << prev->data << " ";
            return;
        }
        if (current->data == value)
        {
            prev->next = current->next;
            current->next = NULL;
            delete current;
            return;
        }

        if (current->data != value && current->next == NULL)
        {
            cout << "value is not present in this linklist" << endl;
            return;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}
int main()
{
    Node *first = new Node(1);
    Node *head = first;
    Node *tail = first;
    inserttotail(tail, 2);
    inserttotail(tail, 3);
    inserttotail(tail, 4);
    inserttotail(tail, 5);
    inserttotail(tail, 6);
    inseratpst(head, tail, 3, 0);
    cout << endl;

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;
    head->show(head);
    Deletenode(head, 6);
    head->show(head);
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    return 0;
};
