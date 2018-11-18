	.file	"main.c"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	ip, sp
	stmfd	sp!, {fp, ip, lr, pc}
	sub	fp, ip, #4
	sub	sp, sp, #16
	mov	r3, #1
	str	r3, [fp, #-16]
	mov	r3, #2
	str	r3, [fp, #-20]
	mov	r3, #3
	str	r3, [fp, #-24]
	mov	r3, #4
	str	r3, [fp, #-28]
	ldr	r0, [fp, #-16]
	ldr	r1, [fp, #-20]
	ldr	r2, [fp, #-24]
	ldr	r3, [fp, #-28]
	bl	func
	mov	r0, r3
	ldmea	fp, {fp, sp, pc}
	.size	main, .-main
	.ident	"GCC: (GNU) 3.3.2"
