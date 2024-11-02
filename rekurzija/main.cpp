#include <iostream>

///reverse order
void ispis1(int n){
    if(n == 0)
        return;
    std::cout<<n%10;
    ispis1(n/10);
}

///right order
void ispis2(int n){
    if(n == 0)
        return;
    ispis2(n/10);
    std::cout<<n%10;
}

///broj parnih cifara broja
int cntEvenDigit(int n){
    if(n == 0)
        return 0;
    else if(n % 10 % 2 == 0)
        return 1 + cntEvenDigit(n/10);
    else return cntEvenDigit(n/10);
}

///najveca cifra broja
int maxDigit(int n){
    if(n == 0)
        return 0;
    int maxx = n%10;
    if( maxx < maxDigit(n/10))
        return maxDigit(n/10);
    else return maxx;
}

///uklanja sva pojavljivanja cif c iz x
int rmDigit(int x,int c){
    if(x == 0)
        return 0;
    else if(x % 10 == c)
        return rmDigit(x/10,c);
    else return rmDigit(x/10,c)*10 + x%10;
}

///broj cifara broja
int cntDigit(int n){
    if(n == 0)
        return 0;
    return 1+cntDigit(n/10);
}

///kreira niz koji sadrzi cifre n;
void intToArr(int *arr,int n){
    if(n == 0)
        return;
    *arr = n%10;
    intToArr(arr-1,n/10);
}

///stampa clanove niza
void printArr(int *arr,int len){
    if(len == 0){
        std::cout<<std::endl;
        return;
    }
    std::cout<<*arr<<" ";
    printArr(arr+1,len-1);
}

///reverse num
int reverseNum(int n, int r){
    if(n == 0)
        return r;
    else{
        r = r*10+n%10;
        reverseNum(n/10,r);
    }
}
//1 2 3 4 5
//
///reverse array
void reverseArr(int *arr,int len,int i){
    if(i == len/2)
        return;
    else{
        int temp = arr[i];
        arr[i] = arr[len-i];
        arr[len-i]=temp;
        reverseArr(arr,len,i+1);
    }
}

///provjerava da li je niz palindrom
bool isPalindrom(int *arr,int n,int i){
    if(i == n/2)
        return true;
    else if(arr[i] != arr[n-i])
        return false;
    else return isPalindrom(arr,n,i+1);
}

///dodati 0 ispred svake neparne cifre broja
int dodaj0(int n){
    if(n == 0)
        return 0;
    else if(n % 10 % 2 == 1)
        return dodaj0(n/10)*100+n%10*10;
    else return dodaj0(n/10)*10+n%10;
}

///ako je ispred neparne cifre 2 uklanjamo je
int f3(int n){
    if(n == 0)
        return 0;
    else if(n%10%2 == 1 && n/10%10 == 2)
        return f3(n/10);
    else return f3(n/10)*10+n%10;
}

///ucitavanje niza
void fillArr(int *arr,int len){
    if(len == 0)
        return;
    std::cin>>*arr;
    fillArr(arr+1,len-1);
}

///postavljamo na nulu parove elemenata
///ciji je zbir jednak x
void updateArr1(int *arr,int len,int x){
    if(len == 1)
        return;
    else if(*arr+*(arr+1) == x)
    {
        updateArr1(arr+1,len-1,x);
        *arr = 0;
        *(arr+1) =0;
        return;
    }
    else updateArr1(arr+1,len-1,x);
}

///izbaciti parne cifre broja
int ukloniParne(int n){
    if(n==0)
        return 0;
    else if(n % 10 % 2 == 0)
        return ukloniParne(n/10);
    else return ukloniParne(n/10)*10+n%10;
}

///maksimum niza
int maxArr(int *arr,int len){
    if(len == 0)
        return 0;
    if( *arr < maxArr(arr+1,len-1))
        return maxArr(arr+1,len-1);
    else return *arr;
}

///ukoliko je element paran i nakon njega je paran br
///smanjujemo ga za jedan
void updateArr2(int *arr,int len){
    if(len == 1)
        return;
    else if(*arr%2 == 0 && *(arr+1)%2 == 0)
    {
        *arr = *arr-1;
        updateArr2(arr+1,len-1);
    }
    else updateArr2(arr+1,len-1);
}

///element postavlja na nulu ako je veci
///od sume prethodnih elemenata
void updateArr3(int *arr,int len,int sum){
    if(len == 0)
        return;
    else if(*arr > sum){
        sum+=*arr;
        *arr = 0;
        updateArr3(arr+1,len-1,sum);
    }
    else {
        sum+=*arr;
        updateArr3(arr+1,len-1,sum);
    }
}

/// ako je  broj jednak sumi prethodnog i narednog el
/// postavlja ga na nulu
void updateArr4(int *arr,int len){
    if(len == 0)
        return;
    else if(*arr == *(arr-1)+*(arr+1)){
        updateArr4(arr+1,len-1);
        *arr = 0;
    }
    else updateArr4(arr+1,len-1);
}

int main()
{
    int n,x;
    std::cin>>n;
    int *niz = new int[n];
    fillArr(niz,n);
    updateArr4(niz+1,n);
    printArr(niz,n);
    //std::cout<<maxArr(niz,n);

    return 0;
}
