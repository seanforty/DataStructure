<?php
declare(strict_types=1);
$arr0 = [6,10,8,7,5,1,3,4,2,9];

function swap(&$a,&$b)
{
    $temp = $a;
    $a = $b;
    $b = $temp;
}

/* 一 冒泡排序变种之二：从小到大排序 
记录某次遍历时最后发生数据交换的位置，这个位置之后的数据显然已经有序了。因此通过记录最后发生数据交换的位置就可以确定下次循环的范围了。
*/
function bubbleSort2(array &$arr)
{
    $len = count($arr);
    $lastSwapPos = 0;
    $lastSwapPosTemp = 0;
    for($i=0;$i<$len-1;$i++)
    {
        $lastSwapPos = $lastSwapPosTemp;
        for($j=$len-1;$j>$lastSwapPos;$j--)
        {
            if($arr[$j-1]>$arr[$j])
            {
                swap($arr[$j-1],$arr[$j]);
                $lastSwapPosTemp = $j;
            }
        }
        if($lastSwapPos == $lastSwapPosTemp){
            break;
        }
    }
    return $arr;
}

bubbleSort2($arr0);
print_r($arr0);






















