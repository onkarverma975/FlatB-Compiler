declblock{
	int i, n, mod, fac, j, find;
	int a[1000000];
}

codeblock{
	mod= 1000000007;
	n=100000;
	i=1;
	fac=1;
	while i <= n {
		fac = ( fac * i ) % mod;
		a[i] = fac;
		i+=1;
	}

	find = 23;
	for i = 0 , n+1{
		for j = 0 , n+1{
			if ( ((a[i]*a[j])%mod)==find)
			{
				print i," ";
				println j;
			}
		}
	}
}
