/*
 * map.h
 *
 *  Created on: 2016/09/18
 *      Author: sasaki
 */

#ifndef MAP_H_
#define MAP_H_

#include <functional>
#include <iterator>
#include <ostream>

template<typename Key, typename V, typename Compare = std::less<Key>>
	class Map;
template<typename Key, typename V> class Map_iterator;
template<typename Key, typename V> class Map_entry;

template<typename Key, typename V>
class Map_entry {

	std::pair<const Key, V> val;
	Map_entry	*parent, *left, *right;

	Map_entry(const Key& k, const V& v = V{}, Map_entry* p = nullptr,
			Map_entry* l = nullptr, Map_entry* r = nullptr)
		:val{k,v}, parent{p}, left{l}, right{r} { }

	Map_entry* leftmost();
	Map_entry* right_ancestor();

	template<typename KKey, typename VV, typename Compare>
	friend class Map;

	friend class Map_iterator<Key,V>;
};

template<typename Key, typename V>
class Map_iterator
: public std::iterator<std::forward_iterator_tag, std::pair<const Key, V>>{

	Map_entry<Key,V> *pos;

public:
	std::pair<const Key,V>& operator*() { return pos->val; }
	//value_type& operator*() { return pos->val; }
	Map_iterator& operator++();
	bool operator==(const Map_iterator& o) const { return pos == o.pos; }
	bool operator!=(const Map_iterator& o) const { return pos != o.pos; }

private:
	Map_iterator(Map_entry<Key,V> *p=nullptr) : pos{p} { }
	static Map_iterator begin(Map_entry<Key,V> *root);
	static Map_iterator end() { return Map_iterator{nullptr}; }

	template<typename KKey, typename VV, typename Compare>
	friend class Map;
};

template<typename Key, typename V, typename Compare>
class Map {

	using Entry = Map_entry<Key,V>;
	Compare cmp {};
	Entry* root;

public:
	using iterator = Map_iterator<Key,V>;

	Map(const Compare& c ={}) :cmp{c},root{nullptr} { }

	V& operator[](const Key& key) { return search_insert(key)->val.second; }
	void print(std::ostream& os) { print_recursive(os, root); os << '\n'; }

	iterator begin() { return Map_iterator<Key,V>::begin(root); }
	iterator end() { return Map_iterator<Key,V>::end(); }

private:

	Entry* search_insert(const Key& key);
};


// implement for Map_entry

template<typename Key, typename V>
Map_entry<Key,V>* Map_entry<Key,V>::leftmost()
{
	Map_entry<Key,V> *most = this;
	while (most->left)
		most = most->left;
	return most;
}

template<typename Key, typename V>
Map_entry<Key,V>* Map_entry<Key,V>::right_ancestor()
{
	Map_entry *cur = this, *ancestor = parent;
	while (ancestor) {
		if (cur == ancestor->left) return ancestor;
		cur = ancestor;
		ancestor = ancestor->parent;
	}
	return nullptr;
}


// implement for Map_iterator

template<typename Key, typename V>
Map_iterator<Key,V>& Map_iterator<Key,V>::operator++()
{
	if (pos->right)
		pos = pos->right->leftmost();
	else
		pos = pos->right_ancestor();
	return *this;
}

template<typename Key, typename V>
Map_iterator<Key,V> Map_iterator<Key,V>::begin(Map_entry<Key,V> *root)
{
	Map_entry<Key,V> *pos = root;
	if (pos)
		pos = pos->leftmost();
	return Map_iterator{pos};
}


// implement for Map

template<typename Key, typename V, typename Compare>
Map_entry<Key,V>* Map<Key,V,Compare>::search_insert(const Key& key)
{
	Entry **pp = &root, *parent = nullptr;
	while (*pp) {
		parent = *pp;
		if (cmp(key, (*pp)->val.first))
			pp = &(*pp)->left;
		else if (cmp((*pp)->val.first, key))
			pp = &(*pp)->right;
		else
			return *pp;
	}

	*pp = new Entry{key,V{},parent};
	return *pp;
}

#endif /* MAP_H_ */
