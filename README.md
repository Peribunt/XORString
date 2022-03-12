# XORString
Easy to include string and wstring obfuscation

# Usage
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
.text:0000000140001095                 mov     [rsp-8+arg_10], rsi
.text:000000014000109A                 mov     [rsp-8+arg_18], rdi
.text:000000014000109F                 push    rbp
.text:00000001400010A0                 mov     rbp, rsp
.text:00000001400010A3                 sub     rsp, 50h
.text:00000001400010A7                 mov     [rbp+_Format], 88h ; 'ˆ'
.text:00000001400010AB                 xor     ebx, ebx
.text:00000001400010AD                 mov     [rbp+var_2F], 0A0h ; ' '
.text:00000001400010B1                 mov     rsi, 0A734021017465BC8h
.text:00000001400010BB                 mov     [rbp+var_2E], 0ADh ; '­'
.text:00000001400010BF                 mov     r11, rsi
.text:00000001400010C2                 mov     [rbp+var_2D], 0A2h ; '¢'
.text:00000001400010C6                 mov     r10d, ebx
.text:00000001400010C9                 mov     [rbp+var_2C], 0A5h ; '¥'
.text:00000001400010CD                 lea     edi, [rbx+0Fh]
.text:00000001400010D0                 mov     [rbp+var_2B], 0E9h ; 'é'
.text:00000001400010D4                 mov     [rbp+var_2A], 9Eh ; 'ž'
.text:00000001400010D8                 mov     [rbp+var_29], 0A1h ; '¡'
.text:00000001400010DC                 mov     [rbp+var_28], 0A2h ; '¢'
.text:00000001400010E0                 mov     [rbp+var_27], 0BCh ; '¼'
.text:00000001400010E4                 mov     [rbp+var_26], 0B4h ; '´'
.text:00000001400010E8                 mov     [rbp+var_25], 0D3h ; 'Ó'
.text:00000001400010EC                 movzx   eax, [rbp+_Format]
.text:00000001400010F0                 lea     rax, [rbp+_Format]
.text:00000001400010F4                 sub     r11, rax
.text:00000001400010F7                 nop     word ptr [rax+rax+00000000h]
.text:0000000140001100
.text:0000000140001100 loc_140001100:                          ; CODE XREF: main+A9↓j
.text:0000000140001100                 mov     rax, r10
.text:0000000140001103                 lea     r9, [rbp+_Format]
.text:0000000140001107                 add     r9, r10
.text:000000014000110A                 and     eax, edi
.text:000000014000110C                 cmp     rax, rdi
.text:000000014000110F                 mov     rdx, rsi
.text:0000000140001112                 cmovnb  rax, rdi
.text:0000000140001116                 inc     r10
.text:0000000140001119                 movzx   r8d, byte ptr [r9]
.text:000000014000111D                 shl     al, 2
.text:0000000140001120                 movzx   ecx, al
.text:0000000140001123                 lea     eax, [r11+r9]
.text:0000000140001127                 shr     rdx, cl
.text:000000014000112A                 and     dl, dil
.text:000000014000112D                 xor     dl, al
.text:000000014000112F                 xor     dl, r8b
.text:0000000140001132                 mov     [r9], dl
.text:0000000140001135                 cmp     r10, 0Ch
.text:0000000140001139                 jb      short loc_140001100
.text:000000014000113B                 lea     rcx, [rbp+_Format] ; _Format
.text:000000014000113F                 call    printf
.text:0000000140001144                 mov     ecx, 5BA2h
.text:0000000140001149                 mov     eax, 5B88h
.text:000000014000114E                 mov     [rbp+var_20], ax
.text:0000000140001152                 mov     r9, rbx
.text:0000000140001155                 mov     eax, 5BA0h
.text:000000014000115A                 mov     [rbp+var_1E], ax
.text:000000014000115E                 mov     eax, 5BADh
.text:0000000140001163                 mov     [rbp+var_1C], ax
.text:0000000140001167                 lea     r10d, [rcx+26h]
.text:000000014000116B                 mov     [rbp+var_1A], cx
.text:000000014000116F                 mov     eax, 5BA5h
.text:0000000140001174                 mov     [rbp+var_18], ax
.text:0000000140001178                 mov     eax, 5BE9h
.text:000000014000117D                 mov     [rbp+var_16], ax
.text:0000000140001181                 mov     eax, 5B9Eh
.text:0000000140001186                 mov     [rbp+var_14], ax
.text:000000014000118A                 mov     eax, 5BA1h
.text:000000014000118F                 mov     [rbp+var_12], ax
.text:0000000140001193                 mov     eax, 5BBCh
.text:0000000140001198                 mov     [rbp+var_10], cx
.text:000000014000119C                 mov     [rbp+var_E], ax
.text:00000001400011A0                 mov     eax, 5BB4h
.text:00000001400011A5                 mov     [rbp+var_C], ax
.text:00000001400011A9                 mov     eax, 5BD3h
.text:00000001400011AE                 mov     [rbp+var_A], ax
.text:00000001400011B2                 movzx   eax, [rbp+var_20]
.text:00000001400011B6                 db      66h, 66h
.text:00000001400011B6                 nop     word ptr [rax+rax+00000000h]
.text:00000001400011C0
.text:00000001400011C0 loc_1400011C0:                          ; CODE XREF: main+169↓j
.text:00000001400011C0                 movzx   r8d, [rbp+r9*2+var_20]
.text:00000001400011C6                 mov     rax, r9
.text:00000001400011C9                 and     eax, edi
.text:00000001400011CB                 mov     rdx, rsi
.text:00000001400011CE                 cmp     rax, rdi
.text:00000001400011D1                 cmovnb  rax, rdi
.text:00000001400011D5                 shl     al, 2
.text:00000001400011D8                 movzx   ecx, al
.text:00000001400011DB                 lea     eax, [r10+r9]
.text:00000001400011DF                 shr     rdx, cl
.text:00000001400011E2                 and     dx, di
.text:00000001400011E5                 xor     dx, ax
.text:00000001400011E8                 xor     dx, r8w
.text:00000001400011EC                 mov     [rbp+r9*2+var_20], dx
.text:00000001400011F2                 inc     r9
.text:00000001400011F5                 cmp     r9, 0Ch
.text:00000001400011F9                 jb      short loc_1400011C0
.text:00000001400011FB                 mov     [rbp+arg_0], 0B5h ; 'µ'
.text:00000001400011FF                 mov     r11, 0F26FFD4189B4CF98h
.text:0000000140001209                 mov     [rbp+arg_1], 0E7h ; 'ç'
.text:000000014000120D                 mov     r10, r11
.text:0000000140001210                 mov     [rbp+arg_2], 0E6h ; 'æ'
.text:0000000140001214                 mov     [rbp+arg_3], 97h ; '—'
.text:0000000140001218                 movzx   eax, [rbp+arg_0]
.text:000000014000121C                 lea     rax, [rbp+arg_0]
.text:0000000140001220                 sub     r10, rax
.text:0000000140001223                 nop     dword ptr [rax+00h]
.text:0000000140001227                 nop     word ptr [rax+rax+00000000h]
.text:0000000140001230
.text:0000000140001230 loc_140001230:                          ; CODE XREF: main+1D9↓j
.text:0000000140001230                 mov     rax, rbx
.text:0000000140001233                 lea     r9, [rbp+arg_0]
.text:0000000140001237                 add     r9, rbx
.text:000000014000123A                 and     eax, edi
.text:000000014000123C                 cmp     rax, rdi
.text:000000014000123F                 mov     rdx, r11
.text:0000000140001242                 cmovnb  rax, rdi
.text:0000000140001246                 inc     rbx
.text:0000000140001249                 movzx   r8d, byte ptr [r9]
.text:000000014000124D                 shl     al, 2
.text:0000000140001250                 movzx   ecx, al
.text:0000000140001253                 lea     eax, [r10+r9]
.text:0000000140001257                 shr     rdx, cl
.text:000000014000125A                 and     dl, dil
.text:000000014000125D                 xor     dl, al
.text:000000014000125F                 xor     dl, r8b
.text:0000000140001262                 mov     [r9], dl
.text:0000000140001265                 cmp     rbx, 4
.text:0000000140001269                 jb      short loc_140001230
.text:000000014000126B                 lea     rdx, [rbp+var_20]
.text:000000014000126F                 lea     rcx, [rbp+arg_0] ; _Format
.text:0000000140001273                 call    printf
.text:0000000140001278                 mov     rbx, [rsp+50h+arg_8]
.text:000000014000127D                 xor     eax, eax
.text:000000014000127F                 mov     rsi, [rsp+50h+arg_10]
.text:0000000140001284                 mov     rdi, [rsp+50h+arg_18]
.text:0000000140001289                 add     rsp, 50h
.text:000000014000128D                 pop     rbp
.text:000000014000128E                 retn
```
