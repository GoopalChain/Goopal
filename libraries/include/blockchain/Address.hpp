#pragma once

#include <blockchain/Config.hpp>
#include <blockchain/PtsAddress.hpp>

#include <fc/array.hpp>
#include <fc/crypto/ripemd160.hpp>

namespace fc { namespace ecc {
    class public_key;
    typedef fc::array<char,33>  public_key_data;
} } // fc::ecc

namespace goopal { namespace blockchain {

   struct WithdrawCondition;
   struct PublicKeyType;

   /**
    *  @brief a 160 bit hash of a public key
    *
    *  An address can be converted to or from a base58 string with 32 bit checksum.
    *
    *  An address is calculated as ripemd160( sha512( compressed_ecc_public_key ) )
    *
    *  When converted to a string, checksum calculated as the first 4 bytes ripemd160( address ) is
    *  appended to the binary address before converting to base58.
    */
   class Address
   {
      public:
       Address(); ///< constructs empty / null address
       explicit Address( const std::string& base58str );   ///< converts to binary, validates checksum
       Address( const fc::ecc::public_key& pub ); ///< converts to binary
       explicit Address( const fc::ecc::public_key_data& pub ); ///< converts to binary
       Address( const PtsAddress& pub ); ///< converts to binary
       Address( const WithdrawCondition& condition );
       Address( const PublicKeyType& pubkey );

       /**
       * Validate address
       *
       * @param base58str address string
       * @param to_account prefix of string
       * @return bool 
       */
       static bool is_valid( const std::string& base58str, const std::string& prefix = GOP_ADDRESS_PREFIX );

       explicit operator std::string()const; ///< converts to base58 + checksum

       fc::ripemd160 addr;
   };
   inline bool operator == ( const Address& a, const Address& b ) { return a.addr == b.addr; }
   inline bool operator != ( const Address& a, const Address& b ) { return a.addr != b.addr; }
   inline bool operator <  ( const Address& a, const Address& b ) { return a.addr <  b.addr; }

} } // namespace goopal::blockchain

namespace fc
{
   void to_variant( const goopal::blockchain::Address& var,  fc::variant& vo );
   void from_variant( const fc::variant& var,  goopal::blockchain::Address& vo );
}

namespace std
{
   template<>
   struct hash<goopal::blockchain::Address>
   {
       public:
         size_t operator()(const goopal::blockchain::Address &a) const
         {
            return (uint64_t(a.addr._hash[0])<<32) | uint64_t( a.addr._hash[0] );
         }
   };
}

#include <fc/reflect/reflect.hpp>
FC_REFLECT( goopal::blockchain::Address, (addr) )
