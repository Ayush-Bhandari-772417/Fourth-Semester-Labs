.MODEL SMALL
.STACK 32

.DATA
str DB "Programming is Fun "
LEN DW $-str

.CODE
MOV AX, @DATA
MOV DS, AX
MOV CX, LEN
MOV DI, 0000
NXT:
	MOV DL, str[DI]
	MOV AH, 06H
	INT 21H
	INC DI
	LOOP NXT
MOV AH, 4CH
INT 21H
END