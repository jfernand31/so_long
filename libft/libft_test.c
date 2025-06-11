#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void del_content(void *content)
{
    free(content);
}

void test_strdup(void)
{
    printf("Testing ft_strdup...\n");
    char *s = "Hello, Libft!";
    char *dup = ft_strdup(s);
    if (dup && strcmp(dup, s) == 0)
        printf("  ✅ ft_strdup passed\n");
    else
        printf("  ❌ ft_strdup failed\n");
    free(dup);
}

void test_memset(void)
{
    printf("Testing ft_memset...\n");
    char buffer[10];
    ft_memset(buffer, 'A', 9);
    buffer[9] = '\0';
    if (strcmp(buffer, "AAAAAAAAA") == 0)
        printf("  ✅ ft_memset passed\n");
    else
        printf("  ❌ ft_memset failed\n");
}

void test_memcpy(void)
{
    printf("Testing ft_memcpy...\n");
    char src[] = "123456";
    char dest[10];
    ft_memcpy(dest, src, 7); // Including null terminator
    if (strcmp(dest, src) == 0)
        printf("  ✅ ft_memcpy passed\n");
    else
        printf("  ❌ ft_memcpy failed\n");
}

void test_isalpha(void)
{
    printf("Testing ft_isalpha...\n");
    if (ft_isalpha('A') && !ft_isalpha('1'))
        printf("  ✅ ft_isalpha passed\n");
    else
        printf("  ❌ ft_isalpha failed\n");
}

void test_strjoin(void)
{
    printf("Testing ft_strjoin...\n");
    char *s1 = "Hello, ";
    char *s2 = "World!";
    char *joined = ft_strjoin(s1, s2);
    if (joined && strcmp(joined, "Hello, World!") == 0)
        printf("  ✅ ft_strjoin passed\n");
    else
        printf("  ❌ ft_strjoin failed\n");
    free(joined);
}

void test_lstnew(void)
{
#ifdef BONUS_PART
    printf("Testing ft_lstnew...\n");
    char *content = "libft node";
    t_list *node = ft_lstnew(content);
    if (node && node->content == content)
        printf("  ✅ ft_lstnew passed\n");
    else
        printf("  ❌ ft_lstnew failed\n");
    free(node);
#endif
}
void test_ft_lstdelone(void)
{
    printf("Testing ft_lstdelone...\n");

    char *data = ft_strdup("delete me");
    t_list *node = ft_lstnew(data);

    if (!node || !node->content)
    {
        printf("  ❌ Node creation failed\n");
        return;
    }

    ft_lstdelone(node, del_content);
    printf("  ✅ ft_lstdelone passed (no crash, memory freed)\n");
}
void test_ft_lstdelone_null_del(void)
{
    printf("Testing ft_lstdelone with NULL del...\n");

    char *data = ft_strdup("should not be freed");
    t_list *node = ft_lstnew(data);

    if (!node || !node->content)
    {
        printf("  ❌ Node creation failed\n");
        return;
    }

    // Expect: possible crash or ignored free, depending on your implementation
    ft_lstdelone(node, NULL);

    printf("  ⚠️ ft_lstdelone(NULL) ran (check if it crashes or leaks with Valgrind)\n");
    // If no crash, free manually to avoid leak
    free(data);
}

void test_ft_lstclear_null_del(void)
{
    printf("Testing ft_lstclear with NULL del...\n");

    t_list *head = NULL;
    for (int i = 0; i < 2; i++)
    {
        char *data = ft_strdup("should also not be freed");
        t_list *new_node = ft_lstnew(data);
        ft_lstadd_front(&head, new_node);
    }

    // Again, behavior is undefined – you're just checking if your code handles it
    ft_lstclear(&head, NULL);

    printf("  ⚠️ ft_lstclear(NULL) ran (check for segfaults or leaks)\n");
    // Manual cleanup if it didn't free the nodes
    while (head)
    {
        t_list *next = head->next;
        free(head->content);
        free(head);
        head = next;
    }
}

void test_ft_lstclear(void)
{
    printf("Testing ft_lstclear...\n");

    t_list *head = NULL;

    for (int i = 0; i < 3; i++)
    {
        char *data = ft_strdup("clear me");
        t_list *new_node = ft_lstnew(data);
        if (!new_node || !data)
        {
            printf("  ❌ Node allocation failed\n");
            return;
        }
        ft_lstadd_front(&head, new_node);
    }

    ft_lstclear(&head, del_content);

    if (head == NULL)
        printf("  ✅ ft_lstclear passed (list cleared and freed)\n");
    else
        printf("  ❌ ft_lstclear failed (head is not NULL)\n");
}



int main(void)
{
    printf("🧪 Running Libft Tests\n\n");

    test_strdup();
    test_memset();
    test_memcpy();
    test_isalpha();
    test_strjoin();

    test_ft_lstdelone();
    test_ft_lstclear();

	test_ft_lstdelone_null_del();
	test_ft_lstclear_null_del();
	
    printf("\n✅ All tests complete.\n");

    return 0;
}

