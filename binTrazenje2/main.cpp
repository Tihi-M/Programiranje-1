#include <iostream>
#include <cmath>

void fillArr(int *arr, int len){
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

void bubbleSort1(int *arr,int len){
    bool swapped = false;
    for(int i = 0;i < len - 1;i++)
    {
        for(int j = 0; j < len - i - 1;j++){
            if(arr[j] > arr[j+1]){
                std::swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
        swapped = false;
    }
}

void bubbleSort2(int *arr,int len){
    bool swapped = false;
    for(int i = 0; i < len-1;i++){
        for(int j = 0; j < len -i-1;j++){
            if(arr[j] < arr[j+1])
            {
                std::swap(arr[j],arr[j+1]);
                    swapped = true;
            }
        }

        if(!swapped)
            break;
        swapped = false;
    }
}

bool isSortedAsc(int *arr,int len){
    for(int i = 0; i < len-1;i++)
        if(arr[i] > arr[i+1])
            return false;
    return true;
}

int binSearch1(int *arr,int len,int el){
    if(!isSortedAsc(arr,len))
    {
        std::cout<<"Niz se sortira..."<<std::endl;
        bubbleSort1(arr,len);
        printArr(arr,len);
    }

    int left = 0;
    int right = len-1;
    int pos;
    while(left <= right){
        pos = left + (right - left)/2;
        if(arr[pos] == el)
            return pos;
        if(arr[pos] > el)
            right = pos-1;
        else left = pos+1;
    }
    return -1;
}

int binSearchRec1(int *arr,int len,int left,int right,int el){
    if(left > right)
        return -1;
    int pos = left +  (right - left)/2;
    if(arr[pos] == el)
        return pos;
    if(arr[pos] > el)
        return binSearchRec1(arr,len,left,pos-1,el);
    else return binSearchRec1(arr,len,pos+1,right,el);
}

int binSearchRec2(int *arr,int len,int left,int right,int close,int el){
    if(left>right)
        return close;
    int pos = left + (right - left)/2;
    if(arr[pos] == el)
        return arr[pos];
    if(std::abs(arr[pos]-el) < std::abs(close-el))
        close = arr[pos];
    if(arr[pos] > el)
        return binSearchRec2(arr,len,left,pos-1,close,el);
    else return binSearchRec2(arr,len,pos+1,right,close,el);
}

int binSearch100(int *arr,int len,int left,int right){
    if(left>right)
        return -1;
    int pos = left + (right - left)/2;
    if(arr[pos] > 100)
        return arr[pos];
    else return binSearch100(arr,len,pos+1,right);
}

int countDigits(int n){
    if(n == 0)
        return 0;
    return 1+countDigits(n/10);
}

int binSearchKEl(int *arr,int len,int k){
    int left = 0;
    int right = len - 1;
    int pos;
    int minInd=len;
    while(left <= right){
        pos = left + (right - left)/2;
        if(countDigits(arr[pos])==k && pos < minInd)
            minInd=pos;
        if(countDigits(arr[pos]) > k)
            left = pos + 1;
        else right = pos - 1;
    }
    if(minInd==len)
        return-1;
    return arr[minInd];

}

int binSearchKEl2(int *arr,int len,int k){
    int left = 0;
    int right = len-1;
    int pos;
    int maxInd=-1;
    while(left <= right)
    {
        pos = left + (right - left)/2;
        if(countDigits(arr[pos]) == k && pos > maxInd)
            maxInd = pos;
        if(countDigits(arr[pos]) < k)
            right = pos - 1;
        else left = pos + 1;
    }

    if(maxInd==-1)
        return -1;
    return arr[maxInd];
}


/// Dat je niz cijelih brojeva, koji je prvobitno bio
/// sortiran rastuce, ali je zatim ciklicno pomjeren za
/// k mesta udesno. Pronaci vrijednost broja k.
int binSearchShift(int *arr,int len){
    int left = 0;
    int right = len-1;
    int pos;
     while(left < right){
        int pos = (right + left)/2;
        if(arr[pos] > arr[right])
            left = pos+1;
        else
            right = pos;
        }
    return left;
}

int binSearchKInd(int *arr,int len,int k){
    int left = 0;
    int right = len - 1;
    int pos;
    int ind = len;
    while(left <= right){
        pos = left + (right - left)/2;
        if(countDigits(arr[pos]) == k && pos < ind)
            ind = pos;
        if(countDigits(arr[pos]) < k)
            left = pos +1;
        else right = pos -1;
    }

    if(ind == len)
        return -1;
    return ind;
}

int findClosestInd(int *arr,int len,int left,int right ,int close ,int el){
    if(left > right)
        return close;
    int pos = left+(right - left)/2;
    if(arr[pos] == el)
        return pos;
    if(std::abs(arr[pos] - el) < std::abs(arr[close]-el))
        close = pos;
    if(arr[pos] > el)
        return findClosestInd(arr,len,left,pos-1,close,el);
    else return findClosestInd(arr,len,pos+1,right,close,el);
}



int main()
{
    int len;
    std::cout<<"Len: ";
    std::cin>>len;
    int *arr = new int[len];

    fillArr(arr,len);

    int k;
    std::cout<<"k: ";
    std::cin>>k;


    std::cout<<findClosestInd(arr,len,0,len-1,0,k);
    return 0;
}
