declblock{
	int data[100];
	int i, sum;
}

codeblock{
	for i = 1, 100 {
		data[i] = i 
	}
	

	sum = 0
	for i = 100, 1, -1 {
		sum = sum + data[i]
 	}

	print "Sum value: ", sum
}

