#include <bits/stdc++.h>
using namespace std;

// class Node - start
class Node
{
public:
    Node(int value, Node *next, Node *prev); // initialize

    void SetValue(int value);
    int GetValue();

    void SetPrev(Node *prev);
    Node *GetPrev();

    void SetNext(Node *next);
    Node *GetNext();


private:
    int value;
    Node *prev;
    Node *next;
};

Node::Node(int value, Node *prev, Node *next) // initialize
{
    this->value = value;
    this->prev = prev;
    this->next = next;
}

void Node::SetValue(int value)
{
    this->value = value;
}

int Node::GetValue()
{
    return this->value;
}

void Node::SetPrev(Node *prev)
{
    this->prev = prev;
}

Node *Node::GetPrev()
{
    return this->prev;
}

void Node::SetNext(Node *next)
{
    this->next = next;
}

Node *Node::GetNext()
{
    return this->next;
}

// class Node - end





// class Linked_List - start

class Linked_List
{
public:
    Linked_List(); // initialize

    void insert_at_end(int value);
    void insert_at_front(int value);
    void delete_last_element();
    void delete_first_element();

    void printListForward(); // print all elements left to right
    void printListBackward();

private:
    Node *head;
    Node *tail;
};

Linked_List::Linked_List() // initialize
{
    this->head = nullptr;
    this->tail = nullptr;
}

void Linked_List::insert_at_end(int value) // insert at end
{
    if (this->head == nullptr)
    {
        this->head = new Node(value, nullptr, nullptr);
        this->tail = this->head;
    }
    else
    {
        this->tail = new Node(value, tail, nullptr);
        this->tail->GetPrev()->SetNext(tail);
    }
}

void Linked_List::insert_at_front(int value) // insert at front
{
    if(this->head == nullptr)
    {
        this->head = new Node(value, nullptr, nullptr);
        this->tail = this->head;
    }
    else
    {
        this->head = new Node(value, nullptr, head);
        this->head->GetNext()->SetPrev(head);
    }
}

void Linked_List::printListForward()
{
    Node *temp = head;

    while(temp)
    {
        cout << temp->GetValue() << ' ';
        temp = temp->GetNext();
    }
    cout << endl;

    // free memory
    delete temp;
    temp = NULL;
}

// class Linked_List - end










int32_t main()
{

    Linked_List ll;

    ll.insert_at_end(4);
    ll.insert_at_end(5);
    ll.insert_at_front(34);
    ll.insert_at_end(6);
    ll.insert_at_end(5);

    ll.printListForward();


    return 0;
}