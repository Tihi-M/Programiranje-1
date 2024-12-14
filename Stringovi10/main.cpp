#include <iostream>
#include <string>
void povrsina(std::string cell1,std::string cell2){
    std::string collE1 = cell1.substr(0,cell1.length()-1);
    std::string collE2 = cell2.substr(0,cell2.length()-1);
    int row1 = cell1[cell1.length()-1]-'0';
    int row2 = cell2[cell2.length()-1]-'0';



}

int main()
{
    std::string polje1,polje2;
    std::cin>>polje1>>polje2;
    povrsina(polje1,polje2);
    return 0;
}
