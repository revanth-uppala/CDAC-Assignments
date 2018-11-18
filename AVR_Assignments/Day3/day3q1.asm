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
   LDI R16,0x0F;N1L
   LDI R17 ,0x0F ;N1H.
   LDI R18,0x02;N2L
   LDI R19,0x00 ; N2H
   MOV  XL,R18 ; N2L copy
   MOV  XH,R19 ; N2H copy
	LDI R20,0 ; Result Lbyte
	LDI R21,0 ;Result Hbyte
	
loop :ADD R20,R16
		ADC R21,R17
		SBIW XL,1
		BRNE loop
		MOV  R0,R21;Result Hbyte
		MOV  R1,R20    ;Result Lbyte
		
;forever:
 ;  nop
  ; nop       ; Infinite loop.
   ;nop       ; Define your main system
   ;nop       ; behaviour here
;rjmp forever


