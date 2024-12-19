#include <iostream>
#include <string>
void sifruj(std::string& str,int key){
    key=key%26;
    for(int i =0 ; i < str.length();i++){
        if(isalpha(str[i])){
            if(islower(str[i]))
                str[i] ='a'+(str[i]-'a'+key)%26;
            else str[i] ='A'+(str[i]-'A'+key)%26;
        }
    }

}

void desifruj(std::string& str,int key){
    key=key%26;
    for(int i = 0; i < str.length();i++)
        if(isalpha(str[i])){
            if(islower(str[i]))
                str[i] ='a'+(str[i]-'a'-key+26)%26;
            else str[i] ='A'+(str[i]-'A'-key+26)%26;
        }
}
int main()
{
    std::string str;
    int kljuc;
    getline(std::cin,str);
    std::cin>>kljuc;

    sifruj(str,kljuc);
    std::cout<<str<<std::endl;
    desifruj(str,kljuc);
    std::cout<<str<<std::endl;
    return 0;
}
