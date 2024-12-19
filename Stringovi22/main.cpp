#include <iostream>

void containsA(std::string str1,std::string str2){
    int alpha[26]={0};

    for(int i = 0; i < str1.length();i++)
        alpha[str1[i]-'a']++;

    for(int i = 0; i < str2.length();i++)
        alpha[str2[i]-'a']--;

    for(int i =0; i < 26;i++)
        if(alpha[i] > 0){
        std::cout<<"String B ne sadrzi A"<<std::endl;
        return;
    }

    std::cout<<"String B sadrzi A"<<std::endl;
}

int main()
{
    std::string strA,strB;
    std::cin>>strA>>strB;
    containsA(strA,strB);
    return 0;
}
