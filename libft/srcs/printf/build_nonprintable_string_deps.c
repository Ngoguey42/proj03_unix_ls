
#include "ft_printf.h"

#define COLOR_TAG_S ":yel:"
#define COLOR_TAG_E ":eoc:"
#define TAGS_LEN ft_strlen(COLOR_TAG_S""COLOR_TAG_E)

static size_t	char_len(char c, t_printf_part *part)
{
	if (c == '\t' && !AND_F(SPAC_MASK))
		return (1);
	if (c == '\n' && !AND_F(DOLL_MASK))
		return (2);
	if (((c >= '\a' && c <= '\r') || c == '\033') && !AND_F(ZERO_MASK))
		return (2);
	if (part->length == 2)
	{
		if (c >= 0)
			return (2);
		return ((c >= -96 && c <= -2) ? 3 : 4);
	}
	if (part->length == 6)
	{
		if (c >= -9 && c <= 9)
			return ((c < 0 ? 2 : 1) + !AND_F(HASH_MASK) * 2);
		if (c >= -99 && c <= 99)
			return ((c < 0 ? 3 : 2) + !AND_F(HASH_MASK) * 2);
		return ((c < 0 ? 4 : 3) + !AND_F(HASH_MASK) * 2);
	}
	return (2 + !AND_F(HASH_MASK) * 2);
}

size_t	npnt_len(char *str, t_printf_part *part, int p)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	while ((!AND_I(PNUM_MASK) && *str) || (AND_I(PNUM_MASK) && p-- > 0))
	{
		if (ft_isprint(*str))
		{
			len++;
			i = 0;
		}
		else if (!AND_F(EXCL_MASK))
		{
			len += (i ? 0 : TAGS_LEN) + char_len(*str, part);
			i = 1;
		}
		else
			len += char_len(*str, part);
		str++;
	}
	return (len + 1);
}

void	npnt_cat(char **ret, char src, char* input, int *color_status)
{
	if (!input)
	{
		if (*color_status > 0)
		{
			ft_strcat(*ret, COLOR_TAG_E);
			*color_status = 0;
		}
		*(*ret + ft_strlen(*ret)) = src;
	}
	else
	{
		if (*color_status == 0)
		{
			ft_strcat(*ret, COLOR_TAG_S);
			*color_status = 1;
		}
		ft_strcat(*ret, input);
		free(input);
	}
	while (**ret)
		(*ret)++;
}
