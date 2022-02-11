# Build an executable using the following:
#
# clang barebones.s -o barebones  # clang is another compiler like gcc
#
.text
_barebones:

.data
	
.globl main

main:
					# (1) What are we setting up here?
					# Ans:
	pushq %rbp			# Push a quadword onto the stack.
	movq  %rsp, %rbp		# Move a quadword of data froom source to destination.

					# (2) What is going on here
					# Ans:
	movq $1, %rax			# Dereference, and set value to immediate value 1 in register rax.
	movq $1, %rdi			# Set value 1 to the first argument
	leaq .hello.str,%rsi		# moves "hello" string into the target register, %rsi(second argument)


					# (3) What is syscall? We did not talk about this
					# in class.
					# Ans: It transfers control to the operating system which then performs the requested service.
	syscall				# Which syscall is being run?
					# Ans: .text

					# (4) What would another option be instead of 
					# using a syscall to achieve this?
					# Ans: printf

	movq	$60, %rax		# (5) We are again setting up another syscall
	movq	$0, %rdi		# What command is it?
					# Ans:	return 
	syscall

	popq %rbp			# (Note we do not really need
					# this command here after the syscall)

.hello.str:
	.string "Hello World!\n"
	.size	.hello.str,13		# (6) Why is there a 13 here?
					# Ans:	It indicates length of the string
