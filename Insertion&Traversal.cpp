#include <iostream>

using namespace std;

class Node {

    //public:
    int data;
    Node* next;

    Node(int d){
        data= d;
        next = NULL;
    }

    friend class List;
};

class List {

    Node *head,*tail;

    public :
    List (){
        head = tail = NULL;
    }

    void pushFront(int d){
        Node *n = new Node(d);
        if(head==NULL){
           head = tail = n;
           return;
        }
        n->next = head;
        head=n;
    }

    void pushBack(int d){
        Node *n = new Node(d);
        if(head==NULL){
            head=tail = n;
            return;
        }
        tail->next = n;
        tail=n;
    }

    void displayList(){
        Node *buffer = head;
        while(buffer!=NULL){
            cout<<buffer->data<<"  ";
            buffer=buffer->next;
        }
    }
};

int main()
{
    //cout << "Hello world!" << endl;
    List l;
    l.pushFront(1);
    l.pushFront(2);
    l.pushFront(3);
    l.pushFront(4);
    l.pushFront(5);
    l.displayList();
    return 0;
}
