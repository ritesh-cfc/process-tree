#include<unistd.h>
#include<bits/stdc++.h>
#include<wait.h>

using namespace std;

void create(int h,int n){
	pid_t p=1;
	if(h==0)
	return;
	for(int i=0;i<n;i++){
		if(p>0)
		p=fork();
	}
	if(p==0)
	return(create(h-1,n));
	waitpid(p,0,0);
}

//h is the height of the process tree and n is the degree of each process node!!!
int main(){
	int h=0,n=0;
	h=2;
	n=3;
	create(h,n);	
	cout<<"child id is "<<getpid()<<" parent id is "<<getppid()<<endl;
}
