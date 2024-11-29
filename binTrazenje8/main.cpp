#include <iostream>

void fillArr(int *arr,int len){
    if(len == 0)
        return;
    std::cin>>*arr;
    fillArr(arr+1,len-1);
}

void printArr(int *arr,int len){
    if(len == 0)
    {
        std::cout<<std::endl;
        return;
    }
    std::cout<<*arr;
}

void bubbleSort(int *arr,int len){
    for(int i = 0; i < len - 1;i++)
    {
        bool swapped = false;
        for(int j = 0;j < len-i-1;j++)
            if(arr[j] > arr[j+1]){
                swapped = true;
                std::swap(arr[j],arr[j+1]);
            }

        if(!swapped)
            break;
        swapped = false;
    }
}

int arrSum(int *arr,int len){
    if(len == 0)
        return 0;
    return *arr+arrSum(arr+1,len-1);
}

bool mozeSePrevesti(int *igracke,int len,int brDana,int teret){
    int suma = 0;
    int dan=1;
    for(int i = 0;i < len;i++){
        suma+=igracke[i];

        if(suma == teret){
            dan++;
            suma=0;
        }
        if(suma > teret){
            dan++;
            suma = igracke[i];
        }
    }
    return dan<=brDana;
}

void fabrika(int brDana,int *igracke,int brIgr){
    bubbleSort(igracke,brIgr);
    int tezina = arrSum(igracke,brIgr);

    int left = 1;
    int right = tezina;
    int rez=0;
    int pos;
    while(left<=right){
        pos = left+(right-left)/2;
        if(mozeSePrevesti(igracke,brIgr,brDana,pos))
        {
            right = pos-1;
            rez = pos;
        }
        else left = pos+1;
    }
    std::cout<<rez;
}

int main()
{
    int n,brIgracaka;
    std::cout<<"Broj dana, broj igracaka:";
    std::cin>>n>>brIgracaka;

    int *igracke= new int[brIgracaka];
    fillArr(igracke,brIgracaka);

    fabrika(n,igracke,brIgracaka);
    return 0;
}
