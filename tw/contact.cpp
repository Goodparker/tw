#include "contact.h"

std::wstring trim(const std::wstring& s) {
   const wchar_t* ws = L" \t\n\r";
   size_t start = s.find_first_not_of(ws);
   if (start == std::wstring::npos) return L"";
   size_t end = s.find_last_not_of(ws);
   return s.substr(start, end - start + 1);
}
