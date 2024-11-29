#include <iostream>

bool printed(int n,int x,int y,int z){
    int prvi = z/x;
    int drugi = z/y;
    int oba = z/(x+y);
    int ukupno = prvi+drugi-oba;
    return ukupno >= n;

}
void copyBin(int brKopija, int prvi,int drugi){
    int left = 1;
    int right = brKopija;
    int rez=1;
    int pos;
    while(left<=right){
         pos =(right+left)/2;
        if(printed(brKopija,prvi,drugi,pos)){
            rez=pos;
            right = pos-1;
        }
        else left = pos+1;
    }
    std::cout<<rez;
}

int main()
{
    int brKopija,prvi,drugi;
    std::cout<<"Broj kopija, brzina prvog, brzina drugog:";
    std::cin>>brKopija>>prvi>>drugi;

    copyBin(brKopija,prvi,drugi);
    return 0;
}
