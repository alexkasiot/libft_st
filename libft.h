/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 18:27:45 by akasiota      #+#    #+#                 */
/*   Updated: 2023/05/30 15:40:17 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
// Header files

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <errno.h>
# include <limits.h>
# include "ft_printf.h"
# include "get_next_line.h"

// Structs

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// Function prototypes
// Mandatory

/**
* * Converts the initial portion of the string pointed to by "str" to "int"
* * representation.

* * It will print all of the decimal digit characters.
* * If any character other than a decimal digit character
* * appears after a decimal digit character, the printing will end.

Decimal digit characters are considered the characters with values "48 to 57"
in the decimal range of the ASCII table.

* @param whitespace It will ignore whitespace (as defined in isspace(3)) 
characters if they are at the start of the string.

* @param plus_sign It will ignore the '+' character if it appears only 1 time
after whitespace characters or at the start of the string,
and only if it is followed by a decimal digit character.

* @param minus_sign It will use the '-' character to print a negative number
if it appears only 1 time after whitespace characters
or at the start of the string,
and only if it is followed by a decimal digit character.
*/
int		ft_atoi(const char *s);

/**
Writes "n" zeroed bytes to the string "s". If "n" is zero,
ft_bzero() does nothing.

It uses the placeholder "unsigned char *sub"" to modify the values in the
string pointed by "s".
*/
void	ft_bzero(void *s, size_t n);

/**
It allocates memory (by using the malloc() function from the "stdlib.h").

The allocated memory can be used for any data type.

* * It contiguously allocates enough space for "count" objects that are
* * "size" bytes of memory each and returns a pointer to the allocated
* * memory.

* * The allocated memory is filled with bytes of value zero
* * (by using the ft_bzero() function).
*/
void	*ft_calloc(size_t count, size_t size);

/**
* * It tests for any character for which isalpha(3) or isdigit(3) is true.
	 
The ft_isalnum() function returns 0 if the character tests false
and returns 1 if the character tests true.
*/
int		ft_isalnum(int c);

/**
It tests for any character for which isupper(3) or islower(3) is true.

The ft_isalpha() function returns 0 if the character tests false
and returns 1 if the character tests true.
*/
int		ft_isalpha(int c);

/**
It tests for an ASCII character,
which is any character between 0 and octal 0177 inclusive.

The ft_isascii() returns 0 if the character tests false
and returns 1 if the character tests true.
*/
int		ft_isascii(int c);

/**
The int ft_isdigit(int c) function test for a decimal digit character.

The ft_isdigit() function returns 0 if the character tests false
and returns 1 if the character tests true.
*/
int		ft_isdigit(int c);

/**
It tests for any printing character, including space (` ').

The ft_isprint() function returns 0 if the character tests false
and returns 1 if the character tests true.
*/
int		ft_isprint(int c);

/*
* * It allocates memory (with malloc(3)) and returns a string
* * representing the integer received as an argument.

The ft_itoa() returns the string representing the integer "n"
or NULL if the allocation fails.
*/
char	*ft_itoa(int n);

/**
* * It locates the first occurence of "c" (converted to an unsigned char)
* * in string "s".

It uses an unsigned char * "sub" placeholder for the pointer "s"
to iterate through the string.

* * The ft_memchr() function returns a pointer to the byte located,
* * or NULL if no such byte located within "n" bytes.
*/
void	*ft_memchr(const void *s, int c, size_t n);

/**
* * It compares byte string "s1" against byte string "s2".

Both strings are assumed to be "n" bytes long.

* * The ft_memcmp() function returns 0 if the two strings are identical,
* * otherwise returns the difference between the first two differing bytes
* * (treated as "unsigned char" values, so that eg. '\200' is greater than
* * '\0').
* * Zero-length strings are always identical.

This behaviour is not required by C and portable code should only depend
on the sign of the returned value.
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
* * It copies "n" bytes from memory area "src" to memory area "dst".

* * The memory areas must not overlap.
* * Use ft_memmove() if the memory areas do overlap.

* * The ft_memcpy() function returns a pointer to "dst".
*/
void	*ft_memcpy(void *dst, const void *src, size_t n);

/*
* * It copies "n" bytes from memory area "src" to memory area "dst".

The memory areas may overlap: copying takes place as though the bytes in "src"
are first copied into a temporary array that does not overlap "src" or "dst",
and the bytes are then copied from the temporary array to "dst".
Of course in case of overlaping "src" is possible to change but not before
the copying of the necessary areas to "dst".

* * The ft_memmove() function returns a pointer to "dst".
*/
void	*ft_memmove(void *dst, const void *src, size_t len);

/*
It fills the first "len" bytes of the memory area pointed to by "s"
with the constant byte "c".

The ft_memset() function returns a pointer to the memory area "s".
*/
void	*ft_memset(void *b, int c, size_t len);

/*
It outputs the character "c" to the given file descriptor.
*/
void	ft_putchar_fd(char c, int fd);

/*
It outputs the string "s" to the given file descriptor
followed by a newline.
*/
void	ft_putendl_fd(char *s, int fd);

/*
It outputs the integer "n" to the given file descriptor.

It does this recursively.
*/
void	ft_putnbr_fd(int n, int fd);

/*
It outputs the string "s" to the given file descriptor.
*/
void	ft_putstr_fd(char *s, int fd);

/*
It allocates (with ft_calloc) and returns an array of strings obtained
by splitting "s" using the character "c" as a delimiter.
The array must end with a NULL pointer.

It returns NULL if the allocation fails and frees already allocated memory
iteratively.
*/
char	**ft_split(char const *s, char c);

/**
* * It returns a pointer to the first occurence of the character "c"
* * in the string "s".

It returns NULL if the character is not found. The terminating null byte is
considered part of the string, so that if "c" is specified as '\0', it will
return a pointer to the terminator.
*/
char	*ft_strchr(const char *s, int c);

/**
* * It returns a pointer to a new string which is a duplicate of the string "s1".

Memory for the new string is obtained with malloc(3) and can be freed with
free(3).

On success, the ft_strdup() function returns a pointer to the duplicated string.
It returns NULL if the allocation fails.
*/
char	*ft_strdup(const char *s1);

/*
It applies the function ’f’ on each character of the string passed as argument,
passing its index as first argument.

Each character is passed by address to ’f’ to be modified if necessary.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
* * It allocates (with malloc(3)) and returns a pointer to a new string,
* * which is the result of the concatenation of "s1" and "s2".

It returns NULL if the allocation fails.
*/
char	*ft_strjoin(char const *s1, char const *s2);

/**
* * It appends the NUL-terminated string "src" to the end of "dst".
* * It will append at most "dstsize - ft_strlen(dst) - 1" bytes,
* * NUL-terminating the result.

It guarantees to NUL-terminate the result (as long as there is at least one
byte free in "dst").
A byte for the NUL should be included in "size".

* * The ft_strlcat() function returns the total length of the string it tried
* * to create. This means the initial length of "dst" plus the length of "src".
* * In case of truncation it is the length of "src" plus "size".
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/**
* * It copies up to "dstsize - 1" characters from string "src" to string "dst",
* * NUL-terminating the result if there is room (it should be included in
* * "dstsize").

* * The ft_strlcpy() function returns the total length of the string it tried
* * to create. This means the length of "src".
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
It calculates the length of the string pointed to by "s",
excluding the NUL-terminator.

The ft_strlen() function returns the number of bytes in the string pointed
by "s".
*/
size_t	ft_strlen(const char *s);

/*
It applies the function "f" to each character of the string "s",
and passing its index as first argument to create a new string
(with malloc(3)) resulting from successive applications of "f".

The string created from the successive applications of "f". 
Returns NULL if the allocation fails.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
It compares at most "n" bytes of the two strings "s1" and "s2".

The ft_strncmp() returns the difference in ASCII decimal values of the first
character found to be different between "s1" and "s2" (in the first "n" bytes),
or 0 if no different characters are found.
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
It locates the first occurence of the nul-terminated string "needle"
in the string "haystack", where no more than "len" characters are searched.

Characters that appear after a '\0' character are not searched.

* * If "needle" is an empty string "haystack" is returned; if "needle" occurs
* * nowhere in "haystack", NULL is returned; otherwise a pointer to the first
* * character of the first occurence of "needle" is returned.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/*
It returns a pointer to the last occurence of the character "c"
in the string "s".

It returns NULL if the character is not found. The terminating nul byte is
considered part of the string, so that if "c" is specified as '\0', it will
return a pointer to the terminator.
*/
char	*ft_strrchr(const char *s, int c);

/*
It allocates (with malloc(3)) and returns a copy of "s1" 
with the characters specified in "set" removed from the beginning
and the end of the string.

The ft_strtrim() function returns a pointer to the trimmed string. It returns
NULL if the allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set);

/*
It allocates with "ft_calloc" and returns a substring from the string "s".

The substring begins at index "start" and is of maximum size "len".

It returns NULL if the allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*
It converts an upper-case letter to the corresponding lower-case letter.

The ft_tolower() function returns the corresponding lower-case letter
if the argument is an upper-case letter, otherwise the argument is
returned unchanged.
*/
int		ft_tolower(int c);

/*
It converts a lower-case letter to the corresponding upper-case letter.

The ft_toupper() function returns the corresponding upper-case letter
if the argument is a lower-case letter, otherwise the argument is
returned unchanged.
*/
int		ft_toupper(int c);

// Bonus

/*
It adds the node "new" at the end of the list.
*/
void	ft_lstadd_back(t_list **lst, t_list *new);

/*
It adds the node "new" at the beginning of the list.
*/
void	ft_lstadd_front(t_list **lst, t_list *new);

/*
It deletes and frees the given node and every successor of that node,
using the function ’del’ and free(3).
Finally, the pointer to the list must be set to NULL.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *));

/*
It takes as a parameter a node and frees the memory of the node’s content
using the function "del" given as a parameter and frees the node.
The memory of "next" must not be freed.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/*
It iterates the list "lst" and applies the function "f"
on the content of each node.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *));

/*
It returns a pointer to the last node of the list.
*/
t_list	*ft_lstlast(t_list *lst);

/*
It iterates the list "lst" and applies the function "f" on the content of
each node.
Creates a new list resulting of the successive applications of the function "f".
The "del" function is used to delete the content of a node if needed.

The ft_lstmap() function returns a pointer to the first element of the newly
created list.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*
It allocates (with malloc(3)) and returns a new node.
The member variable "content" is initialized with the value of the parameter
'content'.
The variable "next" is initialized to NULL.
*/
t_list	*ft_lstnew(void *content);

/*
It counts the number of nodes in a list and returns the result.
*/
int		ft_lstsize(t_list *lst);

#endif