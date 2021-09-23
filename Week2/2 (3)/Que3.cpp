#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream in;
    in.open("input.txt");
    ofstream out;
    out.open("output.txt");
    int n,t,k;
    int a[100];
    in >> t;
    while(t){
        in >> n;
        for(int i=0;i<n;i++)
            in >> a[i];
        in >> k;
        int c =1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n-i-1;j++){
                if(a[i]-a[j]==k || a[i]-a[j]==-k){
                c++;
                }
            }
        }
        out << c << endl;

    t--;
    }

return 0;
}
