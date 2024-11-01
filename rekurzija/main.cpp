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
int main()
{
    int n;
    std::cin>>n;

    std::cout<<maxDigit(n);
    return 0;
}
