// C program to evaluate value of a postfix expression 
#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 
  
// Stack type 
struct Stack 
{ 
    int top; 
    unsigned capacity; 
    int* array; 
}; 
  
// Stack Operations 
struct Stack* createStack( unsigned capacity ) 
{ 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
    
    if (!stack) 
    {
     printf("No stack\n");
        return NULL; 
    }
    stack->top = -1; 
    stack->capacity = capacity; 
    stack->array = (int*) malloc(stack->capacity * sizeof(int)); 
  
    if (!stack->array) return NULL; 
  
    return stack; 
} 
  
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1 ; 
} 
  
char peek(struct Stack* stack) 
{ 
    return stack->array[stack->top]; 
} 
  
char pop(struct Stack* stack) 
{ 
    if (!isEmpty(stack)) 
        return stack->array[stack->top--] ; 
    return '$'; 
} 
  
void push(struct Stack* stack, char op) 
{ 
    stack->array[++stack->top] = op; 
} 
  
  
// The main function that returns value of a given postfix expression 
int evaluatePostfix(char* exp) 
{ 
    // Create a stack of capacity equal to expression size 
    struct Stack* stack = createStack(strlen(exp)); 
    int i; 
  
    // See if stack was created successfully 
    if (!stack) return -1; 
    
    char* token = strtok(exp, " "); 

    // Scan all characters one by one 
    //for (i = 0; exp[i]; ++i)
    while (token != NULL)
    { 
    printf("While: Token%s\n",token);

        // If the scanned character is an operand (number here), 
        // push it to the stack. 
        //if (isdigit(exp[i])) 
        //    push(stack, exp[i] - '0'); 
        if (isdigit(token[0])) 
        {
            push(stack, atoi(token)); 
            printf("If: Token%s\n",token);
            
        }
        // If the scanned character is an operator, pop two 
        // elements from stack apply the operator 
        else
        { 
            int val1 = pop(stack); 
            int val2 = pop(stack); 
            printf("Val1:%d Val2:%d : ", val1,val2);
            printf("Else: Token%s :",token);
            switch (token[0]) 
            { 
            case '+': 
            push(stack, val2 + val1);
            printf("Value :%d \n",val2 + val1 );
            break; 
            case '-': 
            push(stack, val2 - val1); 
            printf("Value :%d \n",val2 - val1 );
            break; 
            case '*': 
            push(stack, val2 * val1);
            printf("Value :%d \n",val2 * val1 );
            break;
            case '/': 
            push(stack, val2/val1); 
            printf("Value :%d \n",val2/val1 );
            break; 
            } 
        } 
    token = strtok(NULL, " "); 

    } 
    int retval = pop(stack);
    free(stack);
    return retval; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    //Enhanced to accept tokens with Spaces
    //to allow for multiple digit expression like 100,200 etc
    //Works for single digit only
    char exp[] = "2 30 5 * + 9 -"; 
    //if the expression has spaces strtok
    
    printf ("postfix evaluation: %d", evaluatePostfix(exp)); 
    return 0; 
}