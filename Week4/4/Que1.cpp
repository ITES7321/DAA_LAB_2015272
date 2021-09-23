#include <iostream>
#include <fstream>
using namespace std;

int inv=0;
int merge(int a[],int l,int m,int r){
	static int c;
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];
	int i,j,k;
	for(i=0;i<n1;i++){
		L[i]=a[l+i];
	}
	for(j=0;j<n2;j++){
		R[j]=a[m+j+1];
	}
	i=0,j=0,k=l;
	while(i<n1&&j<n2){
		if(L[i]<=R[j]){
			a[k]=L[i];
			i++;
			//inv++;
		}
		else{
			a[k]=R[j];
			j++;
			//inv++;
		}
		k++;
		c++;
	}
	while(i<n1){
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		a[k]=R[j];
		j++;
		k++;
	}
	return c;
}
int mergeSort(int a[],int l,int r){
	int comp;
	if(l<r){
		
		int m = l+(r-l)/2;
		mergeSort(a,l,m);
		mergeSort(a,m+1,r);
		

		comp=merge(a,l,m,r);
	}
	return comp;
}
int main(){
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");
	int t;
	in >> t;
	int idx=0;
	int n,a[111],a1[t];
	while(t--){
		in >> n;
		for(int i=0;i<n;i++)
			in >> a[i];

		int c=mergeSort(a,0,n-1);
		a1[idx]=c;
		for(int i=0;i<n;i++)
			out << a[i] << " ";
		if(idx==0)
		out<<endl <<"comparison = "<< c<<endl;
		else
		out<<endl <<"comparison = " << c-a1[idx-1]<<endl;
		
		idx++;
	}
}