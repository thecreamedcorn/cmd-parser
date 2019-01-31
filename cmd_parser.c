
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "hashmap.h"
#include "cmd_parser.h"

typedef struct _ParserOptionsImpl {
    map_t long_name_serach;
    map_t short_name_search;
} ParserOptionsImpl;

typedef struct _ArgOptionsImpl {
    const char *long_name;
    char short_name;
    int32_t min_arg_num;
    int32_t max_arg_num;
    const char *description;
    const char *arg_help;
} ArgOptionsImpl;

typedef struct _grab_argument_name_result {
    int is_valid;
    int is_long;
    char* name;
} GrabArgumentNameResult;

ParserOptions new_parser_options(ArgOptions arg_options_array[]) {
    ParserOptionsImpl* parser_options = (ParserOptionsImpl*) malloc(sizeof(ParserOptionsImpl));
    parser_options->long_name_serach = hashmap_new();
    parser_options->short_name_search = hashmap_new();

    size_t array_size = sizeof(arg_options_array)/sizeof(ArgOptions);
    for (int i = 0; i < array_size; i++) {
        ArgOptionsImpl* arg_options = (ArgOptionsImpl*) arg_options_array[i];
        hashmap_put(parser_options->long_name_serach, arg_options->long_name, arg_options);
        if (isalnum(arg_options->short_name)) {
            hashmap_put(parser_options->short_name_search, &arg_options->short_name, arg_options);
        }
    }

    return parser_options;
}

void free_parser_options_helper(any_t item, char* key, any_t data) {
    free(data);
}

void free_parser_options(ParserOptions parser_options_arg) {
    ParserOptionsImpl* parser_options = (ParserOptionsImpl*) parser_options_arg;
    hashmap_iterate(parser_options->long_name_serach, &free_parser_options_helper, NULL);
    hashmap_free(parser_options->long_name_serach);
    hashmap_free(parser_options->short_name_search);
}

ArgOptions new_arg_options(char* long_name, char short_name, size_t min_arg_length, size_t max_arg_length, const char *description, const char *arg_help) {
    ArgOptionsImpl* result = (ArgOptionsImpl*) malloc(sizeof(ArgOptionsImpl));
    result->long_name = long_name;
    result->short_name = short_name;
    result->min_arg_num = min_arg_length;
    result->max_arg_num = max_arg_length;
    result->description = description;
    result->arg_help = arg_help;
    return result;
}

map_t parse_command_line(int argc, char** argv, ParserOptions main_command) {
    map_t result = hashmap_new();
    map_t short_to_long_name_map = hashmap_new();

    for (int pos = 1; pos < argc; pos++) {
        char* cur_str = argv[pos];
        if (cur_str[0] == '\0') {
            continue;
        }
        if (cur_str[0] != '\0' && cur_str[0]) {
            if (cur_str[1] != '\0' && cur_str[])
        } else if ()
    }

    hashmap_free(short_to_long_name_map);
}

char *create_help_string(ParserOptions options) {
    return NULL;
}


