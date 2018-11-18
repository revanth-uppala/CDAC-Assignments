; ******************************************************
; BASIC .ASM template file for AVR
; ******************************************************

.include "C:\VMLAB\include\m8def.inc"

; Define here the variables
;
.def temp1 = r16
.def i = r17
.def j = r18
.def n =r19
.def swapflag= r25
.def loopcount1 = r20
.def loopcount2 = r21
.def temp2 = r22
.def temp3=r23
.def temp=r24
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
   ;Initialize stack
   LDI temp,low(RAMEND)
   OUT SPL,temp
   LDI temp,high(RAMEND)
   OUT SPH,temp
   LDI XL,0x60     ;starting address of data block
   LDI XH,0x00
  	ldi swapflag,0
  	mov temp,n
  	dec temp ; temp = n-1
  	mov loopcount1, temp
loopout: ldi swapflag,0
			ldi i,0
			
		 ldi j,0
		
		mov loopcount2,loopcount1
		sub loopcount2,i
loopin:  cp j,loopcount2
			BREQ loopout
			 add XL,j
			ld temp1,X
			INC XL
			ld temp2,X
			CP temp1,temp2
			INC j
			BRCS loopin
			ldi swapflag,1
			mov temp3,temp2
			mov temp2,temp1
			mov temp1,temp3
			rjmp loopin
			
			CPI swapflag,0
			BREQ resr
			rjmp loopout
			
resr:  rjmp resr   ;infinite loop
			
			
			
			










