
;/* PROGRAM TO ------------------ */

;ARM CODE 
.code 32		;word align
.text	
.global main_asm
.extern sum

;/* Application code for assembly starts here */

main_asm:
		ldr r0,=2
		ldr r1,=1
		ldr r2,=3
		ldr r3,=4
		ldr r4,=5
		ldr r5,=6
		stmfd sp!,{r4-r5,lr}
		bl sum
		mov r6,r0
	
	
loop:   b loop
.end 
