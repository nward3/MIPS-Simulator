	.file	1 "loop-test.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.gnu_attribute 4, 1
	.abicalls
	.option	pic0
	.section	.rodata.str1.4,"aMS",@progbits,1
	.align	2
$LC0:
	.ascii	"sum = %d\012\000"
	.section	.text.startup,"ax",@progbits
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$sp,32,$31		# vars= 0, regs= 1/0, args= 16, gp= 8
	.mask	0x80000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	lui	$2,%hi(A)
	lui	$4,%hi(A+32)
	addiu	$2,$2,%lo(A)
	addiu	$4,$4,%lo(A+32)
	move	$5,$0
$L2:
	lw	$3,0($2)
	addiu	$2,$2,4
	bne	$2,$4,$L2
	addu	$5,$5,$3

	lui	$4,%hi($LC0)
	addiu	$sp,$sp,-32
	sw	$31,28($sp)
	jal	tfp_printf
	addiu	$4,$4,%lo($LC0)

	lw	$31,28($sp)
	nop
	j	$31
	addiu	$sp,$sp,32

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.globl	A
	.data
	.align	2
	.type	A, @object
	.size	A, 32
A:
	.word	0
	.word	1
	.word	2
	.word	3
	.word	4
	.word	5
	.word	6
	.word	7
	.ident	"GCC: (Sourcery CodeBench Lite 2015.05-18) 4.9.2"
