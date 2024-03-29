#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define DELIM " \t\r\n"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* global variable who stores the data to be added to stack */
extern int data;

/* prototypes */
int data;
void print_error(char *, ...);
void print_error_functions(char *, ...);
int _strcmp(char *, char*);
char *get_content_file(FILE *);
char *_strcpy(char *, char *);
instruction_t get_instruction(char *, int, char *, FILE *, stack_t *);
int is_number(char *);
void free_dlistint(stack_t *);
void free_all(char *, FILE *, stack_t *);

/* functions to handle op_code */
void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);


#endif
