#include <iostream>
///Prva grupa zadataka za vjezbu
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
    std::cout<< *arr << " ";
    printArr(arr+1,len-1);
}

int zad26(int *arr,int len,int k){
    int cnt = 0;
    for(int i = 0; i < len;i++)
        if(arr[i]%2 == 0 && arr[i] > k)
            cnt++;
    return cnt;
}

int zad26Rec(int *arr, int len,int k){
    if(len == 0)
        return 0;
    if(*arr%2 == 0 && *arr>k)
        return 1+zad26Rec(arr+1,len-1,k);
    else return zad26Rec(arr+1,len-1,k);
}

int brojParnih(int *arr,int len){
    if(len==0)
        return 0;
    if(*arr%2==0)
        return 1+brojParnih(arr+1,len-1);
    else return brojParnih(arr+1,len-1);
}

void zad27(int *arr,int *c,int *b,int len){
    for(int i = 0; i < len;i++)
    {
        if(arr[i]%2 == 0){
            *c=arr[i];
            c++;
        }
        else{
            *b=arr[i];
            b++;
        }
    }
}

void zad27Rec(int *arr,int *c,int *b,int len){
    if(len == 0)
        return;
    if(*arr%2 == 0)
    {
        *c=*arr;
        zad27Rec(arr+1,c+1,b,len-1);
    }
    else{
        *b=*arr;
        zad27Rec(arr+1,c,b+1,len-1);
    }
}

int *zad28(int *arr,int len){
    int *copyArr=new int[len*2];
    for(int i =0 ; i < len;i++){
        *copyArr=arr[i];
        *(copyArr+1)=arr[i];
        copyArr+=2;
    }
    return copyArr-len*2    ;
}

void zad28Rec(int *arr,int *arr2,int len){
    if(len == 0)
        return;
    *arr2=*arr;
    *(arr2+1)=*arr;
    zad28Rec(arr+1,arr2+2,len-1);
}

int *zad29(int *arr,int len){
    int *arr2=new int[len];
    int j = 0;
    int k = len-1;
    for(int i =0;i < len;i++){
        if(arr[i] % 2 == 0){
            arr2[j] = arr[i];
            j++;
        }
        else{
            arr2[k] = arr[i];
            k--;
        }
    }
    return arr2;
}

void zad29Rec(int *arr,int *arr2,int i,int j,int len){
    if(len==0)
        return;
    if(*arr%2==0){
        arr2[i]=*arr;
        zad29Rec(arr+1,arr2,i+1,j,len-1);
    }
    else{
        arr2[j]=*arr;
        zad29Rec(arr+1,arr2,i,j-1,len-1);
    }
}
int main()
{
    int len;
    std::cin>>len;
    int *arr = new int[len];
    fillArr(arr,len);
    int *arr2 = new int[len];
    zad29Rec(arr,arr2,0,len-1,len);
    printArr(arr2,len);
    return 0;
}

