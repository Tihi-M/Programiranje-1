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
    for(int i = 0; i < len - 1;i++){
        bool swapped = false;
        for(int j = 0; j < len-i-1;j++)
            if(arr[j] > arr[j+1]){
                swapped = true;
                std::swap(arr[j],arr[j+1]);
            }
        if(!swapped)
            break;
        swapped = false;
    }
}

bool nijeZima(int *kuce,int *grijaci,int len1,int len2,int pos){
    int i=0;
    int j=0;
    while(i < len1 && j < len2){
        if(std::abs(kuce[i]-grijaci[j]) <= pos)
            i++;
        else j++;
    }
    return i==len1;

}

void zima(int *kuce,int *grijaci,int len1,int len2){
    bubbleSort(kuce,len1);
    bubbleSort(grijaci,len2);

    int rez = 0;
    int left=0;
    int right = std::max(kuce[len1-1],grijaci[len2-1]);
    int pos;
    while(left<=right){
        pos = left+(right-left)/2;
        if(nijeZima(kuce,grijaci,len1,len2,pos))
        {
            rez=pos;
            right = pos-1;
        }
        else left = pos+1;
    }

    std::cout<<rez;
}

int main()
{
    int len1,len2;
    std::cout<<"Broj kuca, broj grijaca: ";
    std::cin>>len1>>len2;

    int *kuce = new int[len1];
    int *grijaci = new int[len2];

    fillArr(kuce,len1);
    fillArr(grijaci,len2);

    zima(kuce,grijaci,len1,len2);
    return 0;
}
