
;/* PROGRAM TO ------------------ */

;ARM CODE 
.code 32		;word align
.text	
.global main_asm

;/* Application code for assembly starts here */

main_asm:
		ldr r0,=96
		ldr r1,=6
		ldr r2,=0
		ldr r3,=0
loop1:
		add r2,r2,r1
		cmp r2,r0
		bgt loop
		add r3,r3,#1
		beq loop
		b loop1
		


		
		
loop:   b loop


.end


