#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    int n,t;
    in >> t;
    int a[100];
    while(t){
        in >> n;
        for(int i=0;i<n;i++){
            in >> a[i];
        }
        int mid=0;
        int comparisons=0,swaps=0;
        for(int i=0;i<n-1;i++){
            mid=i;
            for(int j=i+1;j<n;j++){
                if(a[j]<a[mid]){
                    mid=j;
                }
                comparisons++;
            }
            swap(a[mid],a[i]);
            swaps++;
        }
        for(int i=0;i<n;i++)
            out << a[i] << " ";
            out << endl;
        out << "comparisons = " << comparisons << endl;
        out << "Swaps = " << swaps << endl;
        t--;
    }
}
