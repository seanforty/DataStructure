<?php
/* 二分查找 非递归查找 */
function binarySearch($arr,$value)
{
	sort($arr);
	$min = 0;
	$max = count($arr);
	for($i=$min;$i<$max;$i++)
	{
		$mid = ceil(($min+$max)/2);
		if($value==$arr[$i])
		{
			return $i;
		}elseif($value>$mid)
		{
			$min = $mid;
		}else
		{
			$max = $mid;
		}
	}
}

$arr = [25, 51, 33, 24, 81, 40, 17, 46, 76, 59];
if($res = binarySearch($arr,811))
{
	echo $res;
}else
{
	echo "not found";
}


