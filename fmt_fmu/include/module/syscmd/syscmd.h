/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef __SYSCMD_H__
#define __SYSCMD_H__

#include <firmament.h>

enum {
	SYSCMD_ALIGN_LEFT,
	SYSCMD_ALIGN_MIDDLE,
	SYSCMD_ALIGN_RIGHT
};

typedef struct {
	char* opt;
	char* val;
} optv_t;

typedef int (*shell_handle_func)(int, char**, int, optv_t*);

#define STRING_COMPARE(str1, str2)              (strcmp(str1, str2) == 0)

#define PRINT_USAGE(cmd, usage)                 console_printf("usage: %s %s\n", #cmd, #usage)
#define PRINT_STRING(str)                       console_printf("%s", str)
#define PRINT_ACTION(action, len, desc)         console_printf(" %-"#len"s  %s\n", action, desc)

bool syscmd_is_num(char* str);
char syscmd_getc(void);
bool syscmd_has_input(void);
void syscmd_flush(void);
void syscmd_putc(const char c, int cnt);
void syscmd_printf(const char pad, uint32_t len, uint8_t align, const char* fmt, ...);
int syscmd_process(int argc, char** argv, shell_handle_func func);

#endif