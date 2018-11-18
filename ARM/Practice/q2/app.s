
;/* PROGRAM TO ------------------ */

;ARM CODE 
.code 32		;word align
.text	
.global main_asm

;/* Application code for assembly starts here */

main_asm:
		ldr r3,=96
		ldr r1,=1
		add r0,r1,r3
		swi 0
		ldr r0,=98
		swi 0
		ldr r0,=99
		swi 0
		


		
		
loop:   b loop


.end


