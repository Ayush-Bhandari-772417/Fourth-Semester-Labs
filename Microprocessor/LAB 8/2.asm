.MODEL SMALL
.STACK 32

.DATA
STRLEN DB 60
STRSZ DB ?
STR DB 60 DUP('$')
STRTRM DB '$'

.CODE
MOV AX, @DATA
MOV DS, AX

;reading from user
LEA DX, STRLEN
MOV AH, 0AH
INT 21H

;clearing the screen
MOV AH, 00H
MOV AL, 03H
INT 10H

;move cursor
MOV BH, 00H
MOV DH, 12
MOV AL, 80
MOV DL, STRSZ
SUB AL, DL
MOV DL, 02H
DIV DL
MOV DL, AL
MOV AH, 02H
INT 10H

;displaying string
LEA DX, STR
MOV AH, 09H
INT 21H

;ending the program
MOV AH, 4CH
INT 21H
END