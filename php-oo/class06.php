<?php
date_default_timezone_set("PRC");
/**
 * 静态成员
 * 1. 静态属性用于保存类的公有数据
 * 2. 静态方法里面只能访问静态属性
 * 3. 静态成员不需要实例化对象就可以访问
 * 4. 类内部，可以通过self或者static关键字访问自身的静态成员
 * 5. 可以通过parent关键字访问父类的静态成员
 * 6. 可以通过类名称在外部访问类的静态成员
 */
class Human{
    public $name;
    protected $height; // 只有自身和子类可以访问到
    public $weight;
    private $isHungry=true; // 只有自身可以访问到

    public static $sValue="Static Value in Human";

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

    public static $president="David Stern";

    public static function changePresident($newPrsdt){
        static::$president = $newPrsdt; // self用于表示当前类，"::"操作符用于访问类的静态成员
        // static关键字也可以用于访问当前类的静态成员
        // echo $this->age . "\n"; // 不能在静态方法中使用this伪变量，也不能用对象的->方式调用静态成员
        echo parent::$sValue . "\n"; // parent用于表示父类，可以用于访问父类的静态成员
    }

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

// 类名加“::”可以访问类的静态成员
// 静态成员不需要实例化就可以访问
echo "The president is ". NbaPlayer::$president. "\n";
NbaPlayer::changePresident("Adam Silver");
echo "The president is changed to ". NbaPlayer::$president. "\n";

?>
