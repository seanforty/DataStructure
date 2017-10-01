<?php
//队列：先进先出
class queue{
    public $front;//前端，弹出元素
    public $rear; //远端，压入元素
    public $volume; //队列容量
    public $data = array(); //存放队列数据
    
    public function __construct($size)
    {
        $this->InitQueue($size);
    }
    
    /* 初始化 */
    public function InitQueue($size=5)
    {
        $this->front = 0;
        $this->rear  = 0;
        $this->volume = $size;
    }
    
    /* 入队 */
    public function enQueue($data)
    {
        $this->fullQueue();
        array_push($this->data,$data);
        $this->rear += 1;
    }
    
    /* 出队 */
    public function delQueue()
    {
        $this->rear -= 1;
        return array_shift($this->data);
    }
    
    /* 获取队头 */
    public function getFront()
    {
        return $this->data[0];
    }
    
    /* 获取队尾 */
    public function getRear()
    {
        return $this->data[($this->rear)-1];
        //return end($this->data);
    }
    
    /* 判空 */
    public function fullQueue()
    {
        if( abs($this->front - $this->rear) >= $this->volume ){
            exit("Error:Queue is full");
        }
    }
    
    /* 判满 */
    public function emptyQueue()
    {
        if( $this->front = $this->rear ){
            exit("Error:Queue is empty");
        }
    }
}

$que = new queue(4);
$que->enQueue("hello");
$que->enQueue("world");
$que->enQueue("hi");
$que->enQueue("php");

//$que->delQueue();
/* print_r($que->data);
echo $que->delQueue();
print_r($que->data);
echo $que->getRear(); */
$que->enQueue("how");













