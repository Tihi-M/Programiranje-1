#include <iostream>

void fillArr(int *arr,int len){
    if(len == 0)
        return ;
    std::cin>>*arr;
    fillArr(arr+1,len-1);
}

void fillArrN(int *arr,int len,int i){
    if(i > len)
        return;
    *arr=i;
    fillArrN(arr+1,len,i+1);
}

void printArr(int *arr,int len){
    if(len == 0)
    {
        std::cout << std::endl;
        return;
    }
    std::cout<<*arr<<" ";
    printArr(arr+1,len-1);
}

void generateMatrix(int **matrix,int m){
    if(m==0)
        return;
    *matrix = new int[2];
    generateMatrix(matrix+1,m-1);
}

void popuniGranice(int **matrix,int *grupe,int m)
{
    int n = 1;
    for(int i = 0; i < m;i++){
        for(int j = 0; j < 2;j++){
        if(j == 0)
            matrix[i][j] = n;
        else matrix[i][j] = n+grupe[i]-1;
        }
         n+=grupe[i];
    }

}

void printMatrix(int **matrix,int m,int n,int i,int j){
    if(m == i){
        std::cout<<std::endl;
        return;
    }
    if(n == j){
        std::cout<<std::endl;
        printMatrix(matrix,m,n,i+1,0);
    }
    else{
        std::cout<<matrix[i][j]<<" ";
        printMatrix(matrix,m,n,i,j+1);
    }
}

bool pripadaOpsegu(int n,int a,int b){
    if(n >=a  && n <= b)
        return true;
    return false;
}

void binSearchK(int **granice,int m,int k){
    while(k>0){
        int el;
        std::cout<<"El: ";
        std::cin>>el;
        k--;

        int left = 0;
        int right = m-1;
        int pos;
        while(left<=right){
            pos = (left+right)/2;
            if(pripadaOpsegu(el,granice[pos][0],granice[pos][1]))
                {
                    std::cout<<pos+1<<". grupa"<<std::endl;
                    break;
                }
            if(el > granice[pos][1])
                left = pos+1;
            if(el < granice[pos][0])
                right = pos-1;
        }

    }
}

int main()
{
    int n;
    std::cout<<"N:";
    std::cin>>n;

    int *arr = new int[n];
    fillArrN(arr,n,1);
    printArr(arr,n);

    int m;
    std::cout<<"M:";
    std::cin>>m;
    int *grupe = new int[m];
    fillArr(grupe,m);

    int **granice = new int*[m];
    generateMatrix(granice,m);
    popuniGranice(granice,grupe,m);
    printMatrix(granice,m,2,0,0);



    int k;
    std::cout<<"K:";
    std::cin>>k;

    binSearchK(granice,m,k);
    return 0;
}
