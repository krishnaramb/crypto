#include <iostream>
#include <string>
using namespace std;
// https://www.sanfoundry.com/cpp-program-implement-vigenere-cypher/
class Vigenere{
  private:
  string key;

public:
  Vigenere(string key){
    for (int i = 0; i< key.length(); ++i){
      if (key[i] >= 'A' && key[i] <='Z')
        this->key += key[i];
      else if(key[i] >= 'a' && key[i] <= 'z')
        this->key += key[i]- ('a' -'A');
    }
  }

 string encrypt(string text)
 {
   string out;
   char c;
   for (int i = 0, j = 0; i < text.length(); i++)
   {
     c = text[i];
     if (c >= 'a' && c <= 'z')
     {
       c += 'A' - 'a';
     }
     else if (c < 'A' || c > 'Z')
      continue;

    out += (c - 'A' + key[j] - 'A') % 26 + 'A';
    j = (j + 1) % key.length();
   }
   return out;
 }


  string decrypt(string text)
  {
    string out;
    char c;
    for(int i = 0, j= 0; i < text.length(); ++i)
    {
      c = text[i];
      if (c >= 'a' && c <= 'z')
      {
        c += 'A' - 'a';
      }
      else if (c < 'A' || c > 'Z')
       continue;

       out += (c -'A' -(key[j]- 'A') + 26) % 26 +'A';
       // out += (c - key[j] + 26) % 26 + 'A';
       j = (j + 1) % key.length();
    }
    return out;
  }

};

int main()
{
    Vigenere cipher("spy");

    string original =
            "seeyouatnoon";
    string encrypted = cipher.encrypt(original);
    string decrypted = cipher.decrypt(encrypted);

    cout << original << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;
    return 0;
}
