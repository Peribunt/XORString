# XORString
Easy to include string and wstring obfuscation

# Usage Example
```cpp
LONG main( 
  VOID 
  )
{
  printf( _XOR_( "Hello World" ) );
  printf( _XOR_( "%ws" ), _XOR_( L"Hello World" ) );
}
```

# Assembly Output
```asm
.text:0000000140001090                 mov     [rsp-8+arg_8], rbx
.text:0000000140001095                 mov     [rsp-8+arg_10], rdi
.text:000000014000109A                 push    rbp
.text:000000014000109B                 mov     rbp, rsp
.text:000000014000109E                 sub     rsp, 40h
.text:00000001400010A2                 xor     ebx, ebx
.text:00000001400010A4                 mov     dword ptr [rbp+_Format], 6BAF1048h
.text:00000001400010AB                 mov     r8d, ebx
.text:00000001400010AE                 mov     [rbp+var_1C], 0F142F965h
.text:00000001400010B5                 mov     [rbp+var_18], 805A49F5h
.text:00000001400010BC                 mov     rdi, 0BB3C01BA2E33F435h
.text:00000001400010C6                 db      66h, 66h
.text:00000001400010C6                 nop     word ptr [rax+rax+00000000h]
.text:00000001400010D0
.text:00000001400010D0 loc_1400010D0:                          ; CODE XREF: main+62↓j
.text:00000001400010D0                 movzx   ecx, r8b
.text:00000001400010D4                 lea     eax, [r8+35h]
.text:00000001400010D8                 and     cl, 0Fh
.text:00000001400010DB                 mov     rdx, rdi
.text:00000001400010DE                 shl     cl, 2
.text:00000001400010E1                 shr     rdx, cl
.text:00000001400010E4                 xor     dl, al
.text:00000001400010E6                 xor     [rbp+r8+_Format], dl
.text:00000001400010EB                 inc     r8
.text:00000001400010EE                 cmp     r8, 0Ch
.text:00000001400010F2                 jb      short loc_1400010D0
.text:00000001400010F4                 lea     rcx, [rbp+_Format] ; _Format
.text:00000001400010F8                 call    printf
.text:00000001400010FD                 mov     r8, rbx
.text:0000000140001100                 mov     dword ptr [rbp+_Format], 0CB100048h
.text:0000000140001107                 mov     r9d, 0BCBh
.text:000000014000110D                 mov     [rbp+var_1C], 176BC7AFh
.text:0000000140001114                 mov     [rbp+var_18], 56F9DA65h
.text:000000014000111B                 mov     [rbp+var_14], 0EFF14E42h
.text:0000000140001122                 mov     [rbp+var_10], 3449F5F5h
.text:0000000140001129                 mov     [rbp+var_C], 4780C85Ah
.text:0000000140001130
.text:0000000140001130 loc_140001130:                          ; CODE XREF: main+C8↓j
.text:0000000140001130                 movzx   ecx, r8b
.text:0000000140001134                 movzx   eax, r8w
.text:0000000140001138                 and     cl, 0Fh
.text:000000014000113B                 sub     ax, r9w
.text:000000014000113F                 shl     cl, 2
.text:0000000140001142                 mov     rdx, rdi
.text:0000000140001145                 shr     rdx, cl
.text:0000000140001148                 xor     dx, ax
.text:000000014000114B                 xor     word ptr [rbp+r8*2+_Format], dx
.text:0000000140001151                 inc     r8
.text:0000000140001154                 cmp     r8, 0Ch
.text:0000000140001158                 jb      short loc_140001130
.text:000000014000115A                 mov     [rbp+arg_0], 7B00225h
.text:0000000140001161
.text:0000000140001161 loc_140001161:                          ; CODE XREF: main+F0↓j
.text:0000000140001161                 movzx   ecx, bl
.text:0000000140001164                 lea     eax, [rbx+35h]
.text:0000000140001167                 and     cl, 0Fh
.text:000000014000116A                 mov     rdx, rdi
.text:000000014000116D                 shl     cl, 2
.text:0000000140001170                 shr     rdx, cl
.text:0000000140001173                 xor     dl, al
.text:0000000140001175                 xor     byte ptr [rbp+rbx+arg_0], dl
.text:0000000140001179                 inc     rbx
.text:000000014000117C                 cmp     rbx, 4
.text:0000000140001180                 jb      short loc_140001161
.text:0000000140001182                 lea     rdx, [rbp+_Format]
.text:0000000140001186                 lea     rcx, [rbp+arg_0] ; _Format
.text:000000014000118A                 call    printf
.text:000000014000118F                 mov     rbx, [rsp+40h+arg_8]
.text:0000000140001194                 xor     eax, eax
.text:0000000140001196                 mov     rdi, [rsp+40h+arg_10]
.text:000000014000119B                 add     rsp, 40h
.text:000000014000119F                 pop     rbp
.text:00000001400011A0                 retn
```
