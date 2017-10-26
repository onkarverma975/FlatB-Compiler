declblock{
	int i;
	int a,b,c;
}

codeblock{
	b=100;
	read i;
		L: 
		println i;
	i+=1;

		goto L if i <= 5;
		println "Over";
}