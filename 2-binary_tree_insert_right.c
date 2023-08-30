#include "binary_trees.h"
/**
 * binary_tree_insert_right - Inserts a node
 * @parent: Pointer to the node
 * @value: Value for the node
 *
 * Return: Pointer to the node or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *n_node;

	if (!parent)
		return (NULL);

	n_node = binary_tree_node(parent, value);
	if (!n_node)
		return (NULL);
	if (parent->right)
	{
		n_node->right = parent->right;
		parent->right->parent = n_node;
	}
	parent->right = n_node;

	return (n_node);
}
