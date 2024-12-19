#include <iostream>

void reverse_(std::string& str){
    for(int i =0; i < str.length()/2;i++)
        std::swap(str[i],str[str.length()-i-1]);
}

void reverseWords(std::string& str){
    int i =0;
    int start=0;
    std::string temp="";
    while(i < str.length())
    {
        if(i == str.length() || str[i] == ' '){
            reverse_(temp);
            str.replace(start,temp.length(),temp);
            start=i+1;
            i++;
            temp="";
        }
        else {
            temp.push_back(str[i]);
            i++;
        }
    }
}

int main()
{
    std::string str;
    getline(std::cin,str);
    reverseWords(str);
    std::cout<<str;
    return 0;
}
