#include <iostream>

void generateMatrix(int **arr,int row,int coll){
    if(row == 0)
        return;
    *arr = new int[coll];
    generateMatrix(arr+1,row-1,coll);
}

void fillMatrix(int **arr,int row,int coll,int i,int j){
    if(i == row)
        return;
    if(j == coll)
        fillMatrix(arr,row,coll,i+1,0);
    else{
        std::cin>>arr[i][j];
        fillMatrix(arr,row,coll,i,j+1);
    }
}

void printMatrix(int **arr,int row,int coll,int i,int j){
    if(i == row){
        std::cout<<std::endl;
        return;
    }
    if(j == coll)
    {
        std::cout<<std::endl;
        printMatrix(arr,row,coll,i+1,0);
    }
    else{
        std::cout<<arr[i][j]<<" ";
        printMatrix(arr,row,coll,i,j+1);
    }
}

void zad47(int **arr,int row,int coll){
    int sum=0;
    for(int i=0;i<row;i++){
        for(int j = 1; j < coll;j++){
            sum+=arr[i][j];
            j++;
        }
        i++;
    }
    std::cout<<sum;
}

int zad47Rec(int **arr,int row,int coll,int i,int j){
    if(row<=i)
        return 0;
    if(coll<=j)
        return zad47Rec(arr,row,coll,i+2,1);
    else return arr[i][j]+zad47Rec(arr,row,coll,i,j+2);
}

void zad48(int **arr,int row,int coll,int r,int s){
    for(int i =0;i < row;i++){
            int temp = arr[i][r];
            arr[i][r]=arr[i][s];
            arr[i][s]=temp;
    }

    printMatrix(arr,row,coll,0,0);
}
//svugdje sam stavljao arr umjesto matr ili mat?
bool zad49(int **arr,int row,int coll){
    for(int i =0;i < row;i++)
        for(int j =0; j<coll;j++)
            if(arr[i][j] != arr[j][i])
                return false;
    return true;
}

int main()
{
    int row,coll;
    std::cout<<"Red i kolona: ";
    std::cin>>row>>coll;
    int **matr;
    matr = new int*[row];

    generateMatrix(matr,row,coll);
    fillMatrix(matr,row,coll,0,0);
    printMatrix(matr,row,coll,0,0);

    std::cout<<zad49(matr,row,coll);
    return 0;
}
