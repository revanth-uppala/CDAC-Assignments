
;/* PROGRAM TO ------------------ */

;ARM CODE 
.code 32		;word align
.text	
.global main_asm

;/* Application code for assembly starts here */

main_asm:
		ldr r0,=6
		ldr r1,=0
		cmp r0,r1
		blt loop1
		mov r3,r0
		b loop


loop1:   sub r3,r1,r0


		
		
loop:   b loop


.end


