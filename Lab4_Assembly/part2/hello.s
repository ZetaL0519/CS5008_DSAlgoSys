<<<<<<< HEAD
# Your assembly code here
# Type out the assembly--don't just copy and paste!

=======
>>>>>>> 8c28c2e439a2946cb0f767cd8206bbb39d5ba88d
  .global _start

  .text

  _start:
  	# Write a message to the screen
  	mov $1, %rax
  	mov $1, %rdi
  	mov $message, %rsi
  	mov $13, %rdx
  	syscall

  	# Exit the program
  	mov $60, %rax
  	xor %rdi, %rdi
  	syscall

  message:
<<<<<<< HEAD
  	.ascii "Hello, World\n"

=======
  	.ascii "Hello, World\n"
>>>>>>> 8c28c2e439a2946cb0f767cd8206bbb39d5ba88d
