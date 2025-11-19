#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <cstdint>

struct Contact {
   std::wstring lastName;
   std::wstring firstName;
   std::wstring phoneStr;
   std::int64_t phoneNum = 0;
};

std::wstring trim(const std::wstring& s);

#endif
