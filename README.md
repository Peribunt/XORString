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
