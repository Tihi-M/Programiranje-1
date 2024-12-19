#include <iostream>
#include <vector>
bool sadrzi4(std::string genom){
    bool A=false,C=false,T=false,G=false;
    for(int i = 0; i < genom.length();i++)
        if(genom[i] == 'A')
            A=true;
        else if (genom[i] == 'C')
            C=true;
        else if (genom[i] == 'T')
            T=true;
        else if (genom[i] == 'G')
            G=true;
        else if(A&&G&&T&&C)
            return true;
    if(A&&G&&T&&C)
            return true;
    return false;
}

void actg(std::string genom,int n){
    std::vector<std::string> pronadjeni;
    for(int i = 0; i < genom.length()-n+1;i++){
        std::string temp = "";
        for(int j = i; j < i+n;j++)
            temp.push_back(genom[j]);

        if(sadrzi4(temp)){
            bool vecNadjen=false;
            for(int i = 0; i < pronadjeni.size();i++)
                if(pronadjeni[i] == temp)
                {
                    vecNadjen= true;
                    break;
                }
            if(!vecNadjen)
                pronadjeni.push_back(temp);
        }
    }
    for(int i =0; i <pronadjeni.size();i++)
        std::cout<<pronadjeni[i]<<std::endl;
}

int main()
{
    std::string str;
    int n;
    std::cin>>str>>n;
    actg(str,n);
    return 0;
}
