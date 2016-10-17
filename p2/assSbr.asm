;System Programming PROJECT1
;150110125 Ekrem Cihad Cetin
;150110132 Kutay Hekimoglu
;150120061 Metahan Gultekin

segment .text
global assSbr

assSbr:
    push ebp
    mov  ebp,esp

    mov  ecx,0			;firstly total equals 0
calc:
	mov  eax,[ebp+12]  	;adress of dir array starting
	mov  edx,[eax]  	;1. element of dir array
	mov eax,16			;multiply by 2^4
	mul edx				;new eax
	add ecx,eax			;total
	
	mov  eax,[ebp+12]  	;adress of dir array starting
	mov  edx,[eax+4]  	;2. element of dir array
	mov eax,8			;multiply by 2^3
	mul edx             ;new eax
	add ecx,eax			;total
	
	mov  eax,[ebp+12]  	;adress of dir array starting
	mov  edx,[eax+8]  	;3. element of dir array
	mov eax,4			;multiply by 2^2
	mul edx				;new eax
	add ecx,eax			;total
	
	mov  eax,[ebp+12]  	;adress of dir array starting
	mov  edx,[eax+12]  	;4. element of dir array
	mov eax,2			;multiply by 2^1
	mul edx				;new eax
	add ecx,eax			;total
	
	mov  eax,[ebp+12]  	;adress of dir array starting
	mov  edx,[eax+16]  	;5. element of dir array
	mov eax,1			;multiply by 2^0
	mul edx				;new eax
	add ecx,eax			;total
	
	mov eax,[ebp+8]       ;rule array starting point
	mov eax, [eax+ecx*4]   ;pointed number will be returned
	
    pop  ebp
    ret

