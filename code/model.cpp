#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
char getc(){
    static char buf[1<<14],*p1=buf,*p2=buf;
    return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
int read(){
   int s=0,w=1;  
   char ch=getchar();  
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}  
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();  
   return s*w;  
}
#define ll long long
#define ull unsigned long long
const int inf=0x7f7f7f7f;
const int N=10005,M=20005;
//苟利国家生死以，岂因祸福避趋之



int main(){
//    freopen(".in","r",stdin);
//    freopen(".out","w",stdout);
//	printf("%.3lf M\n",(double)sizeof(/*szm*/)/(1<<20));
//	clock_t start_time=clock();
	
	
//	clock_t end_time=clock();
//cout<<"Running time is:"<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
//	fclose(stdin);fclose(stdout);
	return 0;
}
