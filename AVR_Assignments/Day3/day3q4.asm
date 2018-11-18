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
delay2:
		LDI R16,30
		loopo1:
			
				loopin1:SBIW XL,1
						 BRNE loopin1
			LDI XL,0xFF
   		LDI XH,0x0F
			DEC R16
			BRNE loopo1
			;OUT SPL,R16
			;OUT SPH,R17
			RJMP RETADD1
delay1:LDI R16,30
		loopo:
			
				loopin:SBIW XL,1
						 BRNE loopin
			LDI XL,0xFF
   		LDI XH,0x0F
			DEC R16
			BRNE loopo
			;OUT SPL,R16
			;OUT SPH,R17
			RJMP RETADD


start:
   LDI R16,low(RAMEND)
   OUT SPL,R16
   LDI R16,high(RAMEND)
   OUT SPH,R16
	LDI R16,0xFF
	OUT DDRB,R16
   LDI XL,0xFF
   LDI XH,0x0F


forever:
   LDI R16,0xAA
	LDI R17,0x55
	OUT PORTB ,R16
   ;IN R16,SPL
  ;l IN R17,SPH
	RJMP delay1
	RETADD:OUT PORTB, R17
	RJMP delay2
	RETADD1:
rjmp forever




