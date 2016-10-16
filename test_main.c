#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ds/sll/sll.h"

void sll_destroy(sll_s *sll)
{
    sll_node_s *node = 0;

    while (0 != sll->count)
    {
        node = sll->head.next;
        sll_delete(sll, &sll->head, node);
        free(node);
    }

    return;
}

void test_sll(void)
{
    FILE *File = NULL;
    int data = 0;
    sll_s sll = {0};
    sll_node_s *sll_node = NULL;

    printf("Test sll\n");

    sll_init(&sll);

    File = fopen("sll_input.txt", "r");
    if (NULL== File)
    {
        printf("Can not file sll_input.txt\n");
        return;
    }

    while (feof != fscanf(File, "%d", &data))
    {
        sll_node = (sll_node_s *)malloc(sizeof(sll_node_s));
        if (NULL == sll_node)
        {
            printf("\nCan not malloc sizeof(sll_node_s)");
            break;
        }

        sll_node->handle = (unsigned int)data;
        sll_insert_in_tail(&sll, sll_node);
    }
    fclose(File);

    File = fopen("sll_output.txt", "w");
    if (NULL== File)
    {
        printf("Can not file sll_output.txt\n");
        sll_destroy(&sll);
    }

    fclose(File);

    sll_destroy(&sll);

    return;
}

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        printf("Too many parameters.\n");
        return 0;
    }

    if (0 == strcmp("sll", argv[1]))
    {
        test_sll();
    }
    else if (0 == strcmp("dll", argv[1]))
    {
        //test_dll();
    }
    else if (0 == strcmp("stack", argv[1]))
    {
        //test_stack();
    }
    else if (0 == strcmp("queue", argv[1]))
    {
        //test_stack();
    }
    else if (0 == strcmp("rbtree", argv[1]))
    {
        //test_stack();
    }
    else
    {
        printf("Invalid parameter. Please input: sll, dll, stack,queue, rbtree\n");
    }

    exit(0);
}
