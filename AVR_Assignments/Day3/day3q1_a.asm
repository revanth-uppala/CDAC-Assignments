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
carry1 :LDI R26,1; lower nibble carry
		ret
carry2 :LDI R27,1;higher nibble carry
			ret
start:
   LDI R16,0xAA;N1 higher
   LDI R17,0xAA;N1 lower
   LDI R18,0x00;N2 higher
	LDI R19,0x01;N2 lower
   MOV  R20,R16 ; N1Hcopy
   MOV  R21,R17 ;N1Lcopy
   MOV  R22,R18 ;N2H copy
   MOV  R23,R19 ;N2L copy
    LDI R26,0
    LDI R27,0

loop1: Add R21,R17
		Adc R20,R16
		dec R23
		BRNE loop1
		MOV  R0,R21 ;lcopy
		MOV  R1,R20 ;hcopy
		BRCS carry1
		CLR R21
		CLR R20
 loop3 : Add R21,R17
 			ADC R20,R16
 			dec R22
 			BRNE loop3
 			MOV  R2,R21 ; lcopy1
 			MOV  R3,R20 ; hcopy1
 			BRCS  carry2
		
