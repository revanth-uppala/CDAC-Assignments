; ******************************************************
; BASIC .ASM template file for AVR
; ******************************************************

.include "C:\VMLAB\include\m8def.inc"

; Define here the variables
;
.def  temp  =r16

; Define here Reset and interrupt vectors, if any
;
reset:
   rjmp start
   reti      ; Addr $01
   reti      ; Addr $02
   reti      ; Addr $03
   reti      ; Addr $04
   reti      ; Addr $05
   reti      ; Addr $06        Use 'rjmp myVector'
   reti      ; Addr $07        to define a interrupt vector
   reti      ; Addr $08
   reti      ; Addr $09
   reti      ; Addr $0A
   reti      ; Addr $0B        This is just an example
   reti      ; Addr $0C        Not all MCUs have the same
   reti      ; Addr $0D        number of interrupt vectors
   reti      ; Addr $0E
   reti      ; Addr $0F
   reti      ; Addr $10

; Program starts here after Reset
;


start:
   nop       ; Initialize here ports, stack pointer,
   nop       ; cleanup RAM, etc.
   nop       ;
   nop       ;
   rjmp dispatcher


dispatcher :
			;PC automatically pushed onto respective stack
			;save GPRs
			push r0
			push r1
			push r2
			push r3
			push r4
			push r5
			push r6
			push r7
			push r8
			push r9
			push r10
			push r11
			push r12
			push r13
			push r14
			push r15
			push r16
			push r17
			push r18
			push r19
			push r20
			push r21
			push r22
			push r23
			push r24
			push r25
			push r26
			push r27
			push r28
			push r29
			push r30
			push r31
			in temp,sreg
			push temp
			
			
			rcall scheduler   ;scheduler updates SP to stack of next task
			
			;restore sreg
			pop temp
			out sreg,temp
			;restore GPRs
			pop r31
			pop r30
			pop r29
			pop r28
			pop r27
			pop r26
			pop r25
			pop r24
			pop r23
			pop r22
			pop r21
			pop r20
			pop r19
			pop r18
			pop r17
			pop r16
			pop r15
			pop r14
			pop r13
			pop r12
			pop r11
			pop r10 
			pop r9
			pop r8
			pop r7
			pop r6
			pop r5
			pop r4
			pop r3
			pop r2
			pop r1
			pop r0
			
			reti
scheduler :
			nop
			nop
			nop
			ret
