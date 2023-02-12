;bubble sort
data segment
msg1 db 0dh,0ah,"Enter the limit:$"
msg2 db 0dh,0ah,"Enter array elements:",0dh,0ah,"$"
msg3 db 0dh,0ah,"Sorted array:$"
newline db 0dh,0ah,"$"
tab db "   $"
num1 dw 20 dup(0)
n dw 1
data ends

code segment
assume cs:code,ds:data
stpart:mov ax,data
mov ds,ax

print macro msg
push ax
push dx
lea dx,msg
mov ah,09h
int 21h
pop dx
pop ax
endm

print msg1
call read
mov n,ax
mov cx,ax
cmp cx,0000h
jle stp

print msg2
lea bx,num1
rd:cmp cx,0000h
jle down
call read
print newline
mov [bx],ax
inc bx
inc bx
dec cx
jmp rd
stp:mov ah,4ch
int 21h
down:mov si,0001h
lp1:cmp si,n
jge ex1
lea bx,num1
mov di,0001h
lp2:cmp di,n
jge ex2
mov ax,0002h[bx]
cmp ax,[bx]
jge skip
mov dx,[bx]
mov [bx],ax
mov 0002h[bx],dx
skip:inc bx
inc bx
inc di
jmp lp2
ex2:inc si
jmp lp1
ex1:print msg3
mov cx,0000
lea bx,num1
lp3:cmp cx,n
jge stp
mov ax,[bx]
print tab
call display
inc cx
inc bx
inc bx
jmp lp3
jmp stp

read proc near
push bx
push dx
xor ax,ax
push ax
l1:mov ah,01h
int 21h
cmp al,0dh
je l2
mov ah,00h
sub al,30h
mov bx,ax
mov dx,000ah
pop ax
mul dx
add ax,bx
push ax
jmp l1
l2:pop ax
pop dx
pop bx
ret
read endp

display proc near
push ax
push bx
push cx
push dx
mov bx,000ah
xor cx,cx
l3:xor dx,dx
div bx
add dx,0030h
push dx
inc cx
cmp ax,0000h
jnz l3
l4:pop dx
mov ah,02h
int 21h
loop l4
pop dx
pop cx
pop bx
pop ax
ret
display endp

code ends
end stpart