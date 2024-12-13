#include <iostream>
#include <string>

void combine(std::string a,std::string b){
    std::string novi="";
    if(a.length() != b.length())
        return;
    for(int i = 0;i < a.length();i++)
    {
        novi.push_back(a[i]);
        novi.push_back(b[i]);
    }
    std::cout<<novi<<std::endl;

}

int main()
{
    std::string a,b;
    std::cin>>a>>b;
    combine(a,b);
    return 0;
}
