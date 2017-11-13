	.text
	.file	"llout"
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:                                 # %B1
	movq	j(%rip), %rax
	movq	%rax, i(%rip)
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.type	a,@object               # @a
	.bss
	.globl	a
	.align	16
a:
	.zero	180
	.size	a, 180


	.section	".note.GNU-stack","",@progbits
