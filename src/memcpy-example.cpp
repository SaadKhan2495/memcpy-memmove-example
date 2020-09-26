#include <array>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
  array<int, 10> original;
  cout << "Size of original: " << sizeof(original) << endl;
  cout << "Size of &original: " << sizeof(&original) << endl;
  cout << "Size of &original[0]: " << sizeof(&original[0]) << endl;
  for (int index = 0; index < sizeof(original) / sizeof(original[0]); ++index) {
    original[index] = index * 10;
  }

  //-----------------------------------------------------------------------------
  cout << endl;
  cout << "Using memcpy to copy into another array." << endl;
  array<int, 10> copy;
  for (int index = 0; index < sizeof(copy) / sizeof(copy[0]); ++index) {
    copy[index] = index * 100;
  }

  cout << "Array contents before memcpy: ";
  for (int index = 0; index < sizeof(copy) / sizeof(copy[0]); ++index) {
    cout << copy[index] << ", ";
  }
  cout << endl;

  memcpy(&copy, &original, 10 * sizeof(int));

  cout << "Array contents after memcpy: ";
  for (int index = 0; index < sizeof(copy) / sizeof(copy[0]); ++index) {
    cout << copy[index] << ", ";
  }
  cout << endl;

  //-----------------------------------------------------------------------------
  cout << endl;
  cout << "Using memcpy to copy into same array.(Non-overlapping)" << endl;
  cout << "Array contents before memcpy: ";
  for (int index = 0; index < sizeof(original) / sizeof(original[0]); ++index) {
    cout << original[index] << ", ";
  }
  cout << endl;

  // memory addition works as address+5 is actually address+(5*sizeof(datatype
  // of address)) e.g &int+5 will be &int+(5*sizeof(int))
  memcpy(&original[0] + 5, &original, 5 * sizeof(int));

  cout << "Array contents after memcpy: ";
  for (int index = 0; index < sizeof(original) / sizeof(original[0]); ++index) {
    cout << original[index] << ", ";
  }
  cout << endl;

  // Resetting original array
  for (int index = 0; index < sizeof(original) / sizeof(original[0]); ++index) {
    original[index] = index * 10;
  }

  //-----------------------------------------------------------------------------
  // This might work fine but for some cases the behaviour is undefined
  // therefore it is better to use memmove for overlapping cases
  cout << endl;
  cout << "Using memcpy to copy into same array.(overlapping)" << endl;
  cout << "Array contents before memcpy: ";
  for (int index = 0; index < sizeof(original) / sizeof(original[0]); ++index) {
    cout << original[index] << ", ";
  }
  cout << endl;

  memcpy(&original[4], &original[5], 5 * sizeof(int));

  cout << "Array contents after memcpy: ";
  for (int index = 0; index < sizeof(original) / sizeof(original[0]); ++index) {
    cout << original[index] << ", ";
  }
  cout << endl;
}
