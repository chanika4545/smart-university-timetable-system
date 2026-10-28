#include <stdio.h>
#include "timetable.h"
#include "algorithms.h"
int main(void){
 Subject s[]={ {"DAA","Dr. A. Sharma","CSE-A",62,5,4,31},{"OS","Prof. N. Verma","CSE-A",62,4,3,15},{"DBMS","Dr. R. Mehta","CSE-A",62,4,3,23},{"AIML","Prof. P. Singh","CSE-A",62,5,3,30},{"CN","Dr. K. Joshi","CSE-A",62,3,2,29} };
 Room r[]={{"C-301",70},{"C-302",65},{"Lab-1",70},{"Seminar Hall",120}}; int sn=5,rn=4,n=0; Assignment a[MAX_ASSIGNMENTS]; Stats st;
 sort_subjects_by_difficulty(s,sn); printf("Smart University C DAA Timetable Engine\n=======================================\n");
 if(!generate_timetable(s,sn,r,rn,a,&n,&st)){puts("No valid timetable found.");return 1;}
 const char *days[]={"Mon","Tue","Wed","Thu","Fri"}; const char *times[]={"09:00","10:00","11:00","13:00","14:00","15:00"};
 for(int i=0;i<n;i++) printf("%-4s %-3s %-5s %-12s %-16s\n",days[a[i].day],times[a[i].slot],s[a[i].subjectIndex].code,r[a[i].roomIndex].name,s[a[i].subjectIndex].teacher);
 printf("\nAssignments: %d\nAttempts: %ld\nConflicts detected: %ld\nBacktracking operations: %ld\nFinal conflicts: 0\n",n,st.attempts,st.conflicts,st.backtracks); return 0;
}
