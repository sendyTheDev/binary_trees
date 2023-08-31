#include "binary_trees.h"
/**
 *  binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node
 *
 * Return: number of nodes with at least 1 child in the tree, or 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t number_of_nodes = 0;

	if (tree != NULL)
	{
		if (tree->right != NULL || tree->left != NULL)
			number_of_nodes++;
		number_of_nodes += binary_tree_nodes(tree->right);
		number_of_nodes += binary_tree_nodes(tree->left);
	}
	return (number_of_nodes);
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node
 *
 * Return: 1 if tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int nodes_left, nodes_right;

	if (!tree)
		return (0);

	nodes_left = binary_tree_nodes(tree->left);
	nodes_right = binary_tree_nodes(tree->right);

	if (nodes_left == nodes_right)
		return (1);
	else
		return (0);
}
