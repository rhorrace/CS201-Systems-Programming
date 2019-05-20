#Horrace, Robert CS 201
# program is the optimized assembly for the crc file.
#It will use conditions instead of if/else statements.
	.file	"crc.c"
	.intel_syntax noprefix
	.local	crcTable
	.comm	crcTable,256,32
	.text
	.globl	crcInit
	.type	crcInit, @function
crcInit:#function that initializes
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR [rbp-4], 0
	jmp	.L2#jumps to L2 loop, the main loop
.L7:#loop section
	mov	eax, DWORD PTR [rbp-4]
	mov	BYTE PTR [rbp-6], al
	mov	BYTE PTR [rbp-5], 8
	jmp	.L3#jumps to L7, the second loop
.L6:#loop section
	cmp	BYTE PTR [rbp-6], 0 #flags
	jns	.L4#jumps to L4 based on flags
	movsx	eax, BYTE PTR [rbp-6]
	add	eax, eax
	xor	eax, -43
	mov	BYTE PTR [rbp-6], al
	jmp	.L5#jumps to L5
.L4:#loop section
	movsx	eax, BYTE PTR [rbp-6]
	add	eax, eax
	mov	BYTE PTR [rbp-6], al
.L5:#loop section
	sub	BYTE PTR [rbp-5], 1#conditional set
.L3:#loop section
	cmp	BYTE PTR [rbp-5], 0
	jg	.L6#jumps based on flags
	mov	eax, DWORD PTR [rbp-4]
	cdqe
	movzx	edx, BYTE PTR [rbp-6]
	mov	BYTE PTR crcTable[rax], dl
	add	DWORD PTR [rbp-4], 1
.L2:#loop section

	cmp	DWORD PTR [rbp-4], 255
	jle	.L7#jumps to L7, beginning loop
	pop	rbp
	.cfi_def_cfa 7, 8
	ret#returns value of remainder 

crcFast:#function that divides one byte at a time
.LFB1:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-24], rdi
	mov	QWORD PTR [rbp-32], rsi
	mov	BYTE PTR [rbp-10], 0
	mov	QWORD PTR [rbp-8], 0
	jmp	.L9#jumps to L9
.L10:#loop section, repeats until all bytes are deleted
	mov	rdx, QWORD PTR [rbp-8]
	mov	rax, QWORD PTR [rbp-24]
	add	rax, rdx
	movzx	eax, BYTE PTR [rax]
	xor	al, BYTE PTR [rbp-10]
	mov	BYTE PTR [rbp-9], al
	movzx	eax, BYTE PTR [rbp-9]
	cdqe
	movzx	eax, BYTE PTR crcTable[rax]
	mov	BYTE PTR [rbp-10], al
	add	QWORD PTR [rbp-8], 1
.L9:#loop section
	mov	rax, QWORD PTR [rbp-8]
	cmp	rax, QWORD PTR [rbp-32]
	jl	.L10#jumps to L10
	movzx	eax, BYTE PTR [rbp-10]
	pop	rbp
	.cfi_def_cfa 7, 8
	ret#returns and gets out of function
