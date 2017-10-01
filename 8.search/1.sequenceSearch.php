<?php
/* Ë³Ðò²éÕÒ */
function seqSearch(array $arr,$value)
{
	//array_search($value,$arr);
	$flag = false;
	foreach($arr as $k=>$v)
	{
		if($v == $value)
		{
			$flag = true;
			break;
		}
	}
	if($flag)
	{
		return $k;
	}else
	{
		return false;
	}
}

$arr = [25, 51, 33, 24, 81, 40, 17, 46, 76, 59];
echo seqSearch($arr,59);