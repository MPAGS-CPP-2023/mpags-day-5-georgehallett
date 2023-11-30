#ifndef MPAGSCIPHER_VIGENERECIPHER_HPP
#define MPAGSCIPHER_VIGENERECIPHER_HPP

#include "CipherMode.hpp"
#include "CaesarCipher.hpp"
#include "Cipher.hpp"

#include <map>
#include <string>

class VigenereCipher: public Cipher{
    public:
        explicit VigenereCipher(const std::string& key);

        void setKey(const std::string& key);

        std::string applyCipher(const std::string& inputText,
                                const CipherMode cipherMode) const override;

      private:
        std::string key_ = "";

        std::map<char, CaesarCipher> charLookup_;
};

#endif