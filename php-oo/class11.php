<?php
date_default_timezone_set("PRC");
/**
 * 抽象类
 * 1. 抽象类允许类里面的部分方法暂时没有具体实现，这些方法我们成为抽象方法
 * 2. 一旦类里面有抽象方法，这个类就必须是抽象类
 * 3. 抽象类跟接口一样，不能直接实例化为对象
 */

// 抽象类前面以abstract关键字开始
abstract class ACanEat {
   // 没有实现的方法需要设定为抽象方法
   // 抽象方法需要在子类中实现 
   abstract public function eat($food);

   public function breath(){
      echo "Breath use the air.\n";
   }
}

// Human类实现了ICanEat接口
class Human extends ACanEat { 
  // 跟Animal类的实现是不同的
  public function eat($food){
    echo "Human eating " . $food . "\n";
  }
}

// Animal类实现了ICanEat接口
class Animal extends ACanEat {
  public function eat($food){
    echo "Animal eating " . $food . "\n";
  }
}

$man = new Human();
$man->eat("Apple");
$man->breath(); // 和Animal共用了抽象类ICanEat的breath方法
$monkey = new Animal();
$monkey->eat("Banana");
$monkey->breath();

?>
