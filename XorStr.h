#ifndef XORSTR_H
#define XORSTR_H

#include <Windows.h>

#define XORSTR_INLINE	__forceinline
#define XORSTR_NOINLINE __declspec( noinline )
#define XORSTR_CONST	constexpr

#define XORSTR_CONST_INLINE \
XORSTR_INLINE XORSTR_CONST 

#define XORSTR_CONST_NOINLINE \
XORSTR_NOINLINE XORSTR_CONST

#define XORSTR_FNV_OFFSET_BASIS 0xCBF29CE484222325
#define XORSTR_FNV_PRIME 0x100000001B3

#define XORSTR_MAKE_INTEGER_SEQUENCE( _LEN_ ) \
__make_integer_seq< XORSTR_INT_SEQ, SIZE_T, _LEN_ >( )

#define XORSTR_INTEGER_SEQUENCE( _INDICES_ ) \
XORSTR_INT_SEQ< SIZE_T, _INDICES_... >

template< typename _Ty, _Ty... Types >
struct XORSTR_INT_SEQ 
{ 
};

XORSTR_CONST_NOINLINE
INT XORSTR_ATOI8( 
	IN CHAR Character 
	) noexcept
{
	return ( Character >= '0' && Character <= '9' ) ?
		( Character - '0' ) : NULL;
}

XORSTR_CONST_NOINLINE
UINT64 XORSTR_KEY( 
	VOID 
	) noexcept
{
	UINT64 KeyHash = XORSTR_FNV_OFFSET_BASIS;

	for ( SIZE_T i = NULL; i < sizeof( __TIME__ ); i++ ) {
		KeyHash = KeyHash ^ XORSTR_ATOI8( __TIME__[ i ] );
		KeyHash = KeyHash * XORSTR_FNV_PRIME;
	}

	return KeyHash;
}

template< SIZE_T _STR_LENGTH_ >
class XORSTR_8
{
public:
	XORSTR_CONST_INLINE XORSTR_8( 
		IN CHAR CONST( &String )[ _STR_LENGTH_ ] 
		) : XORSTR_8( String, XORSTR_MAKE_INTEGER_SEQUENCE( _STR_LENGTH_ ) )
	{

	}

	XORSTR_INLINE 
	LPCSTR String( 
		VOID 
		)
	{
		DECRYPT_DATA( );

		return ( LPCSTR )( StringData );
	}

private:

	static XORSTR_CONST UINT64 Key = XORSTR_KEY( );

	static XORSTR_CONST_INLINE
	CHAR CRYPT_CHAR(
		IN CHAR Character, 
		IN SIZE_T KeyIndex 
		) noexcept
	{
		return ( Character ^ ( ( Key + KeyIndex ) ^ ( Key >> ( ( KeyIndex % 16 ) * 4 ) ) ) );
	}

	XORSTR_INLINE
	VOID DECRYPT_DATA( 
		VOID 
		) 
	{
		for ( SIZE_T i = NULL; i < _STR_LENGTH_; i++ ) {
			StringData[ i ] = CRYPT_CHAR( StringData[ i ], i );
		}
	}

	template< SIZE_T... _INDEX_ >
	XORSTR_CONST_INLINE XORSTR_8(
		IN CHAR CONST( &String )[ _STR_LENGTH_ ],
		IN XORSTR_INTEGER_SEQUENCE( _INDEX_ ) Index
		) : StringData{ CRYPT_CHAR( String[ _INDEX_ ], _INDEX_ )... }
	{

	}

	CHAR StringData[ _STR_LENGTH_ ];
};

template< SIZE_T _STR_LENGTH_ >
class XORSTR_16
{
public:
	XORSTR_CONST_INLINE XORSTR_16( 
		IN WCHAR CONST( &String )[ _STR_LENGTH_ ]
		) : XORSTR_16( String, XORSTR_MAKE_INTEGER_SEQUENCE( _STR_LENGTH_ ) )
	{

	}

	LPCWSTR String( 
		VOID 
		)
	{
		DECRYPT_DATA( );

		return ( LPCWSTR )( StringData );
	}

private:

	static XORSTR_CONST UINT64 Key = XORSTR_KEY( );

	static XORSTR_CONST_INLINE
	WCHAR CRYPT_CHAR( 
		IN WCHAR Character, 
		IN SIZE_T KeyIndex 
		) noexcept
	{
		return ( Character ^ ( ( Key + KeyIndex ) ^ ( Key >> ( ( KeyIndex % 16 ) * 4 ) ) ) );
	}

	XORSTR_INLINE
	VOID DECRYPT_DATA( 
		VOID 
		) 
	{
		for ( SIZE_T i = NULL; i < _STR_LENGTH_; i++ ) {
			StringData[ i ] = CRYPT_CHAR( StringData[ i ], i );
		}
	}

	template< SIZE_T... _INDEX_ >
	XORSTR_CONST_INLINE XORSTR_16( 
		IN WCHAR CONST( &String )[ _STR_LENGTH_ ], 
		IN XORSTR_INTEGER_SEQUENCE( _INDEX_ ) Index 
		) : StringData{ CRYPT_CHAR( String[ _INDEX_ ], _INDEX_ )... }
	{

	}

	WCHAR StringData[ _STR_LENGTH_ ];
};

template< SIZE_T _STR_LEN_ >
XORSTR_CONST_INLINE
XORSTR_8< _STR_LEN_ > XorStr( 
	IN CHAR CONST( &String )[ _STR_LEN_ ] 
	)
{
	return XORSTR_8< _STR_LEN_ >( String );
}

template< SIZE_T _STR_LEN_ >
XORSTR_CONST_INLINE
XORSTR_16< _STR_LEN_ > XorStr( 
	IN WCHAR CONST ( &String )[ _STR_LEN_ ] 
	)
{
	return XORSTR_16< _STR_LEN_ >( String );
}

#define _XOR_( _STR_ ) XorStr( _STR_ ).String( )

#endif