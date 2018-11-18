
;/* PROGRAM TO ------------------ */

;ARM CODE 
.code 32		;word align
.text	
.global main_asm

;/* Application code for assembly starts here */


main_asm:

	MOV	R2,	#0x01		; R2 = 0x01
	MOV	R3,	#0x02		; R3 = 0x02
		
	;Other examples to move immediate values
	LDR	R5,=0X3210		; R5 = 0x3210

	LDR	R5,=0x7654		; R5 = 0x7654

	LDR	R6,=0x87654321		; R6 = 0x87654321

	LDR	R7,	= 0x87654321    ; R7 = 0x87654321


	ADD	R1,R2,R3		; R1 = 0x00000003
	LDR  R3,= 0xFFFFFFFF		; R3 =0xffffffff 
	ADDS	R1,R2,R3		; R1 = 0x00000000
					; Z,C set

	SUBS	R1,R2,R3		; R1 =0x00000002
					; Z,C set

	MOV	R4, 	#0xFFFFFFFF	; R4 =0xffffffff
	ADD	R1,R2,R4		; R1 =0x00000000
				; no flags affected

	ADDS	R1,R2,R4	; R1 =0x00000000
				
				; Z,C set


	MOV	R2,	#0x00000002	; R2 =0x00000002
	ADDS	R1,R2,R4		; R1 = 0x00000001
					; C set

   	MOV	R2,	#0x00000001	; R2 =0x00000001
	MOV	R3,	#0x00000002	; R3 =0x00000002
	ADDS	R1,R2,R3		; R1 =0x00000003
					 
					;no flags are affected 

	; Add numbers that will create an overflow
	MOV     R2, 	#0x7FFFFFFF	; R2 =0x7fffffff
	MOV	R3, 	#0x7FFFFFFF 	; R3 =0x7fffffff

	ADDS    R1,R2,R3		; R1 =0xfffffffe
					;no flags are affected
loop:   b loop
.end 

