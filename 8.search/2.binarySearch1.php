<?php
/* 二分查找 递归查找 */
function binSearch($arr,$value,$min,$max)
{
	if($min>$max)
	{
		return false;
	}
	$mid = floor( ($min + $max)/2 );
	if($value==$arr[$mid])
	{
		return $mid;
	}
	elseif($value>$arr[$mid])
	{
		
		return binSearch($arr,$value,$mid+1,$max);
	}else
	{
		return binSearch($arr,$value,$min,$mid-1);
	}
}

function binarySearch(array &$arr,$value)
{
	$min = 0;
	$max = count($arr);
	asort($arr);
	if(empty($arr))
	{
		return false;
	}elseif($arr[0]==$value)
	{
		return $arr[0];
	}else
	{
		return binSearch($arr,$value,$min,$max);		
	}
}

$arr = [4, 7, 10, 2, 8, 5, 1, 0, 3, 6, 9];
if($res = binarySearch($arr,2))
{
	echo $res;
}else
{
	echo "not found";
}


/* function binaryRecursive(&$arr,$low,$top,$target){
    if($low<=$top){
      $mid = floor(($low+$top)/2);
      if($mid==$target){
        return $arr[$mid];
      }elseif($target>$arr[$mid]){
        return binaryRecursive($arr,$mid+1,$top,$target);
      }else{
        return binaryRecursive($arr,$low,$top-1,$target);
      }
    }else{
      return -1;
    }
} */