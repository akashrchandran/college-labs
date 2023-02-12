;largest and smallest number in an array
data segment
msg1 db 0dh,0ah,"Enter the limit:$"
msg2 db 0dh,0ah,"Enter the elements:$"
msg3 db 0dh,0ah,"Smallest number:$"
msg4 db 0dh,0ah,"Largest number:$"
newline db 0dh,0ah,"$"
data ends

code segment
assume cs:code,ds:data
start:mov ax,data
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
mov bx,ax
cmp bx,0000h
jle ext
print msg2
call read
print newline
mov cx,ax
mov dx,ax
dec bx
next:cmp bx,0000h
jle down
call read
print newline
cmp cx,ax
jle go1
mov cx,ax
go1:cmp dx,ax
jge go2
mov dx,ax
go2:dec bx
jmp next
down:print msg3
mov ax,cx
call display
print msg4
mov ax,dx
call display
ext:mov ah,4ch
int 21h

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
end start