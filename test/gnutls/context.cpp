//
// context.cpp
// ~~~~~~~~~~~
//
// Copyright (c) 2020 Paul-Louis Ageneau (paul-louis at ageneau dot org)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

// Disable autolinking for unit tests.
#if !defined(ALL_NO_LIB)
#define ALL_NO_LIB 1
#endif // !defined(ALL_NO_LIB)

// Test that header file is self-contained.
#include <asio/gnutls/context.hpp>

#include "../unit_test.hpp"

//------------------------------------------------------------------------------

// gnutls_context_compile test
// ~~~~~~~~~~~~~~~~~~~~~~~
// The following test checks that all public member functions on the class
// gnutls::context compile and link correctly. Runtime failures are ignored.

namespace gnutls_context_compile {

bool verify_callback(bool, asio::gnutls::verify_context&) { return false; }

bool server_name_callback(asio::gnutls::stream_base& s, std::string name) { return false; }

void test()
{
    using namespace asio;

    try
    {
        asio::gnutls::context context(asio::gnutls::context::tls);
        std::error_code ec;

        context.set_verify_mode(gnutls::context::verify_none);
        context.set_verify_mode(gnutls::context::verify_none, ec);

        context.set_verify_depth(1);
        context.set_verify_depth(1, ec);

        context.set_verify_callback(verify_callback);
        context.set_verify_callback(verify_callback, ec);

        // SNI extension

        context.set_server_name_callback(server_name_callback);
        context.set_server_name_callback(server_name_callback, ec);
    }
    catch (std::exception&)
    {}
}

} // namespace gnutls_context_compile

//------------------------------------------------------------------------------

ASIO_TEST_SUITE("gnutls/context", ASIO_TEST_CASE(gnutls_context_compile::test))
