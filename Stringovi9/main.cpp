#include <iostream>
#include <string>
void obrniStr(std::string& str){
    for(int i = 0; i < str.length()/2;i++)
        std::swap(str[i],str[str.length()-1-i]);
}

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
