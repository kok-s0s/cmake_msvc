#include <iostream>
#include "cipher.h"

int main()
{
  Cipher *cipher = new Cipher();
  std::cout << cipher->xorEncrypt("kok-s0s", 11) << std::endl;
  std::cout << cipher->xorDecrypt(cipher->xorEncrypt("kok-s0s", 11), 11) << std::endl;

  std::cout << cipher->caesarEncrypt("SUJIABIN", 11) << std::endl;
  std::cout << cipher->caesarDecrypt(cipher->caesarEncrypt("SUJIABIN", 11), 11) << std::endl;

  // Test 1
  std::string text1 = "01234567890";
  std::string encrypted1 = cipher->morseCodeEncrypt(text1);
  std::string decrypted1 = cipher->morseCodeDecrypt(encrypted1);
  assert(text1 == decrypted1);
  std::cout << "Original text : " << text1 << std::endl;
  std::cout << "Encrypted text : " << encrypted1 << std::endl;
  std::cout << "Decrypted text : " << decrypted1 << std::endl;
  // Test 2
  std::string text2 = "abcdefghijklmnopqrstuvwxyz";
  std::string encrypted2 = cipher->morseCodeEncrypt(text2);
  std::string decrypted2 = cipher->morseCodeDecrypt(encrypted2);
  assert(text2 == decrypted2);
  std::cout << "Original text : " << text2 << std::endl;
  std::cout << "Encrypted text : " << encrypted2 << std::endl;
  std::cout << "Decrypted text : " << decrypted2 << std::endl;

  return 0;
}