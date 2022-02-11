	.file	"array.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	subq	$1632, %rsp
	.seh_stackalloc	1632
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	call	__main
	movl	$121, -56(%rbp)
	movl	$484, -16(%rbp)
	movl	$878, 24(%rbp)
	movl	$8888, 1424(%rbp)
	movl	$9999, 1496(%rbp)
	movl	$0, 1500(%rbp)
	movl	$0, %eax
	addq	$1632, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
