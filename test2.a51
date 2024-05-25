ORG 0000H
MOV R4,#142
MOV TMOD,#01H
MOV R1,#9
MOV DPTR, #200H
MOV R2, #0  ; Initialize counters for spaces
MOV R3, #0  ; Initialize counters for 'A's


LOOP:
	CLR A
    MOVC A, @A+DPTR  ; Load character from string
    CJNE A, #' ', NOT_SPACE  ; Check if character is ' '
    INC R2  ; Increment space counter
    SJMP CONTINUE_LOOP
NOT_SPACE:
    CJNE A, #'A', CONTINUE_LOOP  ; Check if character is 'A'
    INC R3  ; Increment A counter
CONTINUE_LOOP:
    INC DPL  ; Move to next character  
	CLR A
	MOV A, DPL
    CJNE A, #1FH, LOOP  ; Check for end of string

BLINK:
	MOV P1, R2 
    MOV P2, R3
	ACALL DELAY
	MOV P1, #00H
	MOV P2, #00H
	ACALL DELAY
	DJNZ R1,BLINK
	OVER: SJMP OVER
	
DELAY:
	MOV TH0, #0E6H
    MOV TL0, #67H 
    SETB TR0
	WAIT: JNB TF0,WAIT
    CLR TF0
    DJNZ R4,DELAY
	RET
	
	
ORG 200H
msg: DB "DEPARTMENT OF ELECTRICAL ENGINEERING"
		

END