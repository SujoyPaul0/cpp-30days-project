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
void sortContacts(Contact contacts[], int count);
void editContact(Contact contacts[], int count);

// convert strings to lowercase for comparison
std::string toLower(const std::string& str) {
  std::string lowerStr = str;
  for (char& ch: lowerStr) {
    ch = std::tolower(ch);
  }
  return lowerStr;
}

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
        sortContacts(contacts, count);
        break;
      case 6:
        editContact(contacts, count);
        break;
      case 7:
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
  std::cout << "5. Sort Contacts\n";
  std::cout << "6. Edit Contact\n";
  std::cout << "7. Exit\n";

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
      if (toLower(contacts[j].name) > toLower(contacts[j + 1].name)) {
        // Swap the two contacts if out of order
        Contact temp = contacts[j];
        contacts[j] = contacts[j + 1];
        contacts[j + 1] = temp;
      }
    }
  }

  std::cout << "Contacts sorted alphabetically by name.\n";
}


// Function to edit an existing contact
void editContact(Contact contacts[], int count) {
  // If there are no contacts, nothing to edit
  if (count == 0) {
    std::cout << "No contacts to edit.\n";
    return;
  }

  // Show the current list of contacts
  listContacts(contacts, count);

  int editIndex;
  // Prompt user to select which contact to edit
  std::cout << "Enter the contact number to edit (1 to " << count << "): ";
  std::cin >> editIndex;

  // Validate the input number
  if (editIndex < 1 || editIndex > count) {
    std::cout << "Invalid contact number.\n";
    return;
  }

  // Clear leftover newline character from the input buffer
  std::cin.ignore();

  // Convert to 0-based index for internal array access
  editIndex--;

  // Ask for a new name, showing the current name as a hint
  std::cout << "Enter new name (leave blank to keep \"" << contacts[editIndex].name << "\"): ";
  std::string newName;
  std::getline(std::cin, newName);  // Read full line (including spaces)

  // Ask for a new phone number, showing the current number as a hint
  std::cout << "Enter new phone (leave blank to keep \"" << contacts[editIndex].phone << "\"): ";
  std::string newPhone;
  std::getline(std::cin, newPhone);  // Read full line

  // If user typed a new name, update it
  if (!newName.empty()) {
    contacts[editIndex].name = newName;
  }

  // If user typed a new phone number, update it
  if (!newPhone.empty()) {
    contacts[editIndex].phone = newPhone;
  }

  // Confirm to the user that the contact was updated
  std::cout << "Contact updated successfully.\n";
}
