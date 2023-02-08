.MODEL SMALL
.STACK 32

.DATA
STRLEN DB 60
STRSZ DB ?
STR DB 60 DUP(' ')
STRTRM DB '$'

.CODE
	MOV AX, @DATA
	MOV DS, AX

;reading from user
	LEA DX, STRLEN
	MOV AH, 0AH
	INT 21H

;clearing string
MOV AX, 0003H
INT 10H

;displaying diagonally
	MOV CL, STRSZ
	LEA BX, STR
L1:
	MOV DL, [BX]
	CMP DL, ' '
	JNE EX

;getting present cursor position
	PUSH CX
	PUSH DX
	MOV AH, 03H
	INT 10H

;setting cursor position
	ADD DH, 1
	MOV AH, 02H
	INT 10H
	POP DX
	POP CX
	JMP EXIT
EX:
	MOV DL, [BX]
	MOV AH, 02H
	INT 21H

EXIT:
	INC BX
	INC DL
	LOOP L1

;ending the program
	MOV AH, 4CH
	INT 21H
END