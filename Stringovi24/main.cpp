#include <iostream>
#include <vector>

void ponavljanja(std::string genom, int n){
    std::vector<std::string> pronadjeni;

    for(int i =0; i < genom.length()-n+1;i++){
        std::string temp = "";
        for(int j =i; j < i+n;j++)
            temp.push_back(genom[i]);

        bool jePronadjen=false;
        for(int k = 0; k < pronadjeni.size();k++)
            if(pronadjeni[k] == temp){
            jePronadjen=true;
            break;
        }
        if(!jePronadjen)
        {
            for(int l = i+n;l < genom.length()-n+1;l++){
               std::string temp2 = "";
                for(int m = l; m < l+n;m++ )
                    temp2.push_back(genom[m]);
                if(temp2 == temp){
                    pronadjeni.push_back(temp);
                }
            }
        }
    }
    for(int i = 0; i < pronadjeni.size();i++)
        std::cout<<pronadjeni[i]<<std::endl;
}

int main()
{
    std::string str;
    int n;
    std::cin>>str>>n;
    ponavljanja(str,n);
    return 0;
}

