#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 587

typedef struct	s_node
{
	char			*word;
	int				player;
	struct s_node	*next;
}	t_node;

unsigned int	ft_djb2(unsigned char *str)
{
	unsigned long hash;
	int	c;

	hash = 5381;
	while (c = *str++)
		hash = ((hash << 5) + hash) + c;
	return (hash);
}

int		ft_get_other_player(int current_player_i)
{
	if (current_player_i == 0)
		return (6);
	if (current_player_i == 1)
		return (5);
	if (current_player_i == 2)
		return (3);
}

void	ft_count(t_node	**tab_hash, char word[3][1000][4], int len_word)  //todo to update
{
	int		tab_hash_i;
	int		score;
	int		other_player;
	int		current_player_i;
	t_node *current;

	current_player_i = 0;
	while (current_player_i < 3)
	{
		other_player = ft_get_other_player(current_player_i);
		tab_hash_i = 0;
		score = 0;
		while (tab_hash_i < MAX)
		{
			if (tab_hash[tab_hash_i] != NULL)
			{
				current = tab_hash[tab_hash_i];
				while (current)
				{
					if (current->player & (1 << current_player_i))
					{
						if ((current->player & other_player) == 0)
							score += 3;
						else if (current->player == 7)
							score += 0;
						else
							score += 1;
					}		
					current = current->next;
				}
			}
			tab_hash_i++;
		}
		printf("%d ", score);
		current_player_i++;
	}
}

void	add_to_hash(t_node **tab_hash, char *word, int player)
{
	t_node	*current;
	int		pos;

	pos = ft_djb2((unsigned char *)word) % MAX;
	current = (t_node *)malloc(sizeof(t_node));
	current->next = tab_hash[pos];
	current->player = player;
	current->word = word;
	tab_hash[pos] = current;

}

void		update_to_hash(t_node **tab_hash, char *word, int player)
{
	t_node	*current;
	int		pos;

	pos = ft_djb2((unsigned char *)word) % MAX;
	current = tab_hash[pos];
	while (current)
	{
		if (strcmp(current->word, word) == 0)
		{
			current->player |= player;
			break ;
		}
		current = current->next;
	}
}

int		is_in_hash_table(t_node **tab_hash, char *word)
{
	t_node	*current;
	int		pos;

	pos = ft_djb2((unsigned char *)word) % MAX;
	current = tab_hash[pos];
	while (current)
	{
		if (strcmp(current->word, word) == 0)
			return (1);
		current = current->next;
	}
	return (0);
}

void	ft_init_hash(t_node	**tab_hash, char word[1000][4], int len_word, int current_player_i)
{
	int	current_word_i;

	current_word_i = 0;
	while (current_word_i < len_word)
	{
		if (!is_in_hash_table(tab_hash, word[current_word_i]))
			add_to_hash(tab_hash, word[current_word_i], 1 << current_player_i);
		else 
			update_to_hash(tab_hash, word[current_word_i], 1 << current_player_i);
		current_word_i++;
	}
}

int	main(void)
{
	char	word[3][1000][4];
	t_node		**tab_hash;
	int	len_case;
	int	len_player;
	int	len_word;
	int	current_case_i;
	int	current_word_i;
	int	current_player_i;

	scanf("%d\n", &len_case);
	current_case_i = 0;
	len_player = 3;
	while (current_case_i < len_case)
	{
		scanf("%d\n", &len_word);
		current_player_i = 0;
		tab_hash = (t_node **)calloc(sizeof(t_node *), MAX);
		while (current_player_i < len_player)
		{
			current_word_i = 0;
			while (current_word_i < len_word)
			{	
				scanf("%s\n", (char *)&word[current_player_i][current_word_i]);
				current_word_i++;
			}
			ft_init_hash(tab_hash, word[current_player_i], len_word, current_player_i);
			current_player_i++;
		}
		ft_count(tab_hash, word, len_word);
		free(tab_hash);
		printf("\n");
		current_case_i++;
	}
	return (0);
}