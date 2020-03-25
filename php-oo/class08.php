<?php
date_default_timezone_set("PRC");
/**
 * 数据访问补充
 * 1. parent关键字可以用于调用父类被重写的类成员
 * 2. self关键字可以用于访问类自身的成员方法，也可以用于访问自身的静态成员和类常量；不能用于访问类自身的属性；访问类常量时不用在常量名称前面加$符号
 * 3. static关键字用于访问类自身定义的静态成员，访问静态属性时需要在属性名前面添加$符号
 */

class BaseClass {
   public function test() {
       echo "BaseClass::test() called\n";
   }
   
   public function moreTesting() {
       echo "BaseClass::moreTesting() called\n";
   }
}

class ChildClass extends BaseClass {
  public $height="198cm";
  private static $sValue = "static value";
  const CONST_VALUE = 'A constant value';
  public function moreTesting() {
       echo "ChildClass::moreTesting() called\n";
       parent::moreTesting(); // parent关键字可以访问父类被重写的成员
       // step 3 self关键字可以访问该类自身的其他成员
       self::called();
       // step 4 self关键字可以访问该类定义的常量
       echo "CONST_VALUE: " . self::CONST_VALUE."\n";
       // 常量不能被赋值修改
       // self::CONST_VALUE = 11;
       // step 5 static关键字可以访问静态成员，当调用静态属性时记得加$符号
       echo "sValue: " . static::$sValue."\n";
  }
  // step 3
  public function called(){
    echo "ChildClass::called() called\n";
  }
 }
// Results in Fatal error: Cannot override final method BaseClass::moreTesting()
$obj = new ChildClass();
$obj->moreTesting();
?>
