#include "contact_manager.h"
#include <iostream>

#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif

int main() {
#ifdef _WIN32
   _setmode(_fileno(stdout), _O_U16TEXT);
   _setmode(_fileno(stdin),  _O_U16TEXT);
#endif

   while (true) {
      std::wcout << L"\n1 – sort by name\n"
         L"2 – sort by last name\n"
         L"3 – sorting by phone numbers\n"
         L"0 - exit\n";

      int mode;
      if (!(std::wcin >> mode)) break;

      std::wstring dummy;
      std::getline(std::wcin, dummy);

      if (mode == 0) break;
      if (mode < 1 || mode > 3) {
         std::wcout << L"Error: No such mode.\n";
         continue;
      }

      auto list = Contact_manager::readContact();
      Contact_manager::sortContact(list, static_cast<SortMode>(mode));
      Contact_manager::printContact(list, static_cast<SortMode>(mode));
   }

   return 0;
}

