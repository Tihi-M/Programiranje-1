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
    std::cout<<*arr<<" ";
    printArr(arr+1,len-1);
}

void bubbleSort(int *arr,int len){
    for(int i = 0; i < len-1;i++){
        bool swapped = false;
        for(int j = 0; j < len-i-1;j++){
            if(arr[j] > arr[j+1]){
                std::swap(arr[j],arr[j+1]);
                swapped = true;
            }
            if(!swapped)
                break;
            swapped = false;
        }
    }

}

bool mozeSePovezati(int *duzine,int len,int ukupno,int tempDuzina){
    int duzina = 0;
    for(int i = 0; i < len;i++){
            duzina+=duzine[i]/tempDuzina;
            if(duzina >= ukupno)
                return true;
    }
    return false;
}

void poveziRacunare(int n,int *duzine,int len){
    bubbleSort(duzine,len);
    printArr(duzine,len);
    int left=1;
    int right = duzine[len-1];
    int pos;
    int rez=0;
    while(left<=right){
        pos = left+(right-left)/2;
        if(mozeSePovezati(duzine,len,n,pos)){
            rez = pos;
            left = pos+1;
        }
        else right = pos-1;
    }

    std::cout<<"Duzina kabla: "<<rez;
}

int main()
{
    int n,k;
    std::cout<<"N, K:";
    std::cin>>n>>k;

    int *arr=new int[k];
    fillArr(arr,k);

    poveziRacunare(n,arr,k);
    return 0;
}
