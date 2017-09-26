<?php
//单向链表
class doubleLinkList{
    /* 存放链表数据 */
    public $data;
    /* 存放后继数据地址 */
    public $next = null;
    /* 存放前驱数据地址 */
    public $prev = null;
    
    public function __construct($data){
        $this->data  = $data;
    }
}

class doubleLinkListOperation{
    /*
     * 新建链表，返回头结点
     * @param void
     * @return void
     */
    public function newList(){
        return new doubleLinkList(null);
    }

    /*
     * 给链表尾部添加结点
     * @param head object 头结点
     * @param data mixed 结点数据
     * @return void
     */
    public function addNode($head,$data){
        $this->isListAvailable($head);
        $cursor = $head;
        while(!is_null($cursor->next)){
            $cursor = $cursor->next;
        }
        $node = new doubleLinkList($data);
        $cursor->next = $node;
        $node->prev = $cursor;
    }
    
    /*
     * 获取链表结点数量
     * @param head object 头结点
     * @return void
     */
    public function countNode($head){
        $cursor = $head;
        $count = 0;
        while(!is_null($cursor->next)){
            $cursor = $cursor->next;
            $count += 1;
        }
        return $count;
    }
    
    /*
     * 获取链表结点数量
     * @param head object 头结点
     * @param data 新结点要插入的数据
     * @param index 新结点要插入的位置
     * @return void
     */
    public function insertNode($head,$data,$index){
        $this->isListAvailable($head);
        $cursor = $head;
        for($i=1;$i<$index;$i++){
            $cursor = $cursor->next;
        }
        $newNode = new doubleLinkList($data);
        $newNode->next = $cursor->next;
        $cursor->next = $newNode;
    }
    
    /*
     * 删除指定位置的结点
     * @param head object 头结点
     * @param index 新结点要插入的位置
     * @return void
     */
    public function deleteNode($head,$index){
        $this->isListAvailable($head);
        $cursor = $head;
        for($i=1;$i<$index;$i++){
            $cursor = $cursor->next;
        }
        $cursor->next = $cursor->next->next;
    }
    
    /*
     * 遍历链表
     * @param head object 头结点
     * @return mixed
     */
    public function traversal($head){
        $this->isListAvailable($head);
        
        $cursor = $head;
        while(!is_null($cursor->next)){
            print_r($cursor->data); 
            echo("\n");
            $cursor = $cursor->next;
        }
        print_r($cursor->data);
        echo("\n");
    }
    
    /*
     * 根据下标返回结点数据
     * @param head object 头结点
     * @return mixed
     */
    public function findNode($head,$index){
        $this->isListAvailable($head);
        $cursor = $head;
        for($i=1;$i<=$index;$i++){
            $cursor = $cursor->next;
        }
        return $cursor->data;
    }
    
    /*
     * 清空链表
     * @param node object 结点对象
     */
    public function clearList(&$head){
        $head = null;
    }
    
    /*
     * 查找数据返回第一次出现的数据所在位置
     * @param head object 头结点
     * @return mixed
     */
    public function getIndex($head,$data){
        $this->isListAvailable($head);
        $cursor = $head;
        $length = $this->countNode($head);
        for($i=1;$i<=$length;$i++){
            $cursor = $cursor->next;
            if($cursor->data == $data){
                return $i;
            }
        }
        return "not found";
    }
    
    
    protected function isListAvailable($head,$index=0){
        if(null==$head){
            exit("empty list");
        }
        if($head instanceof doubleLinkList){
            if( $index > $this->countNode($head) ){
                exit("index out of range");
            }
        }else{
            exit("head is not instance of singleLinkList");            
        }
    }

}

$oper = new doubleLinkListOperation();
$head = $oper->newList();   //新建链表，返回头结点
$oper->addNode($head,"a");  //给链表尾部添加结点
$oper->addNode($head,"b");
$oper->addNode($head,"c");
$oper->addNode($head,"d");

echo $head->next->next->prev->data;





