<?php
//栈：先进先出
class stack{
    //存储栈数据
    public $stack = array();
    //栈容量
    public $volume=0;
    //栈顶
    public $top=-1;
    
    public function __construct($volume=10){
        $this->InitStack($volume);
    }

    /*
     * 初始化栈
     * @param volume mixed
     * @return void
     */
    public function InitStack($volume){
        $this->volume = $volume;
        $this->top  = -1;
    }
    
    /*
     * 压入栈
     * @param data mixed
     * @return int
     */
    public function push($data){
        $this->isFull();
        $this->top += 1;
        return array_push($this->stack,$data);
    }
    
    /*
     * 弹出栈
     * @param void
     * @return mixed
     */
    public function pop(){
        $this->isEmpty();
        $this->top -= 1;
        return array_pop($this->stack);
    }
    
    /*
     * 获取栈顶
     * @param void
     * @return void
     */
    public function getTop(){
        $this->isEmpty();
        return $this->stack[$this->top];
    }
    
    /*
     * 是否为空栈 空栈返回true, 非空返回false
     * @param void
     * @return void
     */
    public function size(){
        return $this->top + 1;
    }
    
    /*
     * 是否为空栈 空栈返回true, 非空返回false
     * @param void
     * @return void
     */
    public function isEmpty(){
        if(-1==$this->top){
            exit("Error: stack is empty!");
        }
    }
    
    /*
     * 是否为满栈 满栈返回true, 非满返回false
     * @param void
     * @return void
     */
    public function isFull(){
        if($this->volume <= ($this->top + 1)){
            exit("Error: Stack is full!");
        }
    }

}

$stack = new stack(10);
$stack->push("a");
echo "Size:".$stack->size()."\n";
$stack->push("b");
echo "Size:".$stack->size()."\n";
$stack->push("c");
echo "Size:".$stack->size()."\n";
$stack->push("d");
echo $stack->pop()."\n";
echo "Size:".$stack->size()."\n";




