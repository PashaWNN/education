;Шишмарев Павел. Вариант №14.
;Задание 10. Задача 68б.
;Дано четырёхзначное число. Определить, что оно содержит ровно три одинаковых цифры
;Эту задачу я уже решал на ассемблере.
;Используется FASM, формат исполняемого файла для Linux
format ELF
section '.data' writeable

welcome db "68b. Enter 1000<=n<=9999: ",0
trueStr db "There are 3 similar digits.",0
falseStr db "There aren't 3 similar digits(Less or more)",0
rawStr db "%s",0
rawInt db "%i",0
value dd 0

section '.text' executable
extrn scanf
extrn printf
public main


main:
mov ebp, esp; for correct debugging
    push welcome
    push rawStr
    call printf
    add esp, 8

    push value
    push rawInt
    call scanf
    add esp,8

    mov eax, [value]
    cmp eax, 1000 
    jl main
    cmp eax, 9999
    jg main
    
    xor edx,edx
    mov eax, [value]
    mov bx, 10
    div bx
    mov [value],edx
    fild dword[value]
    
    xor edx,edx
    mov bx, 10
    div bx
    mov [value],edx
    fild dword[value]
    
    xor edx,edx
    mov bx, 10
    div bx
    mov [value],edx
    fild dword[value]
    
    mov [value],eax
    fild dword[value]
    
    xor eax,eax ;Will use this registers for digit counters
    xor ebx,ebx
    xor ecx,ecx
    
    fcomi st0,st1
    jne c1
    inc eax
    
    c1:
    fcomi st0,st2
    jne c2
    inc eax
    
    c2:
    fcomi st0,st3
    jne c3
    inc eax
    
    c3:
    cmp eax,2
    je true   
    jg false  
    cmp eax,1 
    je false  
    
    fstp st0 ;pop st0
    
    fcomi st0,st1
    jne false
    
    fcomi st0,st2
    jne false
true:
    push trueStr
    push rawStr
    call printf
    add esp, 8
    jmp theend
false:    
    push falseStr
    push rawStr
    call printf
    add esp, 8
theend:
    xor eax, eax
ret
