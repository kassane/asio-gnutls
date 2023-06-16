//
// rfc2818_verification.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~
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
#include <asio/gnutls/rfc2818_verification.hpp>

#include "../unit_test.hpp"

ASIO_TEST_SUITE("gnutls/rfc2818_verification", ASIO_TEST_CASE(null_test))
