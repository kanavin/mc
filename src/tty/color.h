
/** \file color.h
 *  \brief Header: color setup
 */

#ifndef MC_COLOR_H
#define MC_COLOR_H

#include "../../src/global.h"		/* glib.h */

#ifdef HAVE_SLANG
#   include "../../src/tty/color-slang.h"
#else
#   include "../../src/tty/color-ncurses.h"
#endif

/* Beware! When using Slang with color, not all the indexes are free.
   See color-slang.h (A_*) */
#define NORMAL_COLOR          IF_COLOR (1, 0)
#define SELECTED_COLOR        IF_COLOR (2, A_REVERSE)
#define MARKED_COLOR          IF_COLOR (3, A_BOLD)
/* MARKED_SELECTED_COLOR is screen library specific */
#define ERROR_COLOR           IF_COLOR (5, A_BOLD)
#define MENU_ENTRY_COLOR      IF_COLOR (6, A_REVERSE)
#define REVERSE_COLOR         IF_COLOR (7, A_REVERSE)

/* Dialog colors */
#define COLOR_NORMAL       IF_COLOR (8, A_REVERSE)
#define COLOR_FOCUS        IF_COLOR (9, A_BOLD)
#define COLOR_HOT_NORMAL   IF_COLOR (10, 0)
#define COLOR_HOT_FOCUS    IF_COLOR (11, 0)

#define VIEW_UNDERLINED_COLOR IF_COLOR (12, A_UNDERLINE)
#define MENU_SELECTED_COLOR   IF_COLOR (13, A_BOLD)
#define MENU_HOT_COLOR        IF_COLOR (14, 0)
#define MENU_HOTSEL_COLOR     IF_COLOR (15, 0)

#define HELP_NORMAL_COLOR  IF_COLOR (16, A_REVERSE)
#define HELP_ITALIC_COLOR  IF_COLOR (17, A_REVERSE)
#define HELP_BOLD_COLOR    IF_COLOR (18, A_REVERSE)
#define HELP_LINK_COLOR    IF_COLOR (19, 0)
#define HELP_SLINK_COLOR   IF_COLOR (20, A_BOLD)

/*
 * This should be selectable independently. Default has to be black background
 * foreground does not matter at all.
 */
#define GAUGE_COLOR        IF_COLOR (21, 0)
#define INPUT_COLOR        IF_COLOR (22, 0)

/* For the default color any unused index may be chosen. */
#define DEFAULT_COLOR_INDEX   23
#define DEFAULT_COLOR      IF_COLOR (DEFAULT_COLOR_INDEX, 0)

/*
 * editor colors - only 4 for normal, search->found, select, and whitespace
 * respectively
 * Last is defined to view color.
 */
#define EDITOR_NORMAL_COLOR_INDEX    27
#define EDITOR_NORMAL_COLOR          IF_COLOR (EDITOR_NORMAL_COLOR_INDEX, 0)
#define EDITOR_BOLD_COLOR            IF_COLOR (28, A_BOLD)
#define EDITOR_MARKED_COLOR          IF_COLOR (29, A_REVERSE)
#define EDITOR_WHITESPACE_COLOR      IF_COLOR (30, 0 /* irrelevant */)

/* color of left 8 char status per line */
#define LINE_STATE_COLOR  IF_COLOR (31, 0)

/* Error dialog colors */
#define ERROR_HOT_NORMAL   IF_COLOR (32, 0)
#define ERROR_HOT_FOCUS    IF_COLOR (43, 0)

void tty_init_colors (gboolean disable, gboolean force);
void tty_colors_done (void);
gboolean tty_use_colors (void);
int tty_try_alloc_color_pair (const char *fg, const char *bg);
void tty_setcolor (int color);
void tty_lowlevel_setcolor (int color);
void tty_set_normal_attrs (void);

#endif				/* MC_COLOR_H */