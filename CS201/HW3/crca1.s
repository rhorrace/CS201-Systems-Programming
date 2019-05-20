	.file	"crc.c"
	.local	crcTable
	.comm	crcTable,256,32
	.text
	.globl	crcInit
	.type	crcInit, @function
crcInit:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$0, -4(%rbp)
	jmp	.L2
.L7:
	movl	-4(%rbp), %eax
	movb	%al, -6(%rbp)
	movb	$8, -5(%rbp)
	jmp	.L3
.L6:
	cmpb	$0, -6(%rbp)
	jns	.L4
	movsbl	-6(%rbp), %eax
	addl	%eax, %eax
	xorl	$-43, %eax
	movb	%al, -6(%rbp)
	jmp	.L5
.L4:
	movsbl	-6(%rbp), %eax
	addl	%eax, %eax
	movb	%al, -6(%rbp)
.L5:
istrue:
isfalse:
.L3:
	cmpb	$0, -5(%rbp)
	jg	.L6
	movl	-4(%rbp), %eax
	cltq
	movzbl	-6(%rbp), %edx
	movb	%dl, crcTable(%rax)
	addl	$1, -4(%rbp)
.L2:
	cmpl	$255, -4(%rbp)
	jle	.L7
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	crcInit, .-crcInit
	.globl	crcFast
	.type	crcFast, @function
crcFast:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movb	$0, -10(%rbp)
	movq	$0, -8(%rbp)
	jmp	.L9
.L10:
	movq	-8(%rbp), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	xorb	-10(%rbp), %al
	movb	%al, -9(%rbp)
	movzbl	-9(%rbp), %eax
	cltq
	movzbl	crcTable(%rax), %eax
	movb	%al, -10(%rbp)
	addq	$1, -8(%rbp)
.L9:
	movq	-8(%rbp), %rax
	cmpq	-32(%rbp), %rax
	jl	.L10
	movzbl	-10(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	crcFast, .-crcFast
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
