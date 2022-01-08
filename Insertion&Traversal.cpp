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

    void insertAtNthPosition(int d,int pos){
        if(pos==0){
            pushFront(d);
            return;
        }
        Node *n = new Node(d);
        int i=1;
        Node *buffer = head;
        while(i<pos && buffer!=NULL){
            buffer = buffer->next;
            i++;
        }
        n->next = buffer->next;
        buffer->next = n;
    }
    void displayList(){
        Node *buffer = head;
        while(buffer!=NULL){
            cout<<buffer->data<<"  ";
            buffer=buffer->next;
        }
        cout<<endl;
    }
    int searchElementIteratively(int elementToBeFound){
        Node *buffer = head;
        int pos=0;
        while(buffer!=NULL){
            if(buffer ->data == elementToBeFound){
                return pos;
            }
            pos++;
            buffer = buffer->next;
        }
        return -1;
    }

    Node* getHead(){
        return head;
    }

    int searchRecursively(Node* head,int elementToBeFound){
        if(head==NULL) return -1;
        if(head->data == elementToBeFound) return 0;
        int ind = searchRecursively(head->next,elementToBeFound);
        return ind+1;
    }

    void popFront(){
        Node *n = head;
        head = head->next;
        delete n;
    }

};

int main()
{
    List l;
    l.pushFront(1);
    l.pushFront(2);
    l.pushFront(3);
    l.pushFront(4);
    l.pushFront(5);
    l.displayList();
    l.insertAtNthPosition(79,1);
    l.displayList();
    l.popFront();
    l.displayList();
    int index = l.searchElementIteratively(3);
    if(index == -1) cout<<"Element Not found Iteratively"<<endl;
    else cout <<"Element was found Iteratively at index :"<<index<<endl;
    int indexRecursively = l.searchRecursively(l.getHead(),5);
    if(indexRecursively == -1) cout<<"Element Not found Recursively"<<endl;
    else cout <<"Element was found  Recursively at index :"<<indexRecursively<<endl;

    return 0;
}
