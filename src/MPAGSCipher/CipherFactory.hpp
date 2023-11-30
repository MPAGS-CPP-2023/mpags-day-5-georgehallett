#ifndef MPAGSCIPHER_CIPHERFACTORY_HPP
#define MPAGSCIPHER_CIPHERFACTORY_HPP

#include "CipherType.hpp"
#include "Cipher.hpp"

#include <memory>
#include <string>

namespace CipherFactory{

std::unique_ptr<Cipher> makeCipher(const CipherType type,
                                       const std::string& key);
}

#endif