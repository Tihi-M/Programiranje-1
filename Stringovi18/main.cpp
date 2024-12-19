#include <iostream>

bool jePalindrom(std::string str){
    int len = str.length();
        for(int i =0 ; i <= len/2;i++)
            if(str[i] != str[len-1-i])
                return false;
    return true;
}

std::string najduziPalindrom(std::string str){
    for(int i =str.length()-1; i > 0;i--){
        for(int j = 0; j <= str.length()-i;j++){
            std::string temp ="";
            for(int k = j;k <j+i;k++)
                temp.push_back(str[k]);
            if(jePalindrom(temp)){
                    return temp;
            }
        }
    }
}
int main()
{
    std::string str;
    std::cin>>str;
    std::cout<<najduziPalindrom(str)<<std::endl;
    return 0;
}
