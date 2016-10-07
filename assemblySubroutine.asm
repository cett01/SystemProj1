
segment .text
global assemblySubroutine

assemblySubroutine:
    push ebp
    mov  ebp,esp

    mov  ecx,0			;firstly total equals 0
calc:
	mov  ebx,[ebp+12]  	;2. parameter
	mov eax,4			;multiply by 2^2
	mul ebx				;new eax
	add ecx,eax			;total
	
	mov  ebx,[ebp+16]   ;3.parameter
	mov eax,2			;multiply by 2^1
	mul ebx             ;new eax
	add ecx,eax			;total
	
	mov  ebx,[ebp+20]   ;4.parameter
	mov eax,1			;multiply by 2^0
	mul ebx				;new eax
	add ecx,eax			;total

	
	inc cl       		;it should be shifted at least once that's why we incremented the cl by 1 since it was 0 at the beginning        
	mov  eax,[ebp+8]    ;1.parameter   ;rule
	shr eax,cl      
    jc res              ;jump if carry is set
    mov ax, 0           ;if carry is not set, move 0 to ax and return

    pop  ebp
    ret

res:
	mov ax,1     		;if carry is set, move 1 to ax and return
	pop  ebp
    ret
