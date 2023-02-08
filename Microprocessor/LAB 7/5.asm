.MODEL SMALL
.STACK 32

.DATA
STRLEN DB 255
STRSZ DB ?
STR DB 255 DUP('$')
NEWLINE DB 0DH, 0AH, "Converted string : $"

.CODE
	MOV AX, @DATA
	MOV DS, AX

;reading the string
	LEA DX, STRLEN
	MOV AH, 0AH
	INT 21H

;changing to uppercase
	MOV CH, 00H
	MOV CL, STRLEN
	LEA BX, STR
L1:
	MOV AL, [BX]
	CMP AL, 'a'
	JL EX
	CMP AL, 'z'
	JG EX
	SUB AL, 20H
	MOV[BX], AL
EX:
	INC BX
	LOOP L1

;writting the string
	LEA DX, NEWLINE
	MOV AH, 09H
	INT 21H
	LEA DX, STR
	MOV AH, 09H
	INT 21H

;ending the program
	MOV AH, 4CH
	INT 21H
END