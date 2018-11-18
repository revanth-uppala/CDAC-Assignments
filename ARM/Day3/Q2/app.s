
;/* PROGRAM TO ------------------ */

;ARM CODE 
.code 32		;word align
.text	
.global func

;/* Application code for assembly starts here */

func:
	
	add r0,r0,r1
	add r1,r0,r2
	add r2,r1,r3
	mov r0,r2
	swi 0
	bx lr
	
	
	 	
	
loop:   b loop
.end 
; arm-elf-as -D -ahlms --gstabs -mcpu=arm7tdmi -o boot.o boot.s>t && arm-elf-as -D -ahlms --gstabs -mcpu=arm7tdmi -o crt.o crt.s>t && arm-elf-as -D -ahlms --gstabs -mcpu=arm7tdmi -o app.o app.s>t &&  arm-elf-gcc -g -gstabs -mcpu=arm7tdmi  -c  -o main.o  main.c && arm-elf-ld -o result   main.o app.o crt.o  boot.o -Ttext=0x00 && arm-elf-insight result

