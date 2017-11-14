declblock{
	int i;
	int n, a[1000000], mod;
}

codeblock{
	i=0;
	a[0]=1;
	a[1]=2;
	n=1000000;
	mod = 1000000007;
	for i = 2 , n-1 {
		a[i] = (a[i-1] + a[i-2])%mod;
	}
}
