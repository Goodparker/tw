#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include "contact.h"
#include <vector>

enum class SortMode {
   BY_NAME = 1,
   BY_LASTNAME = 2,
   BY_PHONE = 3
};

class Contact_manager {
public:
   static std::vector<Contact> readContact();
   static void sortContact(std::vector<Contact>& data, SortMode mode);
   static void printContact(const std::vector<Contact>& data, SortMode mode);
};

#endif
