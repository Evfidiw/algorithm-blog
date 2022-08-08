//	link:
//	https://www.luogu.com.cn/problem/P1226

//	模板 

//O(logn)
ll qpow(int x, int y)
{
    ll ans = 1;
    for(; y; y>>=1){
        if(y&1) ans *= x;
        x = x*x;
    }
    return ans;
}

//	快速幂
/*	y = C0*2^0 + ... + C(k-1)*2^(k-1)  Cx要么为0要么为1 
	  x^y
	= x^(C0*2^0)x * ... * x^(C(k-1)*2^(k-1))
*/  
int qpow(int x, int y, int mod)
{
    int ans = 1;
    for(; y; y>>=1){
        if(y&1) ans = 1ll*ans*x%mod;
        x = 1ll*x*x%mod;
    }
    return ans;
}

//	龟速乘
/*	  a*b
	= a*C0*2^0 + ... + a*C(k-1)*2^(k-1)
*/ 
int mul(int a, int b, int mod)
{
	int ans=0;
	for(; b;b >>= 1;){
		if(b&1) ans = 1ll*(ans+a)%mod;
		a = (a+a)%mod;
	}
	return ans;
} 
