#include <iostream>

int main() {
	const int N = 20;
	int ma;
	int a[N]{8, 4, 6, 7, 5, 1, 9, 0, 5, 6, 3, 7, 9, 5, 0, 4, 0, 1 ,2, 3};
	// count yourself
	// 0 - 3, 1 - 2, 2 - 1, 3 - 2, 4 - 2, 5 - 3, 6 - 2, 7 - 2, 8 - 1, 9 - 2
	// max - 0, 5
	_asm {
		mov ecx, N
		// first element
		mov eax, a[ecx*4-4]
		mov ebx, 1
		dec ecx
		fi:
			cmp a[ecx*4-4], eax
			jne nig
			inc ebx
			nig:
		loop fi
		push eax
		push ebx
		mov ecx, N
		dec ecx
			cycle1:
		mov eax, a[ecx*4-4]
		mov ebx, 1
		push ecx
		dec ecx
			cycle2:
		cmp a[ecx * 4 - 4], eax
		jne ne2
		inc ebx
		ne2 :
			loop cycle2
		pop ecx
		cmp ebx, [esp]
		jb bo
		mov [esp], ebx
		mov [esp+4], eax
		bo:
			loop cycle1
		mov eax, [esp+4]
		mov ma, eax
	}
	std::cout << "Max meet is: " << ma << '\n';
}