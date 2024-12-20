#include <iostream>

typedef struct node{
    int val;
    struct node* next;
}Node;

void addFirst(Node*& head,int val){
    Node* newNode = new Node;
    newNode->val=val;
    newNode->next=head;
    head=newNode;
}

void addEnd(Node*& head,int val){
    Node* newNode = new Node;
    newNode->next = nullptr;
    newNode->val = val;

    if(head==nullptr){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next!=nullptr)
        temp=temp->next;

    temp->next=newNode;
    return;
}

void printList(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        std::cout<<temp->val<< " ";
        temp=temp->next;
    }
    std::cout<<std::endl;
}

void delEl(Node*& head,int val){
    Node* temp = head;
    Node* prev = nullptr;

    while(temp!=nullptr && temp->val != val){
        prev = temp;
        temp=temp->next;
    }

    if(temp == nullptr){
        return;
    }
    if(prev == nullptr){
        Node* temp2 = head;
        head=head->next;
        delete temp2;
        return;
    }
    else{
        prev->next = temp->next;
        delete temp;
        return;
    }
}

void delEvery(Node*& head,int val){
    Node* prev = nullptr;
    Node* temp = head;

    while(temp!=nullptr){
        if(temp->val == val){
            if(prev == nullptr){
                head = head->next;
            }
            else{
                prev->next = temp->next;
            }
            temp=temp->next;
        }
        else{
            prev=temp;
            temp=temp->next;
        }
    }
}

int listSize(Node* head){
    Node* temp=head;
    int len = 0;
    while(temp!=nullptr){
        temp=temp->next;
        len++;
    }
    return len;
}

void umetni1(Node*& head){
    Node* temp = head;
    while(temp->next != nullptr){
        Node* newNode = new Node;
        newNode->val=temp->val-temp->next->val;
        newNode->next=temp->next;
        temp->next=newNode;
        temp=newNode->next;
    }
}

void umetni2(Node*& head,int k){
    Node* temp = head;
    Node* prev = nullptr;
    while(temp!=nullptr){
        if(temp->val % k == 0){
            if(prev==nullptr){
                Node* newNode = new Node;
                newNode->val = -1;
                newNode->next =temp;
                head = newNode;
            }
            else{
                Node* newNode = new Node;
                newNode->val = -1;
                newNode->next =temp;
                prev->next = newNode;
            }
        }
            prev = temp;
            temp = temp->next;
    }
}

void umetni3(Node*& head,int a,int b){
    Node* temp = head;
    while(temp!=nullptr){
        if(temp->val > a && temp->val < b){
            Node* newNode = new Node;
            newNode->val = 0;
            newNode->next = temp->next;
            temp->next=newNode;
        }
        temp = temp->next;
    }
}

void umetni4(Node*& head, int k){
    int i = 1;
    Node* temp = head;
    while(temp!=nullptr){
        if(i==k){
            Node* newNode = new Node;
            newNode->val = 0;
            newNode->next = temp->next;
            temp->next = newNode;
            i = 0;
        }
        else{
            i++;
        }
        temp=temp->next;
    }
}

void obrisi(Node*& head, int d, int k){
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        if(abs(temp->val - d) < k){
            if(prev == nullptr){
                head=head->next;
            }
            else{
                prev->next = temp->next;
            }
            temp=temp->next;
        }
        else{
            prev=temp;
            temp=temp->next;
        }

    }

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

void preuredi1(Node*& head,int k){
    int k2 = 1;
    Node* temp = head;

    while(k2<k){
        temp = temp->next;
        k2++;
    }
    Node* kraj = temp->next;
    temp->next = nullptr;

    Node* prev=nullptr;
    Node* nexxt=nullptr;
    Node* curr = head;
    while(curr!=nullptr){
        nexxt=curr->next;
        curr->next = prev;
        prev = curr;
        curr = nexxt;
    }

    head = prev;
    curr = head;
    while(curr->next != nullptr)
        curr = curr->next;

    curr->next = kraj;
}

void preuredi2(Node*& head,int k){
    Node* curr = head;
    Node* nextt = nullptr;
    Node* prev = nullptr;

    while(curr != nullptr){
        if(curr->val>=k){
            prev = curr;
            curr = curr->next;
        }
        else{
            nextt=curr->next;
            prev->next = nextt;
            curr->next = head;
            head = curr;
            curr = nextt->next;
        }

    }
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

Node* joinList(Node* head1,Node* head2){
    Node* res = new Node;
    Node* tmp = res;
    Node* tmp1 = head1;
    Node* tmp2 = head2;

    while(tmp1 != nullptr && tmp2 != nullptr){
        if(tmp1->val <tmp2->val){
            tmp->next = tmp1;
            tmp1=tmp1->next;
        }
        else{
            tmp->next = tmp2;
            tmp2=tmp2->next;
        }
        tmp = tmp->next;
    }
    while(tmp1!=nullptr){
        tmp->next = tmp1;
        tmp = tmp->next;
        tmp1=tmp1->next;
    }
    while(tmp2!=nullptr){
        tmp->next = tmp2;
        tmp = tmp->next;
        tmp2=tmp2->next;
    }
    return res->next;
}


int main()
{
    Node* head = nullptr;

    addFirst(head,10);
    addEnd(head,5);
    addFirst(head,7);
    addEnd(head,3);
    addFirst(head,5);
    addFirst(head,6);
    addFirst(head,25);
    addEnd(head,15);
    addFirst(head,1);
    printList(head);

    //delEvery(head,3);
    //umetni1(head);
    //umetni2(head,5);
    //umetni3(head,5,10);
    //umetni4(head,3);

    //obrisi(head,8,3);
    //std::cout<<midNode(head)->val<<std::endl;

    //preuredi2(head,5);
    head=mergeSort(head);
    printList(head);

    Node* head2 = nullptr;
    addEnd(head2,30);
    addFirst(head2,9);
    addEnd(head2,19);
    printList(head2);
    head2=mergeSort(head2);
    printList(head2);

    head = joinList(head,head2);
    printList(head);
    //std::cout<<listSize(head);
    return 0;
}
