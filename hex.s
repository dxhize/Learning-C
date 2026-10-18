	.file	"hex.c"
	.text
	.globl	chararr
	.data
	.type	chararr, @object
	.size	chararr, 6
chararr:
	.ascii	"ABCDEF"
	.section	.rodata
.LC0:
	.string	"n: "
.LC1:
	.string	"%i"
	.align 8
.LC2:
	.string	"Hexadecimal doesnt support number greater than 255"
.LC3:
	.string	"0x0%i"
.LC4:
	.string	"Hex code is: 0x%c%i\n"
.LC5:
	.string	"Hex code is: 0x%i%c\n"
.LC6:
	.string	"Hex code is: 0x%c%c\n"
.LC7:
	.string	"Hex code is: 0x%i%i\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	leaq	-12(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc23_scanf
	movl	-12(%rbp), %eax
	cmpl	$255, %eax
	jle	.L2
	movl	$.LC2, %edi
	call	puts
	movl	$0, %eax
	jmp	.L13
.L2:
	movl	$0, -8(%rbp)
	movl	-12(%rbp), %eax
	cmpl	$9, %eax
	jg	.L5
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	$1, %eax
	jmp	.L13
.L6:
	addl	$1, -8(%rbp)
	movl	-12(%rbp), %eax
	subl	$16, %eax
	movl	%eax, -12(%rbp)
.L5:
	movl	-12(%rbp), %eax
	cmpl	$15, %eax
	jg	.L6
	movl	-12(%rbp), %eax
	cmpl	$9, %eax
	jle	.L7
	movl	-12(%rbp), %eax
	subl	$10, %eax
	cltq
	movzbl	chararr(%rax), %eax
	movb	%al, -2(%rbp)
.L7:
	cmpl	$9, -8(%rbp)
	jle	.L8
	movl	-8(%rbp), %eax
	subl	$10, %eax
	cltq
	movzbl	chararr(%rax), %eax
	movb	%al, -1(%rbp)
.L8:
	cmpl	$9, -8(%rbp)
	jle	.L9
	movl	-12(%rbp), %eax
	cmpl	$9, %eax
	jg	.L9
	movl	-12(%rbp), %edx
	movsbl	-1(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
.L9:
	cmpl	$9, -8(%rbp)
	jg	.L10
	movl	-12(%rbp), %eax
	cmpl	$9, %eax
	jle	.L10
	movsbl	-2(%rbp), %edx
	movl	-8(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
.L10:
	cmpl	$9, -8(%rbp)
	jle	.L11
	movl	-12(%rbp), %eax
	cmpl	$9, %eax
	jle	.L11
	movsbl	-2(%rbp), %edx
	movsbl	-1(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
.L11:
	cmpl	$9, -8(%rbp)
	jg	.L12
	movl	-12(%rbp), %eax
	cmpl	$9, %eax
	jg	.L12
	movl	-12(%rbp), %edx
	movl	-8(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC7, %edi
	movl	$0, %eax
	call	printf
.L12:
	movl	$0, %eax
.L13:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 16.2.1 20260819 (Red Hat 16.2.1-2)"
	.section	.note.GNU-stack,"",@progbits
