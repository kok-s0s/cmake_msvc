#include "cipher.h"

Cipher::Cipher()
{
}

Cipher::~Cipher()
{
}

std::string Cipher::xorEncrypt(const std::string &text, const int &key)
{
  std::string encrypted_text = "";
  for (auto &c : text)
  {
    char encrypted_char = char(c ^ key);
    encrypted_text += encrypted_char;
  }
  return encrypted_text;
}

std::string Cipher::xorDecrypt(const std::string &text, const int &key)
{
  std::string decrypted_text = "";
  for (auto &c : text)
  {
    char decrypted_char = char(c ^ key);
    decrypted_text += decrypted_char;
  }
  return decrypted_text;
}

inline char Cipher::getChar(const int x)
{
  // By adding 65 we are scaling 0-25 to 65-90.
  // Which are in fact ASCII values of A-Z.
  return char(x + 65);
}

inline int Cipher::getValue(const char c)
{
  // A-Z have ASCII values in range 65-90.
  // Hence subtracting 65 will scale them to 0-25.
  return int(c - 65);
}

std::string Cipher::caesarEncrypt(const std::string &text, const int &shift)
{
  std::string encrypted_text = "";
  for (char c : text)
  {
    int place_value = getValue(c);
    place_value = (place_value + shift) % 26;
    char new_char = getChar(
        place_value);
    encrypted_text += new_char;
  }
  return encrypted_text;
}

std::string Cipher::caesarDecrypt(const std::string &text, const int &shift)
{
  std::string decrypted_text = "";
  for (char c : text)
  {
    int place_value = getValue(c);
    place_value = (place_value - shift) % 26;
    if (place_value < 0)
    {
      place_value = place_value + 26;
    }
    char new_char = getChar(place_value);

    decrypted_text += new_char;
  }
  return decrypted_text;
}

std::string Cipher::charToMorse(const char &c)
{
  // return corresponding morse code
  switch (c)
  {
  case 'a':
    return ".-";
  case 'b':
    return "-...";
  case 'c':
    return "-.-.";
  case 'd':
    return "-..";
  case 'e':
    return ".";
  case 'f':
    return "..-.";
  case 'g':
    return "--.";
  case 'h':
    return "....";
  case 'i':
    return "..";
  case 'j':
    return ".---";
  case 'k':
    return "-.-";
  case 'l':
    return ".-..";
  case 'm':
    return "--";
  case 'n':
    return "-.";
  case 'o':
    return "---";
  case 'p':
    return ".--.";
  case 'q':
    return "--.-";
  case 'r':
    return ".-.";
  case 's':
    return "...";
  case 't':
    return "-";
  case 'u':
    return "..-";
  case 'v':
    return "...-";
  case 'w':
    return ".--";
  case 'x':
    return "-..-";
  case 'y':
    return "-.--";
  case 'z':
    return "--..";
  case '1':
    return ".----";
  case '2':
    return "..---";
  case '3':
    return "...--";
  case '4':
    return "....-";
  case '5':
    return ".....";
  case '6':
    return "-....";
  case '7':
    return "--...";
  case '8':
    return "---..";
  case '9':
    return "----.";
  case '0':
    return "-----";
  default:
    std::cerr << "Found invalid character: " << c << ' ' << std::endl;
    std::exit(0);
  }
}

char Cipher::morseToChar(const std::string &s)
{
  // return corresponding character
  if (s == ".-")
  {
    return 'a';
  }
  else if (s == "-...")
  {
    return 'b';
  }
  else if (s == "-.-.")
  {
    return 'c';
  }
  else if (s == "-..")
  {
    return 'd';
  }
  else if (s == ".")
  {
    return 'e';
  }
  else if (s == "..-.")
  {
    return 'f';
  }
  else if (s == "--.")
  {
    return 'g';
  }
  else if (s == "....")
  {
    return 'h';
  }
  else if (s == "..")
  {
    return 'i';
  }
  else if (s == ".---")
  {
    return 'j';
  }
  else if (s == "-.-")
  {
    return 'k';
  }
  else if (s == ".-..")
  {
    return 'l';
  }
  else if (s == "--")
  {
    return 'm';
  }
  else if (s == "-.")
  {
    return 'n';
  }
  else if (s == "---")
  {
    return 'o';
  }
  else if (s == ".--.")
  {
    return 'p';
  }
  else if (s == "--.-")
  {
    return 'q';
  }
  else if (s == ".-.")
  {
    return 'r';
  }
  else if (s == "...")
  {
    return 's';
  }
  else if (s == "-")
  {
    return 't';
  }
  else if (s == "..-")
  {
    return 'u';
  }
  else if (s == "...-")
  {
    return 'v';
  }
  else if (s == ".--")
  {
    return 'w';
  }
  else if (s == "-..-")
  {
    return 'x';
  }
  else if (s == "-.--")
  {
    return 'y';
  }
  else if (s == "--..")
  {
    return 'z';
  }
  else if (s == ".----")
  {
    return '1';
  }
  else if (s == "..---")
  {
    return '2';
  }
  else if (s == "...--")
  {
    return '3';
  }
  else if (s == "....-")
  {
    return '4';
  }
  else if (s == ".....")
  {
    return '5';
  }
  else if (s == "-....")
  {
    return '6';
  }
  else if (s == "--...")
  {
    return '7';
  }
  else if (s == "---..")
  {
    return '8';
  }
  else if (s == "----.")
  {
    return '9';
  }
  else if (s == "-----")
  {
    return '0';
  }
  else
  {
    std::cerr << "Found invalid Morse code: " << s << ' ' << std::endl;
    std::exit(0);
  }
}

std::string Cipher::morseCodeEncrypt(const std::string &text)
{
  std::string encrypted_text = ""; // Empty string to store encrypted text
  // Going through each character of text and converting it
  // to morse representation
  for (const char &c : text)
  {
    encrypted_text += charToMorse(c) + " ";
  }
  return encrypted_text; // Returning encrypted text
}

std::string Cipher::morseCodeDecrypt(const std::string &text)
{
  // Going through each character of text and converting it
  // back to normal representation.
  std::string decrypted_text = ""; // Empty string to store decrypted text
  // Spliting string (with delimiter = " ") and storing it
  // in vector
  std::size_t pos_start = 0, pos_end = 0, delim_len = 1;
  std::vector<std::string> splits;
  while ((pos_end = text.find(' ', pos_start)) != std::string::npos)
  {
    std::string token = text.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    splits.push_back(token);
  }

  // Traversing through each morse code string
  for (const std::string &s : splits)
  {
    // Add corresponding character
    decrypted_text += morseToChar(s);
  }

  return decrypted_text; // Returning decrypted text
}