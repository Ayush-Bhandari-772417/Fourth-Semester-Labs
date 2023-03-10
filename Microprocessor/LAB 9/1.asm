.MODEL SMALL
.STACK 64
.DATA
	STRLEN DB 8
	STRSZ DB ?
	STR DB 9 DUP('$')
	NUM DW 0
	SUM DW 0
	BASE DW 10
	BASEH DW 10H
	MSG1 DB "ANSWER IN HEXADECIMAL = $"
	MSG2 DB "ANSWER IN DECIMAL = $"
.CODE
	MOV AX, @DATA
	MOV DS, AX
	
;TAKING INPUT FROM USER
	LEA DX, STRLEN
	MOV AH, 0AH
	INT 21H

;INITIALIZING FOR CONVERTING TO NUMBER
	MOV CX, 00	
	MOV CL, STRSZ
	LEA DI, STR
	MOV AX, 00

;CHECKING FOR DIGIT	
L1:	MOV BL, [DI]
	CMP BL, '0'
	JB BRX
	CMP BL, '9'
	JA BRX

;CONVERTING TO NUMBER
	AND BL, 0FH
	MUL BASE
	ADD AX, BX
	INC DI
	LOOP L1

	BRX: MOV NUM, AX
	MOV AX, 0

;CALCULATE THE SUM
	MOV CX, 1
L2:	ADD AX, CX
	CMP CX, NUM
	INC CX
	JBE L2

	MOV SUM, AX

;NEW LINE CHARACTER
	MOV AH, 02H
	MOV DL, 0AH
	INT 21H

;DISPLAYING MESSAGE1
	LEA DX, MSG1
	MOV AH, 09H
	INT 21H

	MOV AX, SUM
	MOV CX, 4

;EXTRACTING DIGITS OF HEXADECIMAL	
L4:	XOR DX, DX
	MUL BASEH
	MOV BX, AX
	CMP DX, 10
	JAE ALPHA
	OR DL, 30H
	JMP DISP

;DISPLAYING IN HEXADECIMAL
	ALPHA: ADD DL, 55
	DISP: MOV AH, 02H
	INT 21H
	MOV AX, BX
	LOOP L4
	
;NEW LINE CHARACTER
	MOV AH, 02H
	MOV DL, 0AH
	INT 21H

;DISPLAYING MESSAGE2
	LEA DX, MSG2
	MOV AH, 09H
	INT 21H
	
;CONVERTING TO DECIMAL
	MOV CX, 10
	MOV AX, SUM
	MOV BX, 0

L3:	MOV DX, 0
	DIV CX
	ADD DX, 30H
	PUSH DX

	INC BX
	CMP AX, 0
	JA L3

;DISPLAYING IN DECIMAL
	MOV AH, 02H
	MOV CX, BX
	DIS: POP DX
	INT 21H
	LOOP DIS

;ENDING PROGRAM
	MOV AH, 4CH
	INT 21H
	END