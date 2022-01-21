<?php
date_default_timezone_set("PRC");
/**
 * 1. 构造函数
 * 2. 析构函数
 */
class NbaPlayer
{
    // 类的属性的定义
    public $name="Jordan";// 定义属性
    public $height="198cm";
    public $weight="98kg";
    public $team="Bull";
    public $playerNumber="23";

    // 默认的构造函数，在对象被实例化的时候自动调用
    /*function __construct() {
       print "In NbaPlayer constructor\n";
    }*/

    // 构造函数通常用于初始化对象的属性值
    function __construct($name, $height, $weight, $team, $playerNumber) {
        print $name . ";" . $height . ";" . $weight . ";" . $team . ";" . $playerNumber."\n";
       $this->name = $name; // $this是php里面的伪变量，表示对象自身
       $this->height = $height; // 通过$this可以设置对象的属性值
       $this->weight = $weight;
       $this->team = $team;
       $this->playerNumber = $playerNumber;
    }

    // 析构函数，用于清理程序中使用的系统资源，比如释放打开的文件等等
    // 析构函数在该对象不会再被使用的情况下自动调用
    function __destruct() {
       print "Destroying " . $this->name . "\n";
    }

    // 类的方法的定义
    public function run() {
        echo "Running\n";
    }

    public function jump(){
        echo "Jumping\n";
    }
    public function dribble(){
        echo "Dribbling\n";
    }
    public function shoot(){
        echo "Shooting\n";
    }
    public function dunk(){
        echo "Dunking\n";
    }
    public function pass(){
        echo "Passing\n";
    }
}

/**
 * 1. 类实例化为对象时使用new关键字，new之后紧跟类的名称和一对括号。
 * 2. 使用对象可以像使用其他值一样进行赋值操作
 */
$jordan = new NbaPlayer("Jordan", "198cm", "98kg", "Bull", "23");
// 访问对象的属性使用的语法是->符号，后面跟着属性的名称
echo $jordan->name."\n";
// 调用对象的某个方法使用的语法是->符号，后面跟着方法的名称和一对括号
$jordan->run();
$jordan->pass();

$james = new NbaPlayer("James", "203cm", "120kg", "Heat", "6");
echo $james->name."\n";
// 当对象变量被赋值为Null的时候，对象的析构函数会被自动调用
// 同一个类的其他对象不受影响
$james = null; 
echo "From now on James will not be used anymore.\n";
// 当程序执行结束时，所有类的对象的析构函数都会自动被调用
?>