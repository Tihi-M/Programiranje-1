#include <iostream>

bool prisustvo(std::string str){
    int o=0;
    int z=0;
    for(int i = 0; i < str.length();i++){
        if(str[i] != 'O'){
            if(o > 2)
                return false;
            o=0;
        }
        else o++;
        if(str[i] != 'Z'){
            if(z > 3)
                return false;
            z=0;
        }
        else z++;
        std::cout<<o <<" "<<z<<std::endl;
    }
    return true;
}
int main()
{
    std::string str;
    std::cin>>str;
    std::cout<<prisustvo(str);
    return 0;
}
