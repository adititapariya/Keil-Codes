/*ORG 0000H 
	MOV A, 30H 
	MOV R0,31H 
	ADD A, R0 
	MOV 40H, A 
	JNC LOC1 
	MOV 41H, #01H 
	LOC1: 
	END */
	
/*ORG 0000H 
	MOV A,30H 
	MOV R1, 31H 
	CPL A 
	ADD A, #01H 
	ADD A, R1 
	MOV 40H, A 
	END */
	
/*ORG 0000H 
	MOV A,30H 
	MOV R1, 31H 
	CPL A 
	ADD A, #01H 
	ADD A, R1 
	CPL A 
	ADD A, #01H 
	MOV 40H, A 
	END*/ 

ORG 0000H 
MOV A,30H 
MOV R1, 31H 
CPL A 
ADD A, #01H 
MOV R2, A 
MOV A, R1 
CPL A 
ADD A, #01H 
ADD A, R2 
MOV 40H, A 
END 

