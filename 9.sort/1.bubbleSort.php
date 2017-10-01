<?php
declare(strict_types=1);
$arr0 = [6,10,8,7,5,1,3,4,2,9];

function swap(&$a,&$b)
{
    $temp = $a;
    $a = $b;
    $b = $temp;
}

/* 一 冒泡排序：从小到大排序 
通过交换使相邻的两个数变成小数在前大数在后，这样每次遍历后，最大的数就“沉”到最后面了。重复N次即可以使数组有序。
*/
function bubbleSort(array &$arr)
{
    $len = count($arr);
    for($i=0;$i<$len-1;$i++)
    {
        for($j=$i+1;$j<$len;$j++)
        {
            if($arr[$i]>$arr[$j])
            {
                swap($arr[$i],$arr[$j]);
            }
        }
    }
}

bubbleSort($arr0);
print_r($arr0);
























