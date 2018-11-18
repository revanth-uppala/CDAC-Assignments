
;/* PROGRAM TO ------------------ */

;ARM CODE 
.code 32		;word align
.text	
.global main_asm

;/* Application code for assembly starts here */

main_asm:
	
	mov r1,#64	;dividend
	mov r2,#5	;divisor
	mov r3,#0	;temp
	mov r4,#0	;quotient
loop1 : 
	add r3,r3,r2
	CMP r3,r1
	BGT loop	
	add r4,r4,#1	
	BEQ loop
	b loop1 	
loop:   b loop
.end 
