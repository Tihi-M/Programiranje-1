#include <iostream>

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

void bubbleSort(int *arr,int len){
    for(int i = 0; i < len - 1;i++)
    {
        bool swapped = false;
        for(int j = 0; j < len - i -1;j++){
            if(arr[j] > arr[j+1])
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

void biblioteka(int *vremena,int len,int ukupnoVremena){
    bubbleSort(vremena,len);

    int left = vremena[0];
    int right = vremena[len-1];
    int vremenaProslo=0;
    int rez=0;
    int pos;
    while(left<=right){
        pos = left+(right-left)/2;
        if(vremenaProslo+vremena[pos]<=ukupnoVremena){
            rez = pos;
            vremenaProslo+=vremena[pos];
            left=pos+1;
        }
        else right = pos-1;
    }

    std::cout<<rez;
}

int main()
{
    int n,t;
    std::cout<<"N, t: ";
    std::cin>>n>>t;

    int *arr= new int[n];
    fillArr(arr,n);

    biblioteka(arr,n,t);
    return 0;
}
