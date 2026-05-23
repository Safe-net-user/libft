#ifndef FT_STRINGS_H
#define FT_STRINGS_H

# include <stddef.h>
# include <stdlib.h>


int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
size_t	ft_strlcat(char *d, const char *src, size_t dst_size);
size_t	ft_strlcpy(char *dst, const char *src, size_t s);
size_t	ft_strlen(const char *str);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

#endif
