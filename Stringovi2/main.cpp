#include <iostream>
#include <string>

void obrniStr(std::string& str){
    int len = str.length();
    for(int i = 0; i < len/2;i++)
        std::swap(str[i],str[len-1-i]);
}

void saberi(std::string a,std::string b){
    int i = a.length()-1;
    int j = b.length()-1;
    std::string zbir = "";
    int ost = 0;
    int bitA,bitB;
    while(i>=0 || j>=0 || ost){
        if(i>=0)
            bitA=a[i]-'0';
        else bitA=0;
        if(j>=0)
            bitB=b[j]-'0';
        else bitB=0;
        int sum = bitA+bitB+ost;
        ost = sum/2;
        zbir.push_back(sum%2+'0');
        i--;
        j--;
    }
    obrniStr(zbir);
    std::cout<<zbir<<std::endl;
}

int main()
{
    std::string a,b;
    std::cin>>a>>b;
    saberi(a,b);
    return 0;
}
