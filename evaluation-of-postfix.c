#include<stdio.h>
#include<string.h> 
#include<limits.h>
#include<stdlib.h>
#include<ctype.h>

//declaration of stack array and top position
int stack[20];                        //   for max size of stack 
int top = -1 ;                         

//function to push element in stack
void push(int x)                    
{
    stack[++top] = x;
}

//function to delete element from array
int pop()                          
{
    return stack[top--];
}


//main function
int main()                           
    char expression[20];
    char *e;
    int a1,a2,a3,num;
    printf("Enter the expression :: ");
    scanf("%s",expression);
    e = expression;
    while(*e != '\0')                      // using while loop
    {
        if(isdigit(*e))
        {
            num = *e - 48;
            push(num);
        }
        else
        {
            a1 = pop();
            a2 = pop();
            switch(*e)                                 // using switch statement
            {
            case '+':
            {
                a3 = a1 + a2;
                break;
            }
            case '-':
            {
                a3 = a2 - a1;
                break;
            }
            case '*':
            {
                a3 = a1 * a2;
                break;
            }
            case '/':
            {
                a3 = a2 / a1;
                break;
            }
            }
            push(a3);
        }
        e++;
    }
    //printing the expreesion value
    printf("\nThe result of expression %s  =  %d\n\n",expression,pop());
    return 0;
}
