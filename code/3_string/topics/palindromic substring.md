## hash

- 思路：预处理正哈希和逆哈希，如果正哈希[l,r]==逆哈希[l,r]，说明两个字符串相同。枚举回文中心，二分求回文半径。
- 时间复杂度O(nlogn)

```c++
void hashs(){
	p[0]=1;
	for(int i=1; i<=n; i++){
    	p[i] = p[i-1]*P;            
    	h1[i] = h1[i-1]*P + s[i];
		h2[i] = h2[i-1]*P + s[n-i+1]; 
	}
}
ull ask1(int l, int r){
	return h1[r]-h1[l-1]*p[r-l+1];
}
ull ask2(int l, int r){
	return h2[r]-h2[l-1]*p[r-l+1];
}
bool check(int l, int r){
    if(ask1(l,r)==ask2(n-r+1,n-l+1)) return true;
    else return false;
}
```