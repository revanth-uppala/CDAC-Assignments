
;/* PROGRAM TO ------------------ */


	;ARM CODE
	.code 32                ;word align
	.text
	.global main_asm

	/* Application code for assembly starts here */

	main_asm:
			LDR R0,= 0x01
			LDR R1,= 0x02
			swi #0x10000
			ADDS R0,R0,R1

	       
	loop:   b loop
	
	
	

	.end
