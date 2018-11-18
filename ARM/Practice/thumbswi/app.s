
;/* PROGRAM TO ------------------ */

;ARM CODE 
.code 32		;word align
.text	
.global main_asm

;/* Application code for assembly starts here */

main_asm:
	ldr r0,= 16
	ldr r10, = 0xe1
	mov lr,pc
	bx r10
	ldr r2,= 2
	ldr r2,=3	

loop:   b loop



.code 16
 thumb:	
	ldr r2,= 23
	swi 0xFF
	ldr r3,= 24
	bx lr
	

.end 
