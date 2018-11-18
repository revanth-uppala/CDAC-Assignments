
;/* PROGRAM TO ------------------ */

;ARM CODE 
.code 32		;word align
.text	
.global main_asm

;/* Application code for assembly starts here */

main_asm:
	
	mov r1,#4
	mov r2,#5
	mov r3,r1
	mov r1,r2
	mov r2,r3	
	
loop:   b loop
.end 
