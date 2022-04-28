#pragma once
#include <stddef.h>
/* optimized combsort
combsort(arr,elems) sort array from smallest to largest
combsortr(arr,elems) sort array from largest to smallest
Usage:arrays <140 elems
Performance: ~160 cycles per int
(about 1/4 of radix sort speed)
*/
#define arrcombsort(arr,elems,dir) ({size_t comb_i,comb_j, combgap=elems,comblen=combgap;\
do{combgap = combgap<10 ? combgap-1 : ((combgap*796)>>10)+1;\
 for (comb_i=0,comb_j=combgap; comb_j<comblen; comb_i++,comb_j++){\
const typeof(arr[0]) comb_tmpi=arr[comb_i];\
const typeof(arr[0]) comb_tmpj=arr[comb_j];\
const int comb_cnd=comb_tmpi dir comb_tmpj;\
arr[comb_i]=comb_cnd?comb_tmpj:comb_tmpi;\
arr[comb_j]=comb_cnd?comb_tmpi:comb_tmpj;};}while (combgap);})

#define combsort(arr,elems) arrcombsort(arr,elems,>)
#define combsortr(arr,elems) arrcombsort(arr,elems,<)

