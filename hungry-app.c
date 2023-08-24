// BT21CSE039 - VEDANT BHUKTE - DSPD ASSIGNMENT 2
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define SIZE 10

typedef struct date_tag
{
	int day, mon, year;
	int hr, min;
}date;

typedef struct fav_food_tag
{
	char name[100];
	int count;
}fav;

typedef struct area_tag
{
	char area_name[80];
	char area_around[2][80];
	struct area_tag  *left;
  	struct area_tag  *right;
  	int height;
}area;

typedef struct agent_tag
{
	int agent_id;
	char name[100];
	char area_assigned[100];
	int phone_no;
	int current_acc_comm;
	int status;
	struct agent_tag  *left;
  	struct agent_tag  *right;
  	int height;	
}agent;

typedef struct order_tag
{
	int order_id;
	int customer_id;
	char customer_name[100];
	char address[200];
	int phone_no;
	date d;
	char rest_name[80];
	char rest_add[200];
	char item_name[100];
	agent * agent_assigned;
	int quantity;
	int price;
	struct order_tag  *left;
  	struct order_tag  *right;
  	int height;
}order;

typedef struct food_tag
{
	char name[200];
	int price;
	
	struct food_tag  *left;
  	struct food_tag  *right;
  	int height;	
}food;

typedef struct restaurant_tag
{
	char name[200];
	char address[200];
	int num_seats;
	char type[20];
	food * menu[5];
	struct restaurant_tag *left;
  	struct restaurant_tag *right;
  	int height;
}restaurant;

typedef struct user_tag
{
	int user_id;
	char name[100];
	char address[200];
	int phone_no;
	int num_order;
	order * order_history;
	struct user_tag *left;
  	struct user_tag *right;
  	int height;
}user;

// Height & Balance Factor

int height_rest(restaurant * n) 
{
	int retval=0;
	if( n != NULL )
	{
		retval = n->height;
	}
	return retval;
}
int height_agent(agent * n) 
{
	int retval=0;
	if( n != NULL )
	{
		retval = n->height;
	}
	return retval;
}
int height_order(order * n) 
{
	int retval=0;
	if( n != NULL )
	{
		retval = n->height;
	}
	return retval;
}
int height_user(user * n) 
{
	int retval=0;
	if( n != NULL )
	{
		retval = n->height;
	}
	return retval;
}
int height_area(area * n) 
{
	int retval=0;
	if( n != NULL )
	{
		retval = n->height;
	}
	return retval;
}
int height_food(food * n) 
{
	int retval=0;
	if( n != NULL )
	{
		retval = n->height;
	}
	return retval;
}
int max(int a, int b) 
{
	int retval=a;
	if( a < b )
	{
		retval=b;
	}
	return retval;
}
int getBalance_rest(restaurant * n) 
{
	int retval=0;
	if( n != NULL )
	{
		retval = height_rest(n->left) - height_rest(n->right);
	}
	return retval;
}
int getBalance_agent(agent * n) 
{
	int retval=0;
	if( n != NULL )
	{
		retval = height_agent(n->left) - height_agent(n->right);
	}
	return retval;
}
int getBalance_order(order * n) 
{
	int retval=0;
	if( n != NULL )
	{
		retval = height_order(n->left) - height_order(n->right);
	}
	return retval;
}
int getBalance_user(user * n) 
{
	int retval=0;
	if( n != NULL )
	{
		retval = height_user(n->left) - height_user(n->right);
	}
	return retval;
}
int getBalance_area(area * n) 
{
	int retval=0;
	if( n != NULL )
	{
		retval = height_area(n->left) - height_area(n->right);
	}
	return retval;
}
int getBalance_food(food * n) 
{
	int retval=0;
	if( n != NULL )
	{
		retval = height_food(n->left) - height_food(n->right);
	}
	return retval;
}

// Rotate right

restaurant * rightRotate_rest(restaurant *x) 
{
	restaurant* y;
	if( x == NULL )
	{
		printf("\nError : Node doesn't exist. (rightRotate_rest) ");
	}
	else if( x->left == NULL )
	{
		printf("\nError : Left Child of Node doesn't exist. (rightRotate_rest)");
	}
	else
	{
		y=x->left;
		x->left=y->right;
		y->right=x;
		
		x->height = max(height_rest(x->left), height_rest(x->right)) + 1;
		y->height = max(height_rest(y->left), height_rest(y->right)) + 1;
	}
	return y;
}
agent * rightRotate_agent(agent *x) 
{
	agent* y;
	if( x == NULL )
	{
		printf("\nError : Node doesn't exist. (rightRotate_agent) ");
	}
	else if( x->left == NULL )
	{
		printf("\nError : Left Child of Node doesn't exist. (rightRotate_agent)");
	}
	else
	{
		y=x->left;
		x->left=y->right;
		y->right=x;
		
		x->height = max(height_agent(x->left), height_agent(x->right)) + 1;
		y->height = max(height_agent(y->left), height_agent(y->right)) + 1;
	}
	return y;
}
order * rightRotate_order(order *x) 
{
	order* y;
	if( x == NULL )
	{
		printf("\nError : Node doesn't exist. (rightRotate_order) ");
	}
	else if( x->left == NULL )
	{
		printf("\nError : Left Child of Node doesn't exist. (rightRotate_order)");
	}
	else
	{
		y=x->left;
		x->left=y->right;
		y->right=x;
		
		x->height = max(height_order(x->left), height_order(x->right)) + 1;
		y->height = max(height_order(y->left), height_order(y->right)) + 1;
	}
	return y;
}
user * rightRotate_user(user *x) 
{
	user* y;
	if( x == NULL )
	{
		printf("\nError : Node doesn't exist. (rightRotate_user) ");
	}
	else if( x->left == NULL )
	{
		printf("\nError : Left Child of Node doesn't exist. (rightRotate_user)");
	}
	else
	{
		y=x->left;
		x->left=y->right;
		y->right=x;
		
		x->height = max(height_user(x->left), height_user(x->right)) + 1;
		y->height = max(height_user(y->left), height_user(y->right)) + 1;
	}
	return y;
}
area * rightRotate_area(area *x) 
{
	area* y;
	if( x == NULL )
	{
		printf("\nError : Node doesn't exist. (rightRotate_area) ");
	}
	else if( x->left == NULL )
	{
		printf("\nError : Left Child of Node doesn't exist. (rightRotate_area)");
	}
	else
	{
		y=x->left;
		x->left=y->right;
		y->right=x;
		
		x->height = max(height_area(x->left), height_area(x->right)) + 1;
		y->height = max(height_area(y->left), height_area(y->right)) + 1;
	}
	return y;
}
food * rightRotate_food(food *x) 
{
	food* y;
	if( x == NULL )
	{
		printf("\nError : Node doesn't exist. (rightRotate_food) ");
	}
	else if( x->left == NULL )
	{
		printf("\nError : Left Child of Node doesn't exist. (rightRotate_food)");
	}
	else
	{
		y=x->left;
		x->left=y->right;
		y->right=x;
		
		x->height = max(height_food(x->left), height_food(x->right)) + 1;
		y->height = max(height_food(y->left), height_food(y->right)) + 1;
	}
	return y;
}

// Rotate Left

restaurant * leftRotate_rest(restaurant *x) 
{
	restaurant* y;
	if( x == NULL )
	{
		printf("\nError : Node doesn't exist. (leftRotate_rest) ");
	}
	else if( x->right == NULL )
	{
		printf("\nError : Right Child of Node doesn't exist. (leftRotate_rest)");
	}
	else
	{
		y=x->right;
		x->right=y->left;
		y->left=x;
		
		x->height = max(height_rest(x->left), height_rest(x->right)) + 1;
		y->height = max(height_rest(y->left), height_rest(y->right)) + 1;
	}
	return y;
}
agent * leftRotate_agent(agent *x) 
{
	agent* y;
	if( x == NULL )
	{
		printf("\nError : Node doesn't exist. (leftRotate_agent) ");
	}
	else if( x->right == NULL )
	{
		printf("\nError : Right Child of Node doesn't exist. (leftRotate_agent)");
	}
	else
	{
		y=x->right;
		x->right=y->left;
		y->left=x;
		
		x->height = max(height_agent(x->left), height_agent(x->right)) + 1;
		y->height = max(height_agent(y->left), height_agent(y->right)) + 1;
	}
	return y;
}
order * leftRotate_order(order *x) 
{
	order* y;
	if( x == NULL )
	{
		printf("\nError : Node doesn't exist. (leftRotate_order) ");
	}
	else if( x->right == NULL )
	{
		printf("\nError : Right Child of Node doesn't exist. (leftRotate_order)");
	}
	else
	{
		y=x->right;
		x->right=y->left;
		y->left=x;
		
		x->height = max(height_order(x->left), height_order(x->right)) + 1;
		y->height = max(height_order(y->left), height_order(y->right)) + 1;
	}
	return y;
}
user * leftRotate_user(user *x) 
{
	user* y;
	if( x == NULL )
	{
		printf("\nError : Node doesn't exist. (leftRotate_user) ");
	}
	else if( x->right == NULL )
	{
		printf("\nError : Right Child of Node doesn't exist. (leftRotate_user)");
	}
	else
	{
		y=x->right;
		x->right=y->left;
		y->left=x;
		
		x->height = max(height_user(x->left), height_user(x->right)) + 1;
		y->height = max(height_user(y->left), height_user(y->right)) + 1;
	}
	return y;
}
area * leftRotate_area(area *x) 
{
	area* y;
	if( x == NULL )
	{
		printf("\nError : Node doesn't exist. (leftRotate_area) ");
	}
	else if( x->right == NULL )
	{
		printf("\nError : Right Child of Node doesn't exist. (leftRotate_area)");
	}
	else
	{
		y=x->right;
		x->right=y->left;
		y->left=x;
		
		x->height = max(height_area(x->left), height_area(x->right)) + 1;
		y->height = max(height_area(y->left), height_area(y->right)) + 1;
	}
	return y;
}
food * leftRotate_food(food *x) 
{
	food* y;
	if( x == NULL )
	{
		printf("\nError : Node doesn't exist. (leftRotate_food) ");
	}
	else if( x->right == NULL )
	{
		printf("\nError : Right Child of Node doesn't exist. (leftRotate_food)");
	}
	else
	{
		y=x->right;
		x->right=y->left;
		y->left=x;
		
		x->height = max(height_food(x->left), height_food(x->right)) + 1;
		y->height = max(height_food(y->left), height_food(y->right)) + 1;
	}
	return y;
}

// Insert node

restaurant * insertNode_rest(restaurant *rest_head, restaurant * node) 
{
  	restaurant * ret_val=rest_head;
	if (rest_head == NULL)
	{
		ret_val = node;
	}
	else
	{
		if( strcmp(node->name, rest_head->name) < 0 )
		{
			rest_head->left = insertNode_rest(rest_head->left, node);
		}
		else if( strcmp(node->name, rest_head->name) > 0 )
		{
			rest_head->right = insertNode_rest(rest_head->right, node);
		}
		else
		{
			printf("\n Node already present in restaurant. ");
			ret_val=rest_head;
		}
		
		rest_head->height = 1 + max(height_rest(rest_head->left), height_rest(rest_head->right));
	
		int balance = getBalance_rest(rest_head);
		if( balance > 1 && strcmp(node->name, rest_head->left->name) < 0)
		{
			//printf("\nRR");
			ret_val=rightRotate_rest(rest_head);
		}
    	else if( balance > 1 && strcmp(node->name, rest_head->left->name) > 0)
    	{
    		//printf("\nLR");
    		rest_head->left = leftRotate_rest(rest_head->left);  
    		ret_val=rightRotate_rest(rest_head);
		}
		else if( balance < -1 && strcmp(node->name, rest_head->right->name) > 0)
		{
			//printf("\nLL");
			ret_val=leftRotate_rest(rest_head);
		}
		else if( balance < -1 && strcmp(node->name, rest_head->right->name) < 0)
		{
			//printf("\nRL");
			rest_head->right = rightRotate_rest(rest_head->right);  
			ret_val=leftRotate_rest(rest_head);
		}
		
	}
	return ret_val;
}
agent * insertNode_agent(agent *agent_head, agent * node) 
{
  	agent * ret_val=agent_head;
	if (agent_head == NULL)
	{
		ret_val = node;
	}
	else
	{
		if( node->agent_id < agent_head->agent_id )
		{
			agent_head->left = insertNode_agent(agent_head->left, node);
		}
		else if(node->agent_id > agent_head->agent_id )
		{
			agent_head->right = insertNode_agent(agent_head->right, node);
		}
		else
		{
			printf("\n Node already present in agent. ");
			ret_val=agent_head;
		}
		
    	agent_head->height = 1 + max(height_agent(agent_head->left), height_agent(agent_head->right));

		int balance = getBalance_agent(agent_head);
		
		if( balance > 1 && node->agent_id < agent_head->agent_id )
		{
			ret_val=rightRotate_agent(agent_head);
		}
	    else if( balance > 1 && node->agent_id > agent_head->agent_id )
	    {	
			agent_head->left = leftRotate_agent(agent_head->left);    
   		 	ret_val=rightRotate_agent(agent_head);
		}
		else if( balance < -1 && node->agent_id > agent_head->agent_id )
		{		
			ret_val=leftRotate_agent(agent_head);
		}
		else if( balance < -1 && node->agent_id < agent_head->agent_id )
		{
			agent_head->right = rightRotate_agent(agent_head->right); 
			ret_val=leftRotate_agent(agent_head);
		}
	} 
	return ret_val;
}
order * insertNode_order(order *order_head, order * node) 
{
  	order * ret_val=order_head;
	if (order_head == NULL)
	{
		ret_val = node;
	}
	else
	{
		if( node->order_id < order_head->order_id )
		{
			order_head->left = insertNode_order(order_head->left, node);
		}
		else if(node->order_id > order_head->order_id )
		{
			order_head->right = insertNode_order(order_head->right, node);
		}
		else
		{
			printf("\n Node already present in Order. ");
			ret_val=order_head;
		}
		
    	order_head->height = 1 + max(height_order(order_head->left), height_order(order_head->right));

		int balance = getBalance_order(order_head);
		
		if( balance > 1 && node->order_id < order_head->left->order_id )
		{
			ret_val=rightRotate_order(order_head);
		}
	    else if( balance > 1 && node->order_id > order_head->left->order_id )
	    {	
			order_head->left = leftRotate_order(order_head->left);    
   		 	ret_val=rightRotate_order(order_head);
		}
		else if( balance < -1 && node->order_id > order_head->right->order_id )
		{		
			ret_val=leftRotate_order(order_head);
		}
		else if( balance < -1 && node->order_id < order_head->right->order_id )
		{
			order_head->right = rightRotate_order(order_head->right); 
			ret_val=leftRotate_order(order_head);
		}
	} 
	return ret_val;
}
food * insertNode_food(food *food_head, food * node) 
{
  	food * ret_val=food_head;
  	
	if (food_head == NULL)
	{
		ret_val = node;
	}
	else
	{
		if( strcmp(node->name, food_head->name) < 0 )
		{
			food_head->left = insertNode_food(food_head->left, node);
		}
		else if( strcmp(node->name, food_head->name) > 0 )
		{
			food_head->right = insertNode_food(food_head->right, node);
		}
		else
		{
			printf("\n Node already present in food. ");
			ret_val=food_head;
		}
		
		
    	food_head->height = 1 + max(height_food(food_head->left), height_food(food_head->right));
		//printf("\n  %d", food_head->height);
		int balance = getBalance_food(food_head);
		//printf("\n  %d", balance);
		if( balance > 1 && strcmp(node->name, food_head->left->name) < 0)
		{
			//printf("\nRR");
			ret_val=rightRotate_food(food_head);
		}
    	else if( balance > 1 && strcmp(node->name, food_head->left->name) > 0)
    	{
    		food_head->left = leftRotate_food(food_head->left);
    		//printf("\nLR");
    		ret_val=rightRotate_food(food_head);
		}
		else if( balance < -1 && strcmp(node->name, food_head->right->name) > 0)
		{
			//printf("\nLL");
			ret_val=leftRotate_food(food_head);
		}
		else if( balance < -1 && strcmp(node->name, food_head->right->name) < 0)
		{
			food_head->right = rightRotate_food(food_head->right);
			//printf("\nRL");
			ret_val=leftRotate_food(food_head);
		}
	}
    
	return ret_val;
}
area * insertNode_area(area *area_head, area * node) 
{
  	area * ret_val=area_head;
	if (area_head == NULL)
	{
		ret_val = node;
	}
	else
	{
		if( strcmp(node->area_name, area_head->area_name) < 0 )
		{
			area_head->left = insertNode_area(area_head->left, node);
		}
		else if( strcmp(node->area_name, area_head->area_name) > 0 )
		{
			area_head->right = insertNode_area(area_head->right, node);
		}
		else
		{
			printf("\n Node already present in area. ");
			ret_val=area_head;
		}
		
		area_head->height = 1 + max(height_area(area_head->left), height_area(area_head->right));
	
		int balance = getBalance_area(area_head);
		if( balance > 1 && strcmp(node->area_name, area_head->left->area_name) < 0)
		{
			//printf("\nRR");
			ret_val=rightRotate_area(area_head);
		}
    	else if( balance > 1 && strcmp(node->area_name, area_head->left->area_name) > 0)
    	{
    		//printf("\nLR");
    		area_head->left = leftRotate_area(area_head->left);  
    		ret_val=rightRotate_area(area_head);
		}
		else if( balance < -1 && strcmp(node->area_name, area_head->right->area_name) > 0)
		{
			//printf("\nLL");
			ret_val=leftRotate_area(area_head);
		}
		else if( balance < -1 && strcmp(node->area_name, area_head->right->area_name) < 0)
		{
			//printf("\nRL");
			area_head->right = rightRotate_area(area_head->right);  
			ret_val=leftRotate_area(area_head);
		}
		
	}
	return ret_val;
}
user * insertNode_user(user *user_head, user * node) 
{
  	user * ret_val=user_head;
	if (user_head == NULL)
	{
		ret_val = node;
	}
	else
	{
		if( node->user_id < user_head->user_id )
		{
			user_head->left = insertNode_user(user_head->left, node);
		}
		else if(node->user_id > user_head->user_id )
		{
			user_head->right = insertNode_user(user_head->right, node);
		}
		else
		{
			printf("\n Node already present in User. ");
			ret_val=user_head;
		}
		
    	user_head->height = 1 + max(height_user(user_head->left), height_user(user_head->right));

		int balance = getBalance_user(user_head);
		
		if( balance > 1 && node->user_id < user_head->user_id )
		{
			ret_val=rightRotate_user(user_head);
		}
	    else if( balance > 1 && node->user_id > user_head->user_id )
	    {	
			user_head->left = leftRotate_user(user_head->left);    
   		 	ret_val=rightRotate_user(user_head);
		}
		else if( balance < -1 && node->user_id > user_head->user_id )
		{		
			ret_val=leftRotate_user(user_head);
		}
		else if( balance < -1 && node->user_id < user_head->user_id )
		{
			user_head->right = rightRotate_user(user_head->right); 
			ret_val=leftRotate_user(user_head);
		}
	} 
	return ret_val;
}

// print functions 

void printPreOrder_food(food *root) 
{
	if (root != NULL) 
	{
		printf("\n Item : %s Price : %d", root->name, root->price);
    	printPreOrder_food(root->left);
    	printPreOrder_food(root->right);
	}
}
void printPreOrder_rest(restaurant * root)
{
	if( root != NULL )
	{
		printf("\nRestaurant name: %s", root->name);
		printf("Restaurant address: %s", root->address);
		printf("Seats : %d", root->num_seats);
		printf("\nRestaurant type: %s", root->type);
		
		int i;
		printf("\nMenu : ");
		for(i=0; i<5; i++)
		{
			printPreOrder_food(root->menu[i]);
		}
		printf("\n\n");
		printPreOrder_rest(root->left);
    	printPreOrder_rest(root->right);
	}
}
void printPreOrder_agent(agent *root) 
{
	if (root != NULL) 
	{
		printf("\nAgent id: %d", root->agent_id);
		printf("\nAgent name: %s", root->name);
		printf("Area assigned : %s", root->area_assigned);
		printf("Agent Phone no : %d", root->phone_no);
		printf("\nAgent's current acc comm. : %d", root->current_acc_comm);
		printf("\nAgent's status : %d", root->status);
		
		printf("\n\n");
    	printPreOrder_agent(root->left);
    	printPreOrder_agent(root->right);
	}
}
void printPreOrder_area(area *root) 
{
	if( root != NULL )
	{
		printf("\nArea : %s ", root->area_name);
		printf("Nearby Area 1 : %s ", root->area_around[0]);
		printf("Nearby Area 2 : %s ", root->area_around[1]);
		
		printf("\n\n");
    	printPreOrder_area(root->left);
    	printPreOrder_area(root->right);
	}
}
void printPreOrder_order(order *root) 
{
	if( root != NULL )
	{
		printf("\nOrder id : %d", root->order_id);
		printf("\nrestaurant name : %s", root->rest_name);
		printf("restaurant address : %s", root->rest_add);
		printf("Order date & time : %d-%d-%d %d:%d", root->d.day, root->d.mon, root->d.year ,root->d.hr, root->d.min);
		printf("\n Item name : %s", root->item_name);
		printf(" Quantity : %d", root->quantity);
		printf("\n Price : %d", root->price);
		
    	printPreOrder_order(root->left);
    	printPreOrder_order(root->right);
	}
}
void printPreOrder_glob_order(order *root) 
{
	if( root != NULL )
	{
		printf("\nOrder id : %d", root->order_id);
		printf("\nUser name : %s", root->customer_name);
		printf("User id : %d", root->customer_id);
		printf("\nUser address : %s", root->address);
		printf("User phone-no : %d", root->phone_no);
		printf("\nrestaurant name : %s", root->rest_name);
		printf("restaurant address : %s", root->rest_add);
		printf("Order date & time : %d-%d-%d %d:%d", root->d.day, root->d.mon, root->d.year ,root->d.hr, root->d.min);
		printf("\n Item name : %s", root->item_name);
		printf(" Quantity : %d", root->quantity);
		printf("\n Price : %d", root->price);
		
		printf("\n\n");
    	printPreOrder_glob_order(root->left);
    	printPreOrder_glob_order(root->right);
	}
}
void printPreOrder_user(user *root) 
{
	if( root != NULL )
	{
		printf("\nUser id : %d", root->user_id);
		printf("\nUser name : %s", root->name);
		printf("User address : %s", root->address);
		printf("User phone-no : %d", root->phone_no);
		
		printf("\n\n Previous orders :");
		printPreOrder_order(root->order_history);
		
		printf("\n\n");
    	printPreOrder_user(root->left);
    	printPreOrder_user(root->right);
	}
}
void print_agent_in_area( area * a, agent * agent_root)
{
	if(agent_root != NULL)
	{
		if(strcmp(agent_root->area_assigned, a->area_name)==0 || strcmp(agent_root->area_assigned, a->area_around[0])==0 || strcmp(agent_root->area_assigned, a->area_around[1])==0)
		{
			printf("\nAgent id: %d", agent_root->agent_id);
			printf("\nAgent name: %s", agent_root->name);
		}
		print_agent_in_area(a, agent_root->left);
		print_agent_in_area(a, agent_root->right);
	}
}
void print_area_wise_agents(area * area_root, agent * agent_root)
{
	if( area_root != NULL )
	{
		printf("\n For Area and nearby : %s", area_root->area_name);
		print_agent_in_area(area_root, agent_root);
		
		print_area_wise_agents(area_root->left, agent_root);
		print_area_wise_agents(area_root->right, agent_root);
	}
}
int print_rest_details(restaurant * root, char * name, char * add)
{
	int retval=0;
	
	if( root != NULL )
	{
		if( strcmp(root->name, name)==0 && strcmp(root->address, add)==0 )
		{
			retval=1;
			printf("\nRestaurant name: %s", root->name);
			printf("Restaurant address: %s", root->address);
			printf("Seats : %d", root->num_seats);
			printf("\nRestaurant type: %s", root->type);
			
			int i;
			printf("\nMenu : ");
			for(i=0; i<5; i++)
			{
				printPreOrder_food(root->menu[i]);
			}
			printf("\n\n");
		}
		else
		{
			retval=print_rest_details(root->left, name, add);
			if(retval != 1)
			{
				retval=print_rest_details(root->right, name, add);
			}
		}
	}
	return retval;
}

// Search functions 

void find_nearby_area(area * root, char * a, char * a1, char * a2)
{
	if( root != NULL )
	{
		if( strcmp(a, root->area_name) != 0)
		{
			if( strcmp(a, root->area_name) < 0)
			{
				find_nearby_area(root->left, a, a1, a2);
			}
			else
			{
				find_nearby_area(root->right, a, a1, a2);
			}
		}
		else
		{
			strcpy(a1, root->area_around[0]);
			strcpy(a2, root->area_around[1]);
		}
	}
}
void print_rest_on_cat(restaurant * root, int n)
{
	if( root != NULL )
	{
		if( root->menu[n] != NULL)
		{
			printf("\nRestaurant name: %s", root->name);
			printf("Restaurant address: %s", root->address);
			printf("Seats : %d", root->num_seats);
			printf("\nRestaurant type: %s", root->type);
			printf("\nMenu : ");
			printPreOrder_food(root->menu[n]);
			
			printf("\n\n");
		}
		print_rest_on_cat(root->left, n);
    	print_rest_on_cat(root->right, n);
	}
}
void find_on_food_category(restaurant * root, char * s)
{
	int i;
	if(strcmp(s,"north indian")==0)
	{
		i=0;
	}
	else if(strcmp(s,"south indian")==0)
	{
		i=1;
	}
	else if(strcmp(s,"continental")==0)
	{
		i=2;
	}
	else if(strcmp(s,"chinese")==0)
	{
		i=3;
	}
	else 
	{
		i=4;
	}
	print_rest_on_cat(root, i);
}
void find_on_type(restaurant * root, char * s)
{
	if( root != NULL )
	{
		if( strcmp(s, root->type) == 0)
		{
			
			printf("\nRestaurant name: %s", root->name);
			printf("Restaurant address: %s", root->address);
			printf("Seats : %d", root->num_seats);
			printf("\nRestaurant type: %s", root->type);
				
			int i;
			printf("\nMenu : ");
			for(i=0; i<5; i++)
			{
				printPreOrder_food(root->menu[i]);
			}
			printf("\n\n");
		}
		find_on_type(root->left, s);
    	find_on_type(root->right, s);
	}
}
void print_nearby_rest(restaurant * root, char * a, char * a1, char * a2)
{
	if( root != NULL )
	{
		if( strcmp(a,root->address)==0 || strcmp(a1,root->address)==0 || strcmp(a2,root->address)==0)
		{
			printf("\nRestaurant name: %s", root->name);
			printf("Restaurant address: %s", root->address);
			printf("Seats : %d", root->num_seats);
			printf("\nRestaurant type: %s", root->type);
				
			int i;
			printf("\nMenu : ");
			for(i=0; i<5; i++)
			{
				printPreOrder_food(root->menu[i]);
			}
			printf("\n\n");
		}
		print_nearby_rest(root->left, a, a1, a2);
    	print_nearby_rest(root->right, a, a1, a2);
	}
}
void find_on_area(restaurant * rest_root, area * area_root, char * a)
{
	char a1[100], a2[100];
	a=strcat(a,"\n");
	a1[0]='\0';
	a2[0]='\0';
	find_nearby_area(area_root, a, a1, a2);
	//printf("\n %s %s %s", a, a1, a2);
	print_nearby_rest(rest_root, a, a1, a2);
}

// Order function

int find_agent(agent * root, order * o, char * a, char * a1, char * a2)
{
	int retval=0;
	if( root != NULL )
	{
		if((strcmp(a,root->area_assigned)==0 || strcmp(a1,root->area_assigned)==0 || strcmp(a2,root->area_assigned)==0) && root->status==0)
		{
			o->agent_assigned=root;
			root->status=1;
			retval=1;
		}
		else
		{
			retval=find_agent(root->left, o, a, a1, a2);
			if(retval != 1)
			{
				retval=find_agent(root->right, o, a, a1, a2);
			}
		}
	}
	return retval;
}
void order_fun(area * area_root, agent * agent_root, order * o)
{
	char a1[200], a2[200];
	find_nearby_area(area_root, o->rest_add, a1, a2);
	//printf("\n %s %s %s",  o->rest_add, a1, a2);
	find_agent(agent_root, o, o->rest_add, a1, a2);
	
	if(o->agent_assigned != NULL)
	{
		printf("\nOrder Details :- \n");
		printf("\nOrder id : %d", o->order_id);
		printf("\nCustomer name : %s", o->customer_name);
		printf("Customer address : %s", o->address);
		printf("Customer phone-no : %d", o->phone_no);
		printf("\nrestaurant name : %s", o->rest_name);
		printf("restaurant address : %s", o->rest_add);
		printf("Order date & time : %d-%d-%d %d:%d", o->d.day, o->d.mon, o->d.year ,o->d.hr, o->d.min);
		printf("\n Item name : %s", o->item_name);
		printf(" Quantity : %d", o->quantity);
		printf("\n Price : %d\n", o->price);
		
		agent * agent_head=o->agent_assigned;	
		printf("\nAgent Details : ");
		printf("\nAgent id: %d", agent_head->agent_id);
		printf("\nAgent name: %s", agent_head->name);
		//printf("Area assigned : %s", agent_head->area_assigned);
		printf("Agent Phone no : %d", agent_head->phone_no);
		printf("\nAgent's current acc comm. : %d", agent_head->current_acc_comm);
	   	//printf("\nAgent's status : %d", agent_head->status);
		
		printf("\n\n");
	}
	else
	{
		printf("\nNo agent availabe for delivery for order number - %d\n",o->order_id);
	}
}
void order_all(order * o, area * area_root, agent * agent_root)
{
	if( o != NULL )
	{
		order_fun(area_root, agent_root, o);
		
		order_all(o->left ,area_root, agent_root);
		order_all(o->right ,area_root, agent_root);
	}
}

// Delivery & Cancel order

order * minValueNode(order* node)
{
    order* current = node;
    while (current->left != NULL)
    {
    	current = current->left;
	} 
    return current;
}
order* delete_order(order * root, int id)
{
    order * ret_val=root;
	if (root == NULL)
	{
		ret_val = root;
	}
	else
	{
		if( id < root->order_id )
		{
			root->left = delete_order(root->left, id);
		}
		else if( id > root->order_id )
		{
			root->right = delete_order(root->right, id);
		}
		else
		{
			if( (root->left == NULL) || (root->right == NULL) )
        	{
            	order* temp ;
            	// No child case
            	if((root->left == NULL) && (root->right == NULL))
            	{
            		temp = root;
            		root = NULL;
				}
            	else // One child case
            	{
            		if( root->left == NULL )
            		{
            			temp=root->right;
						root->right=NULL;	
					}
					else
					{
						temp = root->left;
						root->left=NULL;
					}
					
					strcpy(root->customer_name,temp->customer_name);
					strcpy(root->address,temp->address);
					root->order_id=temp->order_id;
					root->customer_id=temp->customer_id;
					root->phone_no=temp->phone_no;
					root->d.day=temp->d.day;
					root->d.mon=temp->d.mon;
					root->d.year=temp->d.year;
					root->d.hr=temp->d.hr;
					root->d.min=temp->d.min;
					strcpy(root->rest_name,temp->rest_name);
					strcpy(root->rest_add,temp->rest_add);
					strcpy(root->item_name,temp->item_name);
					root->quantity=temp->quantity;
					root->price=temp->price;
					root->agent_assigned=temp->agent_assigned;
				}
            	free(temp);
        	}
        	else
        	{
            	// node with two child
            
            	order * temp = minValueNode(root->right);
 	
        	    strcpy(root->customer_name,temp->customer_name);
				strcpy(root->address,temp->address);
				root->order_id=temp->order_id;
				root->customer_id=temp->customer_id;
				root->phone_no=temp->phone_no;
				root->d.day=temp->d.day;
				root->d.mon=temp->d.mon;
				root->d.year=temp->d.year;
				root->d.hr=temp->d.hr;
				root->d.min=temp->d.min;
				strcpy(root->rest_name,temp->rest_name);
				strcpy(root->rest_add,temp->rest_add);
				strcpy(root->item_name,temp->item_name);
				root->quantity=temp->quantity;
				root->price=temp->price;
				root->agent_assigned=temp->agent_assigned;
				
        	    root->right = delete_order(root->right, temp->order_id);
			}
		}
		
		if(root == NULL )
		{
			ret_val=root;
		}
		else
		{
			root->height = 1 + max(height_order(root->left), height_order(root->right));

			int balance = getBalance_order(root);
			
			if( balance > 1 && id < root->order_id )
			{
				ret_val=rightRotate_order(root);
			}
		    else if( balance > 1 && id > root->order_id )
		    {	
				root->left = leftRotate_order(root->left);    
   			 	ret_val=rightRotate_order(root);
			}
			else if( balance < -1 && id > root->order_id )
			{		
				ret_val=leftRotate_order(root);
			}
			else if( balance < -1 && id < root->order_id )
			{
				root->right = rightRotate_order(root->right); 
				ret_val=leftRotate_order(root);
			}
		}
	} 
	return ret_val;
}
order* find_order(order * root, int id)
{
	order * retval=root;
	if (root != NULL)
	{
		if( root->order_id == id )
		{
			retval = root;
		}
		else
		{
			if( id < root->order_id)
			{
				retval = find_order(root->left, id);
			}
			else 
			{
				retval = find_order(root->right, id);
			}
		}
	}
	return retval;
}
user * find_user(user * root, int id)
{
	user * retval=root;
	if (root != NULL)
	{
		if( root->user_id == id )
		{
			retval = root;
		}
		else
		{
			if( id < root->user_id)
			{
				retval = find_user(root->left, id);
			}
			else 
			{
				retval = find_user(root->right, id);
			}
		}
	}
	return retval;
}
order * copy_order(order * o_new, order * o)
{
	strcpy(o_new->customer_name,o->customer_name);
	strcpy(o_new->address,o->address);
	o_new->order_id=o->order_id;
	o_new->customer_id=o->customer_id;
	o_new->phone_no=o->phone_no;
	o_new->d.day=o->d.day;
	o_new->d.mon=o->d.mon;
	o_new->d.year=o->d.year;
	o_new->d.hr=o->d.hr;
	o_new->d.min=o->d.min;
	strcpy(o_new->rest_name,o->rest_name);
	strcpy(o_new->rest_add,o->rest_add);
	strcpy(o_new->item_name,o->item_name);
	o_new->quantity=o->quantity;
	o_new->price=o->price;
	o_new->agent_assigned=NULL;
	o_new->left=NULL;
	o_new->right=NULL;
	o_new->height=1;
}
void delivery(order ** order_root, int id, user * user_root, order ** hist_root, int * num) 
{
	order * o_temp;
	o_temp=find_order(*order_root, id);
	user * u_temp;
	u_temp=find_user(user_root, o_temp->customer_id);
	agent * a_temp=o_temp->agent_assigned;
	
	o_temp->agent_assigned=NULL;
	a_temp->current_acc_comm=a_temp->current_acc_comm + (a_temp->current_acc_comm)/10;
	a_temp->status=0;

	order * o1=malloc(sizeof(order));
	order * o2=malloc(sizeof(order));	
	o1=copy_order(o1, o_temp);
	o2=copy_order(o2, o_temp);

	u_temp->order_history=insertNode_order(u_temp->order_history, o1);
	*hist_root=insertNode_order(*hist_root,o2);
	*order_root=delete_order(*order_root, id);
	*num=*num+1;	
	u_temp->num_order=u_temp->num_order+1;
}

void cancel_order(order ** order_root, int id)
{
	order * o_temp;
	o_temp=find_order(*order_root, id);
	
	agent * a_temp=o_temp->agent_assigned;
	o_temp->agent_assigned=NULL;
	a_temp->status=0;

	*order_root=delete_order(*order_root, id);
}

// Favourite functions

void insertHeap(fav current, int low, int high, fav data[])
{
	int large = (2*low + 1);
	int done=0;
	
	while( large <= high && done == 0)
	{
		if(large<high && (data[large].count < data[large+1].count))
		{
			large++;
		}
		if(current.count>data[large].count)
		{
			done=1;
		}
		else
		{
			data[low].count=data[large].count;
			strcpy(data[low].name,data[large].name);
			low=large;
			large=2*low + 1;
		}
	}
	data[low].count=current.count;
	strcpy(data[low].name,current.name);
}
void BuildHeap(fav data[], int size)
{
	int low;

	for( low=(size/2)-1; low>=0; low--)
	{
		insertHeap( data[low], low, size-1, data);
	}
}
void HeapSort(fav data[], int size)
{
	int lu;
	fav current;
	BuildHeap(data, size);
	
	for(lu=size-1; lu>=1; lu--)
	{
		current=data[lu];
		data[lu]=data[0];
		insertHeap(current, 0, lu-1, data);
	}
}
void fill_array_food(order * root, date d, fav f[], int size)
{
	if(root != NULL )
	{
		int flag=0;
		if(root->d.year <= d.year)
    	{
    		if(root->d.year == d.year)
    		{
    			if(root->d.mon <= d.mon)
    			{
    				if(root->d.mon == d.mon)
    				{
    					if(root->d.day >= d.day)
    					{
    						flag=1;
						}
					}
				}
				else
				{
					flag=1;
				}
			}
		}
		else
		{
			flag=1;
		}
		if(flag == 1)
		{
			int i, flag2=0;
			for(i=0; i<size && flag2==0; i++)
			{
				if( strcmp(f[i].name, root->item_name)==0)
				{
					flag2=1;
					f[i].count++;
				}
				else if(f[i].name[0]=='\0')
				{
					flag2=1;
					strcpy(f[i].name, root->item_name);
					f[i].count++;
				}
			}
		}
		fill_array_food(root->left, d, f, size);
		fill_array_food(root->right, d, f, size);	
	}
}
void find_fav_food_user(user * root, int id)
{
	date d;
	time_t t = time(NULL);
    struct tm* today = localtime(&t);
    today->tm_mon -= 3;
    if (today->tm_mon < 0) {
        today->tm_mon += 12;
        today->tm_year--;
    }
    mktime(today);
    
    d.day=today->tm_mday;
    d.mon=today->tm_mon + 1;
    d.year=today->tm_year + 1900;
    
	user * u_temp=find_user(root, id);
    order * temp=u_temp->order_history;
    
	int i, j, num=u_temp->num_order;
	fav f[num], temp1;
	for(i=0; i<num; i++)
	{
		f[i].name[0]='\0';
		f[i].count=0;
	}

	fill_array_food(temp, d, f, num);
	
	HeapSort(f, num);
	
	printf("\nFavourite Foods of User : id - %d name - %s", id, root->name);
	for(i=num-1; i>num-4; i--)
	{
		printf("%s", f[i].name);
		//printf("%d\n", f[i].count);
	}
}

void fill_array_rest(order * root, date d, fav f[], int size)
{
	if(root != NULL )
	{
		int flag=0;
		if(root->d.year <= d.year)
    	{
    		if(root->d.year == d.year)
    		{
    			if(root->d.mon <= d.mon)
    			{
    				if(root->d.mon == d.mon)
    				{
    					if(root->d.day >= d.day)
    					{
    						flag=1;
						}
					}
				}
				else
				{
					flag=1;
				}
			}
		}
		else
		{
			flag=1;
		}
		if(flag == 1)
		{
			int i, flag2=0;
			for(i=0; i<size && flag2==0; i++)
			{
				if( strcmp(f[i].name, root->rest_name)==0)
				{
					flag2=1;
					f[i].count++;
				}
				else if(f[i].name[0]=='\0')
				{
					flag2=1;
					strcpy(f[i].name, root->rest_name);
					f[i].count++;
				}
			}
		}
		fill_array_rest(root->left, d, f, size);
		fill_array_rest(root->right, d, f, size);	
	}
}
void find_fav_rest(order * root, int n, int order_num)
{
	date d;
	time_t t = time(NULL);
    struct tm* today = localtime(&t);
    today->tm_mday -= n;
    mktime(today);
    d.day=today->tm_mday;
    d.mon=today->tm_mon + 1;
    d.year=today->tm_year + 1900;
    
	fav rest[order_num], temp;
	int i, j;
	for(i=0; i<order_num; i++)
	{
		rest[i].name[0]='\0';
		rest[i].count=0;
	}
	
	fill_array_rest(root, d, rest, order_num);

	HeapSort(rest, order_num);
	
	printf("\nFavourite Restaurants in last %d days - \n", n);
	for(i=order_num-1; i>order_num-4; i--)
	{
		printf("%s", rest[i].name);
		//printf("%d\n", rest[i].count);
	}
}

void find_fav_food_across_rest(order * root, int n, int order_num)
{
	date d;
	time_t t = time(NULL);
    struct tm* today = localtime(&t);
    today->tm_mday -= n;
    mktime(today);
    d.day=today->tm_mday;
    d.mon=today->tm_mon + 1;
    d.year=today->tm_year + 1900;
    
	fav rest[order_num], temp;
	int i, j;
	for(i=0; i<order_num; i++)
	{
		rest[i].name[0]='\0';
		rest[i].count=0;
	}
	
	fill_array_food(root, d, rest, order_num);
	
	HeapSort(rest, order_num);
	
	printf("\nFavourite Food across Restaurants in last %d days - \n", n);
	for(i=order_num-1; i>order_num-4; i--)
	{
		printf("%s", rest[i].name);
		//printf("%d\n", rest[i].count);
	}
}

// Range Search

void Range_search(order * root, int id1, int id2)
{
	if( root != NULL )
	{
		if( root->customer_id >= id1 && root->customer_id <= id2)
		{
			printf("\nCustomer name : %s", root->customer_name);
			printf("Customer id : %d", root->customer_id);
			printf("\nCustomer address : %s", root->address);
			printf("Customer phone-no : %d", root->phone_no);
			printf("\nrestaurant name : %s", root->rest_name);
			printf("restaurant address : %s", root->rest_add);
			printf("Order date & time : %d-%d-%d %d:%d", root->d.day, root->d.mon, root->d.year ,root->d.hr, root->d.min);
			printf("\n Item name : %s", root->item_name);
			printf(" Quantity : %d", root->quantity);
			printf("\n Price : %d\n\n", root->price);
			
		}
		Range_search(root->left, id1, id2);
		Range_search(root->right, id1, id2);
	}
}

// Writing back data in file

void update_orderhist_data(FILE * fp7, order * root)
{
	if( root != NULL )
	{
		fprintf(fp7, "%d\n", root->order_id);
		fprintf(fp7, "%d\n", root->customer_id);
		fprintf(fp7, "%s", root->customer_name);
    	fprintf(fp7, "%s", root->address);
    	fprintf(fp7, "%d\n", root->phone_no);
    	fprintf(fp7, "%d %d %d\n", root->d.day, root->d.mon, root->d.year);
    	fprintf(fp7, "%d %d\n", root->d.hr, root->d.min);
    	fprintf(fp7, "%s", root->rest_name);
    	fprintf(fp7, "%s", root->rest_add);
    	fprintf(fp7, "%s", root->item_name);
    	fprintf(fp7, "%d\n", root->quantity);
   		fprintf(fp7, "%d\n\n", root->price);
   		
   		update_orderhist_data(fp7, root->left);
   		update_orderhist_data(fp7, root->right);
	}
}
void print_orders_on_file(FILE * fp8, order * root)
{
	if( root != NULL )
	{
		fprintf(fp8, "%d\n", root->order_id);
		fprintf(fp8, "%s", root->rest_name);
    	fprintf(fp8, "%s", root->rest_add);
    	fprintf(fp8, "%d %d %d\n", root->d.day, root->d.mon, root->d.year);
    	fprintf(fp8, "%d %d\n", root->d.hr, root->d.min);
    	fprintf(fp8, "%s", root->item_name);
    	fprintf(fp8, "%d\n", root->quantity);
   		fprintf(fp8, "%d\n", root->price);
   		
   		print_orders_on_file(fp8, root->left);
   		print_orders_on_file(fp8, root->right);
	}
}
void update_user_data(FILE * fp8, user * root)
{
	if( root != NULL )
	{
		fprintf(fp8, "%d\n", root->user_id);
    	fprintf(fp8, "%s", root->name);
    	fprintf(fp8, "%s", root->address);
    	fprintf(fp8, "%d\n", root->phone_no);
    	fprintf(fp8, "%d\n", root->num_order);
    	order * o_temp=root->order_history;
    	
    	print_orders_on_file(fp8, o_temp);
   		fprintf(fp8, "\n");
   		
   		update_user_data(fp8, root->left);
   		update_user_data(fp8, root->right);
	}
}
void update_agent_data(FILE * fp9, agent * root)
{
	if( root != NULL )
	{
		fprintf(fp9, "%d\n", root->agent_id);
    	fprintf(fp9, "%s", root->name);
    	fprintf(fp9, "%s", root->area_assigned);
    	fprintf(fp9, "%d\n", root->phone_no);
    	fprintf(fp9, "%d\n", root->current_acc_comm);
    	fprintf(fp9, "%d\n\n", root->status);
    	
    	update_agent_data(fp9, root->left);
   		update_agent_data(fp9, root->right);
	}
}

int main()
{
	int i, n, status=1;
	restaurant * rest_head = NULL;
	
	FILE *fp = fopen("restaurant.txt","r");
	
	char s1[]="north indian\n", s2[]="south indian\n", s3[]="continental\n", s4[]="chinese\n", s5[]="other\n";
	while(status == 1)
	{
		restaurant * rest_node = malloc(sizeof(restaurant));
		char s[200], t[200];
		fgets(s, 200, fp);
		strcpy(rest_node->name, s);
		fgets(rest_node->address, 200, fp);
		fscanf(fp, "%d", &rest_node->num_seats);
		fgets(s, 200, fp);
		//rest_node->num_seats= getw(fp);
		fgets(rest_node->type, 200, fp);
		//fscanf(fp, "%[^\n]s", s); 
		fgets(s, 200, fp);
		
			if( strcmp(s,s1) != 0)
			{
				rest_node->menu[0]=NULL; 
			}
			else
			{
				fscanf(fp, "%d", &n);
				fgets(t, 200, fp);
				food * temp=NULL;
				
				for(i=0; i<n; i++)
				{
					food * f_node=malloc(sizeof(food));
					
					fgets(f_node->name, 200, fp);
					fscanf(fp, "%d", &(f_node)->price);
					fgets(t, 200, fp);
					f_node->left=NULL;
					f_node->right=NULL;
					f_node->height=1;
					
					temp=insertNode_food(temp, f_node);	
							
				}
				rest_node->menu[0]=temp;
			
				fgets(s, 200, fp);
			}
			
			if(strcmp(s,s2) != 0)
			{
				rest_node->menu[1]=NULL;
			}
			else
			{
				fscanf(fp, "%d", &n);
				fgets(t, 200, fp);
				food * temp=NULL;
		
				for(i=0; i<n; i++)
				{
					food * f_node=malloc(sizeof(food));
					
					fgets(f_node->name, 200, fp);
					fscanf(fp, "%d", &(f_node)->price);
					fgets(t, 200, fp);
					f_node->left=NULL;
					f_node->right=NULL;
					f_node->height=1;
					
					temp=insertNode_food(temp, f_node);	
				}
				rest_node->menu[1]=temp;
				fgets(s, 200, fp);
			}
			
			if(strcmp(s,s3) != 0)
			{
				rest_node->menu[2]=NULL;
			}
			else
			{
				fscanf(fp, "%d", &n);
				fgets(t, 200, fp);
				food * temp=NULL;
		
				for(i=0; i<n; i++)
				{
					food * f_node=malloc(sizeof(food));
					
					fgets(f_node->name, 200, fp);
					fscanf(fp, "%d", &(f_node)->price);
					fgets(t, 200, fp);
					f_node->left=NULL;
					f_node->right=NULL;
					f_node->height=1;
			
					temp=insertNode_food(temp, f_node);	
				}
				rest_node->menu[2]=temp;
				fgets(s, 200, fp);
			}
			
			if(strcmp(s,s4) != 0)
			{
				rest_node->menu[3]=NULL;
			}
			else
			{
				fscanf(fp, "%d", &n);
				fgets(t, 200, fp);
				food * temp=NULL;
		
				for(i=0; i<n; i++)
				{
					food * f_node=malloc(sizeof(food));
					
					fgets(f_node->name, 200, fp);
					fscanf(fp, "%d", &(f_node)->price);
					fgets(t, 200, fp);
					f_node->left=NULL;
					f_node->right=NULL;
					f_node->height=1;
			
					temp=insertNode_food(temp, f_node);	
				}
				rest_node->menu[3]=temp;
				fgets(s, 200, fp); 
			}
			
			if(strcmp(s,s5) != 0)
			{
				rest_node->menu[4]=NULL;
			}
			else
			{
				fscanf(fp, "%d", &n);
				fgets(t, 200, fp);
				food * temp=NULL;
		
				for(i=0; i<n; i++)
				{
					food * f_node=malloc(sizeof(food));
					
					fgets(f_node->name, 200, fp);
					fscanf(fp, "%d", &(f_node)->price);
					fgets(t, 200, fp);
					f_node->left=NULL;
					f_node->right=NULL;
					f_node->height=1;
			
					temp=insertNode_food(temp, f_node);	
				}
				rest_node->menu[4]=temp;
				fgets(s, 200, fp);
			}
			
		rest_node->left=NULL;
		rest_node->right=NULL;
		rest_node->height=1;
		
		rest_head=insertNode_rest(rest_head, rest_node);
		if(feof(fp) != 0)
		{
			status=0;
		}

	}
	//printPreOrder_rest(rest_head);
	fclose(fp);
	
	agent * agent_head = NULL;
	
	FILE *fp2 = fopen("agent.txt","r");
	status=1;
	while(status == 1)
	{
		agent * agent_node = malloc(sizeof(agent));
		char t[4];
		
		fscanf(fp2, "%d", &agent_node->agent_id);
		fgets(t, 4, fp2);
		fgets(agent_node->name, 200, fp2);
		fgets(agent_node->area_assigned, 200, fp2);
		fflush(stdin);
		fscanf(fp2, "%d", &agent_node->phone_no);
		fgets(t, 4, fp2);
		fscanf(fp2, "%d", &agent_node->current_acc_comm);
		fgets(t, 4, fp2);
		fscanf(fp2, "%d", &agent_node->status);
		fgets(t, 4, fp2);
		fgets(t, 4, fp2);
		agent_node->height=1;
		agent_node->left=NULL;
		agent_node->right=NULL;
		
		agent_head=insertNode_agent(agent_head, agent_node);
		
		//printPreOrder_agent(agent_head);
		
		/*
		printf("\nAgent id: %d", agent_head->agent_id);
		printf("\nAgent name: %s", agent_head->name);
		printf("Area assigned : %s", agent_head->area_assigned);
		printf("Agent Phone no : %d", agent_head->phone_no);
		printf("\nAgent's current acc comm. : %d", agent_head->current_acc_comm);
		printf("\nAgent's status : %d", agent_head->status);
		
		printf("\n\n");
		//*/
		if(feof(fp2) != 0)
		{
			status=0;
		}
	}
	//printPreOrder_agent(agent_head);
	fclose(fp2);
	
	area * area_head = NULL;
	
	FILE *fp3 = fopen("area.txt","r");
	
	status=1;
	while(status == 1)
	{
		area * area_node = malloc(sizeof(area));
		char t[4];
		
		fgets(area_node->area_name, 200, fp3);
		fgets(area_node->area_around[0], 200, fp3);
		fgets(area_node->area_around[1], 200, fp3);
		fgets(t, 4, fp2);
		area_node->left=NULL;
		area_node->right=NULL;
		area_node->height=1;
		
		area_head=insertNode_area(area_head, area_node);
		if(feof(fp3) != 0)
		{
			status=0;
		}
	}
	//printPreOrder_area(area_head);
	fclose(fp3);
	
	user * user_head = NULL;
	FILE *fp4 = fopen("user.txt","r");
	
	int user_count, k;
	fscanf(fp4, "%d", &user_count);
	for(k=0; k<user_count; k++)
	{
		user * user_node=malloc(sizeof(user));
		char t[4], s[200];
	
		fscanf(fp4, "%d", &user_node->user_id);
		fgets(t, 4, fp4);
		fgets(user_node->name, 200, fp4);
		fgets(user_node->address, 200, fp4);
		fscanf(fp4, "%d", &user_node->phone_no);
		fgets(t, 4, fp4);
		fscanf(fp4, "%d", &user_node->num_order);
		fgets(t, 4, fp4);
		user_node->left=NULL;
		user_node->right=NULL;
		user_node->height=1;
		
		order * temp=NULL;
		
		
		int i;
		for(i=0; i<user_node->num_order; i++)
		{

			order * order_node=malloc(sizeof(order));
			
			strcpy(order_node->customer_name, user_node->name);
			strcpy(order_node->address, user_node->address);
			order_node->phone_no=user_node->phone_no;
			
			fscanf(fp4, "%d", &order_node->order_id);
			fgets(t, 4, fp4);
			fgets(order_node->rest_name, 200, fp4);
			//strcpy(order_node->rest_name, s);
			fgets(order_node->rest_add, 200, fp4);
			fscanf(fp4, "%d", &order_node->d.day);
			fscanf(fp4, "%d", &order_node->d.mon);
			fscanf(fp4, "%d", &order_node->d.year);
			fgets(t, 4, fp4);
			fscanf(fp4, "%d", &order_node->d.hr);
			fscanf(fp4, "%d", &order_node->d.min);
			fgets(t, 4, fp4);
			fgets(order_node->item_name, 200, fp4);
			fscanf(fp4, "%d", &order_node->quantity);
			fgets(t, 4, fp4);
			fscanf(fp4, "%d", &order_node->price);
			fgets(t, 4, fp4);
			order_node->left=NULL;
			order_node->right=NULL;
			order_node->height=1;
			
			temp=insertNode_order(temp, order_node);	
		}
		user_node->order_history=temp;
		
		user_head=insertNode_user(user_head, user_node);	
	}
	//printPreOrder_user(user_head);	
	fclose(fp4);
	
	order * order_hist_head=NULL;
	
	FILE *fp5 = fopen("order_history.txt","r");
	char s[4];
	int global_order_num;
	fscanf(fp5, "%d", &global_order_num);
	fgets(s, 4, fp5);
	for(k=0; k<global_order_num; k++)
	{
		order * order_hist_node=malloc(sizeof(order));
		char t[4];
		
		fscanf(fp5, "%d", &order_hist_node->order_id);
		fgets(t, 4, fp5);
		fscanf(fp5, "%d", &order_hist_node->customer_id);
		fgets(t, 4, fp5);
		fgets(order_hist_node->customer_name, 200, fp5);
		fgets(order_hist_node->address, 200, fp5);
		fscanf(fp5, "%d", &order_hist_node->phone_no);
		fgets(t, 4, fp5);
		fscanf(fp5, "%d", &order_hist_node->d.day);
		fscanf(fp5, "%d", &order_hist_node->d.mon);
		fscanf(fp5, "%d", &order_hist_node->d.year);
		fgets(t, 4, fp5);
		fscanf(fp5, "%d", &order_hist_node->d.hr);
		fscanf(fp5, "%d", &order_hist_node->d.min);
		fgets(t, 4, fp5);
		fgets(order_hist_node->rest_name, 200, fp5);
		fgets(order_hist_node->rest_add, 200, fp5);
		fgets(order_hist_node->item_name, 200, fp5);
		fscanf(fp5, "%d", &order_hist_node->quantity);
		fgets(t, 4, fp5);
		fscanf(fp5, "%d", &order_hist_node->price);
		fgets(t, 4, fp5);
		fgets(t, 4, fp5);
		order_hist_node->left=NULL;
		order_hist_node->right=NULL;
		order_hist_node->height=1;
			
		order_hist_head=insertNode_order(order_hist_head, order_hist_node);
		
		/*if(feof(fp5) != 0)
		{
			status = 0;
		}*/
	}
	//printPreOrder_glob_order(order_hist_head);
	fclose(fp5);
	
	order * global_order_head = NULL;
	FILE *fp6 = fopen("order.txt","r");
	status=1;
	while(status == 1)
	{
		order * global_order_node=malloc(sizeof(order));
		char t[4];
		
		fscanf(fp6, "%d", &global_order_node->order_id);
		fgets(t, 4, fp6);
		fscanf(fp6, "%d", &global_order_node->customer_id);
		fgets(t, 4, fp6);
		fgets(global_order_node->customer_name, 200, fp6);
		fgets(global_order_node->address, 200, fp6);
		fscanf(fp6, "%d", &global_order_node->phone_no);
		fgets(t, 4, fp6);
		fscanf(fp6, "%d", &global_order_node->d.day);
		fscanf(fp6, "%d", &global_order_node->d.mon);
		fscanf(fp6, "%d", &global_order_node->d.year);
		fgets(t, 4, fp6);
		fscanf(fp6, "%d", &global_order_node->d.hr);
		fscanf(fp6, "%d", &global_order_node->d.min);
		fgets(t, 4, fp6);
		fgets(global_order_node->rest_name, 200, fp6);
		fgets(global_order_node->rest_add, 200, fp6);
		fgets(global_order_node->item_name, 200, fp6);
		global_order_node->agent_assigned=NULL;
		fscanf(fp6, "%d", &global_order_node->quantity);
		fgets(t, 4, fp6);
		fscanf(fp6, "%d", &global_order_node->price);
		fgets(t, 4, fp6);
		fgets(t, 4, fp6);
		
		global_order_node->left=NULL;
		global_order_node->right=NULL;
		global_order_node->height=1;
			
		global_order_head=insertNode_order(global_order_head, global_order_node);
		printPreOrder_glob_order(global_order_head);
		printf("\n---------------------------------- -------");	
		if(feof(fp6) != 0) 
		{
			status = 0;
		}
	}
	//printPreOrder_glob_order(global_order_head);
	fclose(fp6);
	/*
	fflush(stdin);
	char cat[50];
	printf("\n Enter category of restaurant to find : ");
	scanf("%s", cat);
	strcat(cat,"\n");
	find_on_type(rest_head, cat);
	//*/
	/*
	fflush(stdin);
	char cat_food[80];
	printf("\n Enter category of food to find : ");
	scanf("%[^\n]s", cat_food);
	find_on_food_category(rest_head, cat_food);
	//*/
	/*
	fflush(stdin);
	char area_name[100];
	printf("\n Enter area : ");
	scanf("%[^\n]s", area_name);
	find_on_area(rest_head, area_head, area_name);
	//*/
	
	//order_fun(area_head, agent_head, global_order_head);
	//order_all(global_order_head, area_head, agent_head);
	//printPreOrder_agent(agent_head);
	
	//delivery(&global_order_head, 1001, user_head, &order_hist_head, &global_order_num);
	//delivery(&global_order_head, 1002, user_head, &order_hist_head, &global_order_num);
	
	/*
	printf("\n---------------------------------- -------");	
	printPreOrder_user(user_head);
	printf("\n---------------------------------- -------");	
	printPreOrder_glob_order(global_order_head);
	printf("\n---------------------------------- -------");
	printPreOrder_glob_order(order_hist_head);
	printf("\n---------------------------------- -------");
	printPreOrder_agent(agent_head);
	printf("\n---------------------------------- -------");
	//*/
	
	//cancel_order(&global_order_head, 1002);
	
	/*
	printf("\n---------------------------------- -------");	
	printPreOrder_glob_order(global_order_head);
	printf("\n---------------------------------- -------");
	printPreOrder_glob_order(order_hist_head);
	printf("\n---------------------------------- -------");
	printPreOrder_agent(agent_head);
	printf("\n---------------------------------- -------");
	//*/
	
	
	/*
	int n1;
    printf("Enter the number of days: ");
    scanf("%d", &n1);
    find_fav_food_user(user_head, 101);
    find_fav_rest(order_hist_head, n1, global_order_num);
    find_fav_food_across_rest(order_hist_head, n1, global_order_num);
    //*/
	/*
    int n1, n2;
    printf("\nEnter the user-ids : ");
    scanf("%d %d", &n1, &n2);
    Range_search(global_order_head, n1, n2);
    //*/
    
    //printPreOrder_agent(agent_head);
    //printPreOrder_glob_order(global_order_head);
    //print_area_wise_agents(area_head,agent_head);
    /*
    char name[]="Raddison blue\n", add[]="airport\n";
    print_rest_details(rest_head, name, add);
    //*/
    
    /*
    FILE *fp7 = fopen("order_history.txt","w");
   	fprintf(fp7, "%d\n", global_order_num);
   	update_orderhist_data(fp7, order_hist_head);
	fclose(fp7);
	//*/
	/*
	FILE *fp8 = fopen("user.txt","w");
	fprintf(fp8, "%d\n", user_count);
   	update_user_data(fp8, user_head);				
	fclose(fp8);
	//*/
	/*
	FILE *fp9 = fopen("agent.txt","w");
	update_agent_data(fp9, agent_head);			
	fclose(fp9);
	//*/
	return 0;
}
