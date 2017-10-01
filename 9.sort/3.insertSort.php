<?php
declare(strict_types=1);
$arr0 = [6,10,8,7,5,1,3,4,2,9];

function swap(&$a,&$b)
{
    $temp = $a;
    $a = $b;
    $b = $temp;
}

/* 三 插入排序：从小到大排序 
每次将一个待排序的数据，插入到前面已经排好序的序列之中，直到全部数据插入完成。
*/
function insertSort(array &$arr){
    $len = count($arr);
    for($i=0;$i<$len;$i++){
        $tmp = $arr[$i];
        for($j=$i-1;$j>=0;$j--){
            if($tmp<$arr[$j]){
                $arr[$j+1] = $arr[$j];
                $arr[$j] = $tmp;
            }else{
                break;
            }
        }
    }
}

insertSort($arr0);
print_r($arr0);






















