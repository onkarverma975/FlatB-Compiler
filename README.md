# FlatB Compiler

FlatB is a very basic language built to explore the concepts of compiler design and implementation.

The following are the various features.

1. Data Types

Inegers and Array of Integers.

int data, array[100];
int sum;

All the variables have to be declared in the declblock{....} before being used
in the codeblock{...}. Multiple variables can be declared in the statement 
and each declaration statement ends with a semi-colon. 


array can be accesseed using an arithmetic expression between square brackets

2. Expressions

	There are two kinds of expressions
		1. Arithmetic (Ouput is a number)
		2. Boolean (Output is of bool type)

3. for loop

for i = 1, 100 {
	.....
}

for i = 1, 100, 2 {
	.....
}

for var_name = Arith_Expr , Arith_Expr, Arith_Expr
{//code block
	
}

4. if-else statement

	if bool_expression {
	....
	}
	....

	if bool_expression {
	...
	}
	else {
	....
	}

5. while statment

	while bool_expression {

	}

6. conditional and unconditional goto

	got label

	goto label if bool_expression

7. print/read

	print "blah...blah", val
	println "new line at the end"
	read sum
	read data[i]
