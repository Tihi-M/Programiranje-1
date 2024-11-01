#include <iostream>
#include <cmath>


///Stampanje oblika
void printPyramid1(int n){
    for(int i = 0; i <= n; i++){
        for(int j = i; j > 0; j--)
            std::cout<<"* ";
        std::cout<<std::endl;
    }

    for(int i = n-1; i > 0;i--){
        for(int j = i; j > 0;j--)
            std::cout<<"* ";
        std::cout<<std::endl;
    }
}

void printPyramid2(int n){
    for(int i = 0;i <= n;i++){
        for(int j = n-i; j > 0; j--)
            std::cout<<" ";
        for(int j = i; j > 0; j--)
            std::cout<<"*";
        std::cout<<std::endl;
    }

    for(int i = n-1; i > 0;i--){
        for(int j = n-i;j > 0;j--)
            std::cout<<" ";
        for(int j = i; j > 0;j--)
            std::cout<<"*";
        std::cout<<std::endl;
    }
}

void printPyramid3(int n){
    for(int i = 0; i <= n;i++){
        for(int j = n-i; j > 0;j--)
            std::cout<<" ";
        for(int j = i; j > 0; j--)
            std::cout<<"* ";
        std::cout<<std::endl;
    }
}

void printRhombus1(int n){
    for(int i = 0;i <= n;i++){
        for(int j = n - i; j > 0;j--)
            std::cout<<" ";
        for(int j = i; j > 0;j--)
            std::cout<<"* ";
        std::cout<<std::endl;
    }

    for(int i = 1; i < n;i++){
        for(int j = i; j > 0;j--)
            std::cout<<" ";
        for(int j = n-i; j > 0;j--)
            std::cout<<"* ";
        std::cout<<std::endl;
    }
}

void printRhombus2(int n){
    for(int i = 0; i <= n;i++){
        for(int j = n-i; j > 0;j--)
            std::cout<<" ";
        for(int j = i;j > 0;j--)
            std::cout<<"*";
        for(int j = i-1; j > 0;j--)
            std::cout<<"*";
        std::cout<<std::endl;
    }

    for(int i = 1; i < n;i++){
        for(int j = i; j > 0;j--)
            std::cout<<" ";
        for(int j = n-i; j > 0;j--)
            std::cout<<"*";
        for(int j = n-i-1;j > 0;j--)
            std::cout<<"*";
        std::cout<<std::endl;
    }
}

///Stampa koliko razlicitih cif broj ima
void numDiffDigits(int num){
    num = abs(num);
    int cnt = 0;
    int digits[10] = {0,1,2,3,4,5,6,7,8,9};
    while(num > 0 && cnt<10){
        for(int i =0 ; i < 10;i++)
            if(num%10 == digits[i]){
                digits[i] = -1;
                cnt++;
                break;
            }
        num/=10;
    }

    std::cout<<"Broj razlicitih cifara broja je: "<<cnt<<std::endl;
}


///Savrsen broj
void perfect(int num){
    int sum =0;
    for(int i = 1; i <=num/2;i++)
        if(num % i == 0)
            sum+=i;

    if(sum == num)
        std::cout<<"Broj je savrsen";
    else std::cout<<"Broj nije savrsen";
}

///Broj je dvojak ako sadrzi dvije cifre
bool jeDvojak(int num){
    bool jesteDv = false;
    int num1 = num;
    num = abs(num);
    int cnt = 0;
    int cifre[10] = {0,1,2,3,4,5,6,7,8,9};
    while(num > 0 && cnt < 3){
        for(int i = 0; i < 10;i++)
            if(num%10 == cifre[i]){
                cifre[i] = -1;
                cnt++;
                break;
            }
        num/=10;
    }

    if(cnt==2)
            return true;
    return false;
}

///Dvocifreni pitagorini
void pitagorini(int limit){
    int a = 1;
    int b = 1;
    int c = 10;
    while(c < limit){
        for(int a = 1; a < c; a++)
            for(int b =1; b < c;b++)
                if(a*a+b*b==c*c){
                    std::cout<<"("<<a*a<<" + "<<b*b<<" == "<<c*c<<")"<<std::endl;
                    std::cout<<c<<" je Pitagorin"<<std::endl<<std::endl;
                    a = c;
                    break;
                }
        c++;
    }
}

///Armstrongovi
void armstrong(int limit){
    int arm = 153;
    while(arm < limit){
        int temp = arm;
        int sum=0;
        while(temp > 0){
            sum+=pow(temp%10,3);
            temp/=10;
        }
        if(sum == arm){
            //std::cout<<"("<<c*c*c<<" + " <<b*b*b<<" + " <<a*a*a<<" == "<<arm<<")"<<std::endl;
            std::cout<<arm<<std::endl;
        }
        arm++;

    }
}

bool jeProst(int n){
    for(int i = 2;i < sqrt(n);i++)
        if(n % i == 0)
            return false;
    return true;
}

///prosti faktori
void prostiFaktori(int n){
    for(int i = 2; n != 1 || i < n;i++){
        bool jesteFaktor = false;
        if(jeProst(i) && n % i == 0){
            jesteFaktor = true;
            while(n % i == 0)
                n/=i;
        }
        if(jesteFaktor)
            std::cout<<i<<" ";
    }
}

int zbirCifara(int n){
    if(n == 0)
        return 0;
    else return n%10 + zbirCifara(n/10);
}
/// broj koraka da se suma cifara svede na
/// jednocifren broj
int otpornostBroja(int n){
    if(n < 10)
        return 0;
    return 1 + otpornostBroja(zbirCifara(n));
}

int pravougaonik(int height, int width){
    for(int i = 0;i < height;i++){
        if(i == 0 || i == height-1){
            for(int j = 0;j < width;j++)
                std::cout<<"*";
            std::cout<<std::endl;
        }
        else{
            std::cout<<"*";
            for(int j = 0; j < width-2;j++)
                std::cout<<" ";
            std::cout<<"*";
            std::cout<<std::endl;
        }
    }
}

int reverseN(int n,int r){
    if(n == 0)
        return r;
    else {
        r = r*10 + n%10;
        reverseN(n/10,r);
    }
}
int main()
{
    int n;
    std::cin>>n;

    /*if(jeDvojak(n)){
        std::cout<<n << " jeste dvojak."<<std::endl;
        n++;
        std::cout<<"Naredni je : ";
        while(!jeDvojak(n))
            n++;
        std::cout<< n;
    }
    else std::cout<< n<<" nije dvojak."<<std::endl;
    */
    std::cout<<reverseN(n,0);
    return 0;
}
