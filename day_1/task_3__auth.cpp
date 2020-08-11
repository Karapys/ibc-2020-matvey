#include <iostream>

const std::string TEST_LOGIN = "test";
const std::string TEST_PASSWORD = "test";
const int ATTEMPTS = 3;
std::string login, password;

void showTestCredentails() {
  std::cout << "Test credentials\n";
  std::cout << "  Login: " << TEST_LOGIN << "\n";
  std::cout << "  Password: " << TEST_PASSWORD << "\n\n";
}

void getUserInput() {
  std::cout << "Enter your login: ";
  std::cin >> login;
  std::cout << "Enter your password: ";
  std::cin >> password;
  std::cout << "\n";
}

bool credentailsMatch() {
  return (login == TEST_LOGIN) and (password == TEST_PASSWORD);
}

int main() {
  showTestCredentails();

  int attempt;
  std::cout << "You have " << ATTEMPTS << " attempts.\n";
  for (attempt = 1; attempt <= ATTEMPTS; attempt++) {
    getUserInput();
    if (credentailsMatch()) {
      // We need this for the last attempt submition to work
      attempt--;
      // Exit if credentials matches
      break;
    } else {
      std::cout << "Access has restricted. You have " << ATTEMPTS - attempt << " attempts left.\n";
    }
  }

  // guard
  if (attempt >= 3) {
    std::cout << "Goodbye!\n";
    return 0;
  }

  std::cout << "Access has granted. Welcome, " << login << "\n";

  return 0;
}