#include <iostream>

typedef struct node{
    int val;
    struct node* next;
}Node;

void addFirst(Node*& head, int val){
    Node* newNode = new Node;
    newNode->val=val;
    newNode->next=head;
    head=newNode;
}

void addEnd(Node*& head,int val){
    Node* newNode = new Node;
    newNode->val = val;
    newNode->next = nullptr;
    if(head == nullptr){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next!=nullptr)
        temp=temp->next;
    temp->next=newNode;
}

void printList(Node*& head){
    Node* temp = head;
    while(temp!=nullptr){
        std::cout<<temp->val<<" ";
        temp=temp->next;
    }
    std::cout<<std::endl;
}

Node* findMid(Node*& head){
    if(head == nullptr)
        return head;

    Node* slow = head;
    Node* fast = head;
    Node* temp = nullptr;

    while(fast!=nullptr && fast->next != nullptr){
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return temp;
}

void izbrisiSrednji(Node*& head){
    if(head == nullptr)
        return;

    Node* slow = head;
    Node* fast = head;
    Node* temp = nullptr;
    Node* prev = nullptr;
    while(fast!=nullptr && fast->next != nullptr){
        prev = temp;
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prev == nullptr){
        head=head->next;
        delete temp;
        return;
    }
    else{
        prev->next = temp->next;
        delete temp;
        return;
    }
}

Node* mergeList(Node*& left, Node*& right){
    Node* res = new Node;
    Node* temp = res;
    while(left != nullptr && right != nullptr){
        if(left->val < right->val){
            temp->next = left;
            left=left->next;
        }
        else{
            temp->next=right;
            right=right->next;
        }
        temp=temp->next;
    }
    if(left!=nullptr)
        temp->next=left;
    if(right!=nullptr)
        temp->next=right;
    return res->next;
}

Node* mergeSort(Node*& head){
    if(head == nullptr || head->next==nullptr)
        return head;

    Node* left = head;
    Node* right = findMid(head);
    Node* temp = right->next;
    right->next = nullptr;
    right = temp;

    left = mergeSort(head);
    right = mergeSort(right);

    return mergeList(left,right);
}

Node* joinLists(Node*& head1,Node*& head2){
    Node* res = new Node;
    Node* tmp = res;
    Node* tmp1 = head1;
    Node* tmp2 = head2;

    while(tmp1!=nullptr && tmp2!=nullptr){
        if(tmp1->val < tmp2->val){
            tmp->next=tmp1;
            tmp1=tmp1->next;
        }
        else{
            tmp->next=tmp2;
            tmp2=tmp2->next;
        }
        tmp=tmp->next;
    }

    if(tmp1!=nullptr)
        tmp->next=tmp1;

    if(tmp2!=nullptr)
        tmp->next=tmp2;

    return res->next;
}

void prviVeci(Node* head){
    Node* curr = head;
    Node* nextN = curr->next;
    while(curr->next!=nullptr){
        while(nextN->val < curr->val && nextN !=nullptr)
            nextN=nextN->next;
        if(nextN!=nullptr){
            std::cout<<nextN->val<<" ";
        }
        else
        {
            std::cout<<0<<" ";
        }

        curr=curr->next;
        nextN = curr->next;
    }
}

int listSize(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp!=nullptr){
        len++;
        temp=temp->next;
    }
    return len;
}

int valAtPos(Node* head,int pos){
    int i = 0;
    Node* temp = head;
    while(temp!=nullptr && i != pos)
    {
        temp=temp->next;
        i++;
    }
    if(temp!=nullptr)
        return temp->val;
    return -1;
}

bool palindrom(Node*& head){
    int len = listSize(head);
    for(int i =0 ;i < len/2;i++){
        if(valAtPos(head,i) != valAtPos(head,len-1-i))
            return  false;
            std::cout<<valAtPos(head,i)<<" "<< valAtPos(head,len-1-i)<<std::endl;
    }
    return true;
}

void dodati1(Node*& head,int k,int v){
    Node* temp = head;
    int i = 1;
    while(temp!=nullptr){
        if(i==k){
            Node* newNode = new Node;
            newNode->val = v;
            newNode->next = temp->next;
            temp->next = newNode;
            i=0;
        }
        else i++;
        temp = temp->next;
    }
}

int main()
{
    Node* head= nullptr;

    addEnd(head,1);
    addEnd(head,2);
    addEnd(head,3);
    addEnd(head,4);
    addFirst(head,1);
    addFirst(head,2);
    addFirst(head,3);
    addFirst(head,4);

    //printList(head);
    //head = mergeSort(head);
    //printList(head);
/*
    Node* head2 = nullptr;
    addEnd(head2,6);
    addFirst(head2,10);
    addEnd(head2,1);
    addFirst(head2,5);
    //printList(head2);
    head2=mergeSort(head2);
    //printList(head2);

    head = joinLists(head,head2);
    printList(head);
    prviVeci(head);
  */
    head = mergeSort(head);
    printList(head);
    std::cout<<palindrom(head)<<std::endl;
    dodati1(head,2,0);
    printList(head);
    return 0;
}
