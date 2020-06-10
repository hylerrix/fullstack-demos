<?php
date_default_timezone_set("PRC");
/**
 * 访问控制
 * 1. public的类成员可以被自身、子类和其他类访问
 * 2. protected的类成员只能被自身和子类访问
 * 3. private的类成员只能被自身访问
 */
class Human{
    public $name;
    protected $height; // 只有自身和子类可以访问到
    public $weight;
    private $isHungry=true; // 只有自身可以访问到

    public function eat($food){
        echo $this->name . "'s eating ". $food. "\n";
    }

    public function info(){
        print "HUMAN: " . $this->name . ";" . $this->height . ";" . $this->weight . ";" . $this->isHungry ."\n";
    }
}

// extends关键字用于说明该类继承自某个父类
class NbaPlayer extends Human
{
    // 类的属性的定义
    public $team="Bull";
    public $playerNumber="23";

    private $age="40"; // private 类型的属性不能被对象外部访问，但是可以在对象内部使用

    // 构造函数通常用于初始化对象的属性值
    function __construct($name, $height, $weight, $team, $playerNumber) {
       print $name . ";" . $height . ";" . $weight . ";" . $team . ";" . $playerNumber."\n";
       $this->name = $name; // $this是php里面的伪变量，表示对象自身
       $this->height = $height; // 通过$this可以设置对象的属性值
       $this->weight = $weight;
       $this->team = $team;
       $this->playerNumber = $playerNumber;
       echo $this->isHungry."\n";
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
    public function getAge(){
        echo $this->name . "'s age is " . ($this->age - 2) . "\n";
    }
}

$jordan = new NbaPlayer("Jordan", "198cm", "98kg", "Bull", "23");
// step1, 证明public和protected的属性可以被子类和自身访问
$jordan->info();

// step2，证明public的属性可以被其他类访问
echo $jordan->getAge()."\n";

// step3，证明private的属性只能被自身访问
// 把这行代码添加到构造函数试试
echo $this->isHungry."\n";
?>
