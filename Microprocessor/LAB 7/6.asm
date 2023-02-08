.MODEL SMALL
.STACK 32

.DATA
STRLEN DB 255
STRSZ DB ?
STR DB 255 DUP(' ')
NEWLINE DB 0DH, 0AH, '$'

.CODE
	MOV AX, @DATA
	MOV DS, AX

;reading the string
	LEA DX, STRLEN
	MOV AH, 0AH
	INT 21H

;displaying each word of string in separate lines
	LEA DX, NEWLINE
	MOV AH, 09H
	INT 21H

	MOV CH, 00H
	MOV CL, STRSZ
	LEA BX, STR
L1:
	MOV DL, [BX]
	CMP DL, ' '
	JNE EX
;inserting a new line
	LEA DX, NEWLINE
	MOV AH, 09H
	INT 21H
	JMP BRK
EX:
	MOV AH, 02H
	INT 21H

BRK:
	INC BX
	LOOP L1

;ending the program
	MOV AH, 4CH
	INT 21H
END