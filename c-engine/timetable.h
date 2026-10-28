#ifndef TIMETABLE_H
#define TIMETABLE_H
#define MAX_CLASSES 64
#define MAX_ASSIGNMENTS 64
#define DAYS 5
#define SLOTS 6
typedef struct { char code[12], teacher[40], batch[16]; int students, priority, classesPerWeek; unsigned availableMask; } Subject;
typedef struct { char name[24]; int capacity; } Room;
typedef struct { int subjectIndex, day, slot, roomIndex; } Assignment;
typedef struct { long attempts, conflicts, backtracks; } Stats;
int generate_timetable(Subject subjects[], int subjectCount, Room rooms[], int roomCount, Assignment out[], int *outCount, Stats *stats);
int has_conflict(Assignment a[], int count, Subject subjects[], int subjectIndex, int day, int slot, int roomIndex, Room rooms[], Stats *stats);
#endif
