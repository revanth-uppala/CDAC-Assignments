
;/* PROGRAM TO ------------------ */

;ARM CODE 
.code 32		;word align
.text	
.global main_asm
.extern add
;/* Application code for assembly starts here */

main_asm:
	
	mov r0,#1
	mov r1,#2
	mov r2,#3
	mov r3,#4
	;mov r5,#5
	b add
loop:   b loop
.end 
