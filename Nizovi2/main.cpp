#include <iostream>

void fillArrRec(int *arr,int len){
    if(len == 0)
        return;
    std::cin>>*arr;
    fillArrRec(arr+1,len-1);
}

void fillArr(int *arr,int len){
    for(int i = 0;i < len;i++)
        std::cin>>arr[i];
}

void printArrRec(int *arr, int len){
    if(len == 0){
        std::cout<<std::endl;
        return;
    }
    std::cout<<*arr<<" ";
    printArrRec(arr+1,len-1);
}

void printArr(int *arr,int len){
    for(int i = 0; i < len;i++)
        std::cout<<arr[i] << " ";
}

void zad40(int *arr,int len){
    int maxxSum=*arr;
    int *maxxArr;
    int maxxLen=0;
    for(int i = 0; i <= len;i++){
        for(int j=0; j < len-i+1;j++){
            int *tempArr=new int[i];
            int tempSum=0;
            for(int k = i-1; k>=0;k--){
                *(tempArr+k)=arr[k+j];
                tempSum+=arr[k+j];
            }
            //std::cout<<tempSum<<std::endl;
            printArrRec(tempArr,i);
            if(tempSum>maxxSum)
                {
                    maxxArr=tempArr;
                    maxxSum=tempSum;
                    maxxLen=i;
                }

        }
    }

    std::cout<<"Max: "<<maxxSum<<std::endl;
    printArrRec(maxxArr,maxxLen);
}

int arrToDecimal(int *arr,int len){
    int st10=1;
    int num=0;
    for(int i = len-1; i >= 0;i--){
        num+=arr[i]*st10;
        st10*=10;
    }
    return num;
}

int sumArray(int *arr,int len){
    if(len==0)
        return 0;
    return *arr+sumArray(arr+1,len-1);
}

void bubbleSortAsc(int *arr,int len){
    bool swapped = false;
    for(int i = 0;i < len-1;i++){
        for(int j = 0; j < len-i-1;j++){
            if(arr[j] > arr[j+1]){
                std::swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
        swapped = false;
    }
}

void bubbleSortDesc(int *arr,int len){
    bool swapped=false;

    for(int i = 0; i < len-1;i++){
        for(int j = 0;j < len-i-1;j++){
            if(arr[j] < arr[j+1]){
                std::swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
        swapped = false;
    }
}

void zad41(int *arr,int len){
    int evenLen = len/2;
    if(len%2!=0)
        evenLen++;
    int *odd=new int[len/2];
    int *even=new int[evenLen];
    int io=0;
    int ie=0;
    for(int i = 0; i < len;i++){
        if(i%2==0){
            even[ie]=arr[i];
            ie++;
        }
        else{
            odd[io]=arr[i];
            io++;
        }
    }

    bubbleSortAsc(even,evenLen);
    bubbleSortDesc(odd,len/2);
        printArrRec(even,evenLen);
        printArrRec(odd,len/2);

    io=0;
    ie=0;
    for(int i = 0; i<len;i++){
        if(i%2==0)
        {
            arr[i] = even[io];
            io++;
        }
        else{
            arr[i] = odd[ie];
            ie++;
        }
    }

    printArrRec(arr,len);
}

void zad42(int *arr,int len){
    bubbleSortAsc(arr,len);
    int n1=0;
    int n2=0;
    for(int i = 0; i < len;i++){
        if(i%2==0)
            n1=n1*10+arr[i];
        else
            n2=n2*10+arr[i];
    }

    std::cout<<n1 << " + " << n2 << " = " <<n1+n2;
}

int main()
{
    int len;
    std::cin>>len;
    int *arr = new int[len];
    fillArrRec(arr,len);
    printArrRec(arr,len);

    zad41(arr,len);

    return 0;
}
