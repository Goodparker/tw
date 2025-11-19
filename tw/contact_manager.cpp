#include "contact_manager.h"
#include "contact.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <limits>
#include <cstdint>

#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#undef max
#endif

static std::int64_t phoneToInt(const std::wstring& text) {
   std::wstring digits;
   for (wchar_t c : text)
      if (c >= L'0' && c <= L'9')
         digits.push_back(c);

   if (digits.empty()) return 0;

   try {
      return std::stoll(digits);
   } catch (...) {
      return std::numeric_limits<std::int64_t>::max();
   }
}

std::vector<Contact> Contact_manager::readContact() {
   std::vector<Contact> data;
   std::wstring line;

   std::wcout << L"Enter records (blank line - end):\n";

   while (true) {
      std::getline(std::wcin, line);
      if (line.empty()) break;

      size_t pos = line.find(L':');
      if (pos == std::wstring::npos) continue;

      std::wstring left  = trim(line.substr(0, pos));
      std::wstring right = trim(line.substr(pos + 1));

      std::wstringstream ss(left);

      Contact r;
      ss >> r.lastName >> r.firstName;

      r.phoneStr = right;
      r.phoneNum = phoneToInt(right);

      data.push_back(r);
   }

   return data;
}

void Contact_manager::sortContact(std::vector<Contact>& data, SortMode mode) {

   switch (mode) {

   case SortMode::BY_NAME:
      std::stable_sort(data.begin(), data.end(),
         [](const Contact& a, const Contact& b) {
            return a.firstName < b.firstName;
         });
      break;

   case SortMode::BY_LASTNAME:
      std::stable_sort(data.begin(), data.end(),
         [](const Contact& a, const Contact& b) {
            return a.lastName < b.lastName;
         });
      break;

   case SortMode::BY_PHONE:
      std::stable_sort(data.begin(), data.end(),
         [](const Contact& a, const Contact& b) {
            return a.phoneNum < b.phoneNum;
         });
      break;
   }
}

void Contact_manager::printContact(const std::vector<Contact>& data, SortMode mode) {

   for (const auto& r : data) {
      if (mode == SortMode::BY_PHONE)
         std::wcout << r.phoneStr << L": " << r.lastName << L" " << r.firstName << L"\n";
      else if (mode == SortMode::BY_LASTNAME)
         std::wcout << r.lastName << L" " << r.firstName << L": " << r.phoneStr << L"\n";
      else
         std::wcout << r.firstName << L" " << r.lastName << L": " << r.phoneStr << L"\n";
   }
}

