#include <iostream>
#include <string>

struct Contact {
  std::string name;
  std::string phone;
};

void showMenu();
// Contact is struct structing new contacts array and &count is count passed by reference so that the changes affect in real.
void addContact(Contact contacts[], int &count); // to add new contact
// for listing all the contacts parameters are same but here count is passed by value which will change in the function but will not affect in the real code
void listContacts(Contact contacts[], int count);
void deleteContact(Contact contacts[], int &count);
void searchContact(Contact contacts[], int count);

int main() {
  // building a structure of contacts with 100 contacts in it
  Contact contacts[100]; // can store up to 100 contacts
  int count = 0;
  int choice;

  do {
    showMenu(); // Display menu (like : 1> Add, 2> Show, 3> Exit)
    std::cin >> choice; // Takes user input

    switch (choice) {
      case 1:
        addContact(contacts, count);
        break;
      case 2:
        listContacts(contacts, count);
        break;
      case 3:
        deleteContact(contacts, count);
        break;
      case 4:
        searchContact(contacts, count);
        break;
      case 5:
        std::cout << "Goodbye!\n";
        break;
      default:
        std::cout << "Invalid choice.\n";
    }
  } while (choice != 4);

  return 0;
}

void showMenu() {
  std::cout << "\n======= Contact Book Menu =======\n";
  std::cout << "1. Add Contact\n";
  std::cout << "2. View Contacts\n";
  std::cout << "3. Delete Contacts\n";
  std::cout << "4. Search\n";
  std::cout << "5. Exit\n";

  std::cout << "Enter your choice (1-4): ";
}

void addContact(Contact contacts[], int &count) {
  std::cout << "Enter name: ";
  std::cin.ignore(); // clear leftover newline character
  std::getline(std::cin, contacts[count].name); // Read full name with spaces

  std::cout << "Enter phone number: ";
  std::getline(std::cin, contacts[count].phone); // Read full phone number

  count++; // Increase the total number of Contacts
  std::cout << "Contact added successfully!\n";
}

void listContacts(Contact contacts[], int count) {
  if (count == 0) {
    std::cout << "No contacts found.\n";
    return;
  }

  std::cout << "\nYour Contacts:\n";
  for (int i = 0; i < count; ++i) {
    std::cout << i + 1 << ". Name: " << contacts[i].name
              << ", Phone: " << contacts[i].phone << "\n";
  }
}

void deleteContact(Contact contacts[], int &count) {
  if (count == 0) {
    std::cout << "No contacts to delete.\n";
    return;
  }

  listContacts(contacts, count); // show current contacts

  int delIndex;
  std::cout << "Enter the contact number to delete (1 to " << count << "): ";
  std::cin >> delIndex;

  if (delIndex < 1 || delIndex > count) {
    std::cout << "Invalid contact number.\n";
    return;
  }

  // Convert to 0-based index
  delIndex--;

  // Shift remaining contacts left
  for (int i = delIndex; i < count - 1; ++i) {
    contacts[i] = contacts[i + 1];
  }

  count--; // One less contact now
  std::cout << "Contact deleted successfully.\n";
}

void searchContact(Contact contacts[], int count) {
  std::string searchItem;

  // Ignore leftover newline from prev input to prevent getline from skipping
  std::cin.ignore();

  // Prompt the user for the name they want to search
  std::cout << "Enter name to search: ";

  // Read the full line of input (to support names with spaces)
  std::getline(std::cin, searchItem);

  // Flag to track whether any matching contact was found
  bool found = false;

  // Loop through all contacts
  for (int i = 0; i < count; i++) {
    // Check if the search term is part of the contact's name
    if (contacts[i].name.find(searchItem) != std::string::npos) {
      // if a match is found, display the contact's details
      std::cout << "Name: "<< contacts[i].name << ", Phone: " << contacts[i].phone <<"\n";

      // Set found to true so we know at least one match occured
      found = true;
    }
  }

  // If no contact matched the search term
  if (!found) {
    std::cout << "No contact found with that name.\n";
  }

}

void sortContacts(Contact contacts[], int count) {
  // Bubble sort to arrange contacts alphabetically by name
  for (int i = 0; i < count - 1; ++i) {
    for (int j = 0; j < count - i - 1; ++j) {
      // Compare names using the > operator (lexicographical order)
      if (contacts[j].name > contacts[j + 1].name) {
        // Swap the two contacts if out of order
        Contact temp = contacts[j];
        contacts[j] = contacts[j + 1];
        contacts[j + 1] = temp;
      }
    }
  }

  std::cout << "Contacts sorted alphabetically by name.\n";
}
