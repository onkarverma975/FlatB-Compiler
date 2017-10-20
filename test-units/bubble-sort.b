declblock{
	int n,i,j,a[1000000];
	int temp;
}

codeblock{
	read n;
	for i = 0 , n-1 {
		read a[i];
	}
	for i = 0 , n-2 {
		for j = 0, n-i-2 {
			if(a[j] > a[j+1]){
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
	for i = 0 , n-1 {
		print a[i]," ";
	}
	println "";

}

