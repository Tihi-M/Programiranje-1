#include <iostream>
#include <string.h>

void unija(std::string str1,std::string str2){
    int* alph = new int[26];
    std::string unija="";
    for(int i = 0; i < 26;i++)
        alph[i]=0;
    for(int i = 0;i < str1.length();i++)
        if(alph[str1[i]-'a'] == 0){
            unija.push_back(str1[i]);
            alph[str1[i]-'a']++;
        }

    for(int i = 0;i < str2.length();i++)
        if(alph[str2[i]-'a'] == 0){
            unija.push_back(str2[i]);
            alph[str2[i]-'a']++;
        }
    std::cout<<"Unija: "<<unija<<std::endl;
}

void presjek(std::string str1,std::string str2){
    int* alph = new int[26];
    std::string presjek="";
    for(int i = 0; i < 26;i++)
        alph[i]=2;
    for(int i = 0;i < str1.length();i++)
        if(alph[str1[i]-'a'] == 2){
            alph[str1[i]-'a']--;
        }

    for(int i = 0;i < str2.length();i++)
        if(alph[str2[i]-'a'] == 1){
            presjek.push_back(str2[i]);
            alph[str2[i]-'a']--;
        }
    std::cout<<"Presjek: "<<presjek<<std::endl;
}

void simetricnaRazlika(std::string str1,std::string str2){
    int* alph1 = new int[26];
    int* alph2 = new int[26];
    std::string razlika="";
    for(int i = 0; i < 26;i++){
        alph1[i]=0;
        alph2[i]=0;
    }
    for(int i = 0;i < str1.length();i++)
        if(alph1[str1[i]-'a'] == 0)
            alph1[str1[i]-'a']++;

    for(int i = 0;i < str2.length();i++)
        if(alph2[str2[i]-'a'] == 0)
            alph2[str2[i]-'a']++;

    for(int i = 0;i < 26;i++)
        if(alph1[i] != alph2[i])
            razlika.push_back(i+'a');
    std::cout<<"Simetricna razlika: "<<razlika<<std::endl;
}


int main()
{
    std::string str1,str2;
    std::cin>>str1>>str2;
    unija(str1,str2);
    presjek(str1,str2);
    simetricnaRazlika(str1,str2);
    return 0;
}
