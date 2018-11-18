
;/* file  @ boot.s  */


.code 32
.text

.global _start
.global __start

.extern initilize_stack

;/* Entry Point of the programe  */
_start:
__start:


;/* Start of the vector table */

b       RESET_HANDLER
b       UNDEF_HANDLER
b       SWI_HANDLER
b       PREFETCH_ABORT_HANDLER
b       DATA_ABORT_HANDLER
b       RESERVED_HANDLER
b       IRQ_HANDLER
        FIQ_HANDLER:subs pc,r14,#4


;/* Exceptions handlers */

RESET_HANDLER           :       b initilize_stack  

UNDEF_HANDLER           :       movs pc,r14

SWI_HANDLER             :	stmfd sp!,{r0-r12,lr}
				ldr r2,[lr,#-4]
				bic r2,r2,#0xff000000 ;r2 = swi number
				ldr r3,= 0x123 ;0x123 for addition
				ldr r4,= 0x456 ;0x456 for subtraction
				
				cmp r2,r3
				beq add
				cmp r2,r4
				beq sub				
				
				ldmfd sp!,{r0-r12,pc}
				movs pc,r14 
add : 
	adds r2,r0,r1
	ldr r0,r2
	
	swi 0x456
	ldmfd sp!,{r0-r12,pc}	
	movs pc,r14
sub : 
	subs r2,r0,r1
	ldr r0,r2
	swi 0
	ldmfd sp!,{r0-r12,pc}
			


PREFETCH_ABORT_HANDLER  :       subs pc,r14,#4

DATA_ABORT_HANDLER      :       subs pc,r14,#8

RESERVED_HANDLER        :

IRQ_HANDLER             :       subs pc,r14,#4

.end 
