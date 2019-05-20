#Horrace, Robert CS201
#This program is the optimized assembly for hw3.
#This program will be used for linking.
#It will also be used in the makefile.
	.file	"hw3.c"
	.section	.rodata
.LC0:
	.string	"Usage: hw2 message"
.LC1:
	.string	"CRC:%X\n"
	.align 8
.LC2:
	.string	"Iterations: %lu, TotalTime : %lu ms, IterTime : %lu us\n"
	.text
	.globl	main
	.type	main, @function
main:#the function in the file
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movl	%edi, -68(%rbp)
	movq	%rsi, -80(%rbp)
	movb	$0, -49(%rbp)
	movq	$0, -48(%rbp)
	movq	$0, -40(%rbp)
	cmpl	$2, -68(%rbp)
	je	.L2
	movl	$.LC0, %edi
	call	puts
	movl	$1, %eax
	jmp	.L6
.L2:
	leaq	-16(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	gettimeofday
	movq	$0, -48(%rbp)
	jmp	.L4
.L5:
	call	crcInit
	movq	-80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	strlen
	movq	%rax, %rdx
	movq	-80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	crcFast
	movb	%al, -49(%rbp)
	addq	$1, -48(%rbp)
.L4:
	cmpq	$0, -48(%rbp)
	jle	.L5
	leaq	-32(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	gettimeofday
	movq	-32(%rbp), %rax
	imulq	$1000, %rax, %rsi
	movq	-24(%rbp), %rcx
	movabsq	$2361183241434822607, %rdx
	movq	%rcx, %rax
	imulq	%rdx
	sarq	$7, %rdx
	movq	%rcx, %rax
	sarq	$63, %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	leaq	(%rsi,%rax), %rdi
	movq	-16(%rbp), %rax
	imulq	$-1000, %rax, %rsi
	movq	-24(%rbp), %rcx
	movabsq	$2361183241434822607, %rdx
	movq	%rcx, %rax
	imulq	%rdx
	sarq	$7, %rdx
	movq	%rcx, %rax
	sarq	$63, %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	subq	%rax, %rsi
	movq	%rsi, %rax
	addq	%rdi, %rax
	movq	%rax, -40(%rbp)
	movzbl	-49(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movq	-40(%rbp), %rax
	imulq	$1000, %rax, %rax
	movabsq	$4835703278458516699, %rdx
	mulq	%rdx
	movq	%rdx, %rcx
	shrq	$18, %rcx
	movq	-40(%rbp), %rdx
	movq	-48(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
