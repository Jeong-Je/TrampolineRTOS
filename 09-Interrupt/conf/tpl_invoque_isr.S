
//We have to save registers that are not saved by a function call, i.e.
//R18–R27, R30, R31, R0, R1

.equ  TPL_ISR2_HANDLER, 0x40
#include <avr/io.h>


.equ ISRPin2_id, 1
//ISR2 ISRPin2 Handler
.global PIN2
PIN2:
    push r0
    push r1
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
    push r30
    push r31
    ldi r24, ISRPin2_id
    ldi r25, 0
    ldi r30,TPL_ISR2_HANDLER
    call tpl_sc_handler
    pop r31
    pop r30
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
    pop r1
    pop r0
    reti

.equ ISRPin3_id, 2
//ISR2 ISRPin3 Handler
.global PIN3
PIN3:
    push r0
    push r1
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
    push r30
    push r31
    ldi r24, ISRPin3_id
    ldi r25, 0
    ldi r30,TPL_ISR2_HANDLER
    call tpl_sc_handler
    pop r31
    pop r30
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
    pop r1
    pop r0
    reti
