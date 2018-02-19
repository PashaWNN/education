format ELF

section '.data' writeable
    rawFloat  db "%lf",0
    resultStr db "f(x) = %f",0
    a dq 0
    y dq 0

section '.text' executable
extrn   printf
extrn   scanf
extrn   atof
public  main

main:
    push a
    push rawFloat
    call scanf
    add  esp,8
    
    fld qword[a]
    ftst
    fstsw  ax
    and    eax, 0100011100000000B ;take only condition code flags
    cmp    eax, 0000000000000000B ;is st0 > 0 ?
    je     greater
    jmp    lessequal
ret
    
greater: ;What if a>0
    fmul st0,st0
    fchs
    jmp  continue
ret

lessequal: ;What if a<=0
    fchs
    fst qword[y]
    jmp continue
ret

continue: ;Print result
    fst  qword[y]
    push dword[y+4]
    push dword[y]
    push resultStr
    call printf
    add  esp, 12
    xor  eax, eax
ret