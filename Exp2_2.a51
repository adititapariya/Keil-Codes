ORG 0000H
	MOV DPTR,#2500H
	CLR C
	MOV R2,#0AH
	DO: MOV A,#00H
	MOVC A,@A+DPTR
	MOV R3,A
	INC DPH
	MOV A,#00H
	MOVC A,@A+DPTR
	ADD A,R3
	DEC DPH
	MOVX @DPTR,A
	INC DPL
	DJNZ R2,DO
	JNC STOP
	MOV A, #01H
	MOVX @DPTR,A
	STOP:
	END
		
	
	
	
	
	