#include <iostream>

typedef struct node{
    int val;
    struct node* next;
}Node;

void addFirst(Node*& head, int val){
    Node* newNode = new Node;
    newNode->val=val;
    newNode->next=head;
    head = newNode;
}

void addEnd(Node*& head,int val){
    Node* newNode=new Node;
    newNode->val=val;
    newNode->next=nullptr;

    if(head ==nullptr){
        head=newNode;
        return;
    }

    Node* curr = head;
    while(curr->next != nullptr)
        curr=curr->next;
    curr->next=newNode;
}

void printList(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        std::cout<<temp->val<<" ";
        temp = temp->next;
    }
    std::cout<<std::endl;
}

int listSize(Node* head){
    int len = 0;
    Node* curr = head;
    while(curr != nullptr)
    {
        len++;
        curr=curr->next;
    }

    return len;
}

void delEl(Node*& head,int val){
    Node* curr = head;
    Node* prev = nullptr;

    while(curr != nullptr && curr->val != val){
            prev = curr;
            curr = curr->next;
    }
    if(curr==nullptr)
        return;
    if(prev == nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    else {
        prev->next = curr->next;
        delete curr;
        return;
    }
}

void deleteEvery(Node*& head,int val){
    Node* temp = head;
    Node* prev = nullptr;
    while(temp!=nullptr){
        if(temp->val == val){
            if(prev == nullptr){
                head = head->next;
                temp=temp->next;
            }
            else{
                prev->next = temp->next;
                temp=temp->next;
            }
        }
        else{
            prev=temp;
            temp=temp->next;
        }
    }
}

void delHead(Node*& head){
    Node *temp = head;
    if(head==nullptr)
        return;
    head= head->next;
    delete temp;
    return;
}

void delList(Node*& head){
    Node* temp = head;
    while(temp!=nullptr){
        Node* newNode = temp;
        temp = temp->next;
        delete newNode;
    }
    head=nullptr;
}

Node* midList(Node*& head){
    if(head == nullptr)
        return head;

    Node* temp = nullptr;
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next!=nullptr){
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return temp;
}

Node* merge_(Node*& left, Node*& right){
    Node* res = new Node;
    Node* temp = res;
    while(left != nullptr && right != nullptr){
        if(left->val < right->val){
            temp->next = left;
            left = left->next;
        }
        else {
            temp->next = right;
            right=right->next;
        }
        temp=temp->next;
    }

    if(left != nullptr)
        temp->next = left;
    if(right != nullptr)
        temp->next = right;
    return res->next;
}

Node* mergeSort(Node*& head){
    if(head == nullptr || head->next == nullptr)
        return head;

    Node* left = head;
    Node* right = midList(head);
    Node* temp = right->next;
    right->next = nullptr;
    right = temp;

    left=mergeSort(head);
    right=mergeSort(right);

    return merge_(left,right);
}

int main()
{
    Node* head = NULL;

    addFirst(head,7);
    addEnd(head,5);
    addEnd(head,11);
    addFirst(head,15);
    addEnd(head,17);
    addFirst(head,12);
    //std::cout<<listSize(head)<<std::endl;
    //delEl(head,11);
    addFirst(head,3);
    addEnd(head,1);
    //deleteEvery(head,11);
    //delList(head);

    printList(head);
    //delHead(head);
    head=mergeSort(head);

    printList(head);

    return 0;
}
