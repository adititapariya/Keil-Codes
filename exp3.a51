ORG 0000H
	MOV DPTR,#2500H
	MOVX A,@DPTR
	MOV R0,A
	MOV R1,#00H
	MOV R2,#09H
	FIND: INC DPL
	MOVX A,@DPTR
	ADD A,R0
	MOV R0,A
	JNC NEXT
	INC R1
	NEXT: DJNZ R2, FIND
	MOV DPTR,#2600H
	MOV A,R0
	MOVX @DPTR,A
	INC DPL
	MOV A,R1
	MOVX @DPTR,A
	END
		
// INSERT FF IN 2500H till 10 places..ans will be D9 F6 in 2600 and 2601H
