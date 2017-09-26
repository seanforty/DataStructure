<?php
declare(strict_types=1);
$arr0 = [6,10,8,7,5,1,3,4,2,9];

function swap(&$a,&$b)
{
    $temp = $a;
    $a = $b;
    $b = $temp;
}

/* 二 选择排序：从小到大排序 
数组分成有序区和无序区，初始时整个数组都是无序区，然后每次从无序区选一个最小的元素直接放到有序区的最后，直到整个数组变有序区。
*/
function selectSort(array &$arr){
    $len = count($arr);
    for($i=0;$i<$len-1;$i++){
        $minV = $arr[$i];
        $minK = $i;
        for($j=$i+1;$j<$len;$j++){
            if($minV>$arr[$j]){
                $minV = $arr[$j];
                $minK = $j;
            }
        }
        swap($arr[$i],$arr[$minK]);
    }
}

selectSort($arr0);
print_r($arr0);






















