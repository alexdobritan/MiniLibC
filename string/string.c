// SPDX-License-Identifier: BSD-3-Clause
#include <string.h>
char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	int i = 0;
	while (source[i] != '\0') {
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return destination;
}
char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	for (unsigned long i = 0; i < len; i++) {
		destination[i] = source[i];
	}
	return destination;
}
char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int j = 0;
	for (unsigned long i = strlen(destination); i < strlen(destination) + strlen(source); i++) {
		destination[i] = source[j];
		j++;
	}
	return destination;
}
char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	int dest_len = strlen(destination);
    unsigned long i = 0;
    while (i < len && source[i] != '\0') {
        destination[dest_len + i] = source[i];
		i++;
    }
    destination[dest_len + i] = '\0';
    return destination;
}
int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	if (strlen(str1) < strlen(str2)) {
		return -1;
	} else if (strlen(str1) > strlen(str2)) {
		return 1;
	} else {
		for(unsigned long i = 0; i < strlen(str1); i++) {
			if (str1[i] < str2[i]) {
				return -1;
			}
			if (str1[i] > str2[i]) {
				return 1;
			}
		}
	}
	return 0;
}
int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	if (strlen(str1) < strlen(str2) && strlen(str1) < len) {
		return -1;
	} else if (strlen(str1) > strlen(str2) && strlen(str2) < len) {
		return 1;
	} else {
		for(unsigned long i = 0; i < len; i++) {
			if (str1[i] < str2[i]) {
				return -1;
			}
			if (str1[i] > str2[i]) {
				return 1;
			}
		}
	}
	return 0;
}
size_t strlen(const char *str)
{
	size_t i = 0;
	for (; *str != '\0'; str++, i++)
		;
	return i;
}
char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	int str_len = strlen(str);
	for (int i = 0; i < str_len; i++) {
		if (str[i] == c)
			return (char *)&str[i];
	}
	return NULL;
}
char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	int str_len = strlen(str);
	for (int i = str_len; i > 0; i--) {
		if (str[i] == c)
			return (char *)&str[i];
	}
	return NULL;
}
char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);

    for (int i = 0; i < haystack_len - needle_len; i++) {
        if (strncmp(&haystack[i], needle, needle_len) == 0) {
            return (char *)&haystack[i];
        }
    }
	return NULL;
}
char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);

    for (int i = haystack_len - needle_len; i > 0 ; i--) {
        if (strncmp(&haystack[i], needle, needle_len) == 0) {
            return (char *)&haystack[i];
        }
    }
	return NULL;
}
void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *destination_char = (char *)destination;
    const char *source_char = (const char *)source;

    for (unsigned long i = 0; i < num; i++) {
        destination_char[i] = source_char[i];
    }
    return destination;
}
void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *destination_char = destination;
    const char *source_char = source;

    if ((char *)&destination_char == (char *)&source_char) {
        return destination;
    }

    if ((char *)&destination_char < (char *)&source_char) {
        for (size_t i = 0; i < num; i++) {
            destination_char[i] = source_char[i];
        }
    } else {
        for (size_t i = num; i > 0; i--) {
            destination_char[i - 1] = source_char[i - 1];
        }
    }
    return destination;
}
int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char *s1 = (const unsigned char *)ptr1;
    const unsigned char *s2 = (const unsigned char *)ptr2;

    for (unsigned long i = 0; i < num; i++) {
        if (s1[i] < s2[i]) {
            return -1;
        } else if (s1[i] > s2[i]) {
            return 1;
        }
    }
    return 0;
}
void *memset(void *source, int value, size_t num)
{
	unsigned char *source_char = (unsigned char *)source;
    unsigned char val = (unsigned char)value;
    for (size_t i = 0; i < num; i++) {
        source_char[i] = val;
    }
    return source;
}
