#include <iostream>
#include <vector>
bool validIp(std::string adresa){
    int start = 0;
    int endd = adresa.find('.',start);
    if(endd == -1)
        return false;
    std::vector<std::string> djelovi;

    while(endd != -1){
        djelovi.push_back(adresa.substr(start,endd-start));
        start = endd+1;
        endd=adresa.find('.',start);
    }
    djelovi.push_back(adresa.substr(start,adresa.length()-start));

    if(djelovi.size() != 4)
        return false;

    for(int i =0 ;i < 4;i++)
        if(djelovi[i].length()<=3 && djelovi[i].length()>=1){
            if(djelovi[i].length() == 2 && stoi(djelovi[i]) < 10)
                return false;
            else if (djelovi[i].length() == 3 && (stoi(djelovi[i]) < 100||stoi(djelovi[i])>255))
                return false;
        }
        else return false;
    return true;
}

int main()
{
    std::string str;
    std::cin>>str;
    std::cout<<validIp(str);
    return 0;
}
