
;/* PROGRAM TO ------------------ */

;ARM CODE 
.code 32		;word align
.text	
.global main_asm

;/* Application code for assembly starts here */

main_asm:
		ldr r0,=0x02
		ldr r1,=0x03
		add r2,r1,r0
		swi 0x123
		add r2,r2,#0x01


		
		
loop:   b loop


.end


