#include <iostream>
#include <time.h>

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

void zad50(int **matr,int row,int coll){
    for(int i =0; i < row; i++)
        for(int j = 0; j < coll; j++){
            bool lokMax=true;
            if(i-1>=0 && matr[i][j] < matr[i-1][j]) lokMax=false;
            else if(i+1<row && matr[i][j] < matr[i+1][j]) lokMax=false;
            else if(j-1>=0 && matr[i][j] < matr[i][j-1]) lokMax=false;
            else if(j+1<coll && matr[i][j] < matr[i][j+1]) lokMax=false;
            else std::cout<<"( "<<i<<", "<<j<<" )"<<std::endl;
        }
}


///Najveca podmatrica!!!!
void zad51(int **matr,int row,int coll){
    int maxSum=matr[0][0];
    int **maxSub;
    int maxN=0;
    int maxM=0;
    for(int n = row; n >0;n--){
        for(int m = coll; m > 0; m--){
            for(int k = 0; k < row-n+1;k++) {
                for(int l =0; l < coll-m+1;l++) {
					int sum = 0;
					int **subMatrix;
					subMatrix=new int*[n];
					generateMatrix(subMatrix,n,m);
                        for(int i = 0; i < n;i++) {
                            for(int j = 0; j < m;j++) {
                                subMatrix[i][j] = matr[k+i][l+j];
                                sum +=  matr[k+i][l+j];
							}
                        }
                    printMatrix(subMatrix,n,m,0,0);
                    if(sum >maxSum) {
                        maxSum=sum;
                        maxSub=subMatrix;
                        maxN=n;
                        maxM=m;
					}
				}
			}
        }
    }
    printMatrix(maxSub,maxN,maxM,0,0);
    std::cout<<maxSum<<std::endl;
}


///verzija proslog
void zad52(int **matr,int row,int coll,int s){
    int **maxSub;
    int maxN=0;
    int maxM=0;
    int maxGreater=0;
    for(int r=row; r > 0;r--){
        for(int c=coll;c > 0; c--){
            for(int k = 0 ; k < row-r+1;k++){
                for(int l = 0;l < coll-c+1;l++){
                    int sum=0;
                    int **subMatrix;
                    subMatrix=new int*[r];
                    generateMatrix(subMatrix,r,c);
                    for(int i =0;i < r;i++){
                        for(int j = 0; j < c;j++){
                            sum+=matr[i+k][j+l];
                            subMatrix[i][j]=matr[i+k][j+l];
                        }
                    }
                    if(sum <= s && sum>maxGreater){
                        maxN=r;
                        maxM=c;
                        maxGreater=sum;
                        maxSub=subMatrix;
                        printMatrix(maxSub,maxN,maxM,0,0);
                        std::cout<<maxGreater<<std::endl;
                        return;
                    }

                }
            }

        }

    }

}

bool zad54(int **matr,int row,int coll){
    int dijagonala1=0;
    int dijagonala2=0;
    int *kolone=new int[row];
    for(int i =0; i < row ;i++)
        kolone[i]=0;
    int *redovi=new int[row];
    for(int i =0; i < row ;i++)
        redovi[i]=0;
    for(int i = 0; i < row;i++){
            for(int j =0 ; j < row;j++){
                redovi[i]+=matr[i][j];
                kolone[i]+=matr[j][i];
                if(i==j)
                    dijagonala1+=matr[i][j];
                if(i+j==row-1)
                    dijagonala2+=matr[i][j];
        }
    }
    for(int i =0; i < row;i++)
        if(redovi[i] != kolone[i])
        return false;

    if(redovi[0] != dijagonala1 || redovi[0] != dijagonala2)
        return false;
    return true;

}

void fillRandom(int **matrix, int row,int coll,int k){
    srand(time(0));
    for(int i = 0; i < row;i++)
        for(int j = 0; j < coll;j++){
            int rnd=rand()%k;
            if(rnd%2==0)
                matrix[i][j]=rnd;
            else
                matrix[i][j]=-1*rnd;
    }
}

void zad55(int **matr,int row,int coll){
    for(int i = 0;i < row;i++){
        for(int j = 0;j < coll;j++){
            bool lokMax = true;
            if(i-1>=0 && matr[i][j] <= matr[i-1][j]) lokMax = false;
            else if(i+1<row && matr[i][j] <= matr[i+1][j]) lokMax = false;
            else if(j-1<row && matr[i][j] <= matr[i][j-1]) lokMax = false;
            else if(j+1<row && matr[i][j] <= matr[i][j+1]) lokMax = false;
            else std::cout<<"( "<<i<<", "<<j<<" )"<<std::endl;
        }
    }
}

void fill0(int **matrix,int row,int coll){
    for(int i = 0; i < row; i++)
        for(int j = 0; j < coll;j++)
            matrix[i][j]=0;
}

void promijeniSmjer(int *smjer){
    if(smjer[0]==0 && smjer[1]==1)
    {
        smjer[0]=1;
        smjer[1]=0;
        return;
    }
    if(smjer[0]==1 && smjer[1]==0)
    {
        smjer[0]=0;
        smjer[1]=-1;
        return;
    }
    if(smjer[0]==0 && smjer[1]==-1)
    {
        smjer[0]=-1;
        smjer[1]=0;
        return;
    }
    if(smjer[0]==-1 && smjer[1]==0)
    {
        smjer[0]=0;
        smjer[1]=1;
        return;
    }
}

void zad56(int **matrix,int row,int coll){
    int smjer[]={0,1};
    int el=1;
    int i=0;
    int j=0;

    while(el <= row*coll){
        matrix[i][j]=el;
        int i_=smjer[0]+i;
        int j_=smjer[1]+j;
        el++;
        if( i_ < 0 || j_ < 0 || i_ >= row || j_ >= coll || matrix[i_][j_] != 0)
        {
            promijeniSmjer(smjer);
            i_=smjer[0]+i;
            j_=smjer[1]+j;
        }
        i=i_;
        j=j_;
    }
    printMatrix(matrix,row,coll,0,0);

}

void zad57(int **matrix,int n){
    int  m=1;
    int sumOfIndex=0;
    while(sumOfIndex<=2*(n-1)){
        for(int i = 0; i < n;i++){
            for(int j=0; j < n;j++){
                if(i+j==sumOfIndex)
                    matrix[i][j]=m;
            }
        }
        sumOfIndex++;
        if(sumOfIndex > n-1)
            m--;
        else m++;
    }
    printMatrix(matrix,n,n,0,0);
}

int main()
{
    int row,coll;
    std::cout<<"Red,kolona: ";
    std::cin>>row>>coll;
    int **matr;
    matr = new int*[row];

    generateMatrix(matr,row,coll);
    //fillMatrix(matr,row,coll,0,0);
    //fillRandom(matr,row,coll,k);
    //printMatrix(matr,row,coll,0,0);

    zad57(matr,row);
    return 0;
}
