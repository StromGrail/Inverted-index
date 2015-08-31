#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int cmp(string p,string s,int n,int m){
	if(n!=m)
		return 0;
	for(int i=0;i<m;++i)
		if(s[i]!=p[i])
			return 0;
return 1;
}
int main(){
bool a[][6]={{1,1,0,0,0,1},{1,1,0,1,0,0},{1,1,0,1,1,1},{0,1,0,0,0,0},{1,0,0,0,0,0},{1,0,1,1,1,0}};
string s[]={"antony","brutus","caesar","calpurnia","cleoptra","mercy","worser"};
string book[]={"antony and cleopatra","julius caesar","the tempest","hamlet","othello","macbeth"};
cout<<"Enter query length \n";
int query;
cin>>query;
int ans[6];
while(query--){	
	string p;
	cout<<"Enter query\n";
	cin>>p;
	int condition;
	cout<<"and=1 , and not=2,or=3,0 for start\n";
	cin>>condition;
	int index;
	for(int i=0;i<7;++i){
		if(cmp(p,s[i],p.length(),s[i].length()))
		{
			index=i;
			break;
		}
	}
	
	for(int i=0;i<6;++i){
		if(condition==0){
			ans[i]=a[index][i];
		}else if(condition==1){
			ans[i]&=a[index][i];
		}else if(condition==2){
			ans[i]&=~a[index][i];
		}	
	}
	
}
int prev=0;
for(int i=0;i<6;++i){
	if(i==5)
		cout<<" . ";
	else if(ans[i]==1 and prev==0){
		cout<<book[i];
		prev=1;	
		}else if(ans[i]==1 && prev==1){
			cout<<" and "<<book[i];
			}
	}
	cout<<endl;
return 0;
}
