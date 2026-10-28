#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "timetable.h"
void sort_subjects_by_difficulty(Subject a[], int n);
int search_subject(Subject a[], int n, const char *code);
int search_room(Room a[], int n, const char *name);
#endif
