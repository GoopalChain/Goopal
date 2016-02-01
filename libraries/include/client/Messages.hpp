#pragma once
#include <blockchain/Block.hpp>
#include <client/Client.hpp>

namespace goopal { namespace client {

   enum MessageTypeEnum
   {
      trx_message_type          = 1000,
      block_message_type        = 1001
   };

   struct TrxMessage
   {
      static const MessageTypeEnum type;

      goopal::blockchain::SignedTransaction trx;
      TrxMessage() {}
      TrxMessage(goopal::blockchain::SignedTransaction transaction) :
        trx(std::move(transaction))
      {}
   };

   struct BlockMessage
   {
      static const MessageTypeEnum type;

      BlockMessage(){}
      BlockMessage(const goopal::blockchain::FullBlock& blk )
      :block(blk),block_id(blk.id()){}

      goopal::blockchain::FullBlock    block;
      goopal::blockchain::BlockIdType block_id;

   };

} } // goopal::client

FC_REFLECT_ENUM( goopal::client::MessageTypeEnum, (trx_message_type)(block_message_type) )
FC_REFLECT( goopal::client::TrxMessage, (trx) )
FC_REFLECT( goopal::client::BlockMessage, (block)(block_id) )
