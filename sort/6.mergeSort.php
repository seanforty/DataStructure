<?php
declare(strict_types=1);
$arr0 = [6,10,8,7,5,1,3,4,2,9];

function swap(&$a,&$b)
{
    $temp = $a;
    $a = $b;
    $b = $temp;
}

/* 四 并归排序：从小到大排序
归并排序：时间复杂度为~O(nlogn)--又称合并排序
归并(Merge)排序法是将两个（或两个以上）有序表合并成一个新的有序表，
即把待排序序列分为若干个有序的子序列，再把有序的子序列合并为整体有序序列。
*/

function mergeSort(array &$arr)
{
    $start = 0;
    $end = count($arr) - 1;
    MSort($arr,$start,$end);
}

function MSort(array &$arr,$start,$end)
{
    if($start<$end)
    {
        $mid = floor( ($start + $end)/2 );
        MSort($arr,$start,$mid);
        MSort($arr,$mid+1,$end);
        Merge($arr,$start,$mid,$end);
    }
}

function Merge()
{
    $i = $start;
    $j = $mid + 1;
    $k = $start;
    
    $tempArr = [];
    while($i!=$mid+1 && $j=$end+1){
        if($arr[$i]>=$arr[$j])
        {
            
        }
    }
}

























