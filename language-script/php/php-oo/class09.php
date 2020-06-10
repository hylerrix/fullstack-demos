<?php
date_default_timezone_set("PRC");
/**
 * 接口
 * 1. 接口的基本概念和基本使用方法
 * 2. 接口里面的方法没有具体的实现
 * 3. 实现了某个接口的类必须提供接口中定义的方法
 * 4. 不能用接口创建对象，但是能够判断某个对象是否实现了某个接口
 * 5. 接口可以继承接口（interface extends interface）
 * 6. 接口中定义的所有方法都必须是公有，这是接口的特性。
 */

interface ICanEat {
   public function eat($food);
}

// Human类实现了ICanEat接口
class Human implements ICanEat { 
  // 跟Animal类的实现是不同的
  public function eat($food){
    echo "Human eating " . $food . "\n";
  }
}

// Animal类实现了ICanEat接口
class Animal implements ICanEat {
  public function eat($food){
    echo "Animal eating " . $food . "\n";
  }
}

// step1 不同的类可以实现同一个接口，定义接口方法的不同实现
$man = new Human();
$man->eat("Apple");
$monkey = new Animal();
$monkey->eat("Banana");

// step2 尝试删除Human的eat方法并运行
// 实现了某个接口的类必须提供接口中定义的方法

// step3 不能用接口创建对象，但是能够判断某个对象是否实现了某个接口
//$eatObj = new ICanEat();
var_dump($man instanceof ICanEat); // 判断某个对象是否实现了某个接口

// step 4 接口可以继承接口
interface ICanPee extends ICanEat {
  public function pee();
}

class Human1 implements ICanPee{
  public function pee(){}
}

// 回到PPT总结接口和类的区别
?>
