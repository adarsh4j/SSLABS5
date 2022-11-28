.model small
.stack 100h
.data
    s1 db 'Enter a string $'
    vowl db 'AEIOUaeiou $'
    s3 db 10,13,'No of vowels are-> $'
    s2 db 50 dup('$')
    count dw ?
.code
        mov ax,@data
        mov ds,ax
        mov es,ax
        ;display 'enter the string'
        lea dx,s1
        mov ah,09h
        int 21h
        ;read the string
        lea di,s2
        xor cl,cl
        cld
loop1:  mov ah,01                                               
        int 21h
        cmp al,0dh
        jz endinpt
        stosb
        inc cl
        jmp loop1
endinpt:;checking vowel
        mov bl,cl
        cmp cl,00
        jnz jump1
        xor ax,ax
        jmp pr
jump1:  cld
        lea si,s2
next:   mov cx,000bh
        lodsb
        lea di,vowl
        repne scasb
        cmp cx,00
        jz novowl
        inc count
novowl: dec bl
        jnz next
        ;jump to nextline
        mov dl,0ah
        mov ah,02h
        int 21h
        ;print count of vowels
        mov ax,count
pr:     mov bx,000ah
        xor cx,cx
        ;printing multi digit number
        ;push into stack
print:  xor dx,dx
        div bx
        push dx
        inc cx
        cmp ax,0000h
        jne print
        
        ;display 'No of vowels are-> '
        lea dx,s3
        mov ah,09h
        int 21h
        ;pop from stack
display:pop dx
        add dl,30h
        mov ah,02h
        int 21h
        loop display
        mov ah,4ch
        int 21h
        end
