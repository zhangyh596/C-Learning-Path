	.file	"main.c"
	.text
	.globl	div16
	.type	div16, @function
div16:
.LFB23:
	.cfi_startproc
	endbr64
	movl	%edi, %eax
	sarl	$31, %eax
	andl	$15, %eax
	addl	%edi, %eax
	sarl	$4, %eax
	ret
	.cfi_endproc
.LFE23:
	.size	div16, .-div16
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	endbr64
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 15.2.0-16ubuntu1) 15.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
