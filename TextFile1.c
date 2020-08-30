/*author: Sundarpandian*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char data;
    struct node* next;
};
void creating_list(int length, char* argv);
typedef struct node snode;
snode* create_newnode(char value);
snode* First_node, * Last_node, * traverse_node, * new_node;
int main(int argc, char* argv[])
{
    int iterator;
    if (argc >= 2)
    {
        for(iterator=1;iterator<argc;iterator++)
        {
            char* ptr; 
            char *del = " ";
            //split the white spaces
            ptr = strtok(argv[iterator], del);
            while(ptr != NULL)
            {
               int length = strlen(ptr);
               creating_list(length,ptr);
               ptr = strtok(NULL,del);
            }
        }

    }
    return 0;
}
void creating_list(int length, char* ptr)
{
    int iterator,iterator1; 
    iterator1 = 1;
    char copy[20];
    First_node = (snode*)malloc(sizeof(snode));
    First_node->data = *(ptr);
    First_node->next = NULL;
    if (length > 1)
    {
        Last_node = (snode*)malloc(sizeof(snode));
        Last_node = First_node;
        for (iterator = 1;iterator < length;iterator++)
        {
            new_node = create_newnode(*(ptr+iterator));
            Last_node->next = new_node;
            Last_node = new_node;
            Last_node->next = NULL;
        }
        traverse_node = First_node;
        do
        {
            copy[iterator1] = traverse_node->data;
            traverse_node = traverse_node->next;
            iterator1++;
        }while(traverse_node->next != NULL);
        //to store the data of last node
        copy[iterator1] = traverse_node->data;
        //print it in reverse
        do
        {
            printf("%c",copy[iterator1]);
            iterator1--;
        }while(iterator1 != 0);
        printf("\n");
    }
    else if(length==1)
    {
        //if the node has single entry
        printf("%c\n",First_node->data);
    }
}
snode* create_newnode(char value)
{
    new_node = (snode*)malloc(sizeof(snode));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}
