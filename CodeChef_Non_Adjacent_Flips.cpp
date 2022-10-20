#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	 int n; cin>>n; string s; cin>>s;
	 int k = 0, z=0;
  for(int i=0;i<s.length(); i++){
   if(s[i]=='0') z++; 
   //else k++;
  }
	 for(int i=0;i<s.length()-1;i++){
	  if(s[i]=='1' && s[i+1]=='1'){
	   k++;
	  }
	 }
	 if(z==s.length()){
	  cout<<0<<endl;
	 }
	 else if(k>0){
	  cout<<2<<endl;
	 }
	 else{
	  cout<<1<<endl;
	 }
	}
	return 0;
}
