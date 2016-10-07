
segment .text
global assSbr

assSbr:
    push ebp
    mov  ebp,esp

    mov  ecx,0			;firstly total equals 0
calc:
	mov  ebx,[ebp+12]  	;2. parameter
	mov eax,16			;multiply by 2^4
	mul ebx				;new eax
	add ecx,eax			;total
	
	mov  ebx,[ebp+16]   ;3.parameter
	mov eax,8			;multiply by 2^3
	mul ebx             ;new eax
	add ecx,eax			;total
	
	mov  ebx,[ebp+20]   ;4.parameter
	mov eax,4			;multiply by 2^2
	mul ebx				;new eax
	add ecx,eax			;total
	
	mov  ebx,[ebp+24]   ;5.parameter
	mov eax,2			;multiply by 2^1
	mul ebx				;new eax
	add ecx,eax			;total
	
	mov  ebx,[ebp+28]   ;6.parameter
	mov eax,1			;multiply by 2^0
	mul ebx				;new eax
	add ecx,eax			;total
	
	mov eax,[ebp+8]
	mov eax, [eax+ecx*4]
	
    pop  ebp
    ret

