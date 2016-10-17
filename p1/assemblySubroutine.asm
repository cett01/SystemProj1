;System Programming PROJECT1
;150110125 Ekrem Cihad Cetin
;150110132 Kutay Hekimoglu
;150120061 Metahan Gultekin

segment .text
global assemblySubroutine


assemblySubroutine:
    push ebp
    mov  ebp,esp

    mov  ecx,1			;firstly total equals 0
	

forLoop:
    mov eax, [ebp+12]	;
	mov ebx, 0			;Total value for each control
	
	mov edx,[eax + (ecx-1)*4]  	;left
	mov eax,4			;multiply by 2^2
	mul edx				;new eax
	add ebx,eax			;total
	
	mov eax, [ebp+12]	;Line

	mov edx,[eax + ecx*4]  	;center
	mov eax,2			;multiply by 2^1
	mul edx				;new eax
	add ebx,eax			;total
	
	mov eax, [ebp+12]	;Line

	mov edx,[eax + (ecx+1)*4]  	;right
	mov eax,1			;multiply by 2^0
	mul edx				;new eax
	add ebx,eax			;total
						;ebx holds how many shifts are needed
						
	mov edx, ecx		;In order to do shr, counting register should be used. Therefore we saved ecx first and then assign ebx to it.
	mov ecx, ebx
	mov ebx, edx

	inc cl       		;it should be shifted at least once that's why we incremented the cl by 1 since it was 0 at the beginning        
	mov eax,[ebp+8]     ;1.parameter   ;rule
	shr eax,cl      
    jc res              ;JUMP is used to be able to assign the result (0 and 1)
	
	mov eax, [ebp+16]	;The starting address of tempLine
	mov ecx, ebx		;The index of the line array is obtained again from the stored place
	mov ebx,0			; If the result is 0, the related index of tempLine is assigned 0
	mov [eax+ecx*4], ebx

	mov eax, [ebp+20]	;Length of the array
	dec eax

	inc ecx				;Next iteration of for loop
	cmp ecx, eax
	jne forLoop
	
	
	mov eax, [ebp+16]	;Return array

    pop  ebp
    ret

res:
	mov eax, [ebp+16]	;The starting address of tempLine
	mov ecx, ebx		;The index of the line array is obtained again from the stored place
	mov ebx,1			;If the result is 0, the related index of tempLine is assigned 0
	mov [eax+ecx*4], ebx

   	mov eax, [ebp+20]	;Length of the array
	dec eax

	inc ecx				;Next iteration of for loop
	cmp ecx, eax
	jne forLoop
	
	mov eax, [ebp+16]	;Return array

	
	pop  ebp
    ret
