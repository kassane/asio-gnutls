//
// gnutls/error.hpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2020 Paul-Louis Ageneau (paul-louis at ageneau dot org)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef ASIO_GNUTLS_ERROR_HPP
#define ASIO_GNUTLS_ERROR_HPP

#include <asio.hpp>
#include <system_error>

#include <gnutls/gnutls.h>

#include <string>


namespace asio {
namespace gnutls {

class error_category : public std::error_category
{
public:
    char const* name() const ASIO_ERROR_CATEGORY_NOEXCEPT { return "GnuTLS"; }

    std::string message(int value) const
    {
        char const* s = gnutls_strerror(value);
        return s ? s : "GnuTLS error";
    }
};

namespace error {

enum stream_errors
{
  stream_truncated = 1,
  unspecified_system_error = 2,
  unexpected_result = 3
};

static const std::error_category& get_ssl_category()
{
    static error_category instance;
    return instance;
}

static const std::error_category& get_stream_category() { return get_ssl_category(); }

static const auto& ssl_category ASIO_UNUSED_VARIABLE = get_ssl_category();
static const auto& stream_category ASIO_UNUSED_VARIABLE = get_stream_category();

} // namespace error
} // namespace gnutls
} // namespace asio



namespace system {

template<> struct is_error_code_enum<asio::gnutls::error::stream_errors>
{
  static const bool value = true;
};

} // namespace system



namespace asio {
namespace gnutls {
namespace error {
inline std::error_code make_error_code(stream_errors e)
{
  return std::error_code(
      static_cast<int>(e), get_stream_category());
}

} // namespace error
} // namespace gnutls
} // namespace asio


#endif
