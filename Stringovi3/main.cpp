#include <iostream>
#include <string>

void prefiks(std::string a, std::string b){
    std::string pref="";
    for(int i = 0; i < a.length() && i < b.length();i++)
        if(a[i] == b[i])
            pref.push_back(a[i]);
        else break;
    std::cout<<pref<<std::endl;
}

int main()
{
    std::string a,b;
    std::cin>>a>>b;
    prefiks(a,b);
    return 0;
}
