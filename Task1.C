#include<iostream>
#include<map>

using namespace std;

// Base64 Mapping
char CODES[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c',
  'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
  't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8',
  '9', '+', '/'
};

// Hex char map to string
map<char, int> HEX_MAP = {
  pair<char, int>('0', 0x0),
  pair<char, int>('1', 0x1),
  pair<char, int>('2', 0x2),
  pair<char, int>('3', 0x3),
  pair<char, int>('4', 0x4),
  pair<char, int>('5', 0x5),
  pair<char, int>('6', 0x6),
  pair<char, int>('7', 0x7),
  pair<char, int>('8', 0x8),
  pair<char, int>('9', 0x9),
  pair<char, int>('a', 0xa),
  pair<char, int>('b', 0xb),
  pair<char, int>('c', 0xc),
  pair<char, int>('d', 0xd),
  pair<char, int>('e', 0xe),
  pair<char, int>('f', 0xf),
  pair<char, int>('A', 0xa),
  pair<char, int>('B', 0xb),
  pair<char, int>('C', 0xc),
  pair<char, int>('D', 0xd),
  pair<char, int>('E', 0xe),
  pair<char, int>('F', 0xf)
};

// Given two chars of hex string converts into hex integer
int hex_integer(char a, char b) {
  return ((HEX_MAP[a] << 4) | (HEX_MAP[b]));
}

// Required function
string hex_to_base64(string hex) {
  int n = hex.length();
  int i = 0;
  string base64 = "";

  while (i < n) {
    // Extrating data from firt byte
    int sample1 = hex_integer(hex[i], hex[i + 1]);
    int first = (sample1 & 0xFC) >> 2;
    int second = (sample1 & 0x03) << 4;
    base64.append(1, CODES[first]);
    i += 2;
    if (i < n) {
      // Extrating data from second byte
      int sample2 = hex_integer(hex[i], hex[i + 1]);
      int third = (sample2 & 0xF0) >> 4;
      int fourth = (sample2 & 0x0F) << 2;

      base64.append(1, CODES[(second | third)]);

      i += 2;
      if (i < n) {
        // Extracting the third byte
        int sample3 = hex_integer(hex[i], hex[i + 1]);
        int fifth = (sample3 & 0xC0) >> 6;
        int sixth = (sample3 & 0x3F);

        base64.append(1, CODES[(fourth | fifth)]);
        base64.append(1, CODES[sixth]);
        i += 2;
      } else {
        base64 += CODES[fourth];
        base64.append("=");
      }
    } else {
      base64 += CODES[second];
      base64.append("==");
    }
  }

  return base64;
}

// Sample test input
int main() {
  string str = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
  cout << hex_to_base64(str) << endl;
}
