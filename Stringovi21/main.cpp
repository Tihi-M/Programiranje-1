#include <iostream>

std::string razlikaSaPonavljanjima(std::string strA,std::string strB){
    int alpha[26]={0};

    for(int i = 0; i < strA.length();i++)
        alpha[strA[i]-'a']++;

    for(int i = 0; i < strB.length();i++)
        alpha[strB[i]-'a']--;

    std::string razlika="";
    for(int i = 0; i < 26;i++){
        if(alpha[i] > 0){
            while(alpha[i] > 0)
            {
                razlika.push_back(i+'a');
                alpha[i]--;
            }
        }
        else{
                while(alpha[i] < 0)
            {
                razlika.push_back(i+'a');
                alpha[i]++;
            }
        }
    }
    return razlika;
}

int main()
{
    std::string strA,strB;
    std::cin>>strA>>strB;

    std::cout<<razlikaSaPonavljanjima(strA,strB);
    return 0;
}
