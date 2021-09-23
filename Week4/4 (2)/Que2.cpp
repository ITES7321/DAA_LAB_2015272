#include<iostream>
#include<fstream>
using namespace std;
int sw=0;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int part(int arr[],int start,int last){
    int pvt = arr[last];
    int i = start-1;
    for(int j=start;j<last;j++){
        if(arr[j]<=pvt){
            i++;
            swap(&arr[i],&arr[j]);
            sw++;
        }
    }sw++;
    swap(&arr[i+1],&arr[last]);
    return i+1;
}
void quickSort(int arr[],int start,int last){
    if(start<last){
    int pi = part(arr,start,last);
    quickSort(arr,start,pi-1);
    quickSort(arr,pi+1,last);
    }
}

int main(){
    ifstream in;
    in.open("input.txt");
    ofstream out;
    out.open("output.txt");
    int t,n;
    int arr[100],arr1[t],arr2[t];
    int idx=0,idx2=0;
    in >> t;
    while(t){
        in >> n;
       
        for(int i=0;i<n;i++){
            in >> arr[i];
        }
        quickSort(arr,0,n-1);
        arr1[idx]=sw;
        for(int i=0;i<n;i++)
            out << arr[i] << " ";

        if(idx==0)
        out<<endl <<"swaps = "<< arr1[idx]<<endl;
        else
        out<<endl <<"swaps = " << arr1[idx]-arr1[idx-1]<<endl;
        idx++;

    t--;
    }

}
