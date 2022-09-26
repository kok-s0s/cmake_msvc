#pragma once
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class _declspec(dllexport) Cipher
{
public:
  Cipher();
  ~Cipher();

public:
  /**
   * Encrypt given text using XOR cipher.
   * @param text text to be encrypted
   * @param key to be used for encyption
   * @return new encrypted text
   */
  std::string xorEncrypt(const std::string &text, const int &key);

  /**
   * Decrypt given text using XOR cipher.
   * @param text text to be encrypted
   * @param key to be used for decryption
   * @return new decrypted text
   */
  std::string xorDecrypt(const std::string &text, const int &key);

  /**
   * This function finds character for given value (i.e.A-Z)
   * @param x value for which we want character
   * @returns  corresponding character for perticular value
   */
  inline char getChar(const int x);

  /**
   * This function finds value for given character (i.e.0-25)
   * @param c character for which we want value
   * @returns returns corresponding value for perticular character
   */
  inline int getValue(const char c);

  /**
   * Encrypt given text using caesar cipher.
   * @param text text to be encrypted
   * @param shift number of shifts to be applied
   * @returns new encrypted text
   */
  std::string caesarEncrypt(const std::string &text, const int &shift);

  /**
   * Decrypt given text using caesar cipher.
   * @param text text to be decrypted
   * @param shift number of shifts to be applied
   * @returns new decrypted text
   */
  std::string caesarDecrypt(const std::string &text, const int &shift);

  /**
   * Get the morse representation for given character.
   * @param c Character
   * @returns morse representation string of character
   */
  std::string charToMorse(const char &c);

  /**
   * Get character from the morse representation.
   * @param s Morse representation
   * @returns corresponding character
   */
  char morseToChar(const std::string &s);

  /**
   * Encrypt given text using morse code.
   * @param text text to be encrypted
   * @returns new encrypted text
   */
  std::string morseCodeEncrypt(const std::string &text);

  /**
   * Decrypt given morse coded text.
   * @param text text to be decrypted
   * @returns new decrypted text
   */
  std::string morseCodeDecrypt(const std::string &text);
};
