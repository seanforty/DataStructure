<?php
declare(strict_types=1);
$arr0 = [6,10,8,7,5,1,3,4,2,9];


/* 四 快速排序：从小到大排序 
找到当前数组中的任意一个元素（一般选择第一个元素），作为标准，新建两个空数组，遍历整个数组元素，
如果遍历到的元素比当前的元素要小，那么就放到左边的数组，否则放到右面的数组，然后再对新数组进行同样的操作，
以此递归实现，最后将左数组、基准元素、右数组合并返回。
*/
function quickSort(array $arr):array
{
    $len = count($arr);
    if($len<1){
        return $arr;
    }
    $baseNum = $arr[0];
    $leftArr = [];
    $rightArr = [];
    for($i=1;$i<$len;$i++){
        if($arr[$i]>$baseNum){
            $rightArr[] = $arr[$i];
        }else{
            $leftArr[] = $arr[$i];
        }
    }
    
    $leftArr = quickSort($leftArr);
    $rightArr = quickSort($rightArr);
    return array_merge($leftArr,[$baseNum],$rightArr);
}

$arr1 = quickSort($arr0);
print_r($arr1);






















