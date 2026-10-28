#include <string.h>
#include "algorithms.h"
static int difficulty(Subject *s){ return s->priority*1000 + s->students*10 + s->classesPerWeek; }
/* DAA SORTING: insertion sort prioritizes the most constrained/difficult classes. */
void sort_subjects_by_difficulty(Subject a[], int n){ for(int i=1;i<n;i++){ Subject key=a[i]; int j=i-1; while(j>=0 && difficulty(&a[j])<difficulty(&key)){a[j+1]=a[j];j--;} a[j+1]=key; } }
/* DAA SEARCHING: linear search is intentionally explicit for viva demonstration. */
int search_subject(Subject a[], int n, const char *code){ for(int i=0;i<n;i++) if(strcmp(a[i].code,code)==0) return i; return -1; }
int search_room(Room a[], int n, const char *name){ for(int i=0;i<n;i++) if(strcmp(a[i].name,name)==0) return i; return -1; }
