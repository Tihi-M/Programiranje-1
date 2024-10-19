#include <iostream>
#include <iomanip>

void convertScale(int degreeF){
    float degreeC = (degreeF-32)*5/9;
    std::cout<<degreeF<<"F <=> "<<degreeC<<"C"<<std::endl;
}

void downloadSpeed(int gbs){
    double seconds = gbs*1024/11.9;//12 megabajta po sekundi <-> 100Mbit
    std::cout<<"Download time: "<<seconds<<"s"<<std::endl;
}

void printPyramid(int level){
    for(int i = 1;i <= level;i++){
        for(int j = i; j > 0;j--)
            std::cout<<"* ";
        std::cout<<std::endl;
    }
    for(int i = level-1;i > 0;i--){
        for(int j = i;j > 0;j--)
            std::cout<<"* ";
        std::cout<<std::endl;
    }
}

void brojRazlicitihCifara(int n){
    int cifre[] = {0,1,2,3,4,5,6,7,8,9};
    int cnt = 0;
    while(n > 0){
        for(int i = 0; i < 10  ;i++)
        {
            if(n % 10 == cifre[i])
            {
                cnt++;
                cifre[i] = -1;
            }
        }
        n/=10;
    }
    std::cout<<"Br razlicitih cif: "<< cnt<<std::endl;

}

void cntRepsCif(long long int n){
    int cifreCnt[10] = {0};
    int cnt = 0;
    while(n > 0){
        cifreCnt[n%10+1]++;
        n/=10;
    }

    int maxCnt = 0;
    int maxInd = 0;
    for(int i = 0; i < 10;i++)
        if(cifreCnt[i] >= maxCnt){
            maxCnt = cifreCnt[i];
            maxInd = i;
            }
    std::cout<<"Najvise ponavljanja: cifra: "<<maxInd<<" (broj ponavljanja: "<<maxCnt<<")"<<std::endl;
}

int savrsen(int n){
    int n2 = n;
    int sum = 0;
    while(n2 > 0){
        sum +=n2%10;
        n2/=10;
    }
    if(n == sum)
        return 1;
    return 0;
}

int main()
{
    return 0;
}
