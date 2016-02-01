#pragma once

/**
 * This is an internal header for gop. It does not contain any classes or functions intended for clients.
 * It exists purely as an implementation detail, and may change at any time without notice.
 */

#include <fc/reflect/reflect.hpp>

const static uint32_t PROTOCOL_VERSION = 0;

namespace goopal { namespace net { namespace detail {
    enum ChainServerCommands {
        finish = 0,
        get_blocks_from_number
    };
} } } //namespace goopal::net::detail

FC_REFLECT_ENUM(goopal::net::detail::ChainServerCommands, (finish)(get_blocks_from_number))
FC_REFLECT_TYPENAME(goopal::net::detail::ChainServerCommands)
