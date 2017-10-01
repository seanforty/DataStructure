<?php
declare(strict_types=1);
$arr0 = [6,10,8,7,5,1,3,4,2,9];

function swap(&$a,&$b)
{
    $temp = $a;
    $a = $b;
    $b = $temp;
}

/* 四 希尔排序：从小到大排序 
希尔排序是基于插入排序的，区别在于插入排序是相邻的一个个比较（类似于希尔中h=1的情形），而希尔排序是距离h的比较和替换。
*/
function shellSort(array &$arr)
{
    $len = count($arr); //output 10
    $f = 5; //定义因子
    $h = 1; //最小为1
    while($h < $len/$f){
        $h = $f * $h + 1;   //output 4
    }
    
    while($h >= 1){
        for($i=$h;$i<$len;$i++){
            for($j=$i;$j>=$h;$j-=$h){
                if($arr[$j]<$arr[$j-$h]){
                    swap($arr[$j],$arr[$j-$h]);
                }
                //print_r($arr);echo("<br>");
            }
        }
        $h = intval($h/$f);
    }
}

shellSort($arr0);
print_r($arr0);






















