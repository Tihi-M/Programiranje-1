#include <iostream>
#include <cstring>
#include <string>

void transformStr(std::string& str){

    for(int i = 0; i < str.length()-1;i++)
        if(i==0 && str[i] == '#')
            str.erase(str.begin());
        else if(str[i+1] == '#'){
                str.erase(str.begin()+i);
                str.erase(str.begin()+i);
        }
    for(int i =0 ;i < str.length();i++)
        if(str[i]=='#')
            transformStr(str);
}

int main()
{
    std::string str1,str2;
    std::cin>>str1>>str2;
    transformStr(str1);
    transformStr(str2);

    std::cout<<str1<<" "<<str2<<std::endl;
    if(str1==str2)
        std::cout<<true;
    else std::cout<<false;
    return 0;
}
