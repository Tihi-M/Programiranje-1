#include <iostream>
#include <string>


int excel(std::string str){
    int stepen=1;
    int coll=0;
    for(int i = str.length()-1;i>=0;i--)
    {
        coll+=(str[i]-'A'+1)*stepen;
        stepen*=26;
    }

    return coll;
}


void povrsina(std::string cell1,std::string cell2){
    std::string collE1 = cell1.substr(0,cell1.length()-1);
    std::string collE2 = cell2.substr(0,cell2.length()-1);
    int row1 = cell1[cell1.length()-1]-'0';
    int row2 = cell2[cell2.length()-1]-'0';

    int coll1 = excel(collE1);
    int coll2 = excel(collE2);
    std::cout << row1 << " "<<coll1 <<" "<< row2 << " "<<coll2 <<std::endl;
    if(row1!=row2){
        std::cout<<"Povrsina: "<<std::max(row1,row2)*std::max(coll1,coll2)<<std::endl;
        return;
    }
    else{
        std::cout<<"Povrsina: "<<std::max(coll1,coll2)<<std::endl;
        return;
    }
}

int main()
{
    std::string polje1,polje2;
    std::cin>>polje1>>polje2;
    povrsina(polje1,polje2);
    return 0;
}
