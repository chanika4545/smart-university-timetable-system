#include <string.h>
#include "timetable.h"
/* DAA CONFLICT DETECTION: capacity, teacher, batch and room constraints. */
int has_conflict(Assignment a[], int count, Subject s[], int si, int day, int slot, int ri, Room rooms[], Stats *st){
 if(rooms[ri].capacity<s[si].students){st->conflicts++;return 1;}
 if(!(s[si].availableMask&(1u<<day))){st->conflicts++;return 1;}
 for(int i=0;i<count;i++) if(a[i].day==day&&a[i].slot==slot){ Subject *old=&s[a[i].subjectIndex]; if(a[i].roomIndex==ri||strcmp(old->teacher,s[si].teacher)==0||strcmp(old->batch,s[si].batch)==0){st->conflicts++;return 1;} }
 return 0;
}
static int solve(int k,int total,int classSub[],Subject s[],Room r[],int rn,Assignment a[],Stats *st){
 if(k==total) return 1;
 int si=classSub[k];
 /* DAA GREEDY: candidates are tried in deterministic day/slot/smallest-fitting-room order. */
 for(int d=0;d<DAYS;d++) for(int sl=0;sl<SLOTS;sl++) for(int ri=0;ri<rn;ri++){ st->attempts++; if(has_conflict(a,k,s,si,d,sl,ri,r,st))continue; a[k]=(Assignment){si,d,sl,ri}; if(solve(k+1,total,classSub,s,r,rn,a,st))return 1; st->backtracks++; /* DAA BACKTRACKING: undo this assignment and try the next candidate. */ }
 return 0;
}
int generate_timetable(Subject s[],int sn,Room r[],int rn,Assignment out[],int *outCount,Stats *st){ int classSub[MAX_CLASSES],total=0; *st=(Stats){0}; for(int i=0;i<sn;i++)for(int k=0;k<s[i].classesPerWeek;k++)classSub[total++]=i; if(total>MAX_ASSIGNMENTS)return 0; if(!solve(0,total,classSub,s,r,rn,out,st)){*outCount=0;return 0;} *outCount=total;return 1; }
