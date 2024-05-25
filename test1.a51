ORG 0x0000     ; Start address

MOV DPTR, #0x8000   ; Point DPTR to the beginning of the string
MOV R0, #0x00       ; Initialize counter for spaces (part 1)
MOV R1, #0x00       ; Initialize counter for 'A's (part 2)
MOV R2, #0x0A       ; Set loop counter for blinking

LOOP:
  MOVX A, @DPTR     ; Load character from string to accumulator
  INC DPTR          ; Increment pointer to point to the next character
  CJNE A, #0x20, CHECK_A  ; Check if character is a space
  INC R0            ; Increment space counter if space is found
  SJMP CONTINUE     ; Skip checking for 'A' if space is found

CHECK_A:
  CJNE A, #0x41, CONTINUE  ; Compare character with 'A'
  INC R1            ; Increment 'A' counter if 'A' is found

CONTINUE:
  DJNZ R2, LOOP     ; Decrement loop counter and repeat if not zero

MOV R2, #0x0A       ; Reset loop counter for blinking

BLINK:
  MOV P1, R0        ; Display number of spaces on port 1
  ACALL DELAY       ; Call delay subroutine
  MOV P1, R1        ; Display number of 'A's on port 1
  ACALL DELAY       ; Call delay subroutine
  DJNZ R2, BLINK    ; Decrement loop counter and repeat if not zero

END:

DELAY:
  MOV R3, #0xFF     ; Load delay counter
L1:
  MOV R4, #0xFF     ; Nested delay counter
L2:
  DJNZ R4, L2       ; Decrement nested delay counter
  DJNZ R3, L1       ; Decrement delay counter
  RET               ; Return from delay subroutine

ORG 0x8000     ; String address
DB "DEPARTMENT OF ELECTRICAL ENGINEERING", 0x00   ; Null-terminated string