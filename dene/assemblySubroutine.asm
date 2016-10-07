segment .text
global assemblySubroutine

assemblySubroutine:
    push ebp
    mov  ebp,esp

    mov  ax,[ebp+8]


    sym equ 24
    mov bx, 2
	mov dx, 0
	mov ecx,sym
rem:
	div bx 
	mov [ebp+ecx],dx
	add ecx,4
	cmp ecx,56
	jne rem
	;mov ax,[ebp+ecx-16]    ; buradan elemanlara erisebiliyorum ecx=60

	
    mov  ecx,0			;firstly total equals 0
calc:
	mov  ebx,[ebp+12]  	;2.index
	mov eax,4			;multiply by 2^2
	mul ebx				;new eax
	add ecx,eax			;total
	
	mov  ebx,[ebp+16]   ;3.index
	mov eax,2			;multiply by 2^1
	mul ebx             ;new eax
	add ecx,eax			;total
	
	mov  ebx,[ebp+20]   ;4.index
	mov eax,1			;multiply by 2^0
	mul ebx				;new eax
	add ecx,eax			;total

	mov eax,4
	mul ecx
	
	mov ecx,eax
	add ecx,sym
	add ecx,ebp    
	mov eax,[ecx]
    
    pop  ebp
    ret
