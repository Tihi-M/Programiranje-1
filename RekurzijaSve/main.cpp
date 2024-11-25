#include <iostream>
///Zadaci iz rekurzije iz p2 i proslog sem
void ispis1(int n){
    if(n==0)
    {
        std::cout<<std::endl;
        return;
    }
    ispis1(n/10);
    std::cout<<n%10<<" ";
}

void ispis2(int n){
    if(n==0)
    {
        std::cout<<std::endl;
        return;
    }
    std::cout<<n%10<<" ";
    ispis2(n/10);
}

int brojParnih(int n){
    if(n==0)
        return 0;
    if(n%10%2 == 0)
        return 1 + brojParnih(n/10);
    return brojParnih(n/10);
}

int najvecaCifra(int n){
    if(n==0)
        return 0;
    if( n%10 > najvecaCifra(n/10))
        return n%10;
    else return najvecaCifra(n/10);
}

int ukloni(int n,int c){
    if(n==0)
        return 0;
    if(n%10 == c)
        return ukloni(n/10,c);
    else return n%10+ukloni(n/10,c)*10;
}

int brojCifara(int n){
    if(n==0)
        return 0;
    return 1+brojCifara(n/10);
}

void napraviNiz(int *arrEnd,int num){
    if(num == 0)
        return;
    *(arrEnd-1) = num%10;
    napraviNiz(arrEnd-1,num/10);
}

void printArr(int *arr,int len){
    if(len == 0){
        std::cout<<std::endl;
        return;
    }
    std::cout<<*arr << " ";
    printArr(arr+1,len-1);
}

int obrniCifre(int n, int m){
    if(n==0)
        return m;
    m=m*10+n%10;
    return obrniCifre(n/10,m);
}

void fillArr(int *arr,int len){
    if(len==0)
        return;
    std::cin>>*arr;
    fillArr(arr+1,len-1);
}

void obrniNiz(int *arr,int len,int i){
    if(i == len/2)
        return;
    int temp = arr[i];
    arr[i] = arr[len-1-i];
    arr[len-i-1] = temp;
    obrniNiz(arr,len,i+1);
}

int palindrom(int *arr, int n,int i){
    if(i == n/2)
        return 1;
    if (*(arr+i) != *(arr+n-1-i))
        return 0;
    return palindrom(arr,n,i+1);
}

int dodaj0(int n){
    if(n==0)
        return 0;
    if(n%10%2 != 0)
        return n%10*10+dodaj0(n/10)*100;
    else return n%10+dodaj0(n/10)*10;
}

int skalarniProizvod(int *a,int *b, int len){
    if(len == 0)
        return 0;
    return *a*(*b)+skalarniProizvod(a+1,b+1,len-1);
}

int f3(int n){
    if(n == 0)
        return 0;
    if(n%10 == 2 && n%100/10%2 != 0)
        return n%10+f3(n/100)*10;
    else return n%10 + f3(n/10)*10;
}

void f(int *arr,int len,int sum){
    if(len == 0)
        return;
    if(*arr+*(arr+1) == sum)
    {
        f(arr+1,len-1,sum);
        *arr=0;
        *(arr+1)=0;
    }
    else f(arr+1,len-1,sum);
}

int izbaciParne(int n){
    if(n==0)
        return 0;
    if(n%10%2==0)
        return izbaciParne(n/10);
    else return n%10+izbaciParne(n/10)*10;
}

int maksimumNiza(int *arr,int len){
    if(len == 0)
        return 0;
    if(*arr > maksimumNiza(arr+1,len-1))
        return *arr;
    else return maksimumNiza(arr+1,len-1);
}

void f3(int *arr,int len){
    if(len == 0)
        return;
    if(*arr%2==0 && *(arr+1)%2==0)
        *arr=*arr-1;
    f3(arr+1,len-1);
}

void sumaPrethodnih(int *arr,int len,int sum){
    if(len == 0)
        return;
    if(*arr>sum){
        sum+=*arr;
        sumaPrethodnih(arr+1,len-1,sum);
        *arr=0;
    }
    else{
        sum+=*arr;
        sumaPrethodnih(arr+1,len-1,sum);
    }
}

void sumaSusjeda(int *arr,int len){
    if(len == 0)
        return;
    if(*arr == *(arr-1)+*(arr+1))
    {
        sumaSusjeda(arr+1,len-1);
        *arr=0;
    }
    else sumaSusjeda(arr+1,len-1);
}

int equalArr(int *a,int *b,int len){
    if(len == 0)
        return 1;
    if( *a != *b)
        return 0;
    else equalArr(a+1,b+1,len-1);
}

int *shiftK(int *arr,int len,int k){

    int *pomocniNiz = new int[len];
    //prvo kopiramo len-k clanova niza
    // na pocetne pozicije pomocnog niza
    for(int i = 0;i < len-k;i++)
        pomocniNiz[i] = arr[i+k];


    //ostalo je da na kraj pomocnog niza
    //prebacimo k clanova sa originalnog niza
    int j = 0;
    for(int i = len - k;i < len;i++){
        pomocniNiz[i] = arr[j];
        j++;
    }

    return pomocniNiz;
}

int stepen(int n,int k){
    if(k == 0)
        return 1;
    return n*stepen(n,k-1);
}

int paranBrCif(int n,int sum){
    if(n==0)
        {
            if(sum%2==0)
                return 1;
            return 0;
        }
    paranBrCif(n/10,sum+1);
}

int fact(int n){
    if(n==0)
        return 1;
    if(n==1)
        return 1;
    return n*fact(n-1);
}

int fibb(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return fibb(n-1)+fibb(n-2);
}

void fibbToN(int n,int i){
    if(i>n)
        return;
    std::cout<<i<<": "<<fibb(i)<<std::endl;
    fibbToN(n,i+1);
}

int fibb2(int n,int a,int b){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return a*fibb2(n-1,a,b)+b*fibb2(n-2,a,b);
}

int zbirCif(int n){
    if(n==0)
        return 0;

    return n%10+zbirCif(n/10);
}

int zbirEl(int *arr,int len){
    if(len == 0)
        return 0;
    return *arr+zbirEl(arr+1,len-1);
}

int zbirElR(int *arr,int len){
    if(len == 0)
        return 0;
    return *arr+zbirElR(arr-1,len-1);
}

int countReps(int *arr,int len,int a){
    if(len == 0)
        return 0;
    if(*arr == a)
        return 1+countReps(arr+1,len-1,a);
    return countReps(arr+1,len-1,a);
}

int istaTri(int *arr,int len,int a,int b,int c){
    if(len==0)
        return 0;
    if(*arr == a && *(arr+1) == b && *(arr+2) == c)
        return 1;
    else return istaTri(arr+1,len-1,a,b,c);
}

int contains(int *arr1,int *arr2,int len1,int len2,int i){
    if(len1<0)
        return 0;
    if(i == len2)
        return 1;
    if(*arr1 == *arr2){
        std::cout<<*arr1 << " " <<*arr2<< " " << i<<std::endl;
        return contains(arr1+1,arr2+1,len1-1,len2,i+1);
    }
    else {
            std::cout<<*arr1 << " " <<*arr2<< " " << i<<std::endl;
            return contains(arr1+1,arr2-i,len1-1,len2,0);
    }
}

int main()
{
    int len,len2,k;
    std::cin>> len;
    int *arr = new int[len];
    fillArr(arr,len);

    std::cout<<"drugi niz:";
    std::cin>> len2;
    int *arr2 = new int[len2];
    fillArr(arr2,len2);
    //printArr(arr,len);
    //arr = shiftK(arr,len,2);
    //printArr(arr,len);
    std::cout<<contains(arr,arr2,len,len2,0);

    return 0;
}
