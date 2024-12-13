#include <iostream>

bool validnaSifra(std::string str){
    if(str.length()<8)
        return false;
    bool maloSlovo = false;
    bool velikoSlovo = false;
    bool cifra = false;
    bool specch = false;
    for(int i = 0; i < str.length();i++){
        if(str[i]>='a' && str[i]<='z')
            maloSlovo=true;
        else if(str[i]>='A' && str[i]<='Z')
            velikoSlovo=true;
        else if(str[i]>='0' && str[i]<='9')
            cifra=true;
        else if(str[i] == '#' || str[i] == '$' || str[i] == '@' || str[i] == '!')
            specch=true;
        if(maloSlovo && velikoSlovo && cifra && specch)
            return true;
    }
    return false;
}

int main()
{
    std::string str;
    std::cin>>str;
    std::cout<<validnaSifra(str);
    return 0;
}
