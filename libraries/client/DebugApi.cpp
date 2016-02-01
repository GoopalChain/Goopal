#include <blockchain/Time.hpp>
#include <client/Client.hpp>
#include <client/ClientImpl.hpp>
#include <utilities/KeyConversion.hpp>
#include <wallet/Wallet.hpp>

#ifndef WIN32
#include <csignal>
#endif

namespace goopal { namespace client { namespace detail {

std::string ClientImpl::debug_get_client_name() const
{
   return this->_config.client_debug_name;
}

} } } // namespace goopal::client::detail
