<?php
//单向链表
class singleLinkList
{
    /* 存放链表数据 */
    public $data;
    /* 存放后继数据地址 */
    public $next = null;
    
    public function __construct($data)
    {
        $this->data  = $data;
    }
}

class singleLinkListOperation
{
    /*
     * 新建链表，返回头结点
     * @param void
     * @return void
     */
    public function newList()
    {
        return new singleLinkList(null);
    }

    /*
     * 给链表尾部添加结点
     * @param head object 头结点
     * @param data mixed 结点数据
     * @return void
     */
    public function addNode(singleLinkList $head,$data)
    {
        $this->isListAvailable($head);
        $cursor = $head;
        while(!is_null($cursor->next)){
            $cursor = $cursor->next;
        }
        $node = new singleLinkList($data);
        $cursor->next = $node;
    }
    
    /*
     * 获取链表结点数量
     * @param head object 头结点
     * @return void
     */
    public function countNode(singleLinkList $head)
    {
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
     * @param data mixed 新结点要插入的数据
     * @param index int 新结点要插入的位置
     * @return void
     */
    public function insertNode(singleLinkList $head,$data,int $index)
    {
        $this->isListAvailable($head);
        $cursor = $head;
        for($i=1;$i<$index;$i++){
            $cursor = $cursor->next;
        }
        $newNode = new singleLinkList($data);
        $newNode->next = $cursor->next;
        $cursor->next = $newNode;
    }
    
    /*
     * 删除指定位置的结点
     * @param head object 头结点
     * @param index int 新结点要插入的位置
     * @return void
     */
    public function deleteNode(singleLinkList $head,int $index)
    {
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
    public function traversal(singleLinkList $head)
    {
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
     * @param index int
     * @return mixed
     */
    public function findNode(singleLinkList $head,int $index)
    {
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
    public function clearList(singleLinkList &$head)
    {
        $head = null;
    }
    
    /*
     * 查找数据返回第一次出现的数据所在位置
     * @param head object 头结点
     * @param data mixed
     * @return mixed
     */
    public function getIndex(singleLinkList $head,$data)
    {
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
    
    /*
     * 判断链表是否为空
     */
    protected function isListAvailable(singleLinkList $head,int $index=0)
    {
        if(null==$head){
            exit("empty list");
        }
        if($head instanceof singleLinkList){
            if( $index > $this->countNode($head) ){
                exit("index out of range");
            }
        }else{
            exit("head is not instance of singleLinkList");            
        }
    }

}

$head = new singleLinkList(null);//定义头结点
$oper = new singleLinkListOperation();
$head = $oper->newList();   //新建链表，返回头结点
$oper->addNode($head,"a");  //给链表尾部添加结点
$oper->addNode($head,"b");
$oper->addNode($head,"c");
$oper->addNode($head,"d");
//echo $oper->countNode($head);   //输出链表中结点数量
$oper->traversal($head);    //遍历链表结点并输出
/* 
//$oper->clearList($head);    //清空链表
//print_r($head);
$oper->traversal($head);
$oper->insertNode($head,"new",2);
$oper->traversal($head);
$oper->deleteNode($head,3);
$oper->traversal($head); */
echo "找到结点：".$oper->findNode($head,1);//查找指定位置的结点数据
echo("\n");
echo "找到结点位置：".$oper->getIndex($head,"d");





