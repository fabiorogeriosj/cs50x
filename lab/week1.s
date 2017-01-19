	.text
	.file	"week1.c"
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp0:
	.cfi_def_cfa_offset 16
.Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movabsq	$.L.str, %rdi
	movb	$0, %al
	callq	printf
	movl	%eax, -16(%rbp)         # 4-byte Spill
	callq	get_string
	movabsq	$.L.str1, %rdi
	movq	%rax, -8(%rbp)
	movb	$0, %al
	callq	printf
	movl	%eax, -20(%rbp)         # 4-byte Spill
	callq	get_int
	movabsq	$.L.str2, %rdi
	movl	%eax, -12(%rbp)
	movq	-8(%rbp), %rsi
	movb	$0, %al
	callq	printf
	movabsq	$.L.str3, %rdi
	movl	-12(%rbp), %esi
	movl	%eax, -24(%rbp)         # 4-byte Spill
	movb	$0, %al
	callq	printf
	xorl	%esi, %esi
	movl	%eax, -28(%rbp)         # 4-byte Spill
	movl	%esi, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
.Ltmp3:
	.size	main, .Ltmp3-main
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Enter your first name: "
	.size	.L.str, 24

	.type	.L.str1,@object         # @.str1
.L.str1:
	.asciz	"Enter your age: "
	.size	.L.str1, 17

	.type	.L.str2,@object         # @.str2
.L.str2:
	.asciz	"Name:, %s\n"
	.size	.L.str2, 11

	.type	.L.str3,@object         # @.str3
.L.str3:
	.asciz	"Age:, %i\n"
	.size	.L.str3, 10

	.type	GetChar,@object         # @GetChar
	.comm	GetChar,8,8
	.type	GetDouble,@object       # @GetDouble
	.comm	GetDouble,8,8
	.type	GetFloat,@object        # @GetFloat
	.comm	GetFloat,8,8
	.type	GetInt,@object          # @GetInt
	.comm	GetInt,8,8
	.type	GetLongLong,@object     # @GetLongLong
	.comm	GetLongLong,8,8
	.type	GetString,@object       # @GetString
	.comm	GetString,8,8

	.ident	"Ubuntu clang version 3.6.0-2ubuntu1~trusty1 (tags/RELEASE_360/final) (based on LLVM 3.6.0)"
	.section	".note.GNU-stack","",@progbits
