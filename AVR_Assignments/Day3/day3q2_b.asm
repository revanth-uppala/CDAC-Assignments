; ******************************************************
; BASIC .ASM template file for AVR
; ******************************************************

.include "C:\VMLAB\include\m8def.inc"

; Define here the variables
;
.def  dividendLbyte  =     r16
.def dividendHbyte = r17
.def divisorLbyte = r18
.def divisorHbyte = r19
.def flag1= r22 ;Lflag
.def flag2 = r23;Hflag
.def tempL = r20
.def tempH = r21
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
process_flag1:LDI flag1,1
					rjmp ret1
process_flag2 : LDI flag2,1
					rjmp ret2
start:
  LDI dividendLbyte,0xFF
  LDI dividendHbyte,0x00
  LDI divisorLbyte,0x05
  LDI divisorHbyte,0x00
  LDI XL,0x00 ;QuotientL
  LDI XH,0x00;QuotientH	
  LDI tempH ,0
  LDI tempL, 0
	
divloop: LDI flag1,0
			LDI flag2,0
			ADD tempL,divisorLbyte
			ADC tempH,divisorHbyte
			ADIW XL,1
			CP dividendLbyte,tempL
			BREQ process_flag1
		ret1:	CP dividendHbyte,tempH
			 BREQ process_flag2
      ret2: AND  flag1,flag2
      		CPI flag1,1
      		BREQ result
      		rjmp divloop

result:
		nop
		rjmp result
