#include <iostream>

using namespace std;

class Node {

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
        cout<<endl;
    }

    Node* getHead(){
        return head;
    }

    void kthLastElement(Node* head,int k){
        int pos=1;
        Node* f=head;
        Node* s=head;
        while(pos<=k){
            f=f->next;
            pos++;
        }
        while(f!=NULL){
            f= f->next;
            s= s->next;
        }
        cout<<s->data<<endl;
    }
};

int main()
{
    List l;
    l.pushFront(7);
    l.pushFront(6);
    l.pushFront(5);
    l.pushFront(4);
    l.pushFront(3);
    l.pushFront(2);
    l.pushFront(1);
    l.displayList();
    int k=3;
    l.kthLastElement(l.getHead(),k);
    return 0;
}
