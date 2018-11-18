
;/* PROGRAM TO ------------------ */

;ARM CODE 
.code 32		;word align
.text	
.global main_asm

;/* Application code for assembly starts here */

main_asm:
	
	ldr r0,= 0x123
	ldr r1,= 0x123
	swi 0x123
	
	
	
	 	
	
loop:   b loop
.end 
; arm-elf-as --gstabs -ahlms -D -mcpu=arm7tdmi -o boot.o boot.s>t && arm-elf-as --gstabs -ahlms -D -mcpu=arm7tdmi -o crt.o crt.s>t && arm-elf-as --gstabs -ahlms -D -mcpu=arm7tdmi -o app.o app.s>t && arm-elf-gcc -c -g -gstabs -mcpu=arm7tdmi -c -o main.o main.c && arm-elf-ld -o result   main.o app.o crt.o  boot.o -Ttext=0x00 && arm-elf-insight result

