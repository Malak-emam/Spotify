#include "btree.h"
//#include<string>

btree::btree() {
	root = nullptr;
}

btree::~btree() {
	destroy_tree();
}

void btree::destroy_tree(node* leaf) {
	if (leaf != nullptr) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::insert(int key,song s, node* leaf) {

	if (key < leaf->value) {
		if (leaf->left != nullptr) {
			insert(key,s, leaf->left);
		}
		else {
			leaf->left = new node;
			leaf->left->value = key;
			leaf->left->SONG = s;
			leaf->left->left = nullptr;
			leaf->left->right = nullptr;
		}
	}
	else if (key >= leaf->value) {
		if (leaf->right != nullptr) {
			insert(key,s, leaf->right);
		}
		else {
			leaf->right = new node;
			leaf->right->value = key;
			leaf->right->SONG = s;
			leaf->right->right = nullptr;
			leaf->right->left = nullptr;
		}
	}

}

void btree::insert(int key,song s) {
	if (root != nullptr) {
		insert(key, s, root);
	}
	else {
		root = new node;
		root->value = key;
		root->SONG = s;
		root->left = nullptr;
		root->right = nullptr;
	}
}

node* btree::search(int key, node* leaf) {
	if (leaf != nullptr) {
		if (key == leaf->value) {
			return leaf;
		}
		if (key < leaf->value) {
			return search(key, leaf->left);
		}
		else {
			return search(key, leaf->right);
		}
	}
	else {
		return nullptr;
	}
}

node* btree::search(int key) {
	return search(key, root);
}

void btree::destroy_tree() {
	destroy_tree(root);
}

SinglyLinkedList* btree::inorder_print() {
	SinglyLinkedList* songsList = new SinglyLinkedList();
	inorder_print(root, songsList);
	std::cout << "\n";
	return songsList;
}

void btree::inorder_print(node* leaf, SinglyLinkedList* songsList) {
	if (leaf != nullptr) {
		inorder_print(leaf->left, songsList);
		songsList->insert_node(leaf->SONG);
		std::cout << leaf->SONG.getName() << "  ";
		inorder_print(leaf->right, songsList);
	}
}

SinglyLinkedList* btree::postorder_print() {
	SinglyLinkedList* songsList = new SinglyLinkedList();
	postorder_print(root, songsList);
	std::cout << "\n";
	return songsList;
}

void btree::postorder_print(node* leaf, SinglyLinkedList* songsList) {
	if (leaf != nullptr) {
		postorder_print(leaf->left, songsList);
		postorder_print(leaf->right, songsList);
		songsList->insert_node(leaf->SONG);
		std::cout << leaf->SONG.getName() << "  ";
	}


}

SinglyLinkedList* btree::preorder_print() {
	SinglyLinkedList* songsList = new SinglyLinkedList();
	preorder_print(root, songsList);
	std::cout << "\n";
	return songsList;
}

void btree::preorder_print(node* leaf, SinglyLinkedList* songsList) {
	if (leaf != nullptr) {
		std::cout << leaf->SONG.getName() << "  ";
		songsList->insert_node(leaf->SONG);
		preorder_print(leaf->left, songsList);
		preorder_print(leaf->right, songsList);
	}
}

