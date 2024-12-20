#include <iostream>

typedef struct node{
    int val;
    struct node* next;
}Node;

void addFirst(Node*& head,int val_){
    Node* newNode = new Node;
    newNode->val = val_;
    newNode->next = head;
    head = newNode;
}

void addEnd(Node*& head,int val_){
    Node* newNode = new Node;
    newNode->val=val_;
    newNode->next=nullptr;
    if(head == nullptr){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }

    temp->next = newNode;
}

void printList(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        std::cout<<temp->val<<" ";
        temp=temp->next;
    }
    std::cout<<std::endl;
}

int listLen(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp!=nullptr){
        len++;
        temp=temp->next;
    }
    return len;
}

void dodajCvor1(Node*& head,int val_,int pos_){
    if(pos_ > listLen(head)){
        addFirst(head,val_);
        return;
    }
    if(pos_ == listLen(head)){
        addEnd(head,val_);
        return;
    }

    int i =0;
    Node* temp=head;
    Node* prev=nullptr;

    while(i!=pos_ && temp!=nullptr){
        i++;
        prev = temp;
        temp=temp->next;
    }
    if(temp==nullptr)
        return;
    if(prev == nullptr){
        Node* temp2 = head;
        Node* newNode = new Node;
        newNode->val=val_;
        newNode->next = head->next;
        head = newNode;
        delete temp2;
        return;
    }
    else{
        Node* newNode = new Node;
        newNode->val=val_;
        newNode->next = temp->next;
        prev->next = newNode;
        delete temp;
        return;

    }
}

void obrisiCvor1(Node* head,int pos){
    if(pos > listLen(head))
        return;
    Node* prev = nullptr;
    Node* temp = head;
    int p = 0;
    while(temp!=nullptr && p!=pos){
        p++;
        prev = temp;
        temp=temp->next;
    }
    if(temp == nullptr)
        return;
    if(prev==nullptr){
        Node* temp2 = head;
        head = head->next;
        delete temp2;
        return;
    }
    else{
        prev->next = temp->next;
        delete temp;
        return;
    }
}
int main()
{
    Node* head = nullptr;
    addEnd(head,2);
    addEnd(head,10);
    addFirst(head,5);

    //dodajCvor1(head,5,2);
    //obrisiCvor1(head,2);
    printList(head);
    return 0;
}
