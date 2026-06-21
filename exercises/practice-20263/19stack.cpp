#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
class Stack{
    Node *top;
public:
    Stack(){
        top = NULL;
    }
    void push(int x);
    void push(int x){
        Node *temp = new Node(x);
        temp->next = top;
        top = temp;
    }
    void pop();
    void pop(){
        if(top == NULL){
            cout << "Stack Underflow" << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
    }
    int topElement(){
        if(top == NULL){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }
    bool isEmpty(){
        return top == NULL;
    }
};

class queue{
    Node *front, *rear;
public:
    queue(){
        front = rear = NULL;
    }
    void enqueue(int x);
    void enqueue(int x){
        Node *temp = new Node(x);
        if(rear == NULL){
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    void dequeue();
    void dequeue(){
        if(front == NULL){
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        delete temp;
    }
    int frontElement(){
        if(front == NULL){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

}

int main(){ 
    int m , n ;
    cin >> m >> n;
    Stack s;
    while(m--){
        int x;
        cin >> x;
        s.push(x);
    }
}