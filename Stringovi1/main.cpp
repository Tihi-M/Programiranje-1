#include <iostream>
#include <string>
bool jeSamoglasnik(char c){
    if(c == 'a' || c == 'A' || c == 'e' || c == 'E' ||
       c == 'o' || c == 'O' || c == 'i' || c == 'I' ||
       c == 'u' || c == 'U')
       return true;
    return false;
}
///prvo samoglasnici pa suglasnici
///push_back za dodavanje karaktera na kraj stringa
void ispis1(std::string str){
    std::string samoglasnici="";
    for(int i=0;i < str.length();i++){
            if(jeSamoglasnik(str[i]))
                std::cout<<str[i];
            else samoglasnici.push_back(str[i]);
    }
    std::cout<<samoglasnici<<std::endl;
}

///lowercase
void toLowercase(std::string& str){
    for(int i = 0; i < str.length();i++)
        if(str[i]>='A' && str[i]<='Z')
            str[i] = str[i]-'A'+'a';
    std::cout<<str<<std::endl;
}

///izmedju dva velika slova staviti _
void velikaSlova(std::string& str){
    for(int i = 0; i < str.length()-1;i++)
        if(str[i]>='A' && str[i]<='Z' && str[i+1]>='A' && str[i+1]<='Z')
            str.insert(i+1,"_");

    std::cout<<str<<std::endl;
}

///umetni odgovarajuce malo slovo poslije velikog
void umetniSlovo(std::string& str){
    for(int i = 0 ; i < str.length(); i++)
        if(str[i]>='A' && str[i]<='Z'){
            std::string ch="";
            ch.push_back(str[i]-'A'+'a');
            str.insert(i+1,ch);
    }
    std::cout<<str<<std::endl;
}
///umetni - izmedju samoglasnika
void umetniCrtu(std::string str){
    for(int i = 0; i < str.length()-1;i++)
        if(jeSamoglasnik(str[i]) && jeSamoglasnik(str[i+1]))
            str.insert(i+1,"-");
    std::cout<<str<<std::endl;
}

bool jeCifra(char c){
    if(c>='0' && c<='9')
        return true;
    return false;
}

///umetnuti p nakon parne cif i n nakon neparne
void cifre(std::string str){
    for(int i = 0; i < str.length();i++)
        if(isdigit(str[i])){
            if((str[i]-'0')%2==0)
                str.insert(i+1,"P");
            else
                str.insert(i+1,"N");
        }
    std::cout<<str<<std::endl;
}

///nakon cifre vece od 0 umetne +1 cifru, ako
/// je cifra 9 umetne 0
void umetniCifru(std::string str){
    for(int i = 0; i < str.length();i++)
        if(jeCifra(str[i])){
            if(str[i]-'0'!=9){
                std::string ch="";
                ch.push_back(str[i]-'0'+'1');
                str.insert(i+1,ch);
            }
            else str.insert(i+1,"0");
            i++;
        }
    std::cout<<str<<std::endl;
}

///premjesti samoglasnike na pocetak i suglasnike na kraj
void premjesti1(std::string str){
    std::string novi="";
    std::string samoglasnici="";
    for(int i = 0; i < str.length();i++)
        if(jeSamoglasnik(str[i])){
            novi.push_back(str[i]);
        }
        else samoglasnici.push_back(str[i]);
    novi.append(samoglasnici);
    std::cout<<novi<<std::endl;
}
///napisi i premjesti2 bez pomocnih stringova
int main()
{
    std::string str1;
    std::cin>>str1;
    //ispis1(str1);
    //toLowercase(str1);
    //velikaSlova(str1);
    //umetniCrtu(str1);
    //cifre(str1);
    //umetniCifru(str1);
    premjesti1(str1);
    return 0;
}
