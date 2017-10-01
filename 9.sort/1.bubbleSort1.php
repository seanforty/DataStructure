<?php
declare(strict_types=1);
$arr0 = [6,10,8,7,5,1,3,4,2,9];

function swap(&$a,&$b)
{
    $temp = $a;
    $a = $b;
    $b = $temp;
}


/* 一 冒泡排序变种之一：从小到大排序 
在某次遍历中如果没有数据交换，说明整个数组已经有序。因此通过设置标志位来记录此次遍历有无数据交换就可以判断是否要继续循环。
*/
function bubbleSort1(array &$arr)
{
    $len = count($arr);
    for($i=0;$i<$len-1;$i++)
    {
        $flag = true;
        for($j=$i+1;$j<$len;$j++)
        {
            if($arr[$i]>$arr[$j])
            {
                swap($arr[$i],$arr[$j]);
                $flag = false;
            }
        }
        if($flag)
        {
            break;            
        }
    }
}

bubbleSort1($arr0);
print_r($arr0);






















