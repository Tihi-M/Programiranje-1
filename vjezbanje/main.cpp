#include <iostream>

void ispis1(int n){
    if(n == 0)
        return;
    ispis1(n/10);
    std::cout<<n%10<<" ";
}

void ispis2(int n){
    if(n == 0)
        return;
    std::cout<<n%10<<" ";
    ispis2(n/10);
}

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
    std::cout << *arr << " ";
    printArr(arr+1,len-1);
}

void f(int *arr,int len){
    if(len == 1)
        return;
    if(*(arr-1) + *(arr+1) == *arr){
        f(arr+1,len-1);
        *arr =0;
    }
    else f(arr+1,len-1);
}

void bubbleSort(int *arr,int len){
    for(int i = 0; i < len-1;i++){
        bool swapped = false;

        for(int j = 0; j<len-1-i;j++)
            if(arr[j] > arr[j+1])
            {
                std::swap(arr[j],arr[j+1]);
                swapped = true;
            }

        if(!swapped)
            break;
    }


}

void binSearch1(int *arr,int len,int k){
    bubbleSort(arr,len);
    int left = 0;
    int right = len-1;
    int pos;
    while(left<=right){
        pos= left+(right-left)/2;
        if(arr[pos] == k)
        {
            std::cout<<pos;
            return;
        }
        if(arr[pos] > k)
            right = pos-1;
        else left = pos+1;
    }
    std::cout<<-1;
}

int main()
{
    int n,k;
    std::cin>>n>>k;

    int *arr = new int[n];
    fillArr(arr,n);
    printArr(arr,n);

    //ispis1(n);
    //ispis2(n);
    binSearch1(arr,n,k);
    return 0;
}
