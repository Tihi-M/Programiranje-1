#include <iostream>

typedef struct node{
    int val;
    int cnt;
    struct node* next;
}Node;

bool checkList(Node*& head,int val){
    Node* temp = head;
    bool flag=false;
    while(temp!=nullptr){
        if(temp->val == val){
            flag = true;
            temp->cnt+=1;
            break;
        }
        temp=temp->next;
    }
    return flag;
}

void addFirst(Node*& head,int val){
    if(checkList(head,val))
        return;

    Node* newNode = new Node;
    newNode->val = val;
    newNode->next = head;
    newNode->cnt = 1;
    head = newNode;
}

void addEnd(Node*& head,int val){
    if(checkList(head,val))
        return;
    Node* newNode = new Node;
    newNode->val = val;
    newNode->next = nullptr;
    newNode->cnt = 1;
    if(head == nullptr){
        head=newNode;
        return;
    }

    Node* temp = head;
    while(temp->next !=nullptr)
        temp=temp->next;

    temp->next=newNode;
}

void printList1(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        int cnt = temp->cnt;
        while(cnt > 0){
            std::cout<<temp->val<<" ";
            cnt--;
        }
        temp = temp->next;
    }
    std::cout<<std::endl;
}
void printList2(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        std::cout<<temp->val<<" ";
        temp=temp->next;
    }
    std::cout<<std::endl;
}

Node* midNode(Node* head){
    if(head == nullptr)
        return head;
    Node* temp = nullptr;
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return temp;
}
Node* mergeList(Node*& left, Node*& right){
    Node* res = new Node;
    Node* temp = res;
    while(left != nullptr && right != nullptr){
        if(left->val < right->val){
            temp->next = left;
            left = left->next;
        }
        else{
            temp->next = right;
            right=right->next;
        }
        temp=temp->next;
    }
    if(left!=nullptr)
        temp->next = left;
    if(right!=nullptr)
        temp->next = right;

    return res->next;
}

Node* mergeSort(Node*& head){
    if(head == nullptr || head->next == nullptr)
        return head;

    Node* left = head;
    Node* right = midNode(head);
    Node* temp = right->next;
    right->next = nullptr;
    right = temp;

    left = mergeSort(head);
    right = mergeSort(right);

    return mergeList(left,right);
}


int main()
{
    Node* head = nullptr;

    addEnd(head,1);
    addFirst(head,5);
    addEnd(head,8);
    addFirst(head,11);
    addFirst(head,8);
    addEnd(head,5);

    printList2(head);

   std::cout<<head->val<<std::endl;
    head = mergeSort(head);
    printList2(head);
    return 0;
}
