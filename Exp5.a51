/*ORG 0000H
	MOV A,30H
	MOV B,31H
	ADD A,B
	MOV 40H,A
	END*/
	
/*ORG 0000H
	MOV A,30H
	MOV B,31H
	DIV AB
	MOV 40H,A
	MOV 41H,B
	END*/
		
/*ORG 0000H
	MOV R0,30H
	MOV R1,31H
	MOV R2,32H
	MOV R3,33H
	MOV R4,#00H
	MOV R5,#00H
	HERE: MOV A,R1
	CLR C
	SUBB A,R3
	JC NEXT
	JNZ NEXT1
	MOV A,R0
	SUBB A,R2
	JC NEXT
	NEXT1: MOV A,R0
	CLR C
	SUBB A,R2
	MOV R0,A
	MOV A,R1
	SUBB A,R3
	MOV R1,A
	MOV A,#01H
	ADD A,R4
	MOV R4,A
	JNC STEP
	INC R5
	STEP: SJMP HERE
	NEXT: MOV 40H,R4
    MOV 41H,R5
    MOV 42H,R0
    MOV 43H,R1
	END*/

/*ORG 0000H
	MOV R0,#40H
	MOV R1,#50H
	MOV R2,#0AH
	LOC1: MOV A,@R0
	MOV @R1,A
	INC R0
	INC R1
	DJNZ R2,LOC1
	END*/
		
/*ORG 0000H
    MOV R0, #49H   
    MOV R1, #50H   
    MOV R2, #0AH   
    
    LOC1: MOV A, @R0  
          MOV @R1, A  
          DEC R0      
          INC R1      
          DJNZ R2, LOC1  
    END*/

ORG 0000H
    MOV R0, #49H   
    MOV R1, #4EH   
    MOV R2, #0AH   
    
    LOC1: MOV A, @R0  
          MOV @R1, A  
          DEC R0      
          DEC R1      
          DJNZ R2, LOC1  
    END
		
