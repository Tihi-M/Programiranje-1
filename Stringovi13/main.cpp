#include <iostream>
#include <string.h>

void reverseAlpha(std::string& str){
    int len = str.length();
    int first=0;
    int last=len-1;
    while(first < last){
        if(isalpha(str[first])){
            if(isalpha(str[last])){
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
    reverseAlpha(str);
    std::cout<<str<<std::endl;
    return 0;
}
