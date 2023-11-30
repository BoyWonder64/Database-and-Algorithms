#include <iostream>

template <class T, class D, int MAX_SIZE> 
class Dictionary;
template <class T, class D, int MAX_SIZE>
std::ostream &operator<<(std::ostream &, const Dictionary<T, D, MAX_SIZE> &d);

template <class T, class D, int MAX_SIZE> 
class Dictionary {
private:
  T terms[MAX_SIZE];
  D definitions[MAX_SIZE];
  int size;

public:
  Dictionary();
  void Add(T term, D definition);
  int IndexOfTerm(T term) const;
  D GetDefinition(T term) const;
  void UpdateDefinition(T term, D definition);
  friend std::ostream &operator<< <>(std::ostream &,
                                     const Dictionary<T, D, MAX_SIZE> &d);
};

/**
 * Creates an empty dictionary
 */
template <class T, class D, int MAX_SIZE>
Dictionary<T, D, MAX_SIZE>::Dictionary() {
  size = 0;
}

/**
 * Adds a term and definition to the dictionary
 * @param term: The term to be added
 * @param definition: The definition to be paired with the term
 */
template <class T, class D, int MAX_SIZE>
void Dictionary<T, D, MAX_SIZE>::Add(T term, D definition) {
  if (size < MAX_SIZE) {
    terms[size] = term;
    definitions[size] = definition;
    size++;
  }
}

/**
 * Searches the dictionary for the term
 * @param term: The term that the dictionary is searching for
 * @return the position of the term or -1 if it is not found
 */
template <class T, class D, int MAX_SIZE>
int Dictionary<T, D, MAX_SIZE>::IndexOfTerm(T term) const {
  for (int i = 0; i < size; i++) {
    if (term == terms[i]) {
      return i;
    }
  }
  return -1;
}

/**
 * Finds the definition to match the given term
 * @param term: The term that the dictionary is searching for
 * @return the corresponding definition
 */
template <class T, class D, int MAX_SIZE>
D Dictionary<T, D, MAX_SIZE>::GetDefinition(T term) const {
  int position = IndexOfTerm(term);
  if (position >= 0) {
    return definitions[position];
  }
  throw std::out_of_range("Term not found");
}

/**
 * Updates the term with a new definition
 * @param term: The term that the dictionary is searching for
 */
template <typename T, typename D, int MAX_SIZE>
void Dictionary<T, D, MAX_SIZE>::UpdateDefinition(T term, D newDefinition) {
  // Update this function so that it updates the given term with new definition
      int position = IndexOfTerm(term);
      definitions[position] = newDefinition;

    
}

/**
 * Displays the term and definition pairs
 */
template <class T, class D, int MAX_SIZE>
std::ostream &operator<<(std::ostream &out,
                         const Dictionary<T, D, MAX_SIZE> &d) {
  for (int i = 0; i < d.size; i++) {
    out << d.terms[i] << "\t" << d.definitions[i] << std::endl;
  }
  return out;
}