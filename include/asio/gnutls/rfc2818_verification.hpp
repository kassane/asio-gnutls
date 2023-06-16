//
// gnutls/rfc2818_verification.hpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2020 Paul-Louis Ageneau (paul-louis at ageneau dot org)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef ASIO_GNUTLS_RFC2818_VERIFICATION_HPP
#define ASIO_GNUTLS_RFC2818_VERIFICATION_HPP

#include <asio/gnutls/host_name_verification.hpp>


namespace asio {
namespace gnutls {

// Verifies a certificate against a hostname according to the rules described in RFC 2818.
// Deprecated, use host_name_verification instead.
using rfc2818_verification = host_name_verification;

} // namespace gnutls
} // namespace asio


#endif // ASIO_GNUTLS_RFC2818_VERIFICATION_HPP
