#include<iostream>
#include<fstream>
using namespace std;
void swap(int &n1, int &n2)
{
    int t = n1;
    n1 = n2;
    n2 = t;
}

int part(int a[], int l, int r)
{
    int i = l-1;
    int j= l;
    while(j < r)
    {
        if(a[j] <= a[r])
        {
            i++;
            swap(a[i], a[j]);
        }
        j++;
    }
    i++;
    swap(a[i], a[r]);
    return i;
}

int minFindK(int a[], int l, int r, int k, int n)
{
    if(l <= r)
    {
        int p = part(a, l, r);
        if(p == k-1)
            return a[p];
        else if(p > k-1)
           return minFindK(a, l, p-1, k, n);
        else
            return minFindK(a, p+1, r, k, n);
    }
    return -1;
}
int main()
{
    ifstream in;
    in.open("input.txt");
    ofstream out;
    out.open("output.txt");
    int t,n;
    in>>t;
    while(t--)
    {
        int k;
        in>>n;
        int a[n];
        for(int j=0;j<n;j++)
            in>>a[j];
        in>>k;
       int ans = minFindK(a,0,(n-1),k,n);
       if(ans==-1)
        out << "Not Present\n";
       else
        out << ans << endl;
    }
    return 0;

}