#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ofstream out;

void checkPairToK(int a[],int n,int key){
	out.open("output.txt");
	int start=0;
	int end=n-1;
	int flag=0;
	while(start<end){
		if(a[start]+a[end]==key){
			out << a[start] << " " << a[end] << ", ";
			end--;
			flag++;
		}
		else if(a[start]+a[end]>key){
			end--;
		}
		else if(a[start]+a[end]<key){
			start++;
		}
	}
	//cout << endl;
	if(flag==0)
			out << "No Such Pair Exist\n";
		else
			out << endl;
	//return flag;
}
int main(){
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");
	int t,n;
	in >> t;
	while(t--){
		in >> n;
		int a[n];
		for(int i=0;i<n;i++)
			in >> a[i];
		int k;
		in >> k;
		sort(a,a+n);
	 	checkPairToK(a,n,k);
		
	}
}