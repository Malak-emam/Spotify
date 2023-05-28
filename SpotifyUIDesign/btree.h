#pragma once
#include <iostream>
#include<string>
#include "song.h"
#include"LinkedList.h"

struct node {
	int value;
	song SONG;
	node* left;
	node* right;
};



class btree {
public:
	btree();
	~btree();

	void insert(int key, song s);
	node* search(int key);
	void destroy_tree();
	SinglyLinkedList* inorder_print();
	SinglyLinkedList* postorder_print();
	SinglyLinkedList* preorder_print();

private:
	void destroy_tree(node* leaf);
	void insert(int key,song s, node* leaf);
	node* search(int key, node* leaf);
	void inorder_print(node* leaf, SinglyLinkedList* songsList);
	void postorder_print(node* leaf, SinglyLinkedList* songsList);
	void preorder_print(node* leaf, SinglyLinkedList* songsList);

	node* root;
};




