declblock{
	int n,i,j,a[1000000];
	int temp;
}

codeblock{
	read n;
	for i = 0 , n {
		read a[i];
	}
	for i = 0 , n-1 {
		for j = 0, n-i-1 {
			if(a[j] > a[j+1]){
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
	for i = 0 , n {
		print a[i]," ";
	}
	println "";

}

