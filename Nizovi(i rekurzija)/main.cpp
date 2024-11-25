#include <iostream>
#include <cmath>
///Prva grupa zadataka za vjezbu: nizovi
void fillArr(int *arr,int len){
    if(len == 0)
        return;
    std::cin>>*arr;
    fillArr(arr+1,len-1);
}

void printArr(int *arr,int len){
    if(len == 0){
        std::cout<<std::endl;
        return;
    }
    std::cout<< *arr << " ";
    printArr(arr+1,len-1);
}

int zad26(int *arr,int len,int k){
    int cnt = 0;
    for(int i = 0; i < len;i++)
        if(arr[i]%2 == 0 && arr[i] > k)
            cnt++;
    return cnt;
}

int zad26Rec(int *arr, int len,int k){
    if(len == 0)
        return 0;
    if(*arr%2 == 0 && *arr>k)
        return 1+zad26Rec(arr+1,len-1,k);
    else return zad26Rec(arr+1,len-1,k);
}

int brojParnih(int *arr,int len){
    if(len==0)
        return 0;
    if(*arr%2==0)
        return 1+brojParnih(arr+1,len-1);
    else return brojParnih(arr+1,len-1);
}

void zad27(int *arr,int *c,int *b,int len){
    for(int i = 0; i < len;i++)
    {
        if(arr[i]%2 == 0){
            *c=arr[i];
            c++;
        }
        else{
            *b=arr[i];
            b++;
        }
    }
}

void zad27Rec(int *arr,int *c,int *b,int len){
    if(len == 0)
        return;
    if(*arr%2 == 0)
    {
        *c=*arr;
        zad27Rec(arr+1,c+1,b,len-1);
    }
    else{
        *b=*arr;
        zad27Rec(arr+1,c,b+1,len-1);
    }
}

int *zad28(int *arr,int len){
    int *copyArr=new int[len*2];
    for(int i =0 ; i < len;i++){
        *copyArr=arr[i];
        *(copyArr+1)=arr[i];
        copyArr+=2;
    }
    return copyArr-len*2    ;
}

void zad28Rec(int *arr,int *arr2,int len){
    if(len == 0)
        return;
    *arr2=*arr;
    *(arr2+1)=*arr;
    zad28Rec(arr+1,arr2+2,len-1);
}

int *zad29(int *arr,int len){
    int *arr2=new int[len];
    int j = 0;
    int k = len-1;
    for(int i =0;i < len;i++){
        if(arr[i] % 2 == 0){
            arr2[j] = arr[i];
            j++;
        }
        else{
            arr2[k] = arr[i];
            k--;
        }
    }
    return arr2;
}

void zad29Rec(int *arr,int *arr2,int i,int j,int len){
    if(len==0)
        return;
    if(*arr%2==0){
        arr2[i]=*arr;
        zad29Rec(arr+1,arr2,i+1,j,len-1);
    }
    else{
        arr2[j]=*arr;
        zad29Rec(arr+1,arr2,i,j-1,len-1);
    }
}

int sumaNiza(int *arr,int len){
    if(len == 0)
        return 0;
    return *arr+sumaNiza(arr+1,len-1);
}

float zad30(int *poeni,int *ocjene,int len){
    float sum = 0;
    int points = sumaNiza(poeni,len);
    for(int i = 0; i < len;i++)
        sum+=poeni[i]*ocjene[i];

    return sum/points;
}

int zad31(int *arr,int len){
    for(int i = 0; i < len-1;i++)
        for(int j = i+1; j < len;j++)
            if(arr[i] == arr[j])
                return 1;
    return 0;
}

int zad31Rec(int *arr,int len,int i,int j){
    if(len-1 == i)
        return 0;
    if(len == j)
        return zad31Rec(arr,len,i+1,i+2);
    if(arr[i] == arr[j])
        return 1;
    else return zad31Rec(arr,len,i,j+1);

}

void fillArrLessN(int *arr,int len,int n){
    if(len == 0)
        return;
    std::cin>>*arr;
    if(*arr>n){
        std::cout<<"< n !"<<std::endl;
        fillArrLessN(arr,len,n);
    }
    else fillArrLessN(arr+1,len-1,n);
}

bool containsEl(int *arr,int len,int el){
    if(len == 0)
        return false;
    if(*arr==el)
        return true;
    else return containsEl(arr+1,len-1,el);
}

void zad32(int *arr,int len){
    for(int i = 1; i <= len;i++)
        if(!containsEl(arr,len,i))
            std::cout<<i<<std::endl;
}

void zad33(int *arr,int len){
    int maxx=0;
    int maxxInd=0;
    int temp=1;
    for(int i = 0;i < len;i++){
            for(int j =i+1;j<len;j++)
                if (arr[i] == arr[j])
                    temp++;
        if(temp > maxx){
            maxx=temp;
            maxxInd=arr[i];
        }
        temp =0;
    }
    std::cout<<maxxInd<< " ("<<maxx<<")";
}

void zad34(int *arr,int len){
    int pre=0;
    bool flag=false;
    int post=sumaNiza(arr+1,len-1);
    for(int i = 0; i <len;i++ ){
        if(pre==post){
            flag = true;
            std::cout<<i<<" ";
        }
        pre+=arr[i];
        post-=arr[i+1];
    }
    if(!flag)
        std::cout<<-1;
}

float povrsinaTrougla(float x1,float y1,float x2,float y2, float x3,float y3){
    return 0.5*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
}

void generateMatrix(int **arr,int row,int coll){
    if(row == 0)
        return;
    *arr=new int[coll];
    generateMatrix(arr+1,row-1,coll);
}

void fillMatrix(int **arr,int row,int coll,int i,int j){
    if(row == i)
        return;
    if(coll== j)
        fillMatrix(arr,row,coll,i+1,0);
    else{
        std::cin>>arr[i][j];
        fillMatrix(arr,row,coll,i,j+1);
    }
}

void printMatrix(int **arr,int row,int coll,int i,int j){
    if(row == i)
    {
        std::cout<<std::endl;
        return;
    }
    if(coll == j){
        std::cout<<std::endl;
        printMatrix(arr,row,coll,i+1,0);
    }
    else{
        std::cout<<arr[i][j] << " ";
        printMatrix(arr,row,coll,i,j+1);
    }
}

float distanceTwoPoints(float x1,float y1,float x2,float y2){
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

bool isValidTriangle(float x1,float y1,float x2,float y2,float x3, float y3){
    float a = distanceTwoPoints(x1,y1,x2,y2);
    float b = distanceTwoPoints(x2,y2,x3,y3);
    float c = distanceTwoPoints(x1,y1,x3,y3);
    if(a+b <= c || a+c <= b || b+c <= a)
        return false;
    return true;

}

void zad38(int **arr,int len){
    float maxArea=0;
    float tempArea=0;
    for(int i = 0;i < len-2;i++)
        for(int j = i+1;j < len-1;j++){
            if(isValidTriangle(arr[i][0],arr[i][1],arr[j][0],arr[j][1],arr[j+1][0],arr[j+1][1])){
                tempArea=povrsinaTrougla(arr[i][0],arr[i][1],arr[j][0],arr[j][1],arr[j+1][0],arr[j+1][1]);
                if(tempArea > maxArea)
                    maxArea=tempArea;
            tempArea=0;
            }
        }
    std::cout<<maxArea;
}


int main()
{
    int row,coll;
    std::cout<<"row, coll:"<<std::endl;
    std::cin>>row>>coll;
    int **matr;
    matr = new int*[row];
    generateMatrix(matr,row,coll);
    fillMatrix(matr,row,coll,0,0);
    printMatrix(matr,row,coll,0,0);


    zad38(matr,row);
    return 0;
}

