<?php
/*
 * 线性表
 * 顺序存储结构
 */

class linearList{
    /* 存放线性表数据 */
    public $data = array();

    /*
     * @param newdata array
     * @return void
     */
    public function __construct($newdata=array()){
        $this->data = $newdata;
    }

    /*
     * 获取线性表的给定下标的元素
     * @param index int
     * @return mixed
     */
    public function getElement($index=0){
        return $this->data[$index];
    }

    /*
     * 获取线性表的给定值的下标
     * @param index int
     * @return mixed
     */
    public function getIndex($ele=""){
        return array_search($ele,$this->data);
    }
    
    /*
     * 在指定位置插入数据
     * @param data mixed 要插入的元素
     * @param index int 指定的下标
     * @return bool 成功返回true,失败返回false
     */
    public function insert($data,$index=0){
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
     * 删除指定位置的元素\
     * @param index int
     * @return bool
     */
    public function deleteElementByIndex($index=0){
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
     * @param ele mixed
     * @return bool
     */
    public function push($ele=""){
        return array_push($this->data,$ele);
    }
    
    /*
     * 清空线性表数据
     * @param void
     * @return void
     */
    public function clear(){
        foreach($this->data as $k=>$v){
            unset($this->data[$k]);
        }
    }
}

$newArr = [
    "key1"=>"value1",
    "key2"=>"value2",
    "key3"=>"value3"
];
$newdata = new linearList($newArr);
echo $newdata->deleteElementByIndex(3);
print_r( $newdata->data );







