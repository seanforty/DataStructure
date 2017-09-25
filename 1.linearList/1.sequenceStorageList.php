<?php
/*
 * 线性表
 * 顺序存储结构
 */
declare (strict_types=1);
class linearList
{
    /* 存放线性表数据 */
    protected $data = array();

    /*
     * @param newdata array
     * @return void
     */
    public function __construct(array $newdata=[])
    {
        $this->data = $newdata;
    }

    /*
     * 获取线性表的给定下标的元素,元素存在则返回,不存在返回false
     * @param index mixed
     * @return mixed
     */
    public function getElement($index)
    {
        if(isset($this->data[$index])){
            return $this->data[$index];
        }else{
            return false;
        }
    }

    /*
     * 获取线性表的给定值的下标
     * @param value
     * @return int
     */
    public function getIndex(string $value)
    {
        return array_search($value,$this->data);
    }
    
    /*
     * 在指定位置插入数据
     * @param data mixed 要插入的元素
     * @param index int 指定的下标
     * @return bool 成功返回true,失败返回false
     */
    public function insert($data,int $index=0):bool
    {
        $len = count($this->data);
        if(0==$index){
            return array_unshift($this->data,$data);
        }elseif($index<$len){
            array_splice($this->data,$index,0,$data);
            return count($this->data);
        }else{
            return array_push($this->data,$data);
        }
    }
    
    /*
     * 删除指定位置的元素
     * @param index int
     * @return bool
     */
    public function deleteElementByIndex(int $index=0):bool
    {
        $len = count($this->data);
        if($index<$len){
            array_splice($this->data,$index,1);
            return true;
        }else{
            return false;
        }
    }
    
    /*
     * 在表尾部添加一个元素
     * @param element mixed
     * @return int
     */
    public function push($element)
    {
        return array_push($this->data,$element);
    }
    
    /*
     * 清空线性表数据
     * @param void
     * @return void
     */
    public function clear()
    {
        foreach($this->data as $k=>$v){
            unset($this->data[$k]);
        }
    }

    public function __get($name)
    {
        return $this->$name;
    }
}

$newArr = [
    "value1",
    "value2",
    "value3",
    "value4",
    "value5",
    "value6",
];
$newdata = new linearList($newArr); //初始化线性表
/* 获取指定键对应的元素 */
//if($ele = $newdata->getElement("1")){
//    echo $ele;
//}else{
//    echo "Wrong index!";
//}
/* 获取元素对应的键 */
//if($index = $newdata->getIndex("value42")){
//    echo $index;
//}else{
//    echo "Element does not exsit!";
//}
//if($newdata->deleteElementByIndex(1)){  //删除指定元素
//    print_r($newdata->data);
//}
/* 队尾加一个元素 */
//if($newdata->push("hello")){
//    print_r($newdata->data);
//}else{
//    echo "Push error.";
//}





