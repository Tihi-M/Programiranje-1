#include <iostream>

void anagrami(std::string str1,std::string str2){
    int alpha[26] = {0};
    if(str1.length() != str2.length()){
        std::cout<<"Nisu anagrami"<<std::endl;
        return;
    }

    for(int i = 0; i < str1.length();i++){
        alpha[str1[i]-'a']++;
        alpha[str2[i]-'a']--;
    }

    for(int i =0 ; i <26;i++)
        if(alpha[i]!=0){
        std::cout<<"Nisu anagrami"<<std::endl;
        return;
    }
    std::cout<<"Jesu anagrami"<<std::endl;

}

int main()
{
    std::string str1,str2;
    std::cin>>str1>>str2;
    anagrami(str1,str2);
    return 0;
}
