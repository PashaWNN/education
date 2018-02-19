format ELF

section '.data' writeable
    a dd 0
    b dd 0
    c dd 0
    d dd 0
    res dq 0
    helloString db "Задача №443",0Dh,0Ah,0
    errorString db "Ошибка: один или более треугольников с заданными сторонами не существуют!",0Dh,0Ah,0
    rawStr db "%s",0
    rawInt db "%d",0
    inputFormat db "Введите %s: ",0
    outputFormat db "Площадь многоугольника: %f",0
    
    a_lit db "A",0 ;Literals for strings in console
    b_lit db "B",0
    c_lit db "C",0
    d_lit db "D",0
    
    two db 2       ;Constants
    twopointfive dq 2.5
    

section '.text' executable
public main
extrn scanf
extrn printf



triangle: ;Calculate triangles S by A,B,C stored in st(0-2)
;Check if triangle exists
    fldz
    fadd st0,st2
    fadd st0,st3
    fldz
    fadd st0,st2
    fadd st0,st4
    fldz
    fadd st0,st3
    fadd st0,st4
    
    fcomp st5
    fstsw  ax
    and    eax, 0100011100000000B ;take only condition code flags
    cmp    eax, 0000000000000000B ;is a+b>c?
    jne    doesntexist
    
    fcomp st3
    fstsw  ax
    and    eax, 0100011100000000B ;take only condition code flags
    cmp    eax, 0000000000000000B ;is a+c>b?
    jne    doesntexist
    
    fcomp st1
    fstsw  ax
    and    eax, 0100011100000000B ;take only condition code flags
    cmp    eax, 0000000000000000B ;is b+c>a?
    jne    doesntexist
;Calculate S
    fldz            ;Push zero to stack heap     Stack: 0|A|B|C
    fadd st0,st1    ;Add               A                A|A|B|C
    fadd st0,st2    ;                  B              A+B|A|B|C
    fadd st0,st3    ;                  C            A+B+C|A|B|C
    fild dword [two];Push 2 to stack              2|A+B+C|A|B|C
    fdivp           ;Divide by 2                        p|A|B|C
    fsubr st1,st0   ;Subtract                         p|p-A|B|C
    fsubr st2,st0   ;                               p|p-A|p-B|C
    fsubr st3,st0   ;                             p|p-A|p-B|p-C
    fmulp           ;Multiply                   p*(p-A)|p-B|p-C
    fmulp           ;                         p*(p-A)*(p-B)|p-C
    fmulp           ;                       p*(p-A)*(p-B)*(p-C)
    fsqrt           ;Square root                              S
ret

doesntexist:
    push errorString
    push rawStr
    call printf
    add esp, 8
    jmp main
ret

main:
    mov ebp, esp; for correct debugging
    finit
    push helloString
    push rawStr
    call printf
    add esp, 8
    
    push a_lit
    push inputFormat
    call printf
    add esp, 8
    
    push a
    push rawInt
    call scanf
    add esp, 8
    
    push b_lit
    push inputFormat
    call printf
    add esp, 8
    
    push b
    push rawInt
    call scanf
    add esp,8
    
    push c_lit
    push inputFormat
    call printf
    add esp, 8
    
    push c
    push rawInt
    call scanf
    add esp, 8
    
    push d_lit
    push inputFormat
    call printf
    add esp, 8
    
    push d
    push rawInt
    call scanf
    add esp,8
   
    fld1
    fild dword[two]
    fild dword[a]
    call triangle
    
    fild dword [two]
    fld qword [twopointfive]
    fild dword [b]
    call triangle
    
    fild dword [c]
    fild dword [d]
    fld qword [twopointfive]
    call triangle
    
    faddp  ; Sum of triangles S's
    faddp
    
    fstp qword[res]
    push dword[res+4]
    push dword[res]
    push outputFormat
    call printf    
    add esp, 12
    xor eax, eax
    ret

