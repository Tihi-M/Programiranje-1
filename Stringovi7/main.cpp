#include <iostream>
#include <string>
///ERASE: erase(x,n) od x pozicije brise n chars
void changeCase(std::string& str){
    for(int i = 0;i < str.length()-1;i++){
        if(str[i] == '_'){
            str[i+1]=str[i+1]-'a'+'A';
            str.erase(i,1);
        }
    }
    std::cout<<str<<std::endl;
}

int main()
{
    std::string str;
    std::cin>>str;
    changeCase(str);
    return 0;
}
