#include <iostream>
#include <string>

void intToExcel(int n){
    std::string coll = "";
    while(n>0){
            n--;
        coll.push_back(n%26 + 'A');
        n/=26;
    }
    obrniStr(coll);
    std::cout<<coll<<std::endl;
}

int main()
{
    int n;
    std::cin>>n;
    intToExcel(n);
    return 0;
}
