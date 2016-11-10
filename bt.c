#include <stdio.h>
#include <stdlib.h>

struct node {
	double key_value; 
	struct node *left;
	struct node *right;
};

void destroy_tree(struct node *leaf)
{
  if( leaf != 0 )
  {
      destroy_tree(leaf->left);
      destroy_tree(leaf->right);
      free( leaf );
  }
}

void insert(int key, struct node **leaf)
{
    if( *leaf == 0 )
    {
        *leaf = (struct node*) malloc( sizeof( struct node ) );
        (*leaf)->key_value = key;
        /* initialize the children to null */
        (*leaf)->left = 0;    
        (*leaf)->right = 0;  
    }
    else if(key < (*leaf)->key_value)
    {
        insert( key, &(*leaf)->left );
    }
    else if(key > (*leaf)->key_value)
    {
        insert( key, &(*leaf)->right );
    }
}

struct node *search(int key, struct node *leaf)
{
  if( leaf != 0 )
  {
      if(key==leaf->key_value)
      {
          return leaf;
      }
      else if(key<leaf->key_value)
      {
          return search(key, leaf->left);
      }
      else
      {
          return search(key, leaf->right);
      }
  }
  else return 0;
}

void print_tree(struct node *leaf) 
{
  if( leaf != 0 )
  {
      print_tree(leaf->left);
      print_tree(leaf->right);
      printf("%f\n", leaf->key_value);
  }
}


int main(void)
{
    int a = 4;
    int b = 7;

    struct node *root = 0;
    printf("root created!\n");

    for(int i = 0; i < 10; i++) {
    	insert(i, &root);
    }

    print_tree(root);

	printf("exit\n");
    return 0;
}