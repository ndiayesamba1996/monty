#ifndef __MONTY__H
#define __MONTY__H
#define QUEUE 1
#define STACK 0
#define DELIM " \n\t\a\b"

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * globales_s - struct with variable globals
 * @token2: integer
 * @fd: points to the previous element of the stack (or queue)
 * @line_buf: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct globales_s
{
	char *token2;
	FILE *fd;
	char *line_buf;

} globales_t;

extern globales_t globalvar;

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
 * struct instruction_s - opcoode and its function
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

extern stack_t *head;

/*Type for opcode functions*/
typedef void (*op_func)(stack_t **, unsigned int);

/*File operations*/
void open_file(char *);
void read_file(FILE *);
int len_chars(FILE *);
int interpret_line(char *, int, int);
void find_func(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int n);
void free_nodes(void);
void print_stack(stack_t **, unsigned int);
void add_to_stack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);

void call_fun(op_func, char *, char *, int, int);
void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);

/*Math operations with nodes*/
void add_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void mul_nodes(stack_t **, unsigned int);
void mod_nodes(stack_t **, unsigned int);

/*String operations*/
void print_char(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/*Error hanlding*/
void err(int error_code, ...);
void more_err(int error_code, ...);
void string_err(int error_code, ...);
void rotr(stack_t **, unsigned int);

/* main.c */
int main(int argc, char **argv);

/* node functions */
stack_t *create_node_stackfirst(stack_t **stack, int n);
stack_t *create_node_stackend(stack_t **stack, int n);
void free_node_stack(stack_t **stack);

/* get_builtin */
int get_builtin(char *token, stack_t **stack, unsigned int line_number);
/* builtins functions */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void div_m(stack_t **stack, unsigned int line_number);
void mod_m(stack_t **stack, unsigned int line_number);
void pstr_t(stack_t **stack, unsigned int line_number);
void rotrl(stack_t **stack, unsigned int line_number);





/*error*/
void stderr_usage(void);
void stderr_malloc(void);
void stderr_fopen(char *fd);
void stderr_int(unsigned int line_number);
void stderr_unknown(char *token, unsigned int line_number);
void div_e(unsigned int line_number);
void op_e(unsigned int line_number, char *op);
/* TEST F */

void tokerr(int error_code);
unsigned int array_len(void);
char *get_int(int num);
unsigned int abs_m(int);
int len_buff_uint(unsigned int num, unsigned int base);
void full_buff(unsigned int num, unsigned int base, char *buff, int buff_size);
void pop_e(unsigned int line_number);
void pint_e(unsigned int line_number);
void pchar_e(unsigned int line_number, char *msg);
int _isdigit();
void free_dlistint(stack_t *stack);
void free_globalvars(void);
void rotr(stack_t **stack, unsigned int line_number);
stack_t *add_dnodeint(stack_t **head, int n);

/* UNUSED F
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
int cmd_monty(FILE *fd);
void free_tok(void);
int check_delim(char stream, char *delim);
int wstrlen(char *str, char *delim);
int wcounter(char *str, char *delim);
char **strtow(char *str, char *delim);
char *wnext(char *str, char *delim);
int create_node_stack(stack_t **stack);
void free_node_stack(stack_t **stack);
int no_line(char *line, char *delim);
int check_opcode(stack_t *stack);
*/



#endif /*__MONTY__H*/
