# push_swap

## Arguments validation
All of this should show a "Error" followed by new line

- dupllicated numbers
- numbers ordered
- more than 1 sign
- no-digit characters
- numbers and strings 1 2 "8 9" 0 5 (mixed)
- empty/blank strings "1 5 4" "" or "1 5 4" " "

# Turk algorithm (re-make this explantion)

- validate that the stack A has more than 3 elements
	- if it not, just order it without the algorithm
	- if it so, apply the turk algorithm

- applying the algorithm
	- pass to the stack B 2 elements (it doesn't matter the order, I mean without calculating the cost and those things)
	- then each element of A has to have a target, in order to calculate the cost of movements
	- once the cost is calculated, we work with the one that has the minor cost
	- that will be repeated until the stack A has 3 elements
	- the stack B has to be ordered in descending order, in order to when we pass the elements from B o A, A will be ordered in ascending order

- how find out the target
	- know the value of the A's element we want to move
	- know each value of B's nodes/elements (values and order)
	- find out the smallest number that be larger than A's value (it is the target)
		- if there is not grater number, it will be the largest number, so it will be above the largest number of the stack
		- but what if A's value is smallest than each of the stack B?, then it will be the smallest of that stack

- the struct
	- index: a number to represent how each node should be (really I need this??)
	- pos: position of the node in the stack
## NOTES

## Backup (is not needed but until I finish the project I will keep it)
/*
========= target_in_b_finder ==============

// Function that find and returning the position of
//   the node with the smallest integer value
int	ft_find_min_val_pos(t_list *stack)
{
	int	min_val;
	int	min_pos;

	if (!stack)
		return (-1);
	min_val = INT_MAX;
	min_pos = -1;
	while (stack)
	{
		if (stack->content < min_val)
		{
			min_val = stack->content;
			min_pos = stack->pos;
		}
		stack = stack->next;
	}
	return (min_pos);
}

//  Auxiliary function that searches the stack for the smallest
//  number that is greater than the current node value of the stack b
int	ft_get_target_pos_b(t_list *node_b, t_list *a)
{
	t_list	*node_a;
	int		target_pos;
	int		best_match_val;

	best_match_val = INT_MAX;
	target_pos = -1;
	node_a = a;
	while (node_a)
	{
		if (node_a->content > node_b->content
			&& node_a->content < best_match_val)
		{
			best_match_val = node_a->content;
			target_pos = node_a->pos;
		}
		node_a = node_a->next;
	}
	return (target_pos);
}

// Principal function to find targets in A to each
// node in  B
void	ft_find_target_in_stack_b(t_list **b, t_list *a)
{
	t_list	*node_b;
	int		target_pos;

	node_b = *b;
	while (node_b)
	{
		target_pos = ft_get_target_pos_b(node_b, a);
		if (target_pos == -1)
			target_pos = ft_find_min_val_pos(a);
		node_b->target_pos = target_pos;
		node_b = node_b->next;
	}
}*/
/*
============= target_in_a_finder ==============
// int	ft_find_max_val_pos(t_list *stack)
// {
// 	int	max_val;
// 	int	max_pos;

// 	if (!stack)
// 		return (-1);
// 	max_val = INT_MIN;
// 	max_pos = -1;
// 	while (stack)
// 	{
// 		if (stack->content > max_val)
// 		{
// 			max_val = stack->content;
// 			max_pos = stack->pos;
// 		}
// 		stack = stack->next;
// 	}
// 	return(max_pos);
// }
// int	ft_get_target_post_a(t_list *node_a, t_list *b)
// {
// 	t_list	*node_b;
// 	int		target_pos;
// 	int		best_match_val;

// 	best_match_val = INT_MIN;
// 	target_pos = -1;
// 	node_b = b;
// 	while (node_b)
// 	{
// 		if (node_b->content < node_a->content
// 			&& node_b->content > best_match_val)
// 		{
// 			best_match_val = node_b->content;
// 			target_pos = node_b->pos;
// 		}
// 		node_b = node_b->next;
// 	}
// 	return (target_pos);
// }
// void	ft_find_targets_in_stack_a(t_list **a, t_list *b)
// {
// 	t_list	*node_a;
// 	int		target_pos;

// 	node_a = *a;
// 	while (node_a)
// 	{
// 		target_pos = ft_get_target_post_a(node_a, b);
// 		if (target_pos == -1)
// 			target_pos =ft_find_max_val_pos(b);
// 		node_a->target_pos = target_pos;
// 		node_a = node_a->next;
// 	}
// }
*/
