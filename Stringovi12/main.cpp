#include <iostream>

void abc(std::string str){
    int cntA=0;
    int cntB=0;
    int cntC=0;

    int i =0;
    while(str[i] == 'a' && i < str.length()){
        cntA++;
        i++;
    }
    while(str[i] == 'b' && i < str.length()){
        cntB++;
        i++;
    }
    while(str[i] == 'c' && i < str.length()){
        cntC++;
        i++;
    }

    if(cntA%2 ==0 && cntC%2==0 && cntA==cntC)
    {
        std::cout<<"Jeste oblika a^2n b^m c^2n";
        return;
    }
    else{
        std::cout<<"Nije oblika a^2n b^m c^2n";
        return;
    }
}

int main()
{
    std::string str;
    std::cin>>str;
    abc(str);
    return 0;
}
