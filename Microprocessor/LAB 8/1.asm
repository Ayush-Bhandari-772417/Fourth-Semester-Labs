.MODEL SMALL
.STACK 32

.DATA
STR DB "Programming in Assembly Language is Fun $"
STRLREN DB $-STR

.CODE
MOV AX, @DATA
MOV DS, AX

;setting reverse video mode
MOV AH, 00H
MOV AL, 03H
INT 10H

;scrolling from row 5, column 20 to row 20, column 60
MOV CH, 05
MOV CL, 20
MOV DH, 20
MOV DL, 60
MOV AH, 07H
MOV BH, 71H
MOV AL, 00H
INT 10H

;character cursor position change
MOV BH, 00H
MOV DH, 12
MOV DL, 30
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