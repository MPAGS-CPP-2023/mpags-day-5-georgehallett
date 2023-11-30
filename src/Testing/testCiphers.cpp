//! Unit Tests for MPAGSCipher CaesarCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "CipherMode.hpp"
#include "CipherType.hpp"
#include "CipherFactory.hpp"
#include "Cipher.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"
#include <string>


std::map<CipherType, std::string> plainText{
    {CipherType::Caesar, "APPLECRUMBLE"},
    {CipherType::Playfair, "APPLECRUMBLE"},
    {CipherType::Vigenere, "APPLECRUMBLE"}};

std::map<CipherType, std::string> cipherText{
    {CipherType::Caesar, "FUUQJHWZRGQJ"},
    {CipherType::Playfair, "KSQIKDPWOYQD"},
    {CipherType::Vigenere, "KTNVIABYKLPC"}};

bool testCipher(const Cipher& cipher, const CipherMode mode,
                const std::string& inputText, const std::string& outputText)
{
    // Apply the cipher to the input text based on the mode
    return cipher.applyCipher(inputText, mode) == outputText;
}

TEST_CASE("Cipher encryption", "[ciphers]") {
    // Create a CaesarCipher with a specific key
    CaesarCipher cc{5};
    PlayfairCipher pc{"KEY"};
    VigenereCipher vc{"KEY"};

    REQUIRE(testCipher(cc, CipherMode::Encrypt, plainText[CipherType::Caesar],
    cipherText[CipherType::Caesar]));

    REQUIRE(testCipher(cc, CipherMode::Encrypt, plainText[CipherType::Playfair],
    cipherText[CipherType::Playfair]));

    REQUIRE(testCipher(cc, CipherMode::Encrypt, plainText[CipherType::Vigenere],
    cipherText[CipherType::Vigenere]));


}