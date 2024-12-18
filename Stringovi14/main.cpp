#include <iostream>

bool jeSamoglasnik(char ch){
    std::string samoglasnici="AEIOUaeiou";
    for(int i =0; i < 10;i++)
        if(ch == samoglasnici[i])
            return true;
    return false;
}

void okreniSamoglasnike(std::string& str){
    int first = 0;
    int last = str.length()-1;
    while(first < last){
        if(jeSamoglasnik(str[first])){
            if(jeSamoglasnik(str[last]))
            {
                std::swap(str[first],str[last]);
                first++;
                last--;
            }
            else last--;
        }
        else first++;
    }
}

int main()
{
    std::string str;
    std::cin>>str;
    okreniSamoglasnike(str);
    std::cout<<str<<std::endl;
    return 0;
}
