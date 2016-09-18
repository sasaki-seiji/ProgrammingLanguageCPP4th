/*
 * map.h
 *
 *  Created on: 2016/09/18
 *      Author: sasaki
 */

#ifndef MAP_H_
#define MAP_H_

#include <functional>
#include <ostream>

template<typename Key, typename V>
struct assoc_link {
	Key	key;
	V	val;
	assoc_link	*left, *right;
};

template<typename Key, typename V, typename Compare = std::less<Key>>
class map {
public:
	map() :root{nullptr} { }
	map(Compare c) :cmp{c},root{nullptr} { }

	V& operator[](const Key& key) { return find_or_insert(key)->val; }
	void print(std::ostream& os) { print_recursive(os, root); os << '\n'; }

private:
	Compare cmp {};

	using Link = assoc_link<Key,V>;
	Link* root;
	Link* find_or_insert(const Key& key);
	void print_recursive(std::ostream& os, Link* entry);
};

template<typename Key, typename V, typename Compare>
assoc_link<Key,V>* map<Key,V,Compare>::find_or_insert(const Key& key)
{
	Link **pp;
	pp = &root;
	while (*pp) {
		if (cmp(key, (*pp)->key))
			pp = &(*pp)->left;
		else if (cmp((*pp)->key, key))
			pp = &(*pp)->right;
		else
			return *pp;
	}

	Link *p = new Link;
	p->key = key;
	p->val = V{};
	p->left = p->right = nullptr;
	*pp = p;
	return p;
}

template<typename Key, typename V, typename Compare>
void map<Key,V,Compare>::print_recursive(std::ostream& os, Link* entry)
{
	if (!entry) return ;

	print_recursive(os, entry->left);
	os << " (" << entry->key << ":" << entry->val << ")";
	print_recursive(os, entry->right);
}

#endif /* MAP_H_ */
