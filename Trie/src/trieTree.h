#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <cctype>

namespace DS
{
	class Node
	{
		public:
			Node(char alpha = '\0', bool end = false);

			~Node();

			bool isLeaf() const;

			bool matchChar(const char &ch) const;

			const std::vector<Node*>& getNodes() const;

			std::vector<Node*>& getNodes();

			friend std::ostream& operator<<(std::ostream &out, Node &node);
			friend std::ostream& operator<<(std::ostream &out, Node *node);

			friend class Trie;
		private:
			char					mChar;
			bool					mIsEnd;		// It only represent if it's the last char of the word, even if it is, it doesn't mean its a leaf
			std::vector<Node*>	mNodes;
	};


	class Trie
	{
		public:
			Trie();

			// Insert methods
			bool insert(std::string word);

			// Size methods
			size_t size() const;

			size_t count(std::string prefix) const;		// Returns count of word starting with the given prefix

			std::vector<std::string> getAllWordWithPrefix(std::string prefix) const;

			friend std::ostream& operator<<(std::ostream &out, Trie &trie);

		protected:
			// Helper Methods
			bool addWord(const std::string &word);
			
			std::vector<std::string> traverse(const Node *node) const;

			void recurse(const Node *inNode, std::string pref, std::vector<std::string> &vec, size_t &actualSize) const;

			const Node* findWord(const std::string &prefix, size_t &pos) const;

			void convertToLower(std::string &word) const;
			void convertToUpper(std::string &word) const;

		private:
			Node			mRoot;
			size_t		mSize;	// Number of words
	};
}