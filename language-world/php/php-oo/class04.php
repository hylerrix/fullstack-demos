<?php
date_default_timezone_set("PRC");
/**
 * 继承
 * 1. 定义人类
 * 2. 让NbaPlayer继承人类
 * 3. PHP中类不允许同时继承多个父类，也就是extends后面只能跟一个父类名称，这个特性被称为PHP的单继承特性
 */
class Human{
    public $name;
    public $height;
    public $weight;

    public function eat($food){
        echo $this->name . "'s eating ". $food. "\n";
    }
}

// extends关键字用于说明该类继承自某个父类
class NbaPlayer extends Human
{
    // 类的属性的定义
    public $team="Bull";
    public $playerNumber="23";

    private $age="40"; // private 类型的属性不能被对象外部访问，但是可以在对象内部使用

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
$jordan->eat("apple"); // 只要是Human类的子类的对象，就可以调用eat方法

?>
