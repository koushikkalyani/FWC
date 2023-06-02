.include "/sdcard/fwc/assembly/m328pdef.inc"
.MACRO delay
ldi r20,@0
L1: ldi r21,@1
L2: ldi r22,@2
L3:
NOP 
NOP
dec r22
brne L3
dec R21
brne L2
dec r20
brne L1
.ENDMACRO

.org 0x0000
sbi DDRC,5  ;for clock
ldi r16,0b11110001 ;define i/p for digital pins 9,10,11
out DDRB,r16;i/p from portB
ldi r16,0b00011100 ;define o/p for digital pins 2,3,4
out DDRD,r16;o/p from portD
ldi r16,0b00000000;initializing with 000
out PORTD,r16

repeat:       ;loop starts here

SBI PORTC,5   ;set clock high here
delay 200,200,100  ;delay using macro shown in the starting
in r16,PINB ;read input from pinB
 mov r17,r16    ;make a copy of input justt read
 andi r16,0b00000010 ;extracting 2nd bit for Q0
 lsr r16 ;store it in lsb
 mov r18,r17
 andi r18,0b00000100 ;extract 3rd bit for Q1
 lsr r18
 lsr r18  ;store it in lsb
 mov r19,r17
 andi r19,0b00001000
 lsr r19
 lsr r19
 lsr r19  ; store it in lsb
 mov r20,r16 ;  r20 contains Q0
 mov r21,r18  ;r21 contains Q1
 mov r22,r19  ;r22 contains Q2
 ldi r30,0b00000001 ;for doing compliment of given bit we need to exor it with 1
 eor r16,r30  ;now r16 contains Q0'
 eor r18,r30  ;now r18 contains Q1'
 eor r19,r30  ;now r19 contains Q2'
 mov r23,r18
 and r23,r19  ;therefore,r23 = D0 i.e. Q1'.Q2'
 lsl r23
 lsl r23 ;placing D0 to digital pin 2
 mov r24,r20
 and r24,r19  ;therefore,r24 = D1 i.e. Q0.Q2'
 lsl r24
 lsl r24
 lsl r24 ; placing D1 to digital pin 3
 mov r25,r20
 eor r25,r22
 and r25,r21  ; therefore ,r25 = D2 i.e. Q1.(Q0'Q2+Q0Q2')
 lsl r25
 lsl r25
 lsl r25
 lsl r25  ; placing D2 to digital pin 4
 or r23,r24
 or r23,r25
out PORTD,r23
 cbi PORTC,5
 delay 255,255,255
rjmp repeat


