#include <iostream>
#include <string>

void excel(std::string str){
    int stepen=1;
    int coll=0;
    for(int i = str.length()-1;i>=0;i--)
    {
        coll+=(str[i]-'A'+1)*stepen;
        stepen*=26;
    }
    std::cout<<coll<<std::endl;

}

int main()
{
    std::string str;
    std::cin>>str;
    excel(str);
    return 0;
}
