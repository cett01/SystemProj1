segment .text
global assemblySubroutine

assemblySubroutine:
    push ebp
    mov  ebp,esp

    mov  ax,[ebp+8]
    mov  ebx,[ebp+12]
    mov  ecx,[ebp+16]
    mov  edx,[ebp+20]
   
    sym1 equ 0
    sym equ 0
    
    mov bx, 2
	mov dx, 0
	mov ecx, 28
rem:
	div bx 
	mov [ebp+ecx],dx
	add ecx,4
	cmp ax,0
	jne rem
	
	
	;mov ax,[ebp+32]
	
	;mov eax,edx
	;mov cl, 0
    ;add al, 4
	;cmp ax,0
   ; jne rem
	
	;mov eax,[ebp+32]
	;add eax,4
    ;call print_int
    ;mov ebp,edx
    ;mov eax,0
    ;xor  eax,eax
;next:
    ;shr  ecx,1
    ;jnc  even
    ;add  eax,edx
;even:
 ;   shl  edx,1
  ;  cmp  ecx,0
   ; jne  next
;
    pop  ebp
    ret
