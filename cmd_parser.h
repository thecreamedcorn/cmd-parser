#ifndef CMD_PARSER_LIBRARY_H
#define CMD_PARSER_LIBRARY_H

#include <stdint.h>
#include <stddef.h>

#include "hashmap.h"

typedef void *ParserOptions;

typedef void *ArgOptions;

typedef void (*FuncPtrCommand)(map_t results, void* data);

typedef struct _ArgumentData {
    int length;
    char **args;
} ArgumentData;

typedef struct _CommandClosure {
    void* data;
    FuncPtrCommand command;
} CommandClosure;


extern ParserOptions new_parser_options(ArgOptions arg_options_array[]);

extern void free_parser_options(ParserOptions parser_options);

extern ArgOptions new_arg_options(char* long_name, char short_name, size_t min_arg_length, size_t max_arg_length, const char *description, const char *arg_help);

extern map_t parse_command_line_args(int argc, char** argv, ParserOptions options);

extern char* create_help_string(ParserOptions options);

#endif