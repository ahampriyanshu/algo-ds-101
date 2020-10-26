/*
 * This is an implementation of HashSet Data structure
 */
#include <stdio.h>
#include <stdlib.h>
#define HS_REHASH_LIM(x) (x / 2)
#define HS_REHASH_FAC 2

typedef struct {
  long key;
  void *value;
} hashpair;

/* Hashset struct
 * size : the maximum amount of elements it can store
 * used : number of elements currently stored
 * start : pointer to start of hashset
 * hash : function pointer to a function which takes in a void pointer (key) and
 *        return an long (hash) of that key
 */
typedef struct {
  int size;
  int used;
  hashpair *start;
  long (*hash)(void *);
} Hashset;

/*
 * Function to create Hashset structure
 * the structure received should be deleted after use by
 * using function hs_delete
 * Params :
 * size : Initial size allocated to hasmap
 * hashfn : A function which takes in a void pointer (key)
 *          and returns an long representing the hash of that key
 * Returns : A struct Hashset.
 *
 * This allocates the given size from heap memory using calloc, and stores its
 * pointer,as well as the compair function and hash function in the returning
 * structure
 */

Hashset make_hashset(int size, long (*hashfn)(void *)) {
  Hashset ret = {
      .size = size,
      .used = 0,
      .start = (hashpair *)calloc(
          size, sizeof(Hashset)), /* Use calloc so the returned memory will be
                                   * zeroed and if any errors or invalid access,
                                   * will be caught */
      .hash = hashfn};
  return ret;
}

/*
 * Internal function to rehash a Hashset and reallocate the keys and values
 * Should not be exposed
 *
 * this increases the current size of hashset by HM_REHASH_FAC factor,
 * and then rehashes all keys and puts then in this newly allocated memory
 * then frees the old memory
 */
int hs_add(Hashset *hs, void *value);  // forward declaration
static void rehash(Hashset *hs) {
  int size = hs->size;
  hashpair *temp = (hashpair *)calloc(size * HS_REHASH_FAC, sizeof(hashpair));
  if (temp == NULL) {  // If cannot allocate memory , just return
    return;
  }
  hashpair *newstart = temp;
  hashpair *oldstart = hs->start;
  // Change the HM info
  hs->start = newstart;
  hs->size = size * HS_REHASH_FAC;
  hs->used = 0;

  hashpair *iter = oldstart;

  // move all key-value pairs to new locations, using the hm_add function
  while (iter < oldstart + size) {
    // As we have calloc-ed the memory, both key and value being zero
    // means that the location was not allocated
    if (iter->key >= 0 || iter->value != NULL) {
      // If either is non-zero, add it to the new memory
      hs_add(hs, iter->value);
    }
    ++iter;
  }
  free(oldstart);
}

/*
 * Function to add a value to hasset
 * Note that once the hashset reaches its max used capacity,
 * this internally rehashes and reallocates the whole hashset
 *
 * Params :
 * hm : pointer to the hashset in which the pair is to be added
 * value : pointer to value / value (must be typecasted to void *)
 *
 * Returns : int : 0 if succeeded
 *                 -1 if failed
 */
int hs_add(Hashset *hs, void *value) {
  long key = hs->hash(value);
  int hash = key % hs->size;  // bound the hash inside the size

  // If the used capacity of HM is more than max used allowed, reshah
  if (hs->used >= HS_REHASH_LIM(hs->size)) {
    rehash(hs);
  }
  // Start searching empty space at offset of hash
  hashpair *search = hs->start + hash;
  // loop until we find an empty space or we get to end of memory
  while (search->key >= 0 && search->value != NULL &&
         search < hs->start + hs->size) {
    ++search;
  }

  if (search >= hs->start + hs->size) {
    return -1;  // Failed to add
  } else {
    search->key = key;
    search->value = value;
    ++hs->used;
  }
  return 0;
}

/*
 * Function to check if given value exists in hashset
 *
 * Params :
 * hm : pointer to the hashmap from which the value is to be retrieved
 *
 * Returns : 0 if value is not found in given hashset
 *           1 if value is found in hashset
 */
int hs_contains(Hashset *hs, void *value) {
  hashpair *start = hs->start;
  long key = hs->hash(value);
  int hash = (key % hs->size);  // bound the hash in memory size

  // start searching for key at offset of hash
  hashpair *search = start + hash;

  // As we have calloc-ed the memory, both key and value being zero
  // means that the location was not allocated
  while (search->key >= 0 && search->value != NULL &&
         search < start + hs->size) {
    // Compair the found and required key
    if (key == search->key) {
      return 1;
    }
    ++search;
  }
  return 0;
}

/*
 * A function to delete a perticular value from given hashset
 * Note : This only removes the value from hashset.
 *        this returns the value as given to hs_add,
 *        which if were manually allocated, must be manually freed by user.
 *
 * Params :
 * hm : A pointer to hashset from which value is to be deleted
 * value : the value as void *, which is to be removed
 *
 * Returns : if value is found : value as void* as given to hs_add
 *           if value is not found : NULL
 */
void *hs_delete_key(Hashset *hs, void *value) {
  hashpair *start = hs->start;
  long key = hs->hash(value);
  int hash = (key % hs->size);  // bound the hash in memory size

  // start searching for key at offset of hash
  hashpair *search = start + hash;

  // As we have calloc-ed the memory, both key and value being zero
  // means that the location was not allocated
  while (search->key >= 0 && search->value != NULL &&
         search < start + hs->size) {
    if (key == search->key) {
      // if we found the key, save the key and value in structure
      // and set both in the HS to NULL
      void *ret = search->value;
      search->key = -1;
      search->value = NULL;
      --hs->used;
      return ret;
    }
    ++search;
  }
  // We did not find the required key, so return NULL in structure
  return NULL;
}

/*
 * A function to delete the hashset
 * frees the memory allocated to the hashset
 * Params :
 * hs : Hashset structure as returned by the make_hashset function
 * delfn : A function which takes in a void pointer (value)
 *         This will be called on each value in Hashset.
 *         Should be used to free the memory allocated to value, if
 *         required
 *
 */
void hs_delete(Hashset *hs, void (*delfn)(void *)) {
  hashpair *start = hs->start;
  hashpair *iter = start;

  while (iter < start + hs->size) {
    // As we have calloc-ed the memory, both key and value being zero
    // means that the location was not allocated
    if (iter->key >= 0 || iter->value != NULL) {
      // call delfn on giving the key and value
      delfn(iter->value);
    }
    ++iter;
  }
  // Finally free the memory that was allocated to the HM
  free(start);
  hs->size = 0;
  hs->start = NULL;
}

// Tests

static inline long __hash__(void *val) { return (long)val; }

static inline void __del__(
    void *val) { /* do nothing as the values are just ints */
}

void main() {
  // A Hasset for numbers
  Hashset hs = make_hashset(10, __hash__);
  hs_add(&hs, (void *)55);
  hs_add(&hs, (void *)23);
  hs_add(&hs, (void *)785);
  hs_add(&hs, (void *)78);

  if (hs_contains(&hs, (void *)5)) {
    printf("This is error\n");
  } else {
    printf("Test 1 is correct\n");
  }

  if (hs_contains(&hs, (void *)23)) {
    printf("Test 2 is correct\n");
  } else {
    printf("This is error\n");
  }

  long ret = (long)hs_delete_key(&hs, (void *)785);
  if (ret != 785) {
    printf("This is error\n");
  } else {
    printf("Test 3 is correct\n");
  }

  hs_delete(&hs, __del__);
}