//	link:
//	https://www.luogu.com.cn/problem/P1226

//	快速幂的模板 

//O(logn)
ll qpow(int x, int y){
    ll ans = 1;
    for(; y; y>>=1){
        if(y&1) ans *= x;
        x = x*x;
    }
    return ans;
}

int qpow(int x, int y, int mod){
    int ans = 1;
    for(; y; y>>=1){
        if(y&1) ans = 1ll*ans*x%mod;
        x = 1ll*x*x%mod;
    }
    return ans;
}
