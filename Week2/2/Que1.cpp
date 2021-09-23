#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");
	int n,k,t;
	int tmp;
	int arr[100];
	in >> t;
	while(t){
		in >> n;
		for(int i=0;i<n;i++){
			in >> arr[i];
		}
		in >> k;
		int start = 0;
		int end = n-1;
		tmp=0;
		int index;
		while(start<=end){
			int mid = start + ((end-start)/2);
			if(arr[mid]==k){
				index=mid;
				tmp=1;
				break;
			}else if(arr[mid]>k){
				end = mid-1;
			}
			else{
				start = mid+1;
			}
		}
		if(tmp==0){
			out << "Key not Present";
		}
		else{
			int c=1;
			int left = index-1;
			while(left>=0 && arr[left]==k){
				c++;
				left--;
			}
			int right=index+1;
			while(right<n && arr[right]==k){
				c++;
				right++;
			}
			out << k << " - " << c << endl; 
		}
	t--;
	}
}
