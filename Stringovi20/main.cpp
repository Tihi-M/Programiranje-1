#include <iostream>

int maxReps(std::string strA,std::string strB){
    int maxx=0;
    char maxChar='/';
    for(int i = 0; i < strA.length();i++)
    {
        int tempMax=0;
        for(int j = 0; j < strB.length();j++)
            if(strA[i] == strB[j])
                tempMax++;
        if(tempMax > maxx){
            maxChar=strA[i];
            maxx=tempMax;
        }
    }
    if(maxChar!='/'){
        std::cout<<"Najvise pojavljivanja ima char: "<<maxChar<<" - ";
        return maxx;
    }
    return 0;
}

int main()
{
    std::string strA,strB;
    std::cin>>strA>>strB;
    std::cout<<maxReps(strA,strB)<<std::endl;
    return 0;
}
