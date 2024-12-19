#include <iostream>

void expandKey(std::string& key,std::string keyCopy,int len){
    int i = 0;
    while(key.length() != len){
        key.push_back(keyCopy[i]);
        i++;
        if(i == keyCopy.length())
            i=0;
    }
}

void vizenerovEn(std::string& str,std::string key){
    int len = str.length();
    expandKey(key,key,len);

    for(int i = 0; i < len;i++)
        if(isalpha(str[i]))
            str[i] = (str[i]-'a'+key[i]-'a')%26+'a';
}

void vizenerovDe(std::string& str,std::string key){
    int len = str.length();
    expandKey(key,key,len);

    for(int i = 0; i < len;i++)
        if(isalpha(str[i]))
            str[i] = (str[i]-key[i]+26)%26+'a';
}


int main()
{
    std::string str,key;
    std::cin>>str>>key;

    vizenerovEn(str,key);
    std::cout<<str<<std::endl;

    vizenerovDe(str,key);
    std::cout<<str<<std::endl;
    return 0;
}
