#include "VigenereCipher.hpp"
#include "Alphabet.hpp"
#include "CipherMode.hpp"

#include <algorithm>
#include <iostream>

VigenereCipher::VigenereCipher ( const std::string& key )
{
    // Set the given key
    setKey(key);
}

void VigenereCipher::setKey(const std::string& key) {

    // Store the original key
    key_ = key;

    // Make sure the key is uppercase
    std::transform(std::begin(key_), std::end(key_), std::begin(key_), ::toupper);

    // Remove non-alphabet characters
    key_.erase(std::remove_if(std::begin(key_), std::end(key_), [](char c) { return !std::isalpha(c); }), std::end(key_));

    // Check if the key is empty and replace with default if so
    if (key_.empty()){
        key_ = "MYKEY";
    }
    // loop over the key
    for (char c : key_){

        // Find the letter position in the alphabet
        const size_t position = Alphabet::alphabet.find(c);

        // Create a CaesarCipher using this position as a key
        CaesarCipher caesarCipher(position);

        // Insert a std::pair of the letter and CaesarCipher into the lookup
        charLookup_.insert(std::make_pair(c, caesarCipher));
    }
}

std::string VigenereCipher::applyCipher(const std::string& inputText,
                                        const CipherMode cipherMode) const
{
    std::string outputText = "";

    // For each letter in input:
    for (char c : inputText){
        // Find the corresponding letter in the key, repeating/truncating as required
        char keyChar = key_[outputText.size() % key_.size()];

        // Find the Caesar cipher from the lookup
        auto iterator = charLookup_.find(keyChar);

         if (iterator != charLookup_.end())
        {
            // Run the (de)encryption
            std::string result = iterator->second.applyCipher(std::string(1, c), cipherMode);

            // Add the result to the output
            outputText += result;
        }
        else
        {
            // If the keyChar is not found in the lookup, append the inputChar unchanged
            outputText += c;
        }

    }
    return outputText;
}