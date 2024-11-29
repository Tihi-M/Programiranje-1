#include <iostream>
#include <cmath>
void fillArr(int *arr,int len){
    if(len == 0)
        return;
    std::cin>>*arr;
    fillArr(arr+1,len-1);
}

void printArr(int *arr,int len){
    if(len == 0){
        std::cout<<std::endl;
        return;
    }
    std::cout<<*arr<<" ";
    printArr(arr+1,len-1);
}

void linSearch(int *arr,int len,int el){
    for(int i = 0; i < len;i++)
        if(arr[i] == el){
            std::cout<<i<<std::endl;
            return;
    }
    std::cout<<-1<<std::endl;
}

void linSearchRec(int *arr,int len,int i,int el){
    if(len == i)
        {
            std::cout<<-1<<std::endl;
            return;
        }
    if(arr[i] == el)
    {
        std::cout<<i<<std::endl;
        return;

    }
    else linSearchRec(arr,len,i+1,el);
}

int binSearch(int *arr,int len,int el){
    int left = 0;
    int right = len-1;
    int pos;
    while(left<=right){
        pos =left+(right-left)/2;
        if(arr[pos] == el)
            return pos;
        if(arr[pos] > el)
            right = pos-1;
        else left = pos+1;
    }
    return -1;
}

int binSearchRec(int *arr,int len,int left,int right,int el){
    if(left>right)
        return -1;
    int pos = left+(right-left)/2;
    if(arr[pos] == el)
        return pos;
    else if(arr[pos] > el)
        return binSearchRec(arr,len,left,pos-1,el);
    else return binSearchRec(arr,len,pos+1,right,el);

}

int findClosest(int *arr,int len,int el){
    int left = 0;
    int right = len-1;
    int pos;
    int closest=arr[0];
    while(left<=right)
    {
        pos = left+(right-left)/2;
        if(arr[pos] == el)
            return arr[pos];
        if(std::abs(arr[pos] - el) < std::abs(closest-el))
            closest =arr[pos];
        if(arr[pos] > el)
            right = pos-1;
        else left = pos+1;
    }
    return closest;
}

int findClosestRec(int *arr,int len,int left,int right,int close,int el){
    if(left>right)
        return close;
    int pos = left+(right-left)/2;
    if(arr[pos] == el)
        return arr[pos];
    if(std::abs(arr[pos]-el) < std::abs(close-el))
        close=arr[pos];
    if(arr[pos] > el)
        return findClosestRec(arr,len,left,pos-1,close,el);
    else return findClosestRec(arr,len,pos+1,right,close,el);
}

int bigger100(int *arr,int len,int left,int right){
    if(left > right)
        return -1;
    int pos = left+(right-left)/2;
    if(arr[pos] > 100)
        return arr[pos];
    else return bigger100(arr,len,pos+1,right);
}

int countDigit(int n){
    if(n==0)
        return 0;
    return 1+countDigit(n/10);
}

int binSch7(int *arr,int len,int k){
    int left = 0;
    int right = len-1;
    int pos;
    int minInd = len;
    while(left <= right){
        pos = left+(right-left)/2;
        if(countDigit(arr[pos]) == k && pos < minInd)
         minInd=pos;
        if(countDigit(arr[pos]) > k)
            left = pos+1;
        else right = pos-1;
    }
    return arr[minInd];
}

int main()
{
    int len;
    std::cout<<"Len: ";
    std::cin>>len;
    int *arr = new int[len];

    fillArr(arr,len);
    //printArr(arr,len);

    int k;
    std::cout<<"k:";
    std::cin>>k;

    //linSearch(arr,len,k);
    //linSearchRec(arr,len,0,k);
    std::cout<<binSch7(arr,len,k);
    return 0;
}
