declblock{
	int data[100];
	int i, sum;
}

codeblock{
	i = 0;

L1:	data[i] = i ;
	i = i + 1;
	goto L1 if i < 100;
	
	sum = 0;
	i = 0;
L2:	sum = sum + data[i];
	i = i + 1;
	goto L2 if i < 100;

	for i = ((a)*(b))-((c)*(d))+(((e))), ((a)*(b))-((c)*(d))+(((e))) {
		data[i] = i ;
	}

	for i = 1, 100, 2 {
		data[i] = i ;
	}

	i+i;
	i==i;
	1+2;
	a[i] = i*234+(23+11);
	a[i] = (i*234+(23+11)/234);
	a[i] = ((i*234+(23+11))*134) + 2345;


	while a < b {
		data[i] = i ;
	}

	while (a<b) {
		data[i] = i ;
	}
	
	goto L1 if (a>b);
	goto L1 if ((a>b));
	goto L1 if (!(a>b) || a>b);
	goto L1 if (a>b || (a>b));
	goto L1 if (!(a>b) && (b<a) == (c>a));
	goto L1 if ((a>b) && (b<a) == (c>a));

	print "Sum value: ", sum;
	print "kfjld124;", sum,asdf,casdc,asdc;
	print "Sum value: ", sum;
	read a,a[123];
	read a,a[asdf+23];
}

