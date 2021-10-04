package main

import (
	"fmt"
	"strings"
)

// Trie structure
type Trie struct {
	root *trieNode
}

type trieNode struct {
	children [26]*trieNode
	wordEnd  bool
}

// Constructor initialize the Trie data structure
func Constructor() Trie {
	return Trie{
		root: &trieNode{},
	}
}

// Insert a word into the trie
func (this *Trie) Insert(word string) {
	word = strings.ToLower(word)
	current := this.root
	for i := 0; i < len(word); i++ {
		index := word[i] - 'a'
		if current.children[index] == nil {
			current.children[index] = &trieNode{}
		}
		current = current.children[index]
	}
	current.wordEnd = true
}

// Search returns if the word is in the trie
func (this *Trie) Search(word string) bool {
	word = strings.ToLower(word)
	current := this.root
	for i := 0; i < len(word); i++ {
		index := word[i] - 'a'
		if current.children[index] == nil {
			return false
		}
		current = current.children[index]
	}
	if current.wordEnd {
		return true
	}
	return false
}

func main() {
	insertWords := []string{"hello", "world", "golang", "trie", "tree"}
	searchWords := []string{
		"world",  /* true */
		"Golang", /* true */
		"word",   /* false */
	}

	trie := Constructor()

	for _, node := range insertWords {
		trie.Insert(node)
	}

	for _, node := range searchWords {
		found := trie.Search(node)
		if found {
			fmt.Println(node, ": Found in the trie")
		} else {
			fmt.Println(node, ": Not found in the trie")
		}
	}
}
