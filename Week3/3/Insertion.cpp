#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    int t,n;
    int a[100];
    in >> t;
    while(t){
        in >> n;
        for(int i=0;i<n;i++)
            in >> a[i];
        int moves=0,comparisons=0;
        int x=0,j;
        for(int i=1;i<n;i++){
            x=a[i];
            j=i-1;
            while(j>=0 && a[j]>x){
                a[j+1]=a[j];
                j--;
                moves++;
                comparisons++;
            }
            a[j+1]=x;
            comparisons++;
        }
        for(int i=0;i<n;i++)
            out << a[i] << " ";
            out << endl;
        out << "moves = " << moves << endl;
        out << "comparisonss = " << comparisons << endl;
        t--;
    }
}
