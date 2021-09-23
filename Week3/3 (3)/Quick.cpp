#include<iostream>
#include<fstream>
using namespace std;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int part(int a[],int start,int last){
    int pvot = a[last];
    int i = start-1;
    for(int j=start;j<last;j++){
        if(a[j]<=pvot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[last]);
    return i+1;
}
void quickSort(int a[],int start,int last){
    if(start<last){
    int p = part(a,start,last);
    quickSort(a,start,p-1);
    quickSort(a,p+1,last);
    }
}

int main(){
    ifstream in;
    in.open("input.txt");
    ofstream out;
    out.open("output.txt");
    int t,n;
    int a[100];
    in >> t;
    while(t){
        in >> n;
        for(int i=0;i<n;i++){
            in >> a[i];
        }
        quickSort(a,0,n-1);
        int flag=0;
        for(int i=0;i<n-1;i++){
            if(a[i]==a[i+1]){
                flag=1;
                break;
            }
        }
        if(flag==1)
        out << "YES" << endl;
        else
        out << "NO" << endl;
    t--;
    }

}
