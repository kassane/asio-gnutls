# boost-asio-gnutls
GnuTLS wrapper for Boost.Asio

## Usage

Add `include` as include directory for your project, then include the header `asio/gnutls.hpp`.
Don't forget to link against GnuTLS instead of OpenSSL.

The two classes `context` and `stream` in `asio::gnutls` mimic the ones in `asio::ssl`.

## Test

From the boost root directory, run:
```
b2 [PATH_TO_THIS_REPOSITORY]/test/gnutls
```

