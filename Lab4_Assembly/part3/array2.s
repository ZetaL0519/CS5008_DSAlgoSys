	.file	"array2.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	movl	$1600, %ecx
	call	malloc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$40, %rax
	movl	$121, (%rax)
	movq	-8(%rbp), %rax
	addq	$80, %rax
	movl	$484, (%rax)
	movq	-8(%rbp), %rax
	addq	$120, %rax
	movl	$878, (%rax)
	movq	-8(%rbp), %rax
	addq	$1520, %rax
	movl	$8888, (%rax)
	movq	-8(%rbp), %rax
	addq	$1592, %rax
	movl	$9999, (%rax)
	movq	-8(%rbp), %rax
	addq	$1596, %rax
	movl	$0, (%rax)
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
