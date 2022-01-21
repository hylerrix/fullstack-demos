<?php
date_default_timezone_set("PRC");
/**
 * 多态
 * 1. 只要某个对象实现了接口（instanceof），就可以直接在对象上调用接口的方法
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

function eat($obj){
  if($obj instanceof ICanEat){ 
    $obj->eat("FOOD"); // 不需要知道到底是Human还是Animal，直接吃就行了
  }else{
    echo "Can't eat!\n";
  }
}

$man = new Human();
$monkey = new Animal();

// 同样的代码，传入接口的不同实现类的时候，表现不同。这就是为什么成为多态的原因。
eat($man);
eat($monkey);

?>
