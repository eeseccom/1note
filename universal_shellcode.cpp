#include "stdafx.h"

void main()
{
	__asm {
		jmp start

		get_func_addr:
		// name table index를 구함
	loop_ent:
		inc edx //index ++
		lodsd //eax = *esi, esi+=4
		pushad
		add ebs, eax
			mov esi, ebx
			xor eax, eax
			xor edi, edi

	hash :
		lodsb // eax = *esi, esi +=1
			add edi, eax // edi +=char
			test al, al
			jnz hash
			move [ebp+0x10], edi
			popad
			cmp [ebp+0x10], edi //함수 Hash 갑ㅁㅅ 비교
			jne loop_ent
			// get WinExed address
			movzx dex, word ptr [ecx+edx*2-2] //ordival
			mov edi, [ebp+0x18]
			mov edi, [ebp + 0x1c] //export address table
			mov esi, ebx
			add esi, edi
			add edi, [esi+edx*4]
			move eax, edi
			// edi=함수주소 리턴
			ret

	start:
		//cmd 문자열
		xor eax, eax
			mov [ebp+0xc], eax
			mov[ebp + 0xc], 0x63 //eax
			mov[ebp + 0xd], 0x6d //eax
			mov[ebp + 0xe], 0x64 //eax

			//kernal32.dll base address 구함
			mov eax, fs:[0x30] //PEB
			mov eax, [eax+0xc] // _PEB_LDR_DATA
			mov eax, [eax+0x14] // InMemoryOrderModuleList
			mov ebx, [eax] // ntdll.dll InMemoryOrderLinks
			mov ebx, [ebs] // kernal.dll ""
			mov ebx, [ebx+0x10] // ebx = kernel32.dll base address

			//export table
			mov edi, [ebx+0x3c] //PE header


	}
}