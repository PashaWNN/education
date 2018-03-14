org 100h

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;             Program body              ;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
main:
  mov di,input_a
  mov cx,print_str
  call cx
  call input_unsigned_int
  mov [a], eax
  call cx

  mov di,input_b
  mov cx,print_str
  call cx
  call input_unsigned_int
  mov [b], eax
  call cx

  mov di,input_c
  mov cx,print_str
  call cx
  call input_unsigned_int
  mov [c], eax
  call cx

  mov di,input_d
  mov cx,print_str
  call cx
  call input_unsigned_int
  mov [d], eax
  call cx

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
    
    
  fistp dword[r]
  mov di, result
  call print_str
  mov eax, [r]
  call print_unsigned_int
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;            I/O procedures             ;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
input_str:
  push cx
  mov cx,ax
  mov ah,0Ah
  mov [buffer],al
  mov byte[buffer+1],0
  mov dx,buffer
  int 21h
  mov al,[buffer+1]
  add dx,2
  mov ah,ch
  mov di,endline
  call print_str
  pop cx
ret 

strToUInt: ;String to integer
  push cx
  push dx
  push bx
  push si
  push di

  mov si,dx
  mov di,10
  movzx cx,al
  xor ax,ax
  xor bx,bx
  studw_lp:
    mov bl,[si]
    inc si
    sub bl,'0'
    mul di
    add ax,bx
    loop studw_lp
    jmp studw_exit
  studw_exit:
  pop di
  pop si
  pop bx
  pop dx
  pop cx
ret

input_unsigned_int:
  push dx
  mov al,6
  call input_str
  mov si,dx
  call strToUInt
  pop dx
ret

print_unsigned_int:
  push di
  mov di,buffer
  push di
  call uintToStr
  mov byte[di],'$'
  pop di
  call print_str
  pop di
ret

uintToStr:
  push ax
  push cx
  push dx
  push bx
  xor cx,cx
  mov bx,10

  wtuds_lp1:
  xor dx,dx
  div bx; AX=(DX:AX)/BX
  add dl,'0'
  push dx
  inc cx
  test ax,ax
  jnz wtuds_lp1

  wtuds_lp2:
  pop dx
  mov [di],dl
  inc di
  loop wtuds_lp2

  pop bx
  pop dx
  pop cx
  pop ax
ret

print_str:
  push ax
  mov ah,9
  xchg dx,di
  int 21h
  xchg dx,di
  pop ax
ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;          My own procedures            ;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
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
    xor eax,eax
    xor ebx,ebx
    xor ecx,ecx
    xor edx,edx
    finit
    mov di,dsntex
    mov cx,print_str
    call cx
    mov di,endline
    call cx
    jmp main
ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;             Data segment              ;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
input_a db 'Input A: $'
input_b db 'Input B: $'
input_c db 'Input C: $'
input_d db 'Input D: $'
result  db 'Triangle S: $'
dsntex  db 'Triangle with such sides does not exist! $'

a dd ?
b dd ?
c dd ?
d dd ?
r dd ?

endline db 13,10,'$'
buffer  rb 256

two          db 2   ;Constants
twopointfive dq 2.5
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;