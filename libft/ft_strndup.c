#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	int			i;
	char		*mpointer;

	i = 0;
	mpointer = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!mpointer)
		return (0);
	while (i < n)
	{
		mpointer[i] = s1[i];
		i++;
	}
	mpointer[i] = '\0';
	return (mpointer);
}
