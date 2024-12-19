#include <iostream>

void zamijeni(std::string& str1,std::string str2,std::string str3){
    int pos = 0;
    while((pos = str1.find(str2,pos)) != std::string::npos){
        str1.replace(pos,str2.length(),str3);
        pos+=str3.length();
    }
}
int main()
{
    std::string str1,str2,str3;
    getline(std::cin,str1);
    std::cin>>str2>>str3;
    zamijeni(str1,str2,str3);
    std::cout<<str1;
    return 0;
}
