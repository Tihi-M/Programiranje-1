#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void stampanje_piramide(int h){
    int i = 1;
    int j = 0;
    while(i < h){
        while(j < i){
            cout<<"* ";
            j++;
        }
        cout<<endl;
        i++;
        j=0;
    }

    while(h > 0){
        while(h > j){
            cout<<"* ";
            j++;
        }
        h--;
        cout<<endl;
        j=0;
    }
}

bool isEven(int n){
    if(n % 2 == 0)
        return true;
    return false;
}

void fillArr(int *arr,int len){
    srand(time(0));
    for(int i = 0; i < len;i++)
        arr[i] = rand()%100;
}

void printArr(int *arr,int len){
    for(int i = 0;i < len;i++)
        cout<<arr[i]<< " ";
    cout<< endl;
}


int nizovi1(int *n,int len,int k){
    int cnt= 0;
    for(int i = 0; i < len;i++){
        if(n[i] > k && n[i] % 2 == 0)
            cnt++;
    }
    return cnt;
}

int countEven(int *arr,int len){
    int cnt = 0;
    for(int i =0; i < len;i++)
        if(arr[i] % 2 == 0)
        cnt++;
    return cnt;
}

void separateArr(int *arr,int len, int cntEven){
    int *arr1 = new int[cntEven];
    int *arr2 = new int[len-cntEven];

    int i1=0;
    int i2=0;

    for(int i = 0; i < len;i++){
        if(arr[i] % 2 == 0){
            arr1[i1] = arr[i];
            i1++;
        }
        else{
            arr2[i2] = arr[i];
            i2++;
        }
    }

    printArr(arr1,cntEven);
    printArr(arr2,len-cntEven);
}

int* duplicateArr(int *arr,int len){
    int *arr2 = new int[len*2];
    int i2 = 0;
    for(int i = 0 ; i < len; i++){
        arr2[i2] = arr[i];
        arr2[i2+1] = arr[i];
        i2+=2;
    }
    return arr2;
}

int* oddEven(int *arr,int len){
    int *arr2= new int[len];
    int endd = len-1;
    int start = 0;

    for(int i = 0; i < len;i++)
    {
        if(arr[i] % 2 == 0){
            arr2[start] = arr[i];
            start++;
        }
        else{
            arr2[endd] = arr[i];
            endd--;
        }
    }
    return arr2;
}

int main()
{
    int len;
    cin >> len;
    int *niz = new int[len];
    fillArr(niz,len);
    printArr(niz,len);

    niz = oddEven(niz,len);
    printArr(niz,len);
    return 0;
}
